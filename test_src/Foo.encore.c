#include "header.h"

extern void *q;
extern void pony_sendv2(pony_ctx_t* ctx, pony_actor_t* to, pony_msg_t* m, void *q);

static void* trait_method_selector(int id)
{
  switch (id)
  {
    default:
    {
      printf("error, got invalid id: %d", id);
    }
  };
  return NULL;
}


struct _enc__class__test_Foo_t
{
  encore_actor_t _enc__actor;
  _enc__class__test_Main_t* _enc__field_m;
};


void _enc__type_init__test_Foo(_enc__class__test_Foo_t* _this, ... )
{
  va_list params;
  va_start(params, _this);
  va_end(params);
}


void _enc__trace__test_Foo(pony_ctx_t* _ctx_arg, void* p)
{
  pony_ctx_t** _ctx = (&(_ctx_arg));
  _enc__class__test_Foo_t* _this = p;
  _enc__class__test_Main_t* _enc__field_m = _this->_enc__field_m;
  encore_trace_actor((*_ctx), ((pony_actor_t*) _enc__field_m));
}


_enc__class__test_Foo_t* _enc__constructor__test_Foo(pony_ctx_t** _ctx, pony_type_t** runtimeType)
{
  _enc__class__test_Foo_t* _this = ((_enc__class__test_Foo_t*) encore_create((*_ctx), (&(_enc__class__test_Foo_type))));
  return _this;
}


void* _enc__method__test_Foo_await(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType, future_t* _enc__arg_f)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "await");
  pony_type_t* _enc__type__t = (runtimeType[0]);
  future_await(_ctx, _enc__arg_f);
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "await");
  return UNIT;
}


future_t* _enc__method__test_Foo_await_future(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType, future_t* _enc__arg_f)
{
  pony_type_t* _enc__type__t = (runtimeType[0]);
  future_t* _fut = future_mk(_ctx, ENCORE_PRIMITIVE);
  pony_gc_send((*_ctx));
  encore_trace_object((*_ctx), _enc__arg_f, future_trace);
  encore_trace_object((*_ctx), _fut, future_trace);
  pony_send_done((*_ctx));
  _enc__fut_msg__test_Foo_await_t* msg = ((_enc__fut_msg__test_Foo_await_t*) pony_alloc_msg(POOL_INDEX(sizeof(_enc__fut_msg__test_Foo_await_t)), _ENC__FUT_MSG__test_Foo_await));
  msg->f1 = _enc__arg_f;
  msg->_enc__type__t = _enc__type__t;
  msg->_fut = _fut;
  pony_sendv((*_ctx), ((pony_actor_t*) _this), ((pony_msg_t*) msg));
  return _fut;
}


future_t* _enc__method__test_Foo_await_forward(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType, future_t* _enc__arg_f, future_t* _fut)
{
  pony_type_t* _enc__type__t = (runtimeType[0]);
  pony_gc_send((*_ctx));
  encore_trace_object((*_ctx), _enc__arg_f, future_trace);
  encore_trace_object((*_ctx), _fut, future_trace);
  pony_send_done((*_ctx));
  _enc__fut_msg__test_Foo_await_t* msg = ((_enc__fut_msg__test_Foo_await_t*) pony_alloc_msg(POOL_INDEX(sizeof(_enc__fut_msg__test_Foo_await_t)), _ENC__FUT_MSG__test_Foo_await));
  msg->f1 = _enc__arg_f;
  msg->_enc__type__t = _enc__type__t;
  msg->_fut = _fut;
  pony_sendv((*_ctx), ((pony_actor_t*) _this), ((pony_msg_t*) msg));
  return _fut;
}


