#include "header.h"


static void* trait_method_selector(int id)
{
  switch (id)
  {
    case _ENC__MSG_Std_Eq_eq:
    {
      return _enc__method_String_String_eq;
      break;
    }
    default:
    {
      printf("error, got invalid id: %d", id);
    }
  };
  return NULL;
}


void _enc__type_init_String_String(_enc__class_String_String_t* _this, ... )
{
  va_list params;
  va_start(params, _this);
  va_end(params);
}


void _enc__trace_String_String(pony_ctx_t* _ctx_arg, void* p)
{
  pony_ctx_t** _ctx = (&(_ctx_arg));
  _enc__class_String_String_t* _this = p;
  int64_t _enc__field_length = _this->_enc__field_length;
  /* Not tracing field '_enc__field_length' */;
  char* _enc__field_data = _this->_enc__field_data;
  pony_trace((*_ctx), _enc__field_data);
}


_enc__class_String_String_t* _enc__constructor_String_String(pony_ctx_t** _ctx, pony_type_t** runtimeType)
{
  _enc__class_String_String_t* _this = ((_enc__class_String_String_t*) encore_alloc((*_ctx), sizeof(_enc__class_String_String_t)));
  _this->_enc__self_type = (&(_enc__class_String_String_type));
  return _this;
}


option_t* _enc__method_String_String_to_int(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "to_int");
  /* val s = this.data */;
  /* s = this.data */;
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "data");
  char* _fieldacc_0 = (*_this)._enc__field_data;
  char* _s_2 = _fieldacc_0;
  /* val n = 0 */;
  /* n = 0 */;
  int64_t _literal_3 = 0;
  int64_t _n_5 = _literal_3;
  /* val success = false */;
  /* success = false */;
  int64_t _literal_6 = 0/*False*/;
  int64_t _success_8 = _literal_6;
  /* EMBED (unit)
  char *s = #{s};
      char *endptr;
      #{n}= strtol(s,&endptr,0);
      if (s != endptr)
         #{success}= true;
END */;
  ({char *s = _s_2;
      char *endptr;
      _n_5= strtol(s,&endptr,0);
      if (s != endptr)
         _success_8= true;});
  /* if success then
  Just(n)
else
  Nothing
end */;
  option_t* _ite_9;
  if (({ _success_8;}))
  {
    option_t* _option_10 = option_mk(_ctx, JUST, ((encore_arg_t) {.i = _n_5}), ENCORE_PRIMITIVE);
    _ite_9 = ((option_t*) _option_10);
  }
  else
  {
    option_t* _option_11 = (&(DEFAULT_NOTHING));
    _ite_9 = ((option_t*) _option_11);
  };
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "to_int");
  return ((option_t*) _ite_9);
}


