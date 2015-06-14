#include <stdio.h>
#include <stdlib.h>

#include <slist.h>

/* 
 * Create a empty list structure, set a destroy function for its elements.
 * The destroy argument gives a way to free the entire structure when we
 * call slist_destroy. For malloc/calloc data, free must be used. If data
 * is a struct with other members, a function designed to free its memory
 * can be provided. If the data is static or have another way to free its
 * memory outside, NULL must be set.
 * Complexity: O(1).
 */
void slist_create(slist_root *list, void (destroyfunc)(void *element)) {
	list->size = 0;
	list->head = NULL;
	list->destroyfunc = destroyfunc;
}

/*
 * Insert an element in the list after the current element indicated.
 * If *current is NULL, *data is appended on the head.
 * Complexity: O(1).
 */
int slist_insert_el(slist_root *list, slist_node *current,  void *data) {
	slist_node *newelement;
	newelement = (slist_node *) malloc(sizeof(slist_node));
	if (newelement == NULL) {
		perror("Can't create new element.");
		return -1;
	}
	newelement->data = data;
	newelement->root = list;
	newelement->next = NULL;
	if (current == NULL) {
		if (list->head != NULL) {
			newelement->next = list->head;
		}
		list->head = newelement;
	} else {
		if (current->root == list) {
			if (current->next != NULL) {
				newelement->next = slist_el_next(current);
			}
			current->next = newelement;
		} else {
			free(newelement);
			perror("The 'current' element doesn't belong to 'list'.");
			return -2;
		}
	}
	list->size++;
	return 0;
}

/*
 * Remove the element indicated by *current and save the respective 
 * data in **data.
 * Compĺexity: O(n).
 */
int slist_rem_el(slist_root *list, slist_node *current, void **data) {
	slist_node *node;
	if (current->root == list) {
		if (current == list->head) {
			list->head = slist_el_next(current);
		} else {
			node = list->head;
			while (slist_el_next(node) != current) {
				node = slist_el_next(node);
			}
			node->next = slist_el_next(current);
		}
		*data = &slist_el_data(current);
		free(current);
	} else {
		perror("The 'current' element doesn't belong to 'list'.");
		return -2;
	}
	list->size--;
	return 0;
}