void _enc__method__test_Foo_await_one_way(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType, future_t* _enc__arg_f)
{
  pony_type_t* _enc__type__t = (runtimeType[0]);
  pony_gc_send((*_ctx));
  encore_trace_object((*_ctx), _enc__arg_f, future_trace);
  /* No tracing future for oneway msg */;
  pony_send_done((*_ctx));
  _enc__oneway_msg__test_Foo_await_t* msg = ((_enc__oneway_msg__test_Foo_await_t*) pony_alloc_msg(POOL_INDEX(sizeof(_enc__oneway_msg__test_Foo_await_t)), _ENC__ONEWAY_MSG__test_Foo_await));
  msg->f1 = _enc__arg_f;
  msg->_enc__type__t = _enc__type__t;
  pony_sendv((*_ctx), ((pony_actor_t*) _this), ((pony_msg_t*) msg));
}


void* _enc__method__test_Foo_suspend(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "suspend");
  actor_suspend(_ctx);
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "suspend");
  return UNIT;
}


future_t* _enc__method__test_Foo_suspend_future(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType)
{
  future_t* _fut = future_mk(_ctx, ENCORE_PRIMITIVE);
  pony_gc_send((*_ctx));
  encore_trace_object((*_ctx), _fut, future_trace);
  pony_send_done((*_ctx));
  _enc__fut_msg__test_Foo_suspend_t* msg = ((_enc__fut_msg__test_Foo_suspend_t*) pony_alloc_msg(POOL_INDEX(sizeof(_enc__fut_msg__test_Foo_suspend_t)), _ENC__FUT_MSG__test_Foo_suspend));
  msg->_fut = _fut;
  pony_sendv((*_ctx), ((pony_actor_t*) _this), ((pony_msg_t*) msg));
  return _fut;
}


future_t* _enc__method__test_Foo_suspend_forward(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType, future_t* _fut)
{
  pony_gc_send((*_ctx));
  encore_trace_object((*_ctx), _fut, future_trace);
  pony_send_done((*_ctx));
  _enc__fut_msg__test_Foo_suspend_t* msg = ((_enc__fut_msg__test_Foo_suspend_t*) pony_alloc_msg(POOL_INDEX(sizeof(_enc__fut_msg__test_Foo_suspend_t)), _ENC__FUT_MSG__test_Foo_suspend));
  msg->_fut = _fut;
  pony_sendv((*_ctx), ((pony_actor_t*) _this), ((pony_msg_t*) msg));
  return _fut;
}


void _enc__method__test_Foo_suspend_one_way(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType)
{
  pony_gc_send((*_ctx));
  /* No tracing future for oneway msg */;
  pony_send_done((*_ctx));
  _enc__oneway_msg__test_Foo_suspend_t* msg = ((_enc__oneway_msg__test_Foo_suspend_t*) pony_alloc_msg(POOL_INDEX(sizeof(_enc__oneway_msg__test_Foo_suspend_t)), _ENC__ONEWAY_MSG__test_Foo_suspend));
  pony_sendv((*_ctx), ((pony_actor_t*) _this), ((pony_msg_t*) msg));
}


void* _enc__method__test_Foo_echo(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType, int64_t _enc__arg_i)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "echo");
  fprintf(stdout, "%lli\n", _enc__arg_i);
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "echo");
  return UNIT;
}


future_t* _enc__method__test_Foo_echo_future(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType, int64_t _enc__arg_i)
{
  future_t* _fut = future_mk(_ctx, ENCORE_PRIMITIVE);
  pony_gc_send((*_ctx));
  /* Not tracing field '_enc__arg_i' */;
  encore_trace_object((*_ctx), _fut, future_trace);
  pony_send_done((*_ctx));
  _enc__fut_msg__test_Foo_echo_t* msg = ((_enc__fut_msg__test_Foo_echo_t*) pony_alloc_msg(POOL_INDEX(sizeof(_enc__fut_msg__test_Foo_echo_t)), _ENC__FUT_MSG__test_Foo_echo));
  msg->f1 = _enc__arg_i;
  msg->_fut = _fut;
  pony_sendv((*_ctx), ((pony_actor_t*) _this), ((pony_msg_t*) msg));
  return _fut;
}


