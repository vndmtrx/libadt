#ifndef _LIBADT_SLIST_H
#define _LIBADT_SLIST_H

#include <adt_commons.h>

#include <list.h>

typedef list_root slist_root;

struct _list_node {
	list_node *next;	// Pointer to next list_node element.
	void *data;			// Pointer to the element added on the list.
};


/* 
 * Create a empty list structure and set a destroy function for its elements.
 * The destroy argument gives a way to free the entire structure when we
 * call slist_destroy. For malloc/calloc data, free must be used. If data
 * is a struct with other members, a function designed to free its memory
 * must be provided. If the data is static or have another way to free its
 * memory, NULL must be set.
 * Complexity: O(1).
 */
slist_root * slist_create(t_destroyfunc destroyfunc);

/*
 * Insert an element in the list after the current element indicated.
 * If *current is NULL, *data is appended on the head.
 * Complexity: O(1).
 */
int slist_insert_el_next(slist_root *list, list_node *current, void *data);

/*
 * Move an element to the position of newpos element.
 * Complexity: O(n).
 */
int slist_move_el(slist_root *list, list_node *current, list_node *newpos);

/*
 * Change positions of the two elements on the list.
 * Complexity: O(n).
 */
int slist_swap_el(slist_root *list, list_node *el1, list_node *el2);

/*
 * Remove the element indicated by *current and save the respective 
 * data in **data.
 * Compĺexity: O(n).
 */
void * slist_rem_el(slist_root *list, list_node *current);

/*
 * Destroy the list and its elements, if have any. If destroy function is provided,
 * it will be used, otherwise, uses free.
 * Complexity: O(n).
 */
void slist_destroy(slist_root *list);

#endif
