#include <dl_deque.h>

#include <dl_list.h>

#include <stdio.h>
#include <stdlib.h>

struct _list_node {
	list_node *prev;	// Pointer to prev list_node element.
	list_node *next;	// Pointer to next list_node element.
	void *data;			// Pointer to the element added on the list.
};

dl_deque_root * dl_deque_create(t_destroyfunc destroyfunc) {
	return dl_list_create(destroyfunc, HEAD);
}

int dl_deque_push_left(dl_deque_root *deque, void *data) {
	return dl_list_insert_el_next(deque, NULL, data);
}

int dl_deque_push_right(dl_deque_root *deque, void *data) {
	return dl_list_insert_el_prev(deque, NULL, data);
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
		return dl_list_rem_el(deque, deque->head);
	} else {
		fprintf(stderr, "Deque is empty!");
		return NULL;
	}
}

void * dl_deque_pop_right(dl_deque_root *deque) {
	if (list_size(deque) > 0) {
		return dl_list_rem_el(deque, deque->tail);
	} else {
		fprintf(stderr, "Deque is empty!");
		return NULL;
	}
}

void dl_deque_destroy(dl_deque_root *deque) {
	dl_list_destroy(deque);
}

int dl_deque_size(dl_deque_root *deque) {
	return list_size(deque);
}
