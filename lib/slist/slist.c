#include "slist.h"

struct slist_root {
	slist_node *first;
}

struct slist_node {
	slist_node *next;
	void *item;
}