array_t* _enc__method_String_String_split(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, _enc__class_String_String_t* _enc__arg_p)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "split");
  /* occurrences = this.occurrences(p) */;
  check_receiver(_this, ".", "this", "occurrences", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 388, column 21)");
  pony_type_t* _tmp_1[] = {};
  int64_t _sync_method_call_0 = _enc__method_String_String_occurrences(_ctx, _this, NULL, _enc__arg_p);
  int64_t _occurrences_3 = _sync_method_call_0;
  /* pattern_len = p.length() */;
  check_receiver(_enc__arg_p, ".", "p", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 389, column 21)");
  pony_type_t* _tmp_5[] = {};
  int64_t _sync_method_call_4 = _enc__method_String_String_length(_ctx, _enc__arg_p, NULL);
  int64_t _pattern_len_7 = _sync_method_call_4;
  array_t* _ite_8;
  if (({int64_t _binop_10 = (({ _occurrences_3;}) == ({int64_t _literal_9 = 0; _literal_9;})); _binop_10;}))
  {
    array_t* _array_11 = array_mk(_ctx, 1, (&(_enc__class_String_String_type)));
    array_set(_array_11, 0, ((encore_arg_t) {.p = _this}));
    _ite_8 = ((array_t*) _array_11);
  }
  else
  {
    array_t* _ite_12;
    if (({int64_t _binop_14 = (({ _pattern_len_7;}) == ({int64_t _literal_13 = 0; _literal_13;})); _binop_14;}))
    {
      /* s_arr = new [String](this.length()) */;
      check_receiver(_this, ".", "this", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 394, column 34)");
      pony_type_t* _tmp_17[] = {};
      int64_t _sync_method_call_16 = _enc__method_String_String_length(_ctx, _this, NULL);
      array_t* _array_15 = array_mk(_ctx, _sync_method_call_16, (&(_enc__class_String_String_type)));
      array_t* _s_arr_19 = _array_15;
      /* for i <- [0..|s_arr| - 1] do
  s_arr(i) = string_from_char(match this.char_at(i) with
                                case Just(c) =>
                                  c
                                end
                              
                              end)
end */;
      /* Range not generated */;
      int64_t _literal_26 = 0;
      int64_t _binop_29 = (({int64_t _size_27 = array_size(_s_arr_19); _size_27;}) - ({int64_t _literal_28 = 1; _literal_28;}));
      int64_t _literal_30 = 1;
      int64_t _literal_31 = 1;
      int64_t _step_24 = (_literal_31 * _literal_30);
      range_assert_step(_step_24);
      int64_t _index_20;
      if ((_step_24 > 0))
      {
        _index_20 = _literal_26;
      }
      else
      {
        _index_20 = _binop_29;
      };
      while (((_index_20 >= _literal_26) && (_index_20 <= _binop_29)))
      {
        int64_t _i_21 = _index_20;
        check_receiver(_this, ".", "this", "char_at", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 396, column 47)");
        pony_type_t* _tmp_34[] = {};
        option_t* _sync_method_call_33 = _enc__method_String_String_char_at(_ctx, _this, NULL, _i_21);
        char _match_32;
        char _c_35;
        if ((({int64_t _optionCheck_37;
               _optionCheck_37 = ((JUST == (*_sync_method_call_33).tag) && ({int64_t _varBinding_38;
                                                                             char _optionVal_36 = (*_sync_method_call_33).val.i;
                                                                             _c_35 = _optionVal_36;
                                                                             _varBinding_38 = 1; _varBinding_38;})); _optionCheck_37;}) && ({int64_t _literal_39 = 1/*True*/; _literal_39;})))
        {
          _match_32 = ((char) ({ _c_35;}));
        }
        else
        {
          fprintf(stderr, "*** Runtime error: No matching clause was found at \"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 396, column 41) ***\n");
          exit(1);
        };
        ENC_DTRACE2(FUNCTION_CALL, (uintptr_t)*_ctx, "String.string_from_char");
        pony_type_t* _tmp_40[] = {};
        _enc__class_String_String_t* _fun_call_41 = _enc__global_fun_Stringstring_from_char(_ctx, NULL, _match_32);
        array_set(_s_arr_19, _i_21, ((encore_arg_t) {.p = _fun_call_41}));
        _index_20 = (_index_20 + _step_24);
      };
      /* s_arr */;
      _ite_12 = ((array_t*) _s_arr_19);
    }
    else
    {
      /* val result = new [String](occurrences + 1) */;
      /* result = new [String](occurrences + 1) */;
      int64_t _binop_44 = (({ _occurrences_3;}) + ({int64_t _literal_43 = 1; _literal_43;}));
      array_t* _array_42 = array_mk(_ctx, _binop_44, (&(_enc__class_String_String_type)));
      array_t* _result_46 = _array_42;
      /* var start = 0 */;
      /* start = 0 */;
      int64_t _literal_47 = 0;
      int64_t _start_49 = _literal_47;
      /* var stop = 0 */;
      /* stop = 0 */;
      int64_t _literal_50 = 0;
      int64_t _stop_52 = _literal_50;
      /* repeat i <- occurrences do
  stop = this.find_from(p, start)
  result(i) = match this.substring(start, stop) with
                case Just(s) =>
                  s
                end
              
              end
  start = stop + pattern_len
end */;
      /* repeat i <- occurrences do
  stop = this.find_from(p, start)
  result(i) = match this.substring(start, stop) with
                case Just(s) =>
                  s
                end
              
              end
  start = stop + pattern_len
end */;
      /* __start__ = repeat i <- occurrences do
  stop = this.find_from(p, start)
  result(i) = match this.substring(start, stop) with
                case Just(s) =>
                  s
                end
              
              end
  start = stop + pattern_len
end */;
      int64_t _literal_53 = 0;
      int64_t ___start___55 = _literal_53;
      /* repeat i <- occurrences do
  stop = this.find_from(p, start)
  result(i) = match this.substring(start, stop) with
                case Just(s) =>
                  s
                end
              
              end
  start = stop + pattern_len
end */;
      /* __stop__ = occurrences */;
      int64_t ___stop___57 = _occurrences_3;
      /* repeat i <- occurrences do
  stop = this.find_from(p, start)
  result(i) = match this.substring(start, stop) with
                case Just(s) =>
                  s
                end
              
              end
  start = stop + pattern_len
end */;
      /* __step__ = repeat i <- occurrences do
  stop = this.find_from(p, start)
  result(i) = match this.substring(start, stop) with
                case Just(s) =>
                  s
                end
              
              end
  start = stop + pattern_len
end */;
      int64_t ___step___59 = ___start___55;
      /* repeat i <- occurrences do
  stop = this.find_from(p, start)
  result(i) = match this.substring(start, stop) with
                case Just(s) =>
                  s
                end
              
              end
  start = stop + pattern_len
end */;
      while (({int64_t _binop_60 = (({ ___step___59;}) < ({ ___stop___57;})); _binop_60;}))
      {
        /* repeat i <- occurrences do
  stop = this.find_from(p, start)
  result(i) = match this.substring(start, stop) with
                case Just(s) =>
                  s
                end
              
              end
  start = stop + pattern_len
end */;
        /* i = repeat i <- occurrences do
  stop = this.find_from(p, start)
  result(i) = match this.substring(start, stop) with
                case Just(s) =>
                  s
                end
              
              end
  start = stop + pattern_len
end */;
        int64_t _i_62 = ___step___59;
        /* repeat i <- occurrences do
  stop = this.find_from(p, start)
  result(i) = match this.substring(start, stop) with
                case Just(s) =>
                  s
                end
              
              end
  start = stop + pattern_len
end */;
        int64_t _binop_64 = (({ ___step___59;}) + ({int64_t _literal_63 = 1; _literal_63;}));
        ___step___59 = _binop_64;
        /* do
  stop = this.find_from(p, start)
  result(i) = match this.substring(start, stop) with
                case Just(s) =>
                  s
                end
              
              end
  start = stop + pattern_len
end */;
        /* stop = this.find_from(p, start) */;
        check_receiver(_this, ".", "this", "find_from", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 407, column 18)");
        pony_type_t* _tmp_66[] = {};
        int64_t _sync_method_call_65 = _enc__method_String_String_find_from(_ctx, _this, NULL, _enc__arg_p, _start_49);
        _stop_52 = _sync_method_call_65;
        /* result(i) = match this.substring(start, stop) with
              case Just(s) =>
                s
              end
            
            end */;
        check_receiver(_this, ".", "this", "substring", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 408, column 29)");
        pony_type_t* _tmp_69[] = {};
        option_t* _sync_method_call_68 = _enc__method_String_String_substring(_ctx, _this, NULL, _start_49, _stop_52);
        _enc__class_String_String_t* _match_67;
        _enc__class_String_String_t* _s_70;
        if ((({int64_t _optionCheck_72;
               _optionCheck_72 = ((JUST == (*_sync_method_call_68).tag) && ({int64_t _varBinding_73;
                                                                             _enc__class_String_String_t* _optionVal_71 = (*_sync_method_call_68).val.p;
                                                                             _s_70 = _optionVal_71;
                                                                             _varBinding_73 = 1; _varBinding_73;})); _optionCheck_72;}) && ({int64_t _literal_74 = 1/*True*/; _literal_74;})))
        {
          _match_67 = ((_enc__class_String_String_t*) ({ _s_70;}));
        }
        else
        {
          fprintf(stderr, "*** Runtime error: No matching clause was found at \"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 408, column 23) ***\n");
          exit(1);
        };
        array_set(_result_46, _i_62, ((encore_arg_t) {.p = _match_67}));
        /* start = stop + pattern_len */;
        int64_t _binop_75 = (({ _stop_52;}) + ({ _pattern_len_7;}));
        _start_49 = _binop_75;
      };
      /* result(occurrences) = match this.substring(start, this.length()) with
                        case Just(s) =>
                          s
                        end
                      
                      end */;
      check_receiver(_this, ".", "this", "substring", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 413, column 37)");
      check_receiver(_this, ".", "this", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 413, column 59)");
      pony_type_t* _tmp_79[] = {};
      int64_t _sync_method_call_78 = _enc__method_String_String_length(_ctx, _this, NULL);
      pony_type_t* _tmp_80[] = {};
      option_t* _sync_method_call_77 = _enc__method_String_String_substring(_ctx, _this, NULL, _start_49, _sync_method_call_78);
      _enc__class_String_String_t* _match_76;
      _enc__class_String_String_t* _s_81;
      if ((({int64_t _optionCheck_83;
             _optionCheck_83 = ((JUST == (*_sync_method_call_77).tag) && ({int64_t _varBinding_84;
                                                                           _enc__class_String_String_t* _optionVal_82 = (*_sync_method_call_77).val.p;
                                                                           _s_81 = _optionVal_82;
                                                                           _varBinding_84 = 1; _varBinding_84;})); _optionCheck_83;}) && ({int64_t _literal_85 = 1/*True*/; _literal_85;})))
      {
        _match_76 = ((_enc__class_String_String_t*) ({ _s_81;}));
      }
      else
      {
        fprintf(stderr, "*** Runtime error: No matching clause was found at \"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 413, column 31) ***\n");
        exit(1);
      };
      array_set(_result_46, _occurrences_3, ((encore_arg_t) {.p = _match_76}));
      /* result */;
      _ite_12 = ((array_t*) _result_46);
    };
    _ite_8 = ((array_t*) _ite_12);
  };
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "split");
  return ((array_t*) _ite_8);
}


