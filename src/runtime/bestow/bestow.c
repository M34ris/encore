#include <assert.h>
#include <pony.h>

#include "encore.h"
#include "bestow.h"
#include "../libponyrt/sched/scheduler.h"

struct bestow_wrapper
{
  pony_actor_t *owner;  // The owner of the bestowed object
  encore_arg_t  object; // The bestowed object
  pony_type_t  *type;
};

pony_type_t bestowed_type = {
  .id = ID_BESTOW,
  .size = sizeof(struct bestow_wrapper),
  .trace = &bestow_trace
};

static inline void bestow_gc_trace_value(pony_ctx_t *ctx, bestow_wrapper_t *bw)
{
  assert(bw);
  if (bw->type == ENCORE_ACTIVE) {
      encore_trace_actor(ctx, bw->object.p);
  } else if (bw->type != ENCORE_PRIMITIVE) {
    encore_trace_object(ctx, bw->object.p, bw->type->trace);
  }
}

bestow_wrapper_t *bestow_wrapper_mk(pony_ctx_t **ctx, pony_type_t *type, encore_arg_t object)
{
  pony_ctx_t *cctx = *ctx;
  bestow_wrapper_t *bw = pony_alloc(cctx, sizeof(bestow_wrapper_t));
  *bw = (bestow_wrapper_t) { .owner = cctx->current, .object = object,
                             .type = type};  
  return bw;
}

pony_actor_t *bestow_get_target(bestow_wrapper_t *bw)
{
  return bw->owner;
}

encore_arg_t bestow_get_object(bestow_wrapper_t *bw)
{
  return bw->object;
}

void bestow_trace(pony_ctx_t *ctx, void* p)
{
  assert(p);
  (void) ctx;
  (void) p;
  // TODO
}

/* inline encore_arg_t handle_closure(pony_ctx_t **ctx, closure_t *c) */
/* { */
/*   return closure_call(ctx, c, (value_t[1]) { NULL }); */
/* } */
