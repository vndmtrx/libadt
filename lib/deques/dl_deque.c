#include <dl_deque.h>

#include <dlist.h>

#include <stdio.h>
#include <stdlib.h>


dl_deque_root * dl_deque_create(t_destroyfunc destroyfunc) {
	return dlist_create(destroyfunc);
}

int dl_deque_push_left(dl_deque_root *deque, void *data) {
	return dlist_insert_el_next(deque, NULL, data);
}

int dl_deque_push_right(dl_deque_root *deque, void *data) {
	return dlist_insert_el_prev(deque, NULL, data);
}

void * dl_deque_peek_left(dl_deque_root *deque) {
	if (list_size(deque) > 0) {
		return deque->head->data;
	} else {
		fprintf(stderr, "Deque is empty!");
		return NULL;
	}
}

void * dl_deque_peek_right(dl_deque_root *deque) {
	if (list_size(deque) > 0) {
		return deque->tail->data;
	} else {
		fprintf(stderr, "Deque is empty!");
		return NULL;
	}
}

void * dl_deque_pop_left(dl_deque_root *deque) {
if (list_size(deque) > 0) {
		return dlist_rem_el(deque, deque->head);
	} else {
		fprintf(stderr, "Deque is empty!");
		return NULL;
	}
}

void * dl_deque_pop_right(dl_deque_root *deque) {
	if (list_size(deque) > 0) {
		return dlist_rem_el(deque, deque->tail);
	} else {
		fprintf(stderr, "Deque is empty!");
		return NULL;
	}
}

void dl_deque_destroy(dl_deque_root *deque) {
	dlist_destroy(deque);
}

int dl_deque_size(dl_deque_root *deque) {
	return list_size(deque);
}
