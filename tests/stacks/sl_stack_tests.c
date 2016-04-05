#include <stdio.h>
#include <stdlib.h>

#include <sl_stack.h>
#include <sl_iterator.h>

#define QTD 100

void print_stack_iter(sl_stack_root *stack) {
	iterator_s *i = sl_iter_create(stack);
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
	sl_stack_root *a;
	int *num;
	
	a = sl_stack_create(&free);
	
	printf("##### Test 1 - sl_stack_push - Insert element in the stack.\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		sl_stack_push(a, num);
	}
	print_stack_iter(a);
	
	printf("##### Test 2 - sl_stack_peek - View the top element without pop it from the stack.\n");
	num = sl_stack_peek(a);
	printf("Peeked item: %d\n", *num);
	
	printf("##### Test 3 - sl_stack_pop - Remove the top element without pop it from the stack.\n");
	for (int i = 0; i < 5; i++) {
		num = sl_stack_pop(a);
		printf("Popped item: %d\n", *num);
		free(num);
	}
	print_stack_iter(a);
	
	printf("##### Test 2 - sl_stack_destroy - Destroy stack (call destroyfunc for every member).\n");
	sl_stack_destroy(a);
	
	return EXIT_SUCCESS;
}
