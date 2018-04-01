#include <sl_list.h>

#include <stdio.h>
#include <stdlib.h>

struct _list_node {
	list_node *next;	// Pointer to next list_node element.
	void *data;			// Pointer to the element added on the list.
};

static list_node * sl_list_find_prior(sl_list_root *list, list_node *current) {
	if (current != NULL) {
		list_node *node = list->head;

		if (node != current) {
			while (node->next != current) {
				node = node->next;
			}
		} else {
			node = NULL;
		}

		return node;
	} else {
		fprintf(stderr, "No prior element to find. Current doesn't exist.");
		return NULL;
	}
}

list_node * sl_list_next(list_node *current) {
	if (current != NULL) {
		return current->next;
	} else {
		return NULL;
	}
}

list_node * sl_list_get_el_by_index(sl_list_root *list, int index) {
	if (list == NULL) {fprintf(stderr, "List doesn't exist."); return NULL;}
	if (index >= list->size || index < 0) {fprintf(stderr, "Index out of range."); return NULL;}

	list_node * el = list->head;
	for (int i = 0; i < list->size; i++) {
		if (i == index) break;
		el = sl_list_next(el);
	}
	return el;
}

void * sl_list_get_data(list_node *current) {
	if (current != NULL) {
		return current->data;
	} else {
		return NULL;
	}
}

sl_list_root * sl_list_create(t_destroyfunc destroyfunc, enum list_insert_el_mode mode) {
	sl_list_root *list = (sl_list_root *) malloc(sizeof(sl_list_root));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroyfunc = destroyfunc;
	list->mode = mode;
	return list;
}

int sl_change_insert_behaviour(sl_list_root *list, enum list_insert_el_mode mode) {
	if (list_size(list) > 0) {
		fprintf(stderr, "List behavior can only be changed on a empty list.");
		return -1;
	} else {
		list->mode = mode;
		return 0;
	}
}

int sl_list_insert_el_next(sl_list_root *list, list_node *current,  void *data) {
	if (data == NULL)  { fprintf(stderr, "Data is NULL."); return -1; }
	list_node *new = (list_node *) malloc(sizeof(list_node));
	if (new == NULL) {
		fprintf(stderr, "Can't create new element.");
		return -1;
	}
	new->data = data;
	new->next = NULL;
	if (list_size(list) == 0) {
		list->head = new;
		list->tail = new;
	} else {
		if (current == NULL) {
			if (list->mode == HEAD) { //Insert on head
				new->next = list->head;
				list->head = new;
			} else { //Insert on tail
				list->tail->next = new;
				list->tail = new;
			}
		} else { // Insert after the current element (current->next points to new element)
			if (current == list->tail) {
				list->tail = new;
			}
			new->next = current->next;
			current->next = new;
		}
	}
	list->size++;
	return 0;
}

int sl_list_move_el_next(sl_list_root *list, list_node *current, list_node *newpos) {
	if (list_size(list) <= 1) { fprintf(stderr, "No enough elements to move."); return -1; }
	if (current == NULL)  { fprintf(stderr, "Current element is NULL. Can't move."); return -1; }
	if (current == newpos) { fprintf(stderr, "Current and newpos are the same. Can't move."); return -1; }

	list_node *p1;
	if (current == list->head) {
		list->head = current->next;
	} else {
		p1 = sl_list_find_prior(list, current);
		if (newpos == p1) { fprintf(stderr, "Current is already the next item."); return -1; }

		p1->next = current->next;
		if (current == list->tail) {
			list->tail = p1;
			list->tail->next = NULL;
		}
	}

	if (newpos != NULL) {
		if (newpos == list->tail) {
			current->next = NULL;
			list->tail = current;
		} else {
			current->next = newpos->next;
		}
		newpos->next = current;
	} else {
		current->next = list->head;
		list->head = current;
	}
	return 0;
}

int sl_list_swap_el(sl_list_root *list, list_node *el1, list_node *el2) {
	if (el1 != NULL && el2 != NULL) {
		list_node *p1, *p2, *n1, *n2;
		if (el1 != list->head && el2 != list->head) {
			p1 = sl_list_find_prior(list, el1);
			p2 = sl_list_find_prior(list, el2);
			p1->next = el2;
			p2->next = el1;
		} else {
			if (el1 == list->head) {
				p2 = sl_list_find_prior(list, el2);
				p2->next = el1;
				list->head = el2;
			} else if (el2 == list->head) {
				p1 = sl_list_find_prior(list, el1);
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
		fprintf(stderr, "One of the elements is NULL. Can't swap.");
		return -1;
	}
}

void * sl_list_rem_el(sl_list_root *list, list_node *current) {
	void *data;
	if (current != NULL) {
		if (list_size(list) > 1) { // More than two elements on list;
			if (current == list->head) {
				list->head = current->next;
			} else {
				list_node *node = sl_list_find_prior(list, current);
				if (node == NULL) {
					return NULL;
				}

				if (current == list->tail) {
					node->next = NULL;
					list->tail = node;
				} else {
					node->next = current->next;
				}
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

void sl_list_destroy(sl_list_root **list) {
	if (list != NULL) {
		void *data;
		while (list_size(*list) > 0) {
			data = sl_list_rem_el(*list, (*list)->head);
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