future_t* _enc__method__test_Foo_echo_forward(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType, int64_t _enc__arg_i, future_t* _fut)
{
  pony_gc_send((*_ctx));
  /* Not tracing field '_enc__arg_i' */;
  encore_trace_object((*_ctx), _fut, future_trace);
  pony_send_done((*_ctx));
  _enc__fut_msg__test_Foo_echo_t* msg = ((_enc__fut_msg__test_Foo_echo_t*) pony_alloc_msg(POOL_INDEX(sizeof(_enc__fut_msg__test_Foo_echo_t)), _ENC__FUT_MSG__test_Foo_echo));
  msg->f1 = _enc__arg_i;
  msg->_fut = _fut;
  pony_sendv((*_ctx), ((pony_actor_t*) _this), ((pony_msg_t*) msg));
  return _fut;
}


void _enc__method__test_Foo_echo_one_way(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType, int64_t _enc__arg_i)
{
  pony_gc_send((*_ctx));
  /* Not tracing field '_enc__arg_i' */;
  /* No tracing future for oneway msg */;
  pony_send_done((*_ctx));
  _enc__oneway_msg__test_Foo_echo_t* msg = ((_enc__oneway_msg__test_Foo_echo_t*) pony_alloc_msg(POOL_INDEX(sizeof(_enc__oneway_msg__test_Foo_echo_t)), _ENC__ONEWAY_MSG__test_Foo_echo));
  msg->f1 = _enc__arg_i;
  pony_sendv2((*_ctx), ((pony_actor_t*) _this), ((pony_msg_t*) msg), q);
}


void* _enc__method__test_Foo_init(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType, _enc__class__test_Main_t* _enc__arg_m)
{
  ENC_DTRACE3(METHOD_ENTRY, (uintptr_t)*_ctx, (uintptr_t)_this, "init");
  (*({ENC_DTRACE3(FIELD_WRITE, (uintptr_t)*_ctx, (uintptr_t)_this, "m"); _this;}))._enc__field_m = _enc__arg_m;
  ENC_DTRACE3(METHOD_EXIT, (uintptr_t)*_ctx, (uintptr_t)_this, "init");
  return UNIT;
}


future_t* _enc__method__test_Foo_init_future(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType, _enc__class__test_Main_t* _enc__arg_m)
{
  future_t* _fut = future_mk(_ctx, ENCORE_PRIMITIVE);
  pony_gc_send((*_ctx));
  encore_trace_actor((*_ctx), ((pony_actor_t*) _enc__arg_m));
  encore_trace_object((*_ctx), _fut, future_trace);
  pony_send_done((*_ctx));
  _enc__fut_msg__test_Foo_init_t* msg = ((_enc__fut_msg__test_Foo_init_t*) pony_alloc_msg(POOL_INDEX(sizeof(_enc__fut_msg__test_Foo_init_t)), _ENC__FUT_MSG__test_Foo_init));
  msg->f1 = _enc__arg_m;
  msg->_fut = _fut;
  pony_sendv((*_ctx), ((pony_actor_t*) _this), ((pony_msg_t*) msg));
  return _fut;
}


future_t* _enc__method__test_Foo_init_forward(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType, _enc__class__test_Main_t* _enc__arg_m, future_t* _fut)
{
  pony_gc_send((*_ctx));
  encore_trace_actor((*_ctx), ((pony_actor_t*) _enc__arg_m));
  encore_trace_object((*_ctx), _fut, future_trace);
  pony_send_done((*_ctx));
  _enc__fut_msg__test_Foo_init_t* msg = ((_enc__fut_msg__test_Foo_init_t*) pony_alloc_msg(POOL_INDEX(sizeof(_enc__fut_msg__test_Foo_init_t)), _ENC__FUT_MSG__test_Foo_init));
  msg->f1 = _enc__arg_m;
  msg->_fut = _fut;
  pony_sendv((*_ctx), ((pony_actor_t*) _this), ((pony_msg_t*) msg));
  return _fut;
}


