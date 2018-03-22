#include <stdio.h>
#include <stdlib.h>

#include <sl_queue.h>
#include <sl_iterator.h>

#define QTD 100

void print_queue_iter(sl_queue_root *queue) {
	iterator_s *i = sl_iter_create(queue);
	printf("[");
	if (i != NULL) {
		do {
			printf("'%d', ", *((int *) sl_iter_item(i)));
		} while (sl_iter_next(i));
	};
	printf("]\n");
	sl_iter_free(i);
}

int main() {
	sl_queue_root *a;
	int *num;

	a = sl_queue_create(&free);

	printf("##### Test 1 - sl_queue_push - Insert element in the queue.\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		sl_queue_push(a, num);
	}
	print_queue_iter(a);

	printf("##### Test 2 - sl_queue_peek - View the last element without pop it from the queue.\n");
	num = sl_queue_peek(a);
	printf("Peeked item: %d\n", *num);

	printf("##### Test 3 - sl_queue_pop - Remove the last element without pop it from the queue.\n");
	for (int i = 0; i < 5; i++) {
		num = sl_queue_pop(a);
		printf("Popped item: %d\n", *num);
		free(num);
	}
	print_queue_iter(a);

	printf("##### Test 2 - sl_queue_destroy - Destroy queue (call destroyfunc for every member).\n");
	sl_queue_destroy(&a);

	return EXIT_SUCCESS;
}
