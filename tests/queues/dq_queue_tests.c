#include <stdio.h>
#include <stdlib.h>

#include <dq_queue.h>
#include <dl_iterator.h>

#define QTD 100

void print_queue_iter(dq_queue_root *queue) {
	iterator_d *i = dl_iter_create(queue, FORWARD);
	printf("[");
	if (i != NULL) {
		do {
			printf("'%d', ", *((int *) dl_iter_item(i)));
		} while (dl_iter_next(i));
	};
	printf("]\n");
	dl_iter_free(i);
}

int main() {
	dq_queue_root *a;
	int *num;
	
	a = dq_queue_create(&free);
	
	printf("##### Test 1 - dq_queue_push - Insert element in the queue.\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		dq_queue_push(a, num);
	}
	print_queue_iter(a);
	
	printf("##### Test 2 - dq_queue_peek - View the last element without pop it from the queue.\n");
	num = dq_queue_peek(a);
	printf("Peeked item: %d\n", *num);
	
	printf("##### Test 3 - dq_queue_pop - Remove the last element without pop it from the queue.\n");
	for (int i = 0; i < 5; i++) {
		num = dq_queue_pop(a);
		printf("Popped item: %d\n", *num);
		free(num);
	}
	print_queue_iter(a);
	
	printf("##### Test 2 - dq_queue_destroy - Destroy queue (call destroyfunc for every member).\n");
	dq_queue_destroy(a);
	
	return EXIT_SUCCESS;
}
