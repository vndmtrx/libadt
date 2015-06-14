#ifndef _LIBADT_SLIST_H
#define _LIBADT_SLIST_H

typedef struct _slist_root slist_root;

typedef struct _slist_node slist_node;

typedef void (*t_destroyfunc)(void *data);

struct _slist_root {
	int size;			// Size of the list structure.
	t_destroyfunc destroyfunc;
	slist_node *head;	// Position from where we start walking the list.
	slist_node *tail;	// Last item on the list.
};

struct _slist_node {
	slist_node *next;	// Pointer to next slist_node element.
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
void slist_create(slist_root *list, t_destroyfunc destroyfunc);

/*
 * Insert an element in the list after the current element indicated.
 * If *current is NULL, *data is not appended.
 * Complexity: O(1).
 */
int slist_insert_el(slist_root *list, slist_node *current, void *data);

/*
 * Remove the element indicated by *current and save the respective 
 * data in **data.
 * Compĺexity: O(n).
 */
int slist_rem_el(slist_root *list, slist_node *current, void **data);

/*
 * Destroy the list and the elements in it. If destroy function is provided,
 * it will be used, otherwise, uses free.
 */
void slist_destroy(slist_root *list);

/*
 *  Returns the first element of the list.
 */
#define slist_head(list) ((list) ->head)

/*
 * Returns the last element of the list.
 */
#define slist_tail(list) ((list) ->tail)

/*
 * Returns the size of the list.
 */
#define slist_size(list) ((list) ->size)

/*
 * Test if element is actually the head of the list.
 */
#define slist_is_el_head(list, element) ((((element) ->root == (list)) && ((element) == (list) ->head)) ? 1 : 0)

/*
 * Test if element is actually the tail of the list.
 */
#define slist_is_el_tail(list, element) ((((element) ->root == (list)) && ((element) ->next == NULL)) ? 1 : 0)

#endif
