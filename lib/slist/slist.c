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
	new->root = list;
	new->next = NULL;
	if (list->size == 0) {
		list->head = new;
		list->tail = new;
	} else {
		if (current == NULL) {
			new->next = list->next;
			list->next = new;
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
 * Remove the element indicated by *current and save the respective 
 * data in **data.
 * Compĺexity: O(n).
 */
int slist_rem_el(slist_root *list, slist_node *current, void **data) {
	slist_node *node;
	if (list->size > 0) {
		if (current != NULL) {
			node = list->head;
			while (node->next != current) {
				if (node->next == NULL) {
					perror("Item is not on the list.");
					return -2;
				}
				node == node->next;
			}
			node->next = current->next;
			
			if (current == list->head) {
				list->head = current->next;
			}
			if (current == list->tail) {
				list->tail = node;
			}
			
			*data = &(current->data);
			free(current);
		} else {
			
		}
		list->size--;
	} else {
		perror("List is empty.");
		return -1;
	}
	return 0;
}

/*
 *  Returns the first element of the list.
 */
slist_node *slist_head(slist_root *list) {
	return list->head;
}

/*
 * Returns the last element of the list.
 */
slist_node *slist_tail(slist_root *list) {
	return list->tail;
}

/*
 * Destroy the list and the elements in it. If destroy function is provided,
 * it will be used.
 */
void slist_destroy(slist_root *list) {
	void *data;
	while (slist_size(list) > 0) {
		slist_rem_el(list, NULL, &data);
		if (list->destroyfunc != NULL) {
			list->destroyfunc(data);
		}
	}
}
