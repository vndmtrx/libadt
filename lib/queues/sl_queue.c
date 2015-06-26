#include <stdio.h>
#include <stdlib.h>

#include <sl_queue.h>

/* 
 * Create a empty queue structure and set a destroy function for its elements.
 * The destroy argument gives a way to free the entire structure when we
 * call slist_destroy. For malloc/calloc data, free must be used. If data
 * is a struct with other members, a function designed to free its memory
 * must be provided. If the data is static or have another way to free its
 * memory, NULL must be set.
 * Complexity: O(1).
 */
void sl_queue_create(sl_queue_root *queue, t_destroyfunc destroyfunc) {
	slist_create(queue, destroyfunc);
}

/*
 * Insert an element in the queue.
 * Complexity: O(1).
 */
int sl_queue_push(sl_queue_root *queue, void *data) {
	return slist_insert_el_next(queue, queue->tail, data);
}

/*
 * Look the last item of the queue without remove it.
 * Complexity: O(1).
 */
int sl_queue_peek(sl_queue_root *queue, void **data) {
	if (slist_size(queue) > 0) {
		*data = queue->head->data;
		return 0;
	} else {
		perror("Queue is empty!");
		return -1;
	}
}

/*
 * Remove an element from the queue and return its element.
 * Queues are First In First Out, so the item removed is the first item
 * added.
 * Complexity: O(1).
 */
int sl_queue_pop(sl_queue_root *queue, void **data) {
	if (slist_size(queue) > 0) {
		return slist_rem_el(queue, queue->head, data);
	} else {
		perror("Queue is empty!");
		return -1;
	}
}

/*
 * Destroy the list and the elements in it. If destroy function is provided,
 * it will be used, otherwise, uses free.
 * Complexity: O(n).
 */
void sl_queue_destroy(sl_queue_root *queue) {
	slist_destroy(queue);
}
