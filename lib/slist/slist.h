#ifndef _LIBADT_SLIST_H
#define _LIBADT_SLIST_H

typedef struct _slist_root slist_root;

typedef struct _slist_node slist_node;


/* 
 * Create a empty list structure, set a destroy function for its elements
 * and return the new structure on first function parameter.
 * The destroy argument gives a way to free the entire structure when we
 * call slist_destroy. For malloc/calloc data, free must be used. If data
 * is a struct with other members, a function designed to free its memory
 * must be provided. If the data is static or have another way to free its
 * memory, NULL must be set.
 * Complexity: O(1).
 */
void slist_create(slist_root **list, void (destroy)(void *data));


/*
 * Insert an element in the list after the current element indicated.
 * If *current is NULL, *data is not appended.
 * Complexity: O(1).
 */
int slist_insert_el(slist_root *list, slist_node *current, const void *data);

/*
 * Remove the element indicated by *current and save the respective 
 * data in **data.
 */
int slist_rem_el(slist_root *list, slist_node *current, void **data);

/*
 * Returns the size of the list.
 */
int slist_size(slist_root *list);

/*
 *  Returns the first element of the list.
 */
int slist_head(slist_root *list);

/*
 * Returns the last element of the list.
 */
int slist_tail(slist_root *list);

/*
 * Destroy the list and the elements in it. If destroy function is provided,
 * it will be used, otherwise, uses free.
 */
void slist_destroy(slist_root **list);

/*
 * Test if element is actually the head of the list.
 */
#define slist_el_is_head(list, element) ((((element)->root == (list)) && ((element) == (list)->head)) ? 1 : 0)

/*
 * Test if element is actually the tail of the list.
 */
#define slist_el_is_tail(list, element) ((((element)->root == (list)) && ((element)->next == NULL)) ? 1 : 0)

/*
 * Return the data from the element.
 */
#define slist_el_data(element) ((element)->data)

/*
 * Return the next element on the list.
 */
#define slist_el_next(element) ((element)->next)

#endif
