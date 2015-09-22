#include <sl_iterator.h>

#include <slist.h>

#include <stdio.h>
#include <stdlib.h>

struct iterator_s {
	list_node *current;
};

iterator_s * sl_iter_create(list_root *list) {
	iterator_s *iter = NULL;
	if (list->head != NULL) {
		iter = (iterator_s *) malloc(sizeof(iterator_s));
		iter->current = list->head;
	}
	return iter;
}

int sl_iter_hasnext(iterator_s *iter) {
	if (iter != NULL) {
		return (iter->current->next != NULL);
	} else {
		return 0;
	}
}

int sl_iter_next(iterator_s *iter) {
	if (iter != NULL) {
		if (iter->current != NULL) {
			iter->current = iter->current->next;
			return 1;
		}
	}
	return 0;
}

void * sl_iter_item(iterator_s *iter) {
	if (iter != NULL) {
		if (iter->current != NULL) {
			return iter->current->data;
		}
	}
	return NULL;
}

void sl_iter_free(iterator_s *iter) {
	iter->current = NULL;
	free(iter);
}
