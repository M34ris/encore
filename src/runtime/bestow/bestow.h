#ifndef __bestow_h__
#define __bestow_h__

#include <pony.h>

// typedef void* bestow_node_t;

typedef struct bestow_wrapper
{
  pony_type_t  *type;
  pony_actor_t *owner;
  encore_arg_t  object;
  void *next;
} bestow_wrapper_t;

// typedef struct bestow_wrapper bestow_wrapper_t;
extern pony_type_t bestow_type;

void bestow_trace(pony_ctx_t *ctx, void* p);
bestow_wrapper_t* bestow_wrapper_mk(pony_ctx_t **ctx, pony_type_t *type, encore_arg_t object);
pony_actor_t* bestow_get_owner(bestow_wrapper_t *bw);
void* bestow_get_object(bestow_wrapper_t *bw);

bestow_wrapper_t* bestow_head(void *own);
void bestow_insert(pony_ctx_t *ctx, bestow_wrapper_t *bw);
void bestow_remove(pony_ctx_t *ctx, void *own, void *obj);

#endif
