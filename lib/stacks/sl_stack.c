#include <sl_stack.h>

#include <slist.h>

#include <stdio.h>
#include <stdlib.h>

sl_stack_root * sl_stack_create(t_destroyfunc destroyfunc) {
	return slist_create(destroyfunc);
}

int sl_stack_push(sl_stack_root *stack, void *data) {
	return slist_insert_el_next(stack, NULL, data);
}

void * sl_stack_peek(sl_stack_root *stack) {
	if (sl_stack_size(stack) > 0) {
		return stack->head->data;
	} else {
		return NULL;
	}
}

void * sl_stack_pop(sl_stack_root *stack) {
	if (sl_stack_size(stack) > 0) {
		return slist_rem_el(stack, stack->head);
	} else {
		fprintf(stderr, "Stack is empty!");
		return NULL;
	}
}

void sl_stack_destroy(sl_stack_root *stack) {
	slist_destroy(stack);
}

int sl_stack_size(sl_stack_root *stack) {
	return list_size(stack);
}
