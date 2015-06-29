#include <stdio.h>
#include <stdlib.h>

#include <sl_stack.h>

/* 
 * Create a empty stack structure (LiFo - Last In / First Out) and set a
 * destroy function for its elements.
 * 
 * The destroy argument gives a way to free the entire structure when we
 * call slist_destroy. For malloc/calloc data, free must be used. If data
 * is a struct with other members, a function designed to free its memory
 * must be provided. If the data is static or have another way to free its
 * memory, NULL must be set.
 * Complexity: O(1).
 */
void sl_stack_create(sl_stack_root *stack, t_destroyfunc destroyfunc) {
	slist_create(stack, destroyfunc);
}

/*
 * Insert an element in the stack.
 * Complexity: O(1).
 */
int sl_stack_push(sl_stack_root *stack, void *data) {
	return slist_insert_el_next(stack, NULL, data);
}

/*
 * Look the last item of the stack without remove it.
 * If stack is empty, set data NULL and return -1;
 * Complexity: O(1).
 */
int sl_stack_peek(sl_stack_root *stack, void **data) {
	if (slist_size(stack) > 0) {
		*data = stack->head->data;
		return 0;
	} else {
		*data = NULL;
		return -1;
	}
}

/*
 * Remove an element from the stack and return its element.
 * Stacks are Last In First Out, so the item removed is the last item
 * added.
 * Complexity: O(1).
 */
int sl_stack_pop(sl_stack_root *stack, void **data) {
	if (slist_size(stack) > 0) {
		return slist_rem_el(stack, stack->head, data);
	} else {
		perror("Stack is empty!");
		return -1;
	}
}

/*
 * Destroy the stack and the elements in it. If destroy function is provided,
 * it will be used, otherwise, uses free.
 * Complexity: O(n).
 */
void sl_stack_destroy(sl_stack_root *stack) {
	slist_destroy(stack);
}
