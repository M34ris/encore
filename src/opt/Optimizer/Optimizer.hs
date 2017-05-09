module Optimizer.Optimizer(optimizeProgram) where

import Identifiers
import AST.AST
import AST.Util
import qualified AST.Meta as Meta
import Types
import Control.Applicative (liftA2)
import Debug.Trace

optimizeProgram :: Program -> Program
optimizeProgram p@(Program{classes, traits, functions}) =
    p{classes = map optimizeClass classes
     ,traits = map optimizeTrait traits
     ,functions = map optimizeFunction functions}
    where
      optimizeFunction f@(Function{funbody}) =
          f{funbody = optimizeExpr funbody}

      optimizeTrait t@(Trait{tmethods}) =
          t{tmethods = map optimizeMethod tmethods}

      optimizeClass c@(Class{cmethods}) =
          c{cmethods = map optimizeMethod cmethods}

      optimizeMethod m =
          m{mbody = optimizeExpr (mbody m)}

      optimizeExpr ast =
          foldl (\ast opt -> opt ast) ast optimizerPasses

-- | The functions in this list will be performed in order during optimization
optimizerPasses :: [Expr -> Expr]
optimizerPasses = [constantFolding, sugarPrintedStrings, tupleMaybeIdComparison, dropBorrowBlocks,
                   forwardGeneral, atomicPerformClosure, bestowExpression, bestowPerformClosure]

atomicPerformClosure :: Expr -> Expr
atomicPerformClosure = extend performClosure
  where
    performClosure e@(Atomic{emeta, target, name, body}) = awaitPerform
      where
        targetTy = getType target
        resultTy = getType e
        exprTy = futureType resultTy
        bestowTarget = setType (bestowObjectType (getResultType targetTy)) $ target
        performTarget = if (isBestowedType targetTy)
                        then bestowOwner
                        else target
        atomicVars = name:(Name "this"):(Name "_atomic"):[]

        awaitPerform = Await{emeta = emeta,
                             val = markAsNotStat perform}
        perform = setType exprTy $
                  MessageSend{emeta = emeta,
                              target = performTarget,
                              name = Name "perform",
                              args = [closure],
                              typeArguments = [resultTy]}
        closure = setType (arrowType [] resultTy) $
                  Closure{emeta = emeta,
                          eparams = [],
                          mty = Just targetTy,
                          body = filterBody body atomicVars}
        bestowOwner = setType actorObjectType $
                      FieldAccess{emeta = emeta, target = bestowTarget, name = Name "owner"}
    performClosure e = e

    filterBody :: Expr -> [Name] -> Expr
    filterBody e@(Get{val}) names
      | isMethodCall val && isAtomicTarget (target val) = filterBody val names
      | isAtomicTarget val = filterBody val names
      | otherwise = e
    filterBody e@(MethodCall{target = atom@(AtomicTarget{emeta, target}), args}) names
      | isVarAccess target && isBestow =
          setType (filterFutType exprTy) $ e{target = bestowObject, args = mapFilterBody args names}
      | otherwise =
          setType (filterFutType exprTy) $ e{target = atom{target = filterBody target names},
                                             args = mapFilterBody args names}
      where
        exprTy = getType e
        atomicTy = getType target
        innerTy = getResultType atomicTy
        isBestow = isBestowedType atomicTy
        bestowTarget = setType (bestowObjectType innerTy) $ target
        bestowObject = setType innerTy $
                       FieldAccess{emeta = emeta, target = bestowTarget, name = Name "object"}

        filterFutType :: Type -> Type
        filterFutType ty
          | isFutureType ty = getResultType ty
          | otherwise = ty
    filterBody e@(Let{decls, body}) names =
      e{decls = mapAtomicDecl decls names, body = filterBody body extNames}
      where
        extNames = names ++ (addNames decls)

        addNames :: [([VarDecl], Expr)] -> [Name]
        addNames [] = []
        addNames (decl:decls) = (extractName (fst decl)) ++ addNames decls
    filterBody e@(Match{}) names = putChildren (mapFilterBody (getChildren e) extNames) e
      where
        extNames = names ++ (extractMatchClauseNames e)
    filterBody e@(VarAccess{qname}) names
      | isAtomicVar (qnlocal qname) names = setType (atomicVarType exprTy) e
      | otherwise = e
        where
          exprTy = getType e
          isRecursiveAtomic = isAtomicVarType exprTy
    filterBody e@(AtomicTarget{target}) names = filterBody target names
    filterBody e names = putChildren (mapFilterBody (getChildren e) names) e

    mapFilterBody :: [Expr] -> [Name] -> [Expr]
    mapFilterBody [] _ = []
    mapFilterBody (x:xs) names = (filterBody x names):(mapFilterBody xs names)

    mapAtomicDecl :: [([VarDecl], Expr)] -> [Name] -> [([VarDecl], Expr)]
    mapAtomicDecl decls names = map filterExpr decls
      where
        filterExpr (decls', expr') = (decls', filterBody expr' names)

    extractMatchClauseNames :: Expr -> [Name]
    extractMatchClauseNames (Match{clauses = []}) = []
    extractMatchClauseNames e@(Match{clauses = (clause:clauses)}) =
      (extractJustVar (mcpattern clause)) ++ (extractMatchClauseNames e{clauses = clauses})
      where
        extractJustVar (MaybeValue{mdt = JustData{e}}) = varAccessName e
        extractJustVar _ = []

    extractName :: [VarDecl] -> [Name]
    extractName [] = []
    extractName (decl:decls) = (varName decl):(extractName decls)

    varAccessName :: Expr -> [Name]
    varAccessName VarAccess{qname} = [qnlocal qname]
    varAccessName _ = []

    isAtomicVar :: Name -> [Name] -> Bool
    isAtomicVar _ [] = True
    isAtomicVar name (decl:decls)
      | matchName name decl = False
      | otherwise = isAtomicVar name decls
      where
        matchName (Name l) (Name r) = l == r

