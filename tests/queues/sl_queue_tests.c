#include <stdio.h>
#include <stdlib.h>

#include <sl_queue.h>

#define QTD 10

void print_list(sl_queue_root *queue) {
	slist_node *node = queue->head;
	printf("[");
	if (sl_queue_size(queue) > 0) {
		do {
			printf("%d, ", *((int *) node->data));
			node = node->next;
		} while (node != NULL);
	}
	printf("]\n");
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
	print_list(a);
	
	printf("##### Test 2 - sl_queue_peek - View the last element without pop it from the queue.\n");
	num = sl_queue_peek(a);
	printf("Peeked item: %d\n", *num);
	
	printf("##### Test 3 - sl_queue_pop - Remove the last element without pop it from the queue.\n");
	for (int i = 0; i < 5; i++) {
		num = sl_queue_pop(a);
		printf("Popped item: %d\n", *num);
		free(num);
	}
	print_list(a);
	
	printf("##### Test 2 - sl_queue_destroy - Destroy queue (call destroyfunc for every member).\n");
	sl_queue_destroy(a);
	
	return EXIT_SUCCESS;
}
