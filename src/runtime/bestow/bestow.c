#include <assert.h>
#include <pony.h>

#include "encore.h"
#include "bestow.h"
#include "../libponyrt/sched/scheduler.h"
#include "../libponyrt/mem/pool.h"

pony_type_t bestow_type = {
  .id = ID_BESTOW,
  .size = sizeof(struct bestow_wrapper),
  .trace = &bestow_trace
};

/* static inline void bestow_trace(pony_ctx_t *ctx, bestow_wrapper_t *bw) */
/* { */
/*   assert(bw); */
/*   if (bw->type == ENCORE_ACTIVE) { */
/*     encore_trace_actor(ctx, bw->object); */
/*   } else if (bw->type != ENCORE_PRIMITIVE) { */
/*     encore_trace_object(ctx, bw->object, bw->type->trace); */
/*   } */
/* } */

void bestow_trace(pony_ctx_t *ctx, void *p)
{
  encore_trace_actor(ctx, ((bestow_wrapper_t*)p)->owner);
  pony_trace(ctx, ((bestow_wrapper_t*)p)->object);
}

bestow_wrapper_t *bestow_wrapper_mk(pony_ctx_t **ctx, void *object)
{
  pony_ctx_t *cctx = *ctx;
  bestow_wrapper_t *bw = pony_alloc(cctx, sizeof(bestow_wrapper_t));
  bw->type = &bestow_type;
  bw->owner = cctx->current;
  bw->object = object;
  bw->next = NULL;
  return bw;
}

pony_actor_t *bestow_get_owner(bestow_wrapper_t *bw)
{
  return bw->owner;
}

void* bestow_get_object(bestow_wrapper_t *bw)
{
  return bw->object;
}

bestow_wrapper_t* bestow_head(void *own)
{
  return ((encore_actor_t*)own)->head;
}

void* bestow_search(encore_actor_t *own, void *obj)
{
  bestow_wrapper_t *ptr = own->head;
  while (ptr)
  {
    if (ptr->object == obj)
      return ptr;

    ptr = ptr->next;
  }
  return NULL;
}

void bestow_insert(pony_ctx_t *ctx, bestow_wrapper_t *bw)
{
  encore_actor_t *own = (encore_actor_t*) ctx->current;
  if (!own->head)
    own->head = bw;


  if (!bestow_search(own, bw->object))
  {
    ((bestow_wrapper_t*)bw)->next = own->head;
    own->head = bw;
  }
}

void bestow_remove(pony_ctx_t *ctx, void *own, void *obj)
{
  (void) ctx;

  bestow_wrapper_t *prev = NULL;
  bestow_wrapper_t *ptr = ((encore_actor_t*)own)->head;

  while (ptr)
  {
    if (ptr->object == obj)
    {
      if (!prev)
        ((encore_actor_t*)own)->head = ptr->next;
      else
        prev->next = ptr->next;

      POOL_FREE(struct bestow_wrapper, ptr);
      return;
    }

    prev = ptr;
    ptr = ptr->next;
  }
}
