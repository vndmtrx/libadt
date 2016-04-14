#include <stdio.h>
#include <stdlib.h>

#include <cl_list.h>
#include <cl_iterator.h>

#define QTD 100

void print_list_iter(cl_list_root *list) {
	iterator_c *i = cl_iter_create(list, FORWARD);
	printf("[");
	if (i != NULL) {
		do {
			printf("'%d', ", *((int *) cl_iter_item(i)));
		} while (cl_iter_next(i) && cl_iter_is_item(i, list->head));
	};
	printf("]\n");
	cl_iter_free(i);
}

int main() {
	
	return EXIT_SUCCESS;
}
