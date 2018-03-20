#include <dl_list.h>

#include <stdio.h>
#include <stdlib.h>

struct _list_node {
	list_node *prev;	// Pointer to prev list_node element.
	list_node *next;	// Pointer to next list_node element.
	void *data;			// Pointer to the element added on the list.
};

list_node * dl_list_next(list_node *current) {
	if (current != NULL) {
		return current->next;
	} else {
		return NULL;
	}
}

list_node * dl_list_prev(list_node *current) {
	if (current != NULL) {
		return current->prev;
	} else {
		return NULL;
	}
}

void * dl_list_get_data(list_node *current) {
	if (current != NULL) {
		return current->data;
	} else {
		return NULL;
	}
}

dl_list_root * dl_list_create(t_destroyfunc destroyfunc, enum list_insert_el_mode mode) {
	dl_list_root *list = (dl_list_root *) malloc(sizeof(dl_list_root));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroyfunc = destroyfunc;
	list->mode = mode;
	return list;
}

int dl_change_insert_behaviour(dl_list_root *list, enum list_insert_el_mode mode) {
	if (list_size(list) > 0) {
		fprintf(stderr, "List behavior can only be changed on a empty list.");
		return -1;
	} else {
		list->mode = mode;
		return 0;
	}
}

int dl_list_insert_el_next(dl_list_root *list, list_node *current, void *data) {
	list_node *new = (list_node *) malloc(sizeof(list_node));
	if (new == NULL) {
		fprintf(stderr, "Can't create new element.");
		return -1;
	}
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	if (list_size(list) == 0) {
		list->head = new;
		list->tail = new;
	} else {
		if (current == NULL) {
			if (list->mode == HEAD) { //Insert on head
				list->head->prev = new;
				new->next = list->head;
				list->head = new;
			} else {  //Insert on tail
				list->tail->next = new;
				new->prev = list->tail;
				list->tail = new;
			}
		} else { // Insert after the current element (current->next points to new element)
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

int dl_list_insert_el_prev(dl_list_root *list, list_node *current, void *data) {
	list_node *new = (list_node *) malloc(sizeof(list_node));
	if (new == NULL) {
		fprintf(stderr, "Can't create new element.");
		return -1;
	}
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	if (list_size(list) == 0) {
		list->head = new;
		list->tail = new;
	} else {
		if (current == NULL) {
			if (list->mode == TAIL) {  //Insert on tail
				list->tail->next = new;
				new->prev = list->tail;
				list->tail = new;
			} else { //Insert on head
				list->head->prev = new;
				new->next = list->head;
				list->head = new;
			}
		} else { // Insert before the current element (current->prev points to new element)
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

int dl_list_move_el_next(dl_list_root *list, list_node *current, list_node *newpos) {
	if (list_size(list) > 1) {
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
			fprintf(stderr, "One of the elements is NULL. Can't swap.");
			return -1;
		}
	} else {
		fprintf(stderr, "No enough elements to move.");
		return -1;
	}
}

int dl_list_move_el_prev(dl_list_root *list, list_node *current, list_node *newpos) {
	if (list_size(list) > 1) {
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
			fprintf(stderr, "One of the elements is NULL. Can't swap.");
			return -1;
		}
	} else {
		fprintf(stderr, "No enough elements to move.");
		return -1;
	}
}

int dl_list_swap_el(dl_list_root *list, list_node *el1, list_node *el2) {
	if (el1 != NULL && el2 != NULL) {
		list_node *p_el1, *n_el1, *p_el2, *n_el2;

		p_el1 = el1->prev;
		n_el1 = el1->next;
		p_el2 = el2->prev;
		n_el2 = el2->next;

		if (el2 != list->head) {
			dl_list_move_el_next(list, el1, p_el2);
		} else {
			dl_list_move_el_prev(list, el1, n_el2);
		}

		if (el1 != list->tail) {
			dl_list_move_el_prev(list, el2, n_el1);
		} else {
			dl_list_move_el_next(list, el2, p_el1);
		}

		return 0;
	} else {
		fprintf(stderr, "One of the elements is NULL. Can't swap.");
		return -1;
	}
}

void * dl_list_rem_el(dl_list_root *list, list_node *current) {
	void *data;
	if (current != NULL) {
		if (list_size(list) > 1) { // More than two elements on list;
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
		} else if (list_size(list) == 1) { // Only one element on list;
			list->head = NULL;
			list->tail = NULL;
		} else { // No elements on list;
			fprintf(stderr, "List is empty.");
			return NULL;
		}

		data = current->data;
		free(current);
		list->size--;

		return data;
	} else { // Why remove an item that does not exist?
		fprintf(stderr, "No element to remove.");
		return NULL;
	}
}

void dl_list_destroy(dl_list_root *list) {
	void *data;
	while (list_size(list) > 0) {
		data = dl_list_rem_el(list, list->head);
		if (list->destroyfunc != NULL) {
			list->destroyfunc(data);
		} else {
			free(data);
		}
	}
	free(list);
}
