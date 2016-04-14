#ifndef _LIBADT_DL_ITERATOR_H
#define _LIBADT_DL_ITERATOR_H

#include <list.h>

struct iterator_s;

enum dl_iter_direction {
	FORWARD,
	BACKWARD
};

typedef struct iterator_s iterator_s;

typedef enum dl_iter_direction dl_iter_direction;

iterator_s * dl_iter_create(list_root *list, dl_iter_direction d);

int dl_iter_hasnext(iterator_s *iter);

int dl_iter_next(iterator_s *iter);

void * dl_iter_item(iterator_s *iter);

void dl_iter_free(iterator_s *iter);

#endif
