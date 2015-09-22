#include <dl_iterator.h>

#include <dlist.h>

#include <stdio.h>
#include <stdlib.h>

struct iterator_s {
	list_node *current;
	dl_iter_direction flow;
};

iterator_s * dl_iter_create(list_root *list, dl_iter_direction d) {
	iterator_s *iter = NULL;
	if (list->head != NULL) {
		iter = (iterator_s *) malloc(sizeof(iterator_s));
		iter->flow = d;
		switch (iter->flow) {
			case FORWARD: iter->current = list->head; break;
			case BACKWARD: iter->current = list->tail; break;
			default: free(iter); return NULL;
		}
	}
	return iter;
}

int dl_iter_hasnext(iterator_s *iter) {
	if (iter != NULL) {
		switch (iter->flow) {
			case FORWARD: return (iter->current->next != NULL); break;
			case BACKWARD: return (iter->current->prev != NULL); break;
			default: return 0;
		}
	} else {
		return 0;
	}
}

int dl_iter_next(iterator_s *iter) {
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

void * dl_iter_item(iterator_s *iter) {
	if (iter != NULL) {
		if (iter->current != NULL) {
			return iter->current->data;
		}
	}
	return NULL;
}

void dl_iter_free(iterator_s *iter) {
	iter->current = NULL;
	free(iter);
}
