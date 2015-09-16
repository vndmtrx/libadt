#ifndef _LIBADT_DL_DEQUE_H
#define _LIBADT_DL_DEQUE_H

#include <adt_commons.h>
#include <dlist.h>

typedef dlist_root dl_deque_root;

void dl_deque_create(dl_deque_root *deque, t_destroyfunc destroyfunc);

int dl_deque_push(dl_deque_root *deque, void *data);

int dl_deque_put(dl_deque_root *deque, void *data);

void * dl_deque_first(dl_deque_root *deque);

void * dl_deque_last(dl_deque_root *deque);

void * dl_deque_pop(dl_deque_root *deque);

void * dl_deque_get(dl_deque_root *deque);

void dl_deque_destroy(dl_deque_root *deque);

#define dl_deque_size(deque) ((deque) ->size)

#endif
