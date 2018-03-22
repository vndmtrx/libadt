#include <stdio.h>
#include <stdlib.h>

#include <dq_stack.h>
#include <dl_iterator.h>

#define QTD 100

void print_stack_iter(dq_stack_root *stack) {
	iterator_d *i = dl_iter_create(stack, FORWARD);
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
	dq_stack_root *a;
	int *num;

	a = dq_stack_create(&free);

	printf("##### Test 1 - dq_stack_push - Insert element in the stack.\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		dq_stack_push(a, num);
	}
	print_stack_iter(a);

	printf("##### Test 2 - dq_stack_peek - View the top element without pop it from the stack.\n");
	num = dq_stack_peek(a);
	printf("Peeked item: %d\n", *num);

	printf("##### Test 3 - dq_stack_pop - Remove the top element without pop it from the stack.\n");
	for (int i = 0; i < 5; i++) {
		num = dq_stack_pop(a);
		printf("Popped item: %d\n", *num);
		free(num);
	}
	print_stack_iter(a);

	printf("##### Test 2 - dq_stack_destroy - Destroy stack (call destroyfunc for every member).\n");
	dq_stack_destroy(&a);

	return EXIT_SUCCESS;
}
