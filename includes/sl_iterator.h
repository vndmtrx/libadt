#ifndef _LIBADT_SL_ITERATOR_H
#define _LIBADT_SL_ITERATOR_H

#include <list.h>

struct iterator_s;

typedef struct iterator_s iterator_s;

iterator_s * sl_iter_create(list_root *list);

int sl_iter_hasnext(iterator_s *iter);

int sl_iter_next(iterator_s *iter);

void * sl_iter_item(iterator_s *iter);

void sl_iter_free(iterator_s *iter);

#endif
