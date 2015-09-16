#include <dl_deque.h>

#include <stdio.h>
#include <stdlib.h>

void dl_deque_create(dl_deque_root *deque, t_destroyfunc destroyfunc) {
	dlist_create(deque, destroyfunc);
}

int dl_deque_put(dl_deque_root *deque, void *data) {
	return dlist_insert_el_prev(deque, deque->head, data);
}

int dl_deque_push(dl_deque_root *deque, void *data) {
	return dlist_insert_el_next(deque, deque->tail, data);
}

void * dl_deque_first(dl_deque_root *deque) {
	if (dlist_size(deque) > 0) {
		return deque->head->data;
	} else {
		fprintf(stderr, "Deque is empty!");
		return NULL;
	}
}

void * dl_deque_last(dl_deque_root *deque) {
	if (dlist_size(deque) > 0) {
		return deque->tail->data;
	} else {
		fprintf(stderr, "Deque is empty!");
		return NULL;
	}
}

void * dl_deque_get(dl_deque_root *deque) {
if (dlist_size(deque) > 0) {
		return dlist_rem_el(deque, deque->head);
	} else {
		fprintf(stderr, "Deque is empty!");
		return NULL;
	}
}

void * dl_deque_pop(dl_deque_root *deque) {
	if (dlist_size(deque) > 0) {
		return dlist_rem_el(deque, deque->tail);
	} else {
		fprintf(stderr, "Deque is empty!");
		return NULL;
	}
}

void dl_deque_destroy(dl_deque_root *deque) {
	
}
