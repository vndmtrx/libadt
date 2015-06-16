#ifndef _LIBADT_DLIST_H
#define _LIBADT_DLIST_H

typedef struct _dlist_root dlist_root;

typedef struct _dlist_node dlist_node;

typedef void (*t_destroyfunc)(void *data);

struct _dlist_root {
	int size;			// Size of the list structure.
	t_destroyfunc destroyfunc;
	dlist_node *head;	// Position from where we start walking the list.
	dlist_node *tail;	// Last item on the list.
};

struct _dlist_node {
	dlist_node *prev;	// Pointer to prev slist_node element.
	dlist_node *next;	// Pointer to next slist_node element.
	void *data;			// Pointer to the element added on the list.
};


/* 
 * Create a empty list structure, set a destroy function for its elements.
 * The destroy argument gives a way to free the entire structure when we
 * call slist_destroy. For malloc/calloc data, free must be used. If data
 * is a struct with other members, a function designed to free its memory
 * must be provided. If the data is static or have another way to free its
 * memory, NULL must be set.
 * Complexity: O(1).
 */
void dlist_create(dlist_root *list, t_destroyfunc destroyfunc);

/*
 * Insert an element in the list after the current element indicated.
 * If *current is NULL, *data is appended on the head.
 * Complexity: O(1).
 */
int dlist_insert_el_next(dlist_root *list, dlist_node *current, void *data);

/*
 * Insert an element in the list before the current element indicated.
 * If *current is NULL, *data is appended on the tail.
 * Complexity: O(1).
 */
int dlist_insert_el_prev(dlist_root *list, dlist_node *current, void *data);

/*
 * Move an element after the newpos element indicated.
 * Complexity: O(1).
 */
int slist_move_el_next(slist_root *list, slist_node *current, *slist_node newpos);

/*
 * Move an element before the newpos element indicated.
 * Complexity: O(1).
 */
int slist_move_el_prev(slist_root *list, slist_node *current, *slist_node newpos);

/*
 * Change positions of the two elements on the list.
 */
int dlist_swap_el(dlist_root *list, dlist_node *el1, dlist_node *el2);

/*
 * Remove the element indicated by *current and save the respective 
 * data in **data.
 * Compĺexity: O(n).
 */
int dlist_rem_el(dlist_root *list, dlist_node *current, void **data);

/*
 * Destroy the list and the elements in it. If destroy function is provided,
 * it will be used, otherwise, uses free.
 */
void dlist_destroy(dlist_root *list);

/*
 *  Returns the first element of the list.
 */
#define dlist_head(list) ((list) ->head)

/*
 * Returns the last element of the list.
 */
#define dlist_tail(list) ((list) ->tail)

/*
 * Returns the size of the list.
 */
#define dlist_size(list) ((list) ->size)

/*
 * Test if element is actually the head of the list.
 */
#define dlist_is_el_head(list, element) ((((element) ->root == (list)) && ((element) == (list) ->head)) ? 1 : 0)

/*
 * Test if element is actually the tail of the list.
 */
#define dlist_is_el_tail(list, element) ((((element) ->root == (list)) && ((element) == (list) ->tail)) ? 1 : 0)

#endif
