#ifndef _LIBADT_DL_DEQUE_H
#define _LIBADT_DL_DEQUE_H

#include <adt_commons.h>

typedef list_root dl_deque_root;

/*
 * Create an empty deque structure (double ended queue) and set a
 * destroy function for its elements.
 *
 * The destroy argument gives a way to free the entire structure when we
 * call slist_destroy. For malloc/calloc data, free must be used. If data
 * is a struct with other members, a function designed to free its memory
 * must be provided. If the data is static or have another way to free its
 * memory, NULL must be set.
 * Complexity: O(1).
 */
dl_deque_root * dl_deque_create(t_destroyfunc destroyfunc);

/*
 * Insert an element in the rear of the deque.
 * Complexity: O(1).
 */
int dl_deque_push_left(dl_deque_root *deque, void *data);

/*
 * Insert an element in the front of the deque.
 * Complexity: O(1).
 */
int dl_deque_push_right(dl_deque_root *deque, void *data);

/*
 * Look the first item of the deque without remove it.
 * If deque is empty, return NULL;
 * Complexity: O(1).
 */
void * dl_deque_peek_left(dl_deque_root *deque);

/*
 * Look the last item of the deque without remove it.
 * If deque is empty, return NULL;
 * Complexity: O(1).
 */
void * dl_deque_peek_right(dl_deque_root *deque);

/*
 * Remove the rear element from the deque and return its element.
 * Complexity: O(1).
 */
void * dl_deque_pop_left(dl_deque_root *deque);

/*
 * Remove the front element from the deque and return its element.
 * Complexity: O(1).
 */
void * dl_deque_pop_right(dl_deque_root *deque);

/*
 * Destroy the deque and its elements, if have any. If destroy function is provided,
 * it will be used, otherwise, uses free.
 * Complexity: O(n).
 */
void dl_deque_destroy(dl_deque_root *deque);

/*
 * Returns the size of the deque.
 * Complexity: O(1).
 */
int dl_deque_size(dl_deque_root *deque);

#endif
