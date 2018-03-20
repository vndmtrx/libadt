#ifndef _LIBADT_DQ_STACK_H
#define _LIBADT_DQ_STACK_H

#include <list_commons.h>

typedef list_root dq_stack_root;

/*
 * Create a empty stack structure (FiLo - First In / Last Out) and set a
 * destroy function for its elements.
 *
 * The destroy argument gives a way to free the entire structure when we
 * call slist_destroy. For malloc/calloc data, free must be used. If data
 * is a struct with other members, a function designed to free its memory
 * must be provided. If the data is static or have another way to free its
 * memory, NULL must be set.
 * Complexity: O(1).
 */
dq_stack_root * dq_stack_create(t_destroyfunc destroyfunc);

/*
 * Insert an element in the stack.
 * Complexity: O(1).
 */
int dq_stack_push(dq_stack_root *stack, void *data);

/*
 * Look the last item of the stack without remove it.
 * If stack is empty, set data NULL and return -1;
 * Complexity: O(1).
 */
void * dq_stack_peek(dq_stack_root *stack);

/*
 * Remove an element from the stack and return its element.
 * Stacks are First In Last Out, so the item removed is the last item
 * added.
 * Complexity: O(1).
 */
void * dq_stack_pop(dq_stack_root *stack);

/*
 * Destroy the stack and its elements, if have any. If destroy function is provided,
 * it will be used, otherwise, uses free.
 * Complexity: O(n).
 */
void dq_stack_destroy(dq_stack_root *stack);

int dq_stack_size(dq_stack_root *stack);

#endif