array_t* _enc__method_String_String_to_array(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "to_array");
  /* len = this.length() */;
  check_receiver(_this, ".", "this", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 372, column 13)");
  pony_type_t* _tmp_1[] = {};
  int64_t _sync_method_call_0 = _enc__method_String_String_length(_ctx, _this, NULL);
  int64_t _len_3 = _sync_method_call_0;
  /* arr = new [char](len) */;
  array_t* _array_4 = array_mk(_ctx, _len_3, ENCORE_PRIMITIVE);
  array_t* _arr_6 = _array_4;
  /* for i <- [0..len - 1] do
  arr(i) = match this.char_at(i) with
             case Just(c) =>
               c
             end
           
           end
end */;
  /* Range not generated */;
  int64_t _literal_13 = 0;
  int64_t _binop_15 = (({ _len_3;}) - ({int64_t _literal_14 = 1; _literal_14;}));
  int64_t _literal_16 = 1;
  int64_t _literal_17 = 1;
  int64_t _step_11 = (_literal_17 * _literal_16);
  range_assert_step(_step_11);
  int64_t _index_7;
  if ((_step_11 > 0))
  {
    _index_7 = _literal_13;
  }
  else
  {
    _index_7 = _binop_15;
  };
  while (((_index_7 >= _literal_13) && (_index_7 <= _binop_15)))
  {
    int64_t _i_8 = _index_7;
    check_receiver(_this, ".", "this", "char_at", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 376, column 24)");
    pony_type_t* _tmp_20[] = {};
    option_t* _sync_method_call_19 = _enc__method_String_String_char_at(_ctx, _this, NULL, _i_8);
    char _match_18;
    char _c_21;
    if ((({int64_t _optionCheck_23;
           _optionCheck_23 = ((JUST == (*_sync_method_call_19).tag) && ({int64_t _varBinding_24;
                                                                         char _optionVal_22 = (*_sync_method_call_19).val.i;
                                                                         _c_21 = _optionVal_22;
                                                                         _varBinding_24 = 1; _varBinding_24;})); _optionCheck_23;}) && ({int64_t _literal_25 = 1/*True*/; _literal_25;})))
    {
      _match_18 = ((char) ({ _c_21;}));
    }
    else
    {
      fprintf(stderr, "*** Runtime error: No matching clause was found at \"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 376, column 18) ***\n");
      exit(1);
    };
    array_set(_arr_6, _i_8, ((encore_arg_t) {.i = _match_18}));
    _index_7 = (_index_7 + _step_11);
  };
  /* arr */;
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "to_array");
  return ((array_t*) _arr_6);
}


option_t* _enc__method_String_String_char_at(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, int64_t _enc__arg_i)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "char_at");
  /* s = this.data */;
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "data");
  char* _fieldacc_0 = (*_this)._enc__field_data;
  char* _s_2 = _fieldacc_0;
  /* len = this.length() */;
  check_receiver(_this, ".", "this", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 360, column 13)");
  pony_type_t* _tmp_4[] = {};
  int64_t _sync_method_call_3 = _enc__method_String_String_length(_ctx, _this, NULL);
  int64_t _len_6 = _sync_method_call_3;
  option_t* _ite_7;
  if (({int64_t _binop_11 = (({int64_t _binop_9 = (({ _enc__arg_i;}) >= ({int64_t _literal_8 = 0; _literal_8;})); _binop_9;}) && ({int64_t _binop_10 = (({ _enc__arg_i;}) < ({ _len_6;})); _binop_10;})); _binop_11;}))
  {
    char _embed_12 = ({_s_2[_enc__arg_i];});
    option_t* _option_13 = option_mk(_ctx, JUST, ((encore_arg_t) {.i = _embed_12}), ENCORE_PRIMITIVE);
    _ite_7 = ((option_t*) _option_13);
  }
  else
  {
    option_t* _option_14 = (&(DEFAULT_NOTHING));
    _ite_7 = ((option_t*) _option_14);
  };
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "char_at");
  return ((option_t*) _ite_7);
}


