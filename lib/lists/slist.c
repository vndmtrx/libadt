#include <stdio.h>
#include <stdlib.h>

#include <slist.h>

/*
 * Local function used to find the prior element of a item in the list.
 * Only usable on single linked lists by the lack of prior pointer.
 * Complexity: O(n)
 */
static slist_node *slist_find_prior(slist_root *list, slist_node *current) {
	if (current != NULL) {
		slist_node *node = list->head;
		
		if (node != current) {
			while (node->next != current) {
				node = node->next;
			}
		} else {
			node = NULL;
		}
		
		return node;
	} else {
		perror("No prior element to find. Current doesn't exist.");
		return NULL;
	}
}

/* 
 * Create a empty list structure, set a destroy function for its elements.
 * The destroy argument gives a way to free the entire structure when we
 * call slist_destroy. For malloc/calloc data, free must be used. If data
 * is a struct with other members, a function designed to free its memory
 * can be provided. If the data is static or have another way to free its
 * memory outside, NULL must be set.
 * Complexity: O(1).
 */
void slist_create(slist_root *list, t_destroyfunc destroyfunc) {
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroyfunc = destroyfunc;
}

/*
 * Insert an element in the list after the current element indicated.
 * If *current is NULL, *data is appended on the head.
 * Complexity: O(1).
 */
int slist_insert_el(slist_root *list, slist_node *current,  void *data) {
	slist_node *new = (slist_node *) malloc(sizeof(slist_node));
	if (new == NULL) {
		perror("Can't create new element.");
		return -1;
	}
	new->data = data;
	new->next = NULL;
	if (list->size == 0) {
		list->head = new;
		list->tail = new;
	} else {
		if (current == NULL) {
			new->next = list->head;
			list->head = new;
		} else {
			if (current->next != NULL) {
				new->next = current->next;
			} else {
				list->tail = new;
			}
			current->next = new;
		}
	}
	list->size++;
	return 0;
}

/*
 * Change positions of the two elements on the list.
 */
int slist_swap_el(slist_root *list, slist_node *el1, slist_node *el2) {
	if (el1 != NULL && el2 != NULL) {
		slist_node *p1, *p2, *n1, *n2;
		if (el1 != list->head && el2 != list->head) {
			p1 = slist_find_prior(list, el1);
			p2 = slist_find_prior(list, el2);
			p1->next = el2;
			p2->next = el1;
		} else {
			if (el1 == list->head) {
				p2 = slist_find_prior(list, el2);
				p2->next = el1;
				list->head = el2;
			} else if (el2 == list->head) {
				p1 = slist_find_prior(list, el1);
				p1->next = el2;
				list->head = el1;
			}
		}
		
		n1 = el1->next;
		n2 = el2->next;
		
		el1->next = n2;
		el2->next = n1;
		
		if (el1 == list->tail || el2 == list->tail)
			list->tail = (el1 == list->tail ? el2 : el1);
		
		return 0;
	} else {
		perror("One of the elements is NULL. Can't swap.");
		return -1;
	}
}

/*
 * Remove the element indicated by *current and save the respective 
 * data in **data.
 * Compĺexity: O(n).
 */
int slist_rem_el(slist_root *list, slist_node *current, void **data) {
	if (current != NULL) {
		if (slist_size(list) > 1) { // More than two elements on list;
			if (current == list->head) {
				list->head = current->next;
			} else {
				slist_node *node = slist_find_prior(list, current);
				if (node == NULL) {
					return -1;
				}
				
				if (current == list->tail) {
					node->next = NULL;
					list->tail = node;
				} else {
					node->next = current->next;
				}
			}
		} else if (slist_size(list) == 1) { // Only one element on list;
			list->head = NULL;
			list->tail = NULL;
		} else { // No elements on list;
			perror("List is empty.");
			return -1;
		}
		
		*data = current->data;
		free(current);
		list->size--;
	} else { // Why remove an item that does not exist?
			perror("No element to remove.");
			return -1;
	}
	return 0;
}

/*
 * Destroy the list and the elements in it. If destroy function is provided,
 * it will be used.
 */
void slist_destroy(slist_root *list) {
	void *data;
	while (slist_size(list) > 0) {
		slist_rem_el(list, list->head, &data);
		if (list->destroyfunc != NULL) {
			list->destroyfunc(data);
		}
	}
}
