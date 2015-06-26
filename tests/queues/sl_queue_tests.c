#include <stdio.h>
#include <stdlib.h>

#include <sl_queue.h>

#define QTD 10

int main() {
	sl_queue_root *a;
	
	a = (sl_queue_root *) malloc(sizeof(sl_queue_root));
	slist_create(a, &free);
	
	free(a);
	return EXIT_SUCCESS;
}