_enc__class_String_String_t* _enc__method_String_String_format(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, array_t* _enc__arg_b)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "format");
  _enc__class_String_String_t* _new_0 = _enc__constructor_String_String(_ctx, NULL);
  char* _embed_1 = ({"To be implemented";});
  pony_type_t* _tmp_2[] = {};
  _enc__type_init_String_String(_new_0);
  _enc__method_String_String_init(_ctx, _new_0, NULL, _embed_1);
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "format");
  return ((_enc__class_String_String_t*) _new_0);
}


_enc__class_String_String_t* _enc__method_String_String_delete(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, _enc__class_String_String_t* _enc__arg_s)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "delete");
  /* to_len = this.length() */;
  check_receiver(_this, ".", "this", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 321, column 16)");
  pony_type_t* _tmp_1[] = {};
  int64_t _sync_method_call_0 = _enc__method_String_String_length(_ctx, _this, NULL);
  int64_t _to_len_3 = _sync_method_call_0;
  /* s_len = s.length() */;
  check_receiver(_enc__arg_s, ".", "s", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 322, column 15)");
  pony_type_t* _tmp_5[] = {};
  int64_t _sync_method_call_4 = _enc__method_String_String_length(_ctx, _enc__arg_s, NULL);
  int64_t _s_len_7 = _sync_method_call_4;
  _enc__class_String_String_t* _new_8 = _enc__constructor_String_String(_ctx, NULL);
  char* _embed_9 = ({const int STACK_ALLOC_MAX = 16536;
                   char *from = _this->_enc__field_data;
                   char *pattern  = _enc__arg_s->_enc__field_data;
                   char *tmp = NULL;

                   if (_to_len_3> STACK_ALLOC_MAX) {
                     tmp = encore_alloc(*_ctx, _to_len_3+ 1);
                   } else {
                     tmp = alloca(_to_len_3);
                   }

                   int copied = 0;
                   int skipped = 0;
                   for (char *next = strstr(from, pattern); next; next = strstr(next+_s_len_7, pattern))
                     {
                       strncpy(tmp + copied, from + copied + skipped, next - from - copied - skipped);
                       copied  = next - from - skipped;
                       skipped += _s_len_7;
                     }
                   strcpy(tmp + copied, from + copied + skipped);

                   char *result = encore_alloc(*_ctx, copied + 1);
                   strcpy(result, tmp);
                   result;});
  pony_type_t* _tmp_10[] = {};
  _enc__type_init_String_String(_new_8);
  _enc__method_String_String_init(_ctx, _new_8, NULL, _embed_9);
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "delete");
  return ((_enc__class_String_String_t*) _new_8);
}


int64_t _enc__method_String_String_find_from(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, _enc__class_String_String_t* _enc__arg_a, int64_t _enc__arg_b)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "find_from");
  int64_t _ite_0;
  if (({int64_t _binop_6 = (({int64_t _binop_2 = (({ _enc__arg_b;}) < ({int64_t _literal_1 = 0; _literal_1;})); _binop_2;}) || ({int64_t _binop_5 = (({ _enc__arg_b;}) >= ({check_receiver(_this, ".", "this", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 306, column 25)");
                                                                                                                                                                            pony_type_t* _tmp_4[] = {};
                                                                                                                                                                            int64_t _sync_method_call_3 = _enc__method_String_String_length(_ctx, _this, NULL); _sync_method_call_3;})); _binop_5;})); _binop_6;}))
  {
    int64_t _literal_7 = 1;
    int64_t _unary_8 = (- _literal_7);
    _ite_0 = ((int64_t) _unary_8);
  }
  else
  {
    int64_t _embed_9 = ({char *str = _this->_enc__field_data;
        char *pattern = _enc__arg_a->_enc__field_data;
        char *loc = strstr(str + _enc__arg_b, pattern);
        loc ? loc - str : -1;});
    _ite_0 = ((int64_t) _embed_9);
  };
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "find_from");
  return ((int64_t) _ite_0);
}


int64_t _enc__method_String_String_find(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, _enc__class_String_String_t* _enc__arg_a)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "find");
  check_receiver(_this, ".", "this", "find_from", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 300, column 5)");
  int64_t _literal_1 = 0;
  pony_type_t* _tmp_2[] = {};
  int64_t _sync_method_call_0 = _enc__method_String_String_find_from(_ctx, _this, NULL, _enc__arg_a, _literal_1);
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "find");
  return ((int64_t) _sync_method_call_0);
}


_enc__class_String_String_t* _enc__method_String_String_replace(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, _enc__class_String_String_t* _enc__arg_a, _enc__class_String_String_t* _enc__arg_b)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "replace");
  check_receiver(_enc__arg_b, ".", "b", "join", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 294, column 5)");
  check_receiver(_this, ".", "this", "split", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 294, column 12)");
  pony_type_t* _tmp_2[] = {};
  array_t* _sync_method_call_1 = _enc__method_String_String_split(_ctx, _this, NULL, _enc__arg_a);
  pony_type_t* _tmp_3[] = {};
  _enc__class_String_String_t* _sync_method_call_0 = _enc__method_String_String_join(_ctx, _enc__arg_b, NULL, _sync_method_call_1);
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "replace");
  return ((_enc__class_String_String_t*) _sync_method_call_0);
}


