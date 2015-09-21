#ifndef _LIBADT_LIST_H
#define _LIBADT_LIST_H

#include <adt_commons.h>

typedef struct _list_root list_root;

typedef struct _list_node list_node;

struct _list_node;

struct _list_root {
	int size;			// Size of the list structure.
	t_destroyfunc destroyfunc;
	list_node *head;	// Position from where we start walking the list.
	list_node *tail;	// Last item on the list.
};

/*
 * Returns the size of the list.
 */
#define list_size(list) ((list) ->size)

#endif
