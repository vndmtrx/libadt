#ifndef _LIBADT_DL_ITERATOR_H
#define _LIBADT_DL_ITERATOR_H

#include <list.h>

struct iterator_d;

enum dl_iter_direction {
	FORWARD,
	BACKWARD
};

typedef struct iterator_d iterator_d;

typedef enum dl_iter_direction dl_iter_direction;

iterator_d * dl_iter_create(list_root *list, dl_iter_direction d);

int dl_iter_hasnext(iterator_d *iter);

int dl_iter_next(iterator_d *iter);

void * dl_iter_item(iterator_d *iter);

void dl_iter_free(iterator_d *iter);

#endif
