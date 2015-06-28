#ifndef _LIBADT_SL_STACK_H
#define _LIBADT_SL_STACK_H

#include <slist.h>

typedef slist_root sl_stack_root;

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
void sl_stack_create(sl_stack_root *stack, t_destroyfunc destroyfunc);

/*
 * Insert an element in the stack.
 * Complexity: O(1).
 */
int sl_stack_push(sl_stack_root *stack, void *data);

/*
 * Look the top item of the stack without remove it.
 * Complexity: O(1).
 */
int sl_stack_peek(sl_stack_root *stack, void **data);

/*
 * Remove an element from the stack and return its element.
 * Stacks are First In Last Out, so the item removed is the last item
 * added.
 * Complexity: O(1).
 */
int sl_stack_pop(sl_stack_root *stack, void **data);

/*
 * Destroy the stack and the elements in it. If destroy function is provided,
 * it will be used, otherwise, uses free.
 * Complexity: O(n).
 */
void sl_stack_destroy(sl_stack_root *stack);

#define sl_stack_size(stack) ((stack) ->size)

#endif
