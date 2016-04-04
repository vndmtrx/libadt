#include <stdio.h>
#include <stdlib.h>

#include <dl_list.h>
#include <dl_deque.h>
#include <dl_iterator.h>

#define QTD 10

void print_deque_iter(dl_deque_root *deque) {
	iterator_s *i = dl_iter_create(deque, FORWARD);
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
	dl_deque_root *a;
	int *num;
	
	a = dl_deque_create(&free);
	
	printf("##### Test 1 - dl_deque_push_left - Insert in the left of the deque\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		dl_deque_push_left(a, num);
	}
	print_deque_iter(a);
	
	printf("##### Test 2 - dl_deque_push_right - Insert in the right of the deque\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		dl_deque_push_right(a, num);
	}
	print_deque_iter(a);
	
	printf("##### Test 3 - dl_deque_peek_left - View the left element without pop it from the deque\n");
	num = dl_deque_peek_left(a);
	printf("Peeked item from left: %d\n", *num);
	
	printf("##### Test 4 - dl_deque_peek_right - View the right element without pop it from the deque\n");
	num = dl_deque_peek_right(a);
	printf("Peeked item from right: %d\n", *num);
	
	printf("##### Test 5 - dl_deque_peek_left - Return the left element removing it from the deque.\n");
	for (int i = 0; i < 5; i++) {
		num = dl_deque_pop_left(a);
		printf("Popped left item: %d\n", *num);
		free(num);
	}
	print_deque_iter(a);
	
	printf("##### Test 6 - dl_deque_peek_right - Return the right element removing it from the deque.\n");
	for (int i = 0; i < 5; i++) {
		num = dl_deque_pop_right(a);
		printf("Popped right item: %d\n", *num);
		free(num);
	}
	print_deque_iter(a);
	
	printf("##### Test 22 - dl_deque_destroy - Destroy deque (call destroyfunc for every member)\n");
	dl_deque_destroy(a);
	
	return EXIT_SUCCESS;
}