_enc__class_String_String_t* _enc__method_String_String_trim(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "trim");
  /* len = this.length() */;
  check_receiver(_this, ".", "this", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 279, column 13)");
  pony_type_t* _tmp_1[] = {};
  int64_t _sync_method_call_0 = _enc__method_String_String_length(_ctx, _this, NULL);
  int64_t _len_3 = _sync_method_call_0;
  /* str = this.data */;
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "data");
  char* _fieldacc_4 = (*_this)._enc__field_data;
  char* _str_6 = _fieldacc_4;
  /* start_index = EMBED (int)
  int s = 0;        while (#{str}[s] && isspace(#{str}[s])) ++s; s;
END */;
  int64_t _embed_7 = ({int s = 0;        while (_str_6[s] && isspace(_str_6[s])) ++s; s;});
  int64_t _start_index_9 = _embed_7;
  /* stop_index = EMBED (int)
  int s = #{len}-1; while (#{str}[s] && isspace(#{str}[s])) --s; s;
END */;
  int64_t _embed_10 = ({int s = _len_3-1; while (_str_6[s] && isspace(_str_6[s])) --s; s;});
  int64_t _stop_index_12 = _embed_10;
  check_receiver(_this, ".", "this", "substring", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 284, column 13)");
  int64_t _binop_16 = (({ _stop_index_12;}) + ({int64_t _literal_15 = 1; _literal_15;}));
  pony_type_t* _tmp_17[] = {};
  option_t* _sync_method_call_14 = _enc__method_String_String_substring(_ctx, _this, NULL, _start_index_9, _binop_16);
  _enc__class_String_String_t* _match_13;
  _enc__class_String_String_t* _s_18;
  if ((({int64_t _optionCheck_20;
         _optionCheck_20 = ((JUST == (*_sync_method_call_14).tag) && ({int64_t _varBinding_21;
                                                                       _enc__class_String_String_t* _optionVal_19 = (*_sync_method_call_14).val.p;
                                                                       _s_18 = _optionVal_19;
                                                                       _varBinding_21 = 1; _varBinding_21;})); _optionCheck_20;}) && ({int64_t _literal_22 = 1/*True*/; _literal_22;})))
  {
    _match_13 = ((_enc__class_String_String_t*) ({ _s_18;}));
  }
  else
  {
    fprintf(stderr, "*** Runtime error: No matching clause was found at \"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 284, column 7) ***\n");
    exit(1);
  };
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "trim");
  return ((_enc__class_String_String_t*) _match_13);
}


char* _enc__method_String_String_getData(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "getData");
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "data");
  char* _fieldacc_0 = (*_this)._enc__field_data;
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "getData");
  return ((char*) _fieldacc_0);
}


_enc__class_String_String_t* _enc__method_String_String_join(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, array_t* _enc__arg_strings)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "join");
  _enc__class_String_String_t* _ite_0;
  if (({int64_t _binop_3 = (({int64_t _size_1 = array_size(_enc__arg_strings); _size_1;}) == ({int64_t _literal_2 = 0; _literal_2;})); _binop_3;}))
  {
    _enc__class_String_String_t* _new_4 = _enc__constructor_String_String(_ctx, NULL);
    char* _embed_5 = ({"";});
    pony_type_t* _tmp_6[] = {};
    _enc__type_init_String_String(_new_4);
    _enc__method_String_String_init(_ctx, _new_4, NULL, _embed_5);
    _ite_0 = ((_enc__class_String_String_t*) _new_4);
  }
  else
  {
    /* var result = strings(0) */;
    /* result = strings(0) */;
    int64_t _literal_7 = 0;
    _enc__class_String_String_t* _access_8 = array_get(_enc__arg_strings, _literal_7).p;
    _enc__class_String_String_t* _result_10 = _access_8;
    /* for i <- [1..|strings| - 1] do
  result = result.concatenate(this).concatenate(strings(i))
end */;
    /* Range not generated */;
    int64_t _literal_17 = 1;
    int64_t _binop_20 = (({int64_t _size_18 = array_size(_enc__arg_strings); _size_18;}) - ({int64_t _literal_19 = 1; _literal_19;}));
    int64_t _literal_21 = 1;
    int64_t _literal_22 = 1;
    int64_t _step_15 = (_literal_22 * _literal_21);
    range_assert_step(_step_15);
    int64_t _index_11;
    if ((_step_15 > 0))
    {
      _index_11 = _literal_17;
    }
    else
    {
      _index_11 = _binop_20;
    };
    while (((_index_11 >= _literal_17) && (_index_11 <= _binop_20)))
    {
      int64_t _i_12 = _index_11;
      check_receiver(_result_10, ".", "result", "concatenate", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 265, column 18)");
      pony_type_t* _tmp_25[] = {};
      _enc__class_String_String_t* _sync_method_call_24 = _enc__method_String_String_concatenate(_ctx, _result_10, NULL, _this);
      check_receiver(_sync_method_call_24, ".", "result.concatenate(this)", "concatenate", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 265, column 18)");
      _enc__class_String_String_t* _access_26 = array_get(_enc__arg_strings, _i_12).p;
      pony_type_t* _tmp_27[] = {};
      _enc__class_String_String_t* _sync_method_call_23 = _enc__method_String_String_concatenate(_ctx, _sync_method_call_24, NULL, _access_26);
      _result_10 = _sync_method_call_23;
      _index_11 = (_index_11 + _step_15);
    };
    /* result */;
    _ite_0 = ((_enc__class_String_String_t*) _result_10);
  };
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "join");
  return ((_enc__class_String_String_t*) _ite_0);
}


