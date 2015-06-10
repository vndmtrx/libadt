#include "slist.h"

struct _slist_root {
	int size;			// Size of the list structure.
	slist_node *head;	// Position from where we start walking the list.
}

struct _slist_node {
	slist_node *next;	// Pointer to next slist_node element.
	slist_root *root;	// Pointer to initial list structure.
	void *item;			// Pointer to the element added on the list.
}

void slist_create(slist_root **list) {
	slist_root newlist = (slist_root *) malloc(sizeof(slist_root);
	newlist->size = 0;
	newlist->head = NULL;
	*list = &newlist;
}