bestowExpression :: Expr -> Expr
bestowExpression = extend bestowTranslate
  where
    bestowTranslate e@(Bestow{emeta, bestowExpr}) = setType (bestowedType bestowTy) $ bestowBox
      where
        bestowTy = getType bestowExpr
        bestowBox = NewWithInit{emeta = emeta,
                                ty = bestowObjectType bestowTy,
                                args = [bestowExpr, VarAccess{emeta, qname = qName "this"}]}
    bestowTranslate e = e

bestowPerformClosure :: Expr -> Expr
bestowPerformClosure = extend bestowSend
    where
      bestowSend e@(MessageSend{emeta, target, name, args, typeArguments})
        | (isBestowedType targetTy) = setType exprTy $ perform
        | otherwise = e
        where
          targetTy = getType target
          resultTy = getResultType $ getType e
          innerTy = getResultType targetTy
          exprTy = if (isStatement e)
                   then unitType
                   else futureType resultTy
          bestowTarget = setType (bestowObjectType innerTy) $ target

          perform = MessageSend{emeta = emeta,
                                target = bestowOwner,
                                name = Name "perform",
                                args = [bestowClosure],
                                typeArguments = [resultTy]}
          bestowClosure = setType (arrowType [] resultTy) $
                          Closure{emeta = emeta,
                                  eparams = [],
                                  mty = Just (getType bestowObject),
                                  body = bestowBody}
          bestowBody = setType resultTy $
                       MethodCall{emeta = emeta,
                                  typeArguments = typeArguments,
                                  target = bestowObject,
                                  name = name,
                                  args = args}
          bestowObject = setType innerTy $
                         FieldAccess{emeta = emeta, target = bestowTarget, name = Name "object"}
          bestowOwner = setType actorObjectType $
                        FieldAccess{emeta = emeta, target = bestowTarget, name = Name "owner"}
      bestowSend e = e
      
-- Note that this is not intended as a serious optimization, but
-- as an example to how an optimization could be made. As soon as
-- there is a serious optimization in place, please remove this
-- function.
constantFolding :: Expr -> Expr
constantFolding = extend foldConst
    where
      foldConst (Binop {emeta = meta, binop = PLUS,
                        loper = IntLiteral{intLit = m},
                        roper = IntLiteral{intLit = n}}) =
          IntLiteral{emeta = meta, intLit = m + n}
      foldConst e = e

