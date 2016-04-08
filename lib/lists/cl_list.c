#include <cl_list.h>

#include <stdio.h>
#include <stdlib.h>

cl_list_root * cl_list_create(t_destroyfunc destroyfunc) {
	cl_list_root *list = (cl_list_root *) malloc(sizeof(cl_list_root));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroyfunc = destroyfunc;
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
			new->next = list->head;
			new->prev = list->head->prev;
			list->head->prev = new;
			list->head = new;
		} else {
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
			new->prev = list->head;
			new->next = list->head->next;
			list->head->next = new;
			list->head = new;
		} else {
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
	
	return 0;
}

int cl_list_move_el_prev(cl_list_root *list, list_node *current, list_node *newpos) {
	
	return 0;
}

int cl_list_swap_el(cl_list_root *list, list_node *el1, list_node *el2) {
	
	return 0;
}

void * cl_list_rem_el(cl_list_root *list) {
	
	return NULL;
}

void cl_list_destroy(cl_list_root *list) {
	void *data;
	while (list_size(list) > 0) {
		data = cl_list_rem_el(list);
		if (list->destroyfunc != NULL) {
			list->destroyfunc(data);
		}
	}
	free(list);
}