int64_t _enc__method_String_String_occurrences(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, _enc__class_String_String_t* _enc__arg_s)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "occurrences");
  int64_t _ite_0;
  if (({int64_t _binop_4 = (({check_receiver(_enc__arg_s, ".", "s", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 241, column 8)");
                              pony_type_t* _tmp_2[] = {};
                              int64_t _sync_method_call_1 = _enc__method_String_String_length(_ctx, _enc__arg_s, NULL); _sync_method_call_1;}) == ({int64_t _literal_3 = 0; _literal_3;})); _binop_4;}))
  {
    check_receiver(_this, ".", "this", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 242, column 7)");
    pony_type_t* _tmp_6[] = {};
    int64_t _sync_method_call_5 = _enc__method_String_String_length(_ctx, _this, NULL);
    _ite_0 = ((int64_t) _sync_method_call_5);
  }
  else
  {
    /* var counter = 0 */;
    /* counter = 0 */;
    int64_t _literal_7 = 0;
    int64_t _counter_9 = _literal_7;
    /* var i = this.find(s) */;
    /* i = this.find(s) */;
    check_receiver(_this, ".", "this", "find", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 245, column 21)");
    pony_type_t* _tmp_11[] = {};
    int64_t _sync_method_call_10 = _enc__method_String_String_find(_ctx, _this, NULL, _enc__arg_s);
    int64_t _i_13 = _sync_method_call_10;
    /* val s_len = s.length() */;
    /* s_len = s.length() */;
    check_receiver(_enc__arg_s, ".", "s", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 246, column 21)");
    pony_type_t* _tmp_15[] = {};
    int64_t _sync_method_call_14 = _enc__method_String_String_length(_ctx, _enc__arg_s, NULL);
    int64_t _s_len_17 = _sync_method_call_14;
    /* while i >= 0 do
  counter = counter + 1
  i = this.find_from(s, i + s_len)
end */;
    while (({int64_t _binop_19 = (({ _i_13;}) >= ({int64_t _literal_18 = 0; _literal_18;})); _binop_19;}))
    {
      /* counter = counter + 1 */;
      int64_t _binop_21 = (({ _counter_9;}) + ({int64_t _literal_20 = 1; _literal_20;}));
      _counter_9 = _binop_21;
      /* i = this.find_from(s, i + s_len) */;
      check_receiver(_this, ".", "this", "find_from", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 249, column 13)");
      int64_t _binop_23 = (({ _i_13;}) + ({ _s_len_17;}));
      pony_type_t* _tmp_24[] = {};
      int64_t _sync_method_call_22 = _enc__method_String_String_find_from(_ctx, _this, NULL, _enc__arg_s, _binop_23);
      _i_13 = _sync_method_call_22;
    };
    /* counter */;
    _ite_0 = ((int64_t) _counter_9);
  };
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "occurrences");
  return ((int64_t) _ite_0);
}


int64_t _enc__method_String_String_eq(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, _enc__class_String_String_t* _enc__arg_s)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "eq");
  int64_t _binop_3 = (({check_receiver(_this, ".", "this", "compare", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 236, column 5)");
                        pony_type_t* _tmp_1[] = {};
                        int64_t _sync_method_call_0 = _enc__method_String_String_compare(_ctx, _this, NULL, _enc__arg_s); _sync_method_call_0;}) == ({int64_t _literal_2 = 0; _literal_2;}));
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "eq");
  return ((int64_t) _binop_3);
}


int64_t _enc__method_String_String_equals(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, _enc__class_String_String_t* _enc__arg_s)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "equals");
  check_receiver(_this, ".", "this", "eq", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 231, column 5)");
  pony_type_t* _tmp_1[] = {};
  int64_t _sync_method_call_0 = _enc__method_String_String_eq(_ctx, _this, NULL, _enc__arg_s);
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "equals");
  return ((int64_t) _sync_method_call_0);
}


option_t* _enc__method_String_String_substring(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, int64_t _enc__arg_from, int64_t _enc__arg_to)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "substring");
  option_t* _ite_0;
  if (({int64_t _binop_1 = (({ _enc__arg_to;}) < ({ _enc__arg_from;})); _binop_1;}))
  {
    _enc__class_String_String_t* _new_2 = _enc__constructor_String_String(_ctx, NULL);
    char* _embed_3 = ({"";});
    pony_type_t* _tmp_4[] = {};
    _enc__type_init_String_String(_new_2);
    _enc__method_String_String_init(_ctx, _new_2, NULL, _embed_3);
    option_t* _option_5 = option_mk(_ctx, JUST, ((encore_arg_t) {.p = _new_2}), (&(_enc__class_String_String_type)));
    _ite_0 = ((option_t*) _option_5);
  }
  else
  {
    /* t_len = this.length() */;
    check_receiver(_this, ".", "this", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 210, column 17)");
    pony_type_t* _tmp_7[] = {};
    int64_t _sync_method_call_6 = _enc__method_String_String_length(_ctx, _this, NULL);
    int64_t _t_len_9 = _sync_method_call_6;
    /* data = this.data */;
    ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "data");
    char* _fieldacc_10 = (*_this)._enc__field_data;
    char* _data_12 = _fieldacc_10;
    option_t* _ite_13;
    if (({int64_t _binop_15 = (({ _enc__arg_from;}) >= ({int64_t _literal_14 = 0; _literal_14;})); _binop_15;}))
    {
      _enc__class_String_String_t* _new_16 = _enc__constructor_String_String(_ctx, NULL);
      char* _embed_17 = ({int siz = _enc__arg_to- _enc__arg_from;
                            siz = siz < _t_len_9? siz : _t_len_9;
                            char *str = encore_alloc(*_ctx, siz + 1);
                            strncpy(str, ((char *)_data_12)+_enc__arg_from, siz);
                            str[siz] = '\0';
                            str;});
      pony_type_t* _tmp_18[] = {};
      _enc__type_init_String_String(_new_16);
      _enc__method_String_String_init(_ctx, _new_16, NULL, _embed_17);
      option_t* _option_19 = option_mk(_ctx, JUST, ((encore_arg_t) {.p = _new_16}), (&(_enc__class_String_String_type)));
      _ite_13 = ((option_t*) _option_19);
    }
    else
    {
      option_t* _option_20 = (&(DEFAULT_NOTHING));
      _ite_13 = ((option_t*) _option_20);
    };
    _ite_0 = ((option_t*) _ite_13);
  };
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "substring");
  return ((option_t*) _ite_0);
}


