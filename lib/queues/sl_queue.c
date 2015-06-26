#include <stdio.h>
#include <stdlib.h>

#include <sl_queue.h>

void sl_queue_create(sl_queue_root *queue, t_destroyfunc destroyfunc) {
	slist_create(queue, destroyfunc);
}

void sl_queue_destroy(sl_queue_root *queue) {
	slist_destroy(queue);
}
