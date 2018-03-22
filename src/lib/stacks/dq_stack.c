#include <dq_stack.h>

#include <dl_deque.h>

#include <stdio.h>
#include <stdlib.h>

struct _list_node {
	list_node *prev;	// Pointer to prev list_node element.
	list_node *next;	// Pointer to next list_node element.
	void *data;			// Pointer to the element added on the list.
};

dq_stack_root * dq_stack_create(t_destroyfunc destroyfunc) {
	return dl_deque_create(destroyfunc);
}

int dq_stack_push(dq_stack_root *stack, void *data) {
	return dl_deque_push_left(stack, data);
}

void * dq_stack_peek(dq_stack_root *stack) {
	return dl_deque_peek_left(stack);
}

void * dq_stack_pop(dq_stack_root *stack) {
	return dl_deque_pop_left(stack);
}

void dq_stack_destroy(dq_stack_root **stack) {
	dl_deque_destroy(stack);
}

int dq_stack_size(dq_stack_root *stack) {
	return dl_deque_size(stack);
}
