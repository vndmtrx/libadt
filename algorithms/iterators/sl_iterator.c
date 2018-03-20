#include <sl_iterator.h>

#include <sl_list.h>

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
		return (sl_list_next(iter->current) != NULL);
	} else {
		return 0;
	}
}

int sl_iter_next(iterator_s *iter) {
	if (iter != NULL) {
		if (iter->current != NULL) {
			iter->current = sl_list_next(iter->current);
		}
		return (iter->current != NULL);
	}
	return 0;
}

void * sl_iter_item(iterator_s *iter) {
	if (iter != NULL) {
		return sl_list_get_data(iter->current);
	}
	return NULL;
}

void sl_iter_free(iterator_s *iter) {
	if (iter != NULL) {
		iter->current = NULL;
		free(iter);
	}
}
