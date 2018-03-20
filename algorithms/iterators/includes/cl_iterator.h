#ifndef _LIBADT_CL_ITERATOR_H
#define _LIBADT_CL_ITERATOR_H

#include <list_commons.h>

struct iterator_c;

enum cl_iter_direction {
	FORWARD,
	BACKWARD
};

typedef struct iterator_c iterator_c;

typedef enum cl_iter_direction cl_iter_direction;

iterator_c * cl_iter_create(list_root *list, cl_iter_direction c);

int cl_iter_next(iterator_c *iter);

void * cl_iter_item(iterator_c *iter);

void cl_iter_free(iterator_c *iter);

#endif
