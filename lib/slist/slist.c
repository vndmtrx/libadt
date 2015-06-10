#include "slist.h"

struct slist_root {
	int size;			// Size of the list structure.
	slist_node *head;	// Position from where we start walking the list.
}

struct slist_node {
	slist_node *next;	// Pointer to next slist_node element.
	slist_root *root;	// Pointer to initial list structure.
	void *item;			// Pointer to the element added on the list.
}

