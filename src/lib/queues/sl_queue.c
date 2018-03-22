#include <sl_queue.h>

#include <sl_list.h>

#include <stdio.h>
#include <stdlib.h>

struct _list_node {
	list_node *next;	// Pointer to next list_node element.
	void *data;			// Pointer to the element added on the list.
};

sl_queue_root * sl_queue_create(t_destroyfunc destroyfunc) {
	return sl_list_create(destroyfunc, TAIL);
}

int sl_queue_push(sl_queue_root *queue, void *data) {
	return sl_list_insert_el_next(queue, NULL, data);
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
		return sl_list_rem_el(queue, queue->head);
	} else {
		fprintf(stderr, "Queue is empty!");
		return NULL;
	}
}

void sl_queue_destroy(sl_queue_root **queue) {
	sl_list_destroy(queue);
}

int sl_queue_size(sl_queue_root *queue) {
	return list_size(queue);
}
