#ifndef _LIBADT_CL_LIST_H
#define _LIBADT_CL_LIST_H

#include <adt_commons.h>

typedef list_root cl_list_root;

struct _list_node {
	list_node *prev;	// Pointer to prev list_node element.
	list_node *next;	// Pointer to next list_node element.
	void *data;			// Pointer to the element added on the list.
};

/*
 * Create a empty list structure and set a destroy function for its elements.
 * The destroy argument gives a way to free the entire structure when we
 * call cl_list_destroy. For malloc/calloc data, free must be used. If data
 * is a struct with other members, a function designed to free its memory
 * must be provided. If the data is static or have another way to free its
 * memory, NULL must be set.
 * Complexity: O(1).
 */
cl_list_root * cl_list_create(t_destroyfunc destroyfunc, enum list_insert_el_mode mode);

/*
 * Insert an element in the list after the current element indicated.
 * If *current is NULL, the new element is set as head.
 * Complexity: O(1).
 */
int cl_list_insert_el_next(cl_list_root *list, list_node *current, void *data);

/*
 * Insert an element in the list before the current element indicated.
 * If *current is NULL, the new element is set as head.
 * Complexity: O(1).
 */
int cl_list_insert_el_prev(cl_list_root *list, list_node *current, void *data);

/*
 * Move an element after the newpos element indicated.
 * Complexity: O(1).
 */
int cl_list_move_el_next(cl_list_root *list, list_node *current, list_node *newpos);

/*
 * Move an element before the newpos element indicated.
 * Complexity: O(1).
 */
int cl_list_move_el_prev(cl_list_root *list, list_node *current, list_node *newpos);

/*
 * Change positions of the two elements on the list.
 * Complexity: O(1).
 */
int cl_list_swap_el(cl_list_root *list, list_node *el1, list_node *el2);

/*
 * Remove the element in the head and save the respective data in **data.
 * Compĺexity: O(1).
 */
void * cl_list_rem_el(cl_list_root *list, list_node *current);

/*
 * Destroy the list and its elements, if have any. If destroy function is provided,
 * it will be used.
 * Complexity: O(n).
 */
void cl_list_destroy(cl_list_root *list);

#endif