int64_t _enc__method_String_String_size(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "size");
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "length");
  int64_t _fieldacc_0 = (*_this)._enc__field_length;
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "size");
  return ((int64_t) _fieldacc_0);
}


int64_t _enc__method_String_String_length(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "length");
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "length");
  int64_t _fieldacc_0 = (*_this)._enc__field_length;
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "length");
  return ((int64_t) _fieldacc_0);
}


_enc__class_String_String_t* _enc__method_String_String_to_lower(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "to_lower");
  /* t_len = this.length() */;
  check_receiver(_this, ".", "this", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 178, column 15)");
  pony_type_t* _tmp_1[] = {};
  int64_t _sync_method_call_0 = _enc__method_String_String_length(_ctx, _this, NULL);
  int64_t _t_len_3 = _sync_method_call_0;
  /* data = this.data */;
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "data");
  char* _fieldacc_4 = (*_this)._enc__field_data;
  char* _data_6 = _fieldacc_4;
  _enc__class_String_String_t* _new_7 = _enc__constructor_String_String(_ctx, NULL);
  char* _embed_8 = ({char *str = encore_alloc(*_ctx, _t_len_3+ 1);
                   for (int i = 0; i < _t_len_3; ++i)
                     {
                       str[i] = tolower(((char *)_data_6)[i]);
                     }
                   str[_t_len_3] = '\0';
                   str;});
  pony_type_t* _tmp_9[] = {};
  _enc__type_init_String_String(_new_7);
  _enc__method_String_String_init(_ctx, _new_7, NULL, _embed_8);
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "to_lower");
  return ((_enc__class_String_String_t*) _new_7);
}


_enc__class_String_String_t* _enc__method_String_String_to_upper(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "to_upper");
  /* t_len = this.length() */;
  check_receiver(_this, ".", "this", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 160, column 15)");
  pony_type_t* _tmp_1[] = {};
  int64_t _sync_method_call_0 = _enc__method_String_String_length(_ctx, _this, NULL);
  int64_t _t_len_3 = _sync_method_call_0;
  /* data = this.data */;
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "data");
  char* _fieldacc_4 = (*_this)._enc__field_data;
  char* _data_6 = _fieldacc_4;
  _enc__class_String_String_t* _new_7 = _enc__constructor_String_String(_ctx, NULL);
  char* _embed_8 = ({char *str = encore_alloc(*_ctx, _t_len_3+ 1);
                   for (int i = 0; i < _t_len_3; ++i)
                     {
                       str[i] = toupper(((char *)_data_6)[i]);
                     }
                   str[_t_len_3] = '\0';
                   str;});
  pony_type_t* _tmp_9[] = {};
  _enc__type_init_String_String(_new_7);
  _enc__method_String_String_init(_ctx, _new_7, NULL, _embed_8);
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "to_upper");
  return ((_enc__class_String_String_t*) _new_7);
}


int64_t _enc__method_String_String_compare_ignore_case(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, _enc__class_String_String_t* _enc__arg_b)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "compare_ignore_case");
  check_receiver(_this, ".", "this", "to_upper", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 154, column 5)");
  pony_type_t* _tmp_2[] = {};
  _enc__class_String_String_t* _sync_method_call_1 = _enc__method_String_String_to_upper(_ctx, _this, NULL);
  check_receiver(_sync_method_call_1, ".", "this.to_upper()", "compare", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 154, column 5)");
  check_receiver(_enc__arg_b, ".", "b", "to_upper", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 154, column 29)");
  pony_type_t* _tmp_4[] = {};
  _enc__class_String_String_t* _sync_method_call_3 = _enc__method_String_String_to_upper(_ctx, _enc__arg_b, NULL);
  pony_type_t* _tmp_5[] = {};
  int64_t _sync_method_call_0 = _enc__method_String_String_compare(_ctx, _sync_method_call_1, NULL, _sync_method_call_3);
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "compare_ignore_case");
  return ((int64_t) _sync_method_call_0);
}


int64_t _enc__method_String_String_compare(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, _enc__class_String_String_t* _enc__arg_b)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "compare");
  /* t_len = this.length */;
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "length");
  int64_t _fieldacc_0 = (*_this)._enc__field_length;
  int64_t _t_len_2 = _fieldacc_0;
  /* b_len = b.length */;
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_enc__arg_b, "length");
  int64_t _fieldacc_3 = (*_enc__arg_b)._enc__field_length;
  int64_t _b_len_5 = _fieldacc_3;
  /* len = if t_len > b_len then
  t_len
else
  b_len
end */;
  int64_t _ite_6;
  if (({int64_t _binop_7 = (({ _t_len_2;}) > ({ _b_len_5;})); _binop_7;}))
  {
    _ite_6 = ((int64_t) _t_len_2);
  }
  else
  {
    _ite_6 = ((int64_t) _b_len_5);
  };
  int64_t _len_9 = _ite_6;
  /* t_data = this.data */;
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "data");
  char* _fieldacc_10 = (*_this)._enc__field_data;
  char* _t_data_12 = _fieldacc_10;
  /* b_data = b.data */;
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_enc__arg_b, "data");
  char* _fieldacc_13 = (*_enc__arg_b)._enc__field_data;
  char* _b_data_15 = _fieldacc_13;
  int64_t _embed_16 = ({strncmp((char *)_t_data_12, (char *)_b_data_15, _len_9);});
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "compare");
  return ((int64_t) _embed_16);
}


