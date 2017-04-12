#ifndef __bestow_h__
#define __bestow_h__

#include <pony.h>
#include "closure.h"

typedef struct bestow_wrapper bestow_wrapper_t;
extern pony_type_t bestow_type;

void bestow_trace(pony_ctx_t *ctx, void* p);

bestow_wrapper_t *bestow_wrapper_mk(pony_ctx_t **ctx, pony_type_t *type, encore_arg_t object);

pony_actor_t *bestow_get_target(bestow_wrapper_t *bw);

encore_arg_t bestow_get_object(bestow_wrapper_t *bw);

static inline encore_arg_t handle_closure(pony_ctx_t **ctx, closure_t *c)
{
    return closure_call(ctx, c, (value_t[1]) {{ NULL}});
}

#endif
