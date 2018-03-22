#ifndef _LIBADT_SL_LIST_H
#define _LIBADT_SL_LIST_H

#include <list_commons.h>

typedef list_root sl_list_root;

/*
 * Get the next element of the list based on current element.
 * If the current is NULL, return NULL instead.
 * Complexity: O(1).
 */
list_node * sl_list_next(list_node *current);

/*
 * Get the data from the current element.
 * If the current is NULL, return NULL instead.
 * Complexity: O(1).
 */
void * sl_list_get_data(list_node *current);

/*
 * Create a empty list structure and set a destroy function for its elements.
 * The destroy argument gives a way to free the entire structure when we
 * call sl_list_destroy. For malloc/calloc data, free must be used. If data
 * is a struct with other members, a function designed to free its memory
 * must be provided. If the data is static or have another way to free its
 * memory, NULL must be set.
 * Complexity: O(1).
 */
sl_list_root * sl_list_create(t_destroyfunc destroyfunc, enum list_insert_el_mode mode);

/*
 * Change the list default behavior for insert itens without pass a node
 * as reference.
 * Complexity: O(1).
 */
int sl_change_insert_behaviour(sl_list_root *list, enum list_insert_el_mode mode);

/*
 * Insert an element in the list after the current element indicated.
 * If *current is NULL, *data is appended on the head.
 * Complexity: O(1).
 */
int sl_list_insert_el_next(sl_list_root *list, list_node *current, void *data);

/*
 * Move an element after the position of newpos element.
 * Complexity: O(n).
 */
int sl_list_move_el_next(sl_list_root *list, list_node *current, list_node *newpos);

/*
 * Change positions of the two elements on the list.
 * Complexity: O(n).
 */
int sl_list_swap_el(sl_list_root *list, list_node *el1, list_node *el2);

/*
 * Remove the element indicated by *current and save the respective
 * data in **data.
 * Compĺexity: O(n).
 */
void * sl_list_rem_el(sl_list_root *list, list_node *current);

/*
 * Destroy the list and its elements, if have any. If destroy function is provided,
 * it will be used, otherwise, uses free.
 * Complexity: O(n).
 */
void sl_list_destroy(sl_list_root **list);

#endif
