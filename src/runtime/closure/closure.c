#include "closure.h"
#include "mem/pool.h"
#include <assert.h>
#include <dtrace_encore.h>
#include <stdio.h>

pony_type_t closure_type = {
  .id = ID_CLOSURE,
  .size = sizeof(struct closure),
  .trace = closure_trace,
};

void closure_trace(pony_ctx_t *ctx, void *p)
{
  assert(p);
  closure_t *c = (closure_t *) p;
  encore_trace_object(ctx, c->env, c->trace);
  pony_trace(ctx, c->runtimeTypes);
}

closure_t *closure_mk(pony_ctx_t **ctx, closure_fun fn, void *env,
                      pony_trace_fn trace, pony_type_t **runtimeTypes)
{
  closure_t *c = encore_alloc(*ctx, sizeof(closure_t));
  c->call = fn;
  c->env = env;
  c->trace = trace;
  c->runtimeTypes = runtimeTypes;

  ENC_DTRACE2(CLOSURE_CREATE, (uintptr_t)(*ctx), (uintptr_t)c);

  return c;
}

value_t closure_call(pony_ctx_t **ctx, closure_t *closure, value_t args[]){
  return closure->call(ctx, closure->runtimeTypes, args, closure->env);
}

void encore_send_oneway_closure(pony_ctx_t** _ctx, pony_actor_t* _this, pony_type_t** runtimeType, closure_t* _enc__arg_c)
{
  (void) runtimeType;
  pony_gc_send((*_ctx));
  encore_trace_object((*_ctx), _enc__arg_c, closure_trace);
  /* No tracing future for oneway msg */;
  pony_send_done((*_ctx));
  encore_perform_oneway_msg_t *msg = ((encore_perform_oneway_msg_t*) pony_alloc_msg(POOL_INDEX(sizeof(encore_perform_oneway_msg_t)), _ENC__MSG_RUN_CLOSURE));
  msg->c = _enc__arg_c;
  pony_sendv((*_ctx), ((pony_actor_t*) _this), ((pony_msg_t*) msg));
}

future_t* encore_send_future_closure(pony_ctx_t** _ctx, pony_actor_t* _this, pony_type_t** runtimeType, closure_t* _enc__arg_c)
{
  (void) runtimeType;
  future_t* _fut = future_mk(_ctx, ENCORE_PRIMITIVE);
  pony_gc_send((*_ctx));
  /* Not tracing field '_enc__arg_c' */;
  encore_trace_object((*_ctx), _fut, future_trace);
  pony_send_done((*_ctx));  
  encore_perform_future_msg_t* msg = ((encore_perform_future_msg_t*) pony_alloc_msg(POOL_INDEX(sizeof(encore_perform_future_msg_t)), _ENC__MSG_FUT_RUN_CLOSURE));
  msg->c = _enc__arg_c;
  msg->msg->_fut = _fut;
  pony_sendv((*_ctx), ((pony_actor_t*) _this), ((pony_msg_t*) msg));
  return _fut;
}
