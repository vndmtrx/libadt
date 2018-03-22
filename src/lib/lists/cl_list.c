#include <cl_list.h>

#include <stdio.h>
#include <stdlib.h>

struct _list_node {
	list_node *prev;	// Pointer to prev list_node element.
	list_node *next;	// Pointer to next list_node element.
	void *data;			// Pointer to the element added on the list.
};

list_node * cl_list_next(list_node *current) {
	if (current != NULL) {
		return current->next;
	} else {
		return NULL;
	}
}

list_node * cl_list_prev(list_node *current) {
	if (current != NULL) {
		return current->prev;
	} else {
		return NULL;
	}
}

void * cl_list_get_data(list_node *current) {
	if (current != NULL) {
		return current->data;
	} else {
		return NULL;
	}
}

cl_list_root * cl_list_create(t_destroyfunc destroyfunc, enum list_insert_el_mode mode) {
	cl_list_root *list = (cl_list_root *) malloc(sizeof(cl_list_root));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroyfunc = destroyfunc;
	list->mode = mode;
	return list;
}

int cl_list_insert_el_next(cl_list_root *list, list_node *current, void *data) {
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
		new->next = new;
		new->prev = new;
	} else {
		if (current == NULL) {
			new->next = list->head->next;
			new->prev = list->head;
			list->head->next->prev = new;
			list->head->next = new;
			list->head = new;
		} else { // Insert after the current element (current->next points to new element)
			new->next = current->next;
			new->prev = current;
			current->next->prev = new;
			current->next = new;
		}
	}
	list->size++;
	return 0;
}

int cl_list_insert_el_prev(cl_list_root *list, list_node *current, void *data) {
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
		new->next = new;
		new->prev = new;
	} else {
		if (current == NULL) {
			new->prev = list->head->prev;
			new->next = list->head;
			list->head->prev->next = new;
			list->head->prev = new;
			list->head = new;
		} else { // Insert before the current element (current->prev points to new element)
			new->prev = current->prev;
			new->next = current;
			current->prev->next = new;
			current->prev = new;
		}
	}
	list->size++;
	return 0;
}

int cl_list_move_el_next(cl_list_root *list, list_node *current, list_node *newpos) {
	if (list_size(list) > 1) {
		if (current != NULL && newpos != NULL) {
			current->next->prev = current->prev;
			current->prev->next = current->next;

			current->next = newpos->next;
			newpos->next->prev = current;

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

int cl_list_move_el_prev(cl_list_root *list, list_node *current, list_node *newpos) {
	if (list_size(list) > 1) {
		if (current != NULL && newpos != NULL) {
			current->prev->next = current->next;
			current->next->prev = current->prev;

			current->prev = newpos->prev;
			newpos->prev->next = current;

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

int cl_list_swap_el(cl_list_root *list, list_node *el1, list_node *el2) {
	if (el1 != NULL && el2 != NULL) {
		list_node *p_el1, *n_el2;

		p_el1 = el1->prev;
		n_el2 = el2->next;

		cl_list_move_el_prev(list, el1, n_el2);
		cl_list_move_el_next(list, el2, p_el1);

		return 0;
	} else {
		fprintf(stderr, "One of the elements is NULL. Can't swap.");
		return -1;
	}
}

void * cl_list_rem_el(cl_list_root *list, list_node *current) {
	void *data;
	if (current != NULL) {
		if (list_size(list) > 1) { // More than two elements on list;
			current->prev->next = current->next;
			current->next->prev = current->prev;
		} else if (list_size(list) == 1) { // Only one element on list;
			list->head = NULL;
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

void cl_list_destroy(cl_list_root **list) {
	if (list != NULL) {
		void *data;
		while (list_size(*list) > 0) {
			data = cl_list_rem_el(*list, (*list)->head);
			if ((*list)->destroyfunc != NULL) {
				(*list)->destroyfunc(data);
			} else {
				free(data);
			}
		}
		free(*list);
		*list = NULL;
	}
}
