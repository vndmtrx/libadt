#include <dq_queue.h>

#include <dl_deque.h>

#include <stdio.h>
#include <stdlib.h>

dq_queue_root * dq_queue_create(t_destroyfunc destroyfunc) {
	return dl_deque_create(destroyfunc);
}

int dq_queue_push(dq_queue_root *queue, void *data) {
	return dl_deque_push_left(queue, data);
}

void * sl_queue_peek(sl_queue_root *queue) {
	return dl_deque_peek_right(queue);
}

void * sl_queue_pop(sl_queue_root *queue) {
	return dl_deque_pop_right(queue)
}

void sl_queue_destroy(sl_queue_root *queue) {
	dl_deque_destroy(queue);
}

int sl_queue_size(sl_queue_root *queue) {
	return dl_deque_size(queue);
}