void _enc__method__test_Foo_init_one_way(pony_ctx_t** _ctx, _enc__class__test_Foo_t* _this, pony_type_t** runtimeType, _enc__class__test_Main_t* _enc__arg_m)
{
  pony_gc_send((*_ctx));
  encore_trace_actor((*_ctx), ((pony_actor_t*) _enc__arg_m));
  /* No tracing future for oneway msg */;
  pony_send_done((*_ctx));
  _enc__oneway_msg__test_Foo_init_t* msg = ((_enc__oneway_msg__test_Foo_init_t*) pony_alloc_msg(POOL_INDEX(sizeof(_enc__oneway_msg__test_Foo_init_t)), _ENC__ONEWAY_MSG__test_Foo_init));
  msg->f1 = _enc__arg_m;
  pony_sendv((*_ctx), ((pony_actor_t*) _this), ((pony_msg_t*) msg));
}


static void _enc__dispatch__test_Foo(pony_ctx_t** _ctx, pony_actor_t* _a, pony_msg_t* _m)
{
  _enc__class__test_Foo_t* _this = ((_enc__class__test_Foo_t*) _a);
  switch (_m->id)
  {
    case 4711:
      break;
    case _ENC__FUT_MSG__test_Foo_await:
    {
      future_t* _fut = ((encore_fut_msg_t*) _m)->_fut;
      pony_type_t* _enc__type__t = ((_enc__fut_msg__test_Foo_await_t*) _m)->_enc__type__t;
      future_t* _enc__arg_f = ((_enc__fut_msg__test_Foo_await_t*) _m)->f1;
      
      // --- GC on receive ----------------------------------------;
      pony_gc_recv((*_ctx));
      encore_trace_object((*_ctx), _enc__arg_f, future_trace);
      encore_trace_object((*_ctx), _fut, future_type.trace);
      pony_recv_done((*_ctx));
      // --- GC on receive ----------------------------------------;
      
      pony_type_t* methodTypeVars[] = {_enc__type__t};
      future_fulfil(_ctx, _fut, ((encore_arg_t) {.p = _enc__method__test_Foo_await(_ctx, _this, methodTypeVars, _enc__arg_f)}));
      break;
    }
    case _ENC__ONEWAY_MSG__test_Foo_await:
    {
      pony_type_t* _enc__type__t = ((_enc__oneway_msg__test_Foo_await_t*) _m)->_enc__type__t;
      future_t* _enc__arg_f = ((_enc__oneway_msg__test_Foo_await_t*) _m)->f1;
      
      // --- GC on receive ----------------------------------------;
      pony_gc_recv((*_ctx));
      encore_trace_object((*_ctx), _enc__arg_f, future_trace);
      /* Not tracing the future in a oneWay send */;
      pony_recv_done((*_ctx));
      // --- GC on receive ----------------------------------------;
      
      pony_type_t* methodTypeVars[] = {_enc__type__t};
      _enc__method__test_Foo_await(_ctx, _this, methodTypeVars, _enc__arg_f);
      break;
    }
    case _ENC__FUT_MSG__test_Foo_suspend:
    {
      future_t* _fut = ((encore_fut_msg_t*) _m)->_fut;
      
      // --- GC on receive ----------------------------------------;
      pony_gc_recv((*_ctx));
      encore_trace_object((*_ctx), _fut, future_type.trace);
      pony_recv_done((*_ctx));
      // --- GC on receive ----------------------------------------;
      
      pony_type_t* methodTypeVars[] = {};
      future_fulfil(_ctx, _fut, ((encore_arg_t) {.p = _enc__method__test_Foo_suspend(_ctx, _this, methodTypeVars)}));
      break;
    }
    case _ENC__ONEWAY_MSG__test_Foo_suspend:
    {
      
      // --- GC on receive ----------------------------------------;
      pony_gc_recv((*_ctx));
      /* Not tracing the future in a oneWay send */;
      pony_recv_done((*_ctx));
      // --- GC on receive ----------------------------------------;
      
      pony_type_t* methodTypeVars[] = {};
      _enc__method__test_Foo_suspend(_ctx, _this, methodTypeVars);
      break;
    }
    case _ENC__FUT_MSG__test_Foo_echo:
    {
      future_t* _fut = ((encore_fut_msg_t*) _m)->_fut;
      int64_t _enc__arg_i = ((_enc__fut_msg__test_Foo_echo_t*) _m)->f1;
      
      // --- GC on receive ----------------------------------------;
      pony_gc_recv((*_ctx));
      /* Not tracing field '_enc__arg_i' */;
      encore_trace_object((*_ctx), _fut, future_type.trace);
      pony_recv_done((*_ctx));
      // --- GC on receive ----------------------------------------;
      
      pony_type_t* methodTypeVars[] = {};
      future_fulfil(_ctx, _fut, ((encore_arg_t) {.p = _enc__method__test_Foo_echo(_ctx, _this, methodTypeVars, _enc__arg_i)}));
      break;
    }
    case _ENC__ONEWAY_MSG__test_Foo_echo:
    {
      int64_t _enc__arg_i = ((_enc__oneway_msg__test_Foo_echo_t*) _m)->f1;
      
      // --- GC on receive ----------------------------------------;
      pony_gc_recv((*_ctx));
      /* Not tracing field '_enc__arg_i' */;
      /* Not tracing the future in a oneWay send */;
      pony_recv_done((*_ctx));
      // --- GC on receive ----------------------------------------;
      
      pony_type_t* methodTypeVars[] = {};
      _enc__method__test_Foo_echo(_ctx, _this, methodTypeVars, _enc__arg_i);
      break;
    }
    case _ENC__FUT_MSG__test_Foo_init:
    {
      future_t* _fut = ((encore_fut_msg_t*) _m)->_fut;
      _enc__class__test_Main_t* _enc__arg_m = ((_enc__fut_msg__test_Foo_init_t*) _m)->f1;
      
      // --- GC on receive ----------------------------------------;
      pony_gc_recv((*_ctx));
      encore_trace_actor((*_ctx), ((pony_actor_t*) _enc__arg_m));
      encore_trace_object((*_ctx), _fut, future_type.trace);
      pony_recv_done((*_ctx));
      // --- GC on receive ----------------------------------------;
      
      pony_type_t* methodTypeVars[] = {};
      future_fulfil(_ctx, _fut, ((encore_arg_t) {.p = _enc__method__test_Foo_init(_ctx, _this, methodTypeVars, _enc__arg_m)}));
      break;
    }
    case _ENC__ONEWAY_MSG__test_Foo_init:
    {
      _enc__class__test_Main_t* _enc__arg_m = ((_enc__oneway_msg__test_Foo_init_t*) _m)->f1;
      
      // --- GC on receive ----------------------------------------;
      pony_gc_recv((*_ctx));
      encore_trace_actor((*_ctx), ((pony_actor_t*) _enc__arg_m));
      /* Not tracing the future in a oneWay send */;
      pony_recv_done((*_ctx));
      // --- GC on receive ----------------------------------------;
      
      pony_type_t* methodTypeVars[] = {};
      _enc__method__test_Foo_init(_ctx, _this, methodTypeVars, _enc__arg_m);
      break;
    }
    default:
    {
      printf("error, got invalid id: %zd\n", _m->id);
    }
  };
}


pony_type_t _enc__class__test_Foo_type = {.id=_ENC__ID__test_Foo, .size=sizeof(_enc__class__test_Foo_t), .trace=_enc__trace__test_Foo, .dispatch=_enc__dispatch__test_Foo, .vtable=trait_method_selector};
