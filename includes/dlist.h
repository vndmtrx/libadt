#ifndef _LIBADT_DLIST_H
#define _LIBADT_DLIST_H

#include <adt_commons.h>

#include <list.h>

typedef list_root dlist_root;

struct _list_node {
	list_node *prev;	// Pointer to prev list_node element.
	list_node *next;	// Pointer to next list_node element.
	void *data;			// Pointer to the element added on the list.
};


/* 
 * Create a empty list structure and set a destroy function for its elements.
 * The destroy argument gives a way to free the entire structure when we
 * call dlist_destroy. For malloc/calloc data, free must be used. If data
 * is a struct with other members, a function designed to free its memory
 * must be provided. If the data is static or have another way to free its
 * memory, NULL must be set.
 * Complexity: O(1).
 */
dlist_root * dlist_create(t_destroyfunc destroyfunc);

/*
 * Insert an element in the list after the current element indicated.
 * If *current is NULL, *data is appended on the head.
 * Complexity: O(1).
 */
int dlist_insert_el_next(dlist_root *list, list_node *current, void *data);

/*
 * Insert an element in the list before the current element indicated.
 * If *current is NULL, *data is appended on the tail.
 * Complexity: O(1).
 */
int dlist_insert_el_prev(dlist_root *list, list_node *current, void *data);

/*
 * Move an element after the newpos element indicated.
 * Complexity: O(1).
 */
int dlist_move_el_next(dlist_root *list, list_node *current, list_node *newpos);

/*
 * Move an element before the newpos element indicated.
 * Complexity: O(1).
 */
int dlist_move_el_prev(dlist_root *list, list_node *current, list_node *newpos);

/*
 * Change positions of the two elements on the list.
 * Complexity: O(1).
 */
int dlist_swap_el(dlist_root *list, list_node *el1, list_node *el2);

/*
 * Remove the element indicated by *current and save the respective 
 * data in **data.
 * Compĺexity: O(1).
 */
void * dlist_rem_el(dlist_root *list, list_node *current);

/*
 * Destroy the list and its elements, if have any. If destroy function is provided,
 * it will be used.
 * Complexity: O(n).
 */
void dlist_destroy(dlist_root *list);

#endif
