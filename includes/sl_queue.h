#ifndef _LIBADT_SL_QUEUE_H
#define _LIBADT_SL_QUEUE_H

#include <adt_commons.h>

typedef list_root sl_queue_root;

/*
 * Create a empty queue structure (FiFo - Fist In / First Out) and set a
 * destroy function for its elements.
 *
 * The destroy argument gives a way to free the entire structure when we
 * call slist_destroy. For malloc/calloc data, free must be used. If data
 * is a struct with other members, a function designed to free its memory
 * must be provided. If the data is static or have another way to free its
 * memory, NULL must be set.
 * Complexity: O(1).
 */
sl_queue_root * sl_queue_create(t_destroyfunc destroyfunc);

/*
 * Insert an element in the queue.
 * Complexity: O(1).
 */
int sl_queue_push(sl_queue_root *queue, void *data);

/*
 * Look the last item of the queue without remove it.
 * If queue is empty, set data NULL and return -1;
 * Complexity: O(1).
 */
void * sl_queue_peek(sl_queue_root *queue);

/*
 * Remove an element from the queue and return its element.
 * Queues are First In First Out, so the item removed is the first item
 * added.
 * Complexity: O(1).
 */
void * sl_queue_pop(sl_queue_root *queue);

/*
 * Destroy the queue and its elements, if have any. If destroy function is provided,
 * it will be used, otherwise, uses free.
 * Complexity: O(n).
 */
void sl_queue_destroy(sl_queue_root *queue);

/*
 * Returns the size of the queue.
 * Complexity: O(1).
 */
int sl_queue_size(sl_queue_root *queue);

#endif
