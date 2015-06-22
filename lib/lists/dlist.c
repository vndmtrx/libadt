#include <stdio.h>
#include <stdlib.h>

#include <dlist.h>

/* 
 * Create a empty list structure, set a destroy function for its elements.
 * The destroy argument gives a way to free the entire structure when we
 * call dlist_destroy. For malloc/calloc data, free must be used. If data
 * is a struct with other members, a function designed to free its memory
 * must be provided. If the data is static or have another way to free its
 * memory, NULL must be set.
 * Complexity: O(1).
 */
void dlist_create(dlist_root *list, t_destroyfunc destroyfunc) {
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
int dlist_insert_el_next(dlist_root *list, dlist_node *current, void *data) {
	dlist_node *new = (dlist_node *) malloc(sizeof(dlist_node));
	if (new == NULL) {
		perror("Can't create new element.");
		return -1;
	}
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	if (list->size == 0) {
		list->head = new;
		list->tail = new;
	} else {
		if (current == NULL) {
			new->next = list->head;
			list->head->prev = new;
			list->head = new;
		} else {
			new->prev = current;
			new->next = current->next;
			if (current == list->tail) {
				list->tail = new;
			} else {
				current->next->prev = new;
			}
			current->next = new;
		}
	}
	list->size++;
	return 0;
}

/*
 * Insert an element in the list before the current element indicated.
 * If *current is NULL, *data is appended on the tail.
 * Complexity: O(1).
 */
int dlist_insert_el_prev(dlist_root *list, dlist_node *current, void *data) {
	dlist_node *new = (dlist_node *) malloc(sizeof(dlist_node));
	if (new == NULL) {
		perror("Can't create new element.");
		return -1;
	}
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	if (list->size == 0) {
		list->head = new;
		list->tail = new;
	} else {
		if (current == NULL) {
			new->prev = list->tail;
			list->tail->next = new;
			list->tail = new;
		} else {
			new->next = current;
			new->prev = current->prev;
			if (current == list->head) {
				list->head = new;
			} else {
				current->prev->next = new;
			}
			current->prev = new;
		}
	}
	list->size++;
	return 0;
}

/*
 * Move an element after the newpos element indicated.
 * Complexity: O(1).
 */
int dlist_move_el_next(dlist_root *list, dlist_node *current, dlist_node *newpos) {
	if (dlist_size(list) > 1) {
		if (current != NULL && newpos != NULL) {
			if (current == list->head) {
				current->next->prev = NULL;
				list->head = current->next;
			} else if (current == list->tail) {
				current->prev->next = NULL;
				list->tail = current->prev;
			} else {
				current->next->prev = current->prev;
				current->prev->next = current->next;
			}
			
			if (newpos == list->tail) {
				current->next = NULL;
				list->tail = current;
			} else {
				current->next = newpos->next;
				newpos->next->prev = current;
			}
			
			current->prev = newpos;
			newpos->next = current;
			
			return 0;
		} else {
			perror("One of the elements is NULL. Can't swap.");
			return -1;
		}
	} else {
		perror("No enough elements to move.");
		return -1;
	}
}

/*
 * Move an element before the newpos element indicated.
 * Complexity: O(1).
 */
int dlist_move_el_prev(dlist_root *list, dlist_node *current, dlist_node *newpos) {
	if (dlist_size(list) > 1) {
		if (current != NULL && newpos != NULL) {
			if (current == list->tail) {
				current->prev->next = NULL;
				list->tail = current->prev;
			} else if (current == list->head) {
				current->next->prev = NULL;
				list->head = current->next;
			} else {
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}
			
			if (newpos == list->head) {
				current->prev = NULL;
				list->head = current;
			} else {
				current->prev = newpos->prev;
				newpos->prev->next = current;
			}
			
			current->next = newpos;
			newpos->prev = current;
			
			return 0;
		} else {
			perror("One of the elements is NULL. Can't swap.");
			return -1;
		}
	} else {
		perror("No enough elements to move.");
		return -1;
	}
}

/*
 * Change positions of the two elements on the list.
 * Complexity: O(1).
 */
int dlist_swap_el(dlist_root *list, dlist_node *el1, dlist_node *el2);

/*
 * Remove the element indicated by *current and save the respective 
 * data in **data.
 * Compĺexity: O(1).
 */
int dlist_rem_el(dlist_root *list, dlist_node *current, void **data) {
	if (current != NULL) {
		if (dlist_size(list) > 1) { // More than two elements on list;
			if (current == list->head) {
				current->next->prev = NULL;
				list->head = current->next;
			} else if (current == list->tail) {
				current->prev->next = NULL;
				list->tail = current->prev;
			} else {
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}
		} else if (dlist_size(list) == 1) { // Only one element on list;
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
 * Complexity: O(n).
 */
void dlist_destroy(dlist_root *list) {
	void *data;
	while (dlist_size(list) > 0) {
		dlist_rem_el(list, list->head, &data);
		if (list->destroyfunc != NULL) {
			list->destroyfunc(data);
		}
	}
}
