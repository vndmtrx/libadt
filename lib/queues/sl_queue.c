#include <stdio.h>
#include <stdlib.h>

#include <sl_queue.h>

void sl_queue_create(sl_queue_root *queue, t_destroyfunc destroyfunc) {
	slist_create(queue, destroyfunc);
}

int sl_queue_push(sl_queue_root *queue, void *data) {
	return slist_insert_el_next(queue, queue->tail, data);
}

int sl_queue_peek(sl_queue_root *queue, void **data) {
	if (slist_size(queue) > 0) {
		*data = queue->head->data;
		return 0;
	} else {
		perror("Queue is empty!");
		return -1;
	}
}

int sl_queue_pop(sl_queue_root *queue, void **data) {
	if (slist_size(queue) > 0) {
		return slist_rem_el(queue, queue->head, data);
	} else {
		perror("Queue is empty!");
		return -1;
	}
}

void sl_queue_destroy(sl_queue_root *queue) {
	slist_destroy(queue);
}
