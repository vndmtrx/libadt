#include <cl_iterator.h>

#include <cl_list.h>

#include <stdio.h>
#include <stdlib.h>

struct _list_node {
	list_node *prev;	// Pointer to prev list_node element.
	list_node *next;	// Pointer to next list_node element.
	void *data;			// Pointer to the element added on the list.
};

struct iterator_c {
	list_node *current;
	cl_iter_direction flow;
};

iterator_c * cl_iter_create(list_root *list, cl_iter_direction c) {
	iterator_c *iter = NULL;
	if (list->head != NULL) {
		iter = (iterator_c *) malloc(sizeof(iterator_c));
		iter->flow = c;
		switch (iter->flow) {
			case FORWARD:
			case BACKWARD: iter->current = list->head; break;
			default: free(iter); return NULL;
		}
	}
	return iter;
}

int cl_iter_next(iterator_c *iter) {
	if (iter != NULL) {
		if (iter->current != NULL) {
			switch (iter->flow) {
				case FORWARD: iter->current = iter->current->next; break;
				case BACKWARD: iter->current = iter->current->prev; break;
				default: return 0;
			}
		}
		return (iter->current != NULL);
	}
	return 0;
}

void * cl_iter_item(iterator_c *iter) {
	if (iter != NULL) {
		if (iter->current != NULL) {
			return iter->current->data;
		}
	}
	return NULL;
}

void cl_iter_free(iterator_c *iter) {
	if (iter != NULL) {
		iter->current = NULL;
		free(iter);
	}
}
