#include <dq_queue.h>

#include <dl_deque.h>

#include <stdio.h>
#include <stdlib.h>

struct _list_node {
	list_node *prev;	// Pointer to prev list_node element.
	list_node *next;	// Pointer to next list_node element.
	void *data;			// Pointer to the element added on the list.
};

dq_queue_root * dq_queue_create(t_destroyfunc destroyfunc) {
	return dl_deque_create(destroyfunc);
}

int dq_queue_push(dq_queue_root *queue, void *data) {
	return dl_deque_push_left(queue, data);
}

void * dq_queue_peek(dq_queue_root *queue) {
	return dl_deque_peek_right(queue);
}

void * dq_queue_pop(dq_queue_root *queue) {
	return dl_deque_pop_right(queue);
}

void dq_queue_destroy(dq_queue_root **queue) {
	dl_deque_destroy(queue);
}

int dq_queue_size(dq_queue_root *queue) {
	return dl_deque_size(queue);
}