-- Desugars a == b when a : Just[t] and b : Just[t] into
-- match (a, b) with
--   case (Just(_fst), Just(_snd)) when _fst == _snd => true
--   case _                                          => false
-- end
tupleMaybeIdComparison = extend tupleMaybeIdComparison'
  where
  tupleMaybeIdComparison' Binop {emeta, binop, loper=MaybeValue{mdt=NothingData}, roper=MaybeValue{mdt=NothingData}} = setType boolType BTrue{emeta}

  tupleMaybeIdComparison' Binop {emeta, binop, loper, roper}
    | (isMaybeType $ getType loper) &&
      (isMaybeType $ getType roper) &&
      (binop == Identifiers.EQ || binop == Identifiers.NEQ) =
      tupleMaybeIdComparison $ maybeNeg Match{emeta, arg=setType tt Tuple{emeta, args}, clauses=[trueClause1, trueClause2, falseClause]}
    where
      tt = tupleType [lmty, rmty]
      args = [loper, roper]
      falseClause = MatchClause{mcpattern=setType tt VarAccess{emeta, qname=qName "_"}
                               ,mchandler=setType boolType BFalse{emeta}
                               ,mcguard=setType boolType BTrue{emeta}}
      trueClause1 = MatchClause{mcpattern=setType tt Tuple{emeta
                                                          ,args=[setType lmty MaybeValue{emeta, mdt=JustData lid}
                                                                ,setType rmty MaybeValue{emeta, mdt=JustData rid}]}
                               ,mchandler
                               ,mcguard=setType boolType Binop{emeta, binop, loper=lid, roper=rid}}
      trueClause2 = MatchClause{mcpattern=setType tt Tuple{emeta
                                                          ,args=[setType lmty MaybeValue{emeta, mdt=NothingData}
                                                                ,setType rmty MaybeValue{emeta, mdt=NothingData}]}
                               ,mchandler
                               ,mcguard=setType boolType BTrue{emeta}}
      lid = setType lty VarAccess{emeta, qname=qName "_fst"}
      rid = setType rty VarAccess{emeta, qname=qName "_snd"}
      leftResult = getResultType $ getType loper
      rightResult = getResultType $ getType roper
      -- When one operand is Nothing, replace its inferred bottom type by the type of the other operand
      lty = if leftResult == bottomType then rightResult else leftResult
      rty = if rightResult == bottomType then leftResult else rightResult
      lmty = maybeType lty
      rmty = maybeType rty
      -- Negate result when != comparison
      maybeNeg n = setType boolType $ if binop == Identifiers.EQ then n else Unary{emeta, uop=NOT, operand=n}
      mchandler = setType boolType BTrue{emeta}
  tupleMaybeIdComparison' b@Binop {emeta, binop, loper, roper}
    | (isTupleType $ getType loper) &&
      (isTupleType $ getType roper) &&
      (binop == Identifiers.EQ || binop == Identifiers.NEQ) =
      tupleMaybeIdComparison $ foldl and (setType boolType BTrue{emeta}) pairwiseCompare
    where
      and loper roper = setType boolType Binop{emeta, binop=Identifiers.AND, loper, roper}
      pairwiseCompare = map mkComparison [0..(tupleLength $ getType loper)-1]
      mkComparison idx = setType boolType Binop {emeta
                                                ,binop
                                                ,loper=setType (lty!!idx) TupleAccess{emeta
                                                                                     ,target=loper
                                                                                     ,compartment=idx}
                                                ,roper=setType (rty!!idx) TupleAccess{emeta
                                                                                     ,target=roper
                                                                                     ,compartment=idx}}
      lty = getArgTypes $ getType loper
      rty = getArgTypes $ getType roper

  tupleMaybeIdComparison' e = e

sugarPrintedStrings = extend sugarPrintedString
    where
      sugarPrintedString e@(Print{args}) =
        e{args = map simplifyStringLit args}
      sugarPrintedString e = e
      simplifyStringLit arg
        | NewWithInit{ty} <- arg
        , isStringObjectType ty
        , Just sugared <- getSugared arg
          = setType stringType sugared
        | otherwise = arg

dropBorrowBlocks = extend dropBorrowBlock
    where
      dropBorrowBlock e@Borrow{emeta, target, name, body} =
        Let{emeta
           ,mutability = Val
           ,decls = [([VarNoType name], target)]
           ,body}
      dropBorrowBlock e = e

forwardGeneral = extend forwardGeneral'
  where
    forwardGeneral' e@(Forward{forwardExpr=MessageSend{}}) = e

    forwardGeneral' e@(Forward{forwardExpr=FutureChain{}}) = e

    forwardGeneral' e@(Forward{emeta, forwardExpr}) =
      Forward{emeta=emeta', forwardExpr=newExpr}
      where
         emeta' = Meta.setType (Meta.getType emeta) (Meta.meta $ Meta.getPos emeta)
         newExpr = FutureChain{emeta=fcmeta, future=forwardExpr, chain=idfun}
         fcmeta = Meta.setType (getType $ forwardExpr) (Meta.meta (Meta.getPos emeta'))
         idfun = Closure {emeta=mclosure
                          ,eparams=[pdecl]
                          ,mty=Just closureType
                          ,body=VarAccess {emeta=Meta.setType paramType mclosure
                                            ,qname=qName "_id_fun_tmp"}}
         closureType = arrowType [paramType] paramType
         mclosure = Meta.metaClosure "" (Meta.setType closureType emeta)
         paramType = getResultType . getType $ forwardExpr
         pdecl = Param {pmeta=Meta.setType paramType (Meta.meta (Meta.getPos emeta))
                        ,pmut =Val
                        ,pname=Name "_id_fun_tmp"
                        ,ptype=paramType}

    forwardGeneral' e = e