int64_t _enc__method_String_String_contains_ignore_case(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, _enc__class_String_String_t* _enc__arg_b)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "contains_ignore_case");
  check_receiver(_this, ".", "this", "to_upper", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 136, column 5)");
  pony_type_t* _tmp_2[] = {};
  _enc__class_String_String_t* _sync_method_call_1 = _enc__method_String_String_to_upper(_ctx, _this, NULL);
  check_receiver(_sync_method_call_1, ".", "this.to_upper()", "contains", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 136, column 5)");
  check_receiver(_enc__arg_b, ".", "b", "to_upper", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 136, column 30)");
  pony_type_t* _tmp_4[] = {};
  _enc__class_String_String_t* _sync_method_call_3 = _enc__method_String_String_to_upper(_ctx, _enc__arg_b, NULL);
  pony_type_t* _tmp_5[] = {};
  int64_t _sync_method_call_0 = _enc__method_String_String_contains(_ctx, _sync_method_call_1, NULL, _sync_method_call_3);
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "contains_ignore_case");
  return ((int64_t) _sync_method_call_0);
}


int64_t _enc__method_String_String_contains(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, _enc__class_String_String_t* _enc__arg_b)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "contains");
  /* data = this.data */;
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "data");
  char* _fieldacc_0 = (*_this)._enc__field_data;
  char* _data_2 = _fieldacc_0;
  /* b_data = b.data */;
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_enc__arg_b, "data");
  char* _fieldacc_3 = (*_enc__arg_b)._enc__field_data;
  char* _b_data_5 = _fieldacc_3;
  int64_t _embed_6 = ({strstr((char *)_data_2, (char *)_b_data_5) != NULL;});
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "contains");
  return ((int64_t) _embed_6);
}


_enc__class_String_String_t* _enc__method_String_String_copy(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "copy");
  /* t_len = this.length() */;
  check_receiver(_this, ".", "this", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 112, column 15)");
  pony_type_t* _tmp_1[] = {};
  int64_t _sync_method_call_0 = _enc__method_String_String_length(_ctx, _this, NULL);
  int64_t _t_len_3 = _sync_method_call_0;
  /* data = this.data */;
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "data");
  char* _fieldacc_4 = (*_this)._enc__field_data;
  char* _data_6 = _fieldacc_4;
  _enc__class_String_String_t* _new_7 = _enc__constructor_String_String(_ctx, NULL);
  char* _embed_8 = ({char *str = encore_alloc(*_ctx, _t_len_3+ 1);
                   strncpy(str, (char *)_data_6, _t_len_3+ 1);
                   str;});
  pony_type_t* _tmp_9[] = {};
  _enc__type_init_String_String(_new_7);
  _enc__method_String_String_init(_ctx, _new_7, NULL, _embed_8);
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "copy");
  return ((_enc__class_String_String_t*) _new_7);
}


_enc__class_String_String_t* _enc__method_String_String_concatenate(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, _enc__class_String_String_t* _enc__arg_b)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "concatenate");
  /* t_len = this.length() */;
  check_receiver(_this, ".", "this", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 95, column 16)");
  pony_type_t* _tmp_1[] = {};
  int64_t _sync_method_call_0 = _enc__method_String_String_length(_ctx, _this, NULL);
  int64_t _t_len_3 = _sync_method_call_0;
  /* b_len = b.length() */;
  check_receiver(_enc__arg_b, ".", "b", "length", "\"/home/stw/r/group/all-bachelor-students/joel.wallin/encore/modules/standard/String.enc\" (line 96, column 16)");
  pony_type_t* _tmp_5[] = {};
  int64_t _sync_method_call_4 = _enc__method_String_String_length(_ctx, _enc__arg_b, NULL);
  int64_t _b_len_7 = _sync_method_call_4;
  /* t_data = this.data */;
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "data");
  char* _fieldacc_8 = (*_this)._enc__field_data;
  char* _t_data_10 = _fieldacc_8;
  /* b_data = b.data */;
  ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_enc__arg_b, "data");
  char* _fieldacc_11 = (*_enc__arg_b)._enc__field_data;
  char* _b_data_13 = _fieldacc_11;
  _enc__class_String_String_t* _new_14 = _enc__constructor_String_String(_ctx, NULL);
  char* _embed_15 = ({void *str = encore_alloc(*_ctx, _t_len_3+ _b_len_7+ 1);
                   strncpy(str, (char *)_t_data_10, _t_len_3);
                   strncat(str, (char *)_b_data_13, _b_len_7);
                   str;});
  pony_type_t* _tmp_16[] = {};
  _enc__type_init_String_String(_new_14);
  _enc__method_String_String_init(_ctx, _new_14, NULL, _embed_15);
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "concatenate");
  return ((_enc__class_String_String_t*) _new_14);
}


int64_t _enc__method_String_String_is_empty(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "is_empty");
  int64_t _binop_2 = (({ENC_DTRACE3(FIELD_ACCESS, (uintptr_t)*_ctx, (uintptr_t)_this, "length");
                        int64_t _fieldacc_0 = (*_this)._enc__field_length; _fieldacc_0;}) == ({int64_t _literal_1 = 0; _literal_1;}));
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "is_empty");
  return ((int64_t) _binop_2);
}


void* _enc__method_String_String_init(pony_ctx_t** _ctx, _enc__class_String_String_t* _this, pony_type_t** runtimeType, char* _enc__arg_s)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "init");
  /* this.data = s */;
  (*({ENC_DTRACE3(FIELD_WRITE, (uintptr_t)*_ctx, (uintptr_t)_this, "data"); _this;}))._enc__field_data = _enc__arg_s;
  /* this.length = EMBED (int)
                ; strlen(#{s});
              END */;
  int64_t _embed_0 = ({; strlen(_enc__arg_s);});
  (*({ENC_DTRACE3(FIELD_WRITE, (uintptr_t)*_ctx, (uintptr_t)_this, "length"); _this;}))._enc__field_length = _embed_0;
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "init");
  return UNIT;
}


pony_type_t _enc__class_String_String_type = {.id=_ENC__ID_String_String, .size=sizeof(_enc__class_String_String_t), .trace=_enc__trace_String_String, .vtable=trait_method_selector};
