#include <sl_queue.h>

#include <slist.h>

#include <stdio.h>
#include <stdlib.h>

sl_queue_root * sl_queue_create(t_destroyfunc destroyfunc) {
	return slist_create(destroyfunc);
}

int sl_queue_push(sl_queue_root *queue, void *data) {
	return slist_insert_el_next(queue, queue->tail, data);
}

void * sl_queue_peek(sl_queue_root *queue) {
	if (sl_queue_size(queue) > 0) {
		return queue->head->data;
	} else {
		fprintf(stderr, "Queue is empty!");
		return NULL;
	}
}

void * sl_queue_pop(sl_queue_root *queue) {
	if (sl_queue_size(queue) > 0) {
		return slist_rem_el(queue, queue->head);
	} else {
		fprintf(stderr, "Queue is empty!");
		return NULL;
	}
}

/*
 * Destroy the queue and the elements in it. If destroy function is provided,
 * it will be used, otherwise, uses free.
 * Complexity: O(n).
 */
void sl_queue_destroy(sl_queue_root *queue) {
	slist_destroy(queue);
}

/*
 * Returns the size of the queue.
 * Complexity: O(1).
 */
int sl_queue_size(sl_queue_root *queue) {
	return list_size(queue);
}
