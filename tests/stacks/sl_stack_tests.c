#include <stdio.h>
#include <stdlib.h>

#include <sl_stack.h>
#include <slist.h>

#define QTD 10

void print_list(sl_stack_root *stack) {
	list_node *node = stack->head;
	printf("[");
	if (sl_stack_size(stack) > 0) {
		do {
			printf("%d, ", *((int *) node->data));
			node = node->next;
		} while (node != NULL);
	}
	printf("]\n");
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
	print_list(a);
	
	printf("##### Test 2 - sl_stack_peek - View the top element without pop it from the stack.\n");
	num = sl_stack_peek(a);
	printf("Peeked item: %d\n", *num);
	
	printf("##### Test 3 - sl_stack_pop - Remove the top element without pop it from the stack.\n");
	for (int i = 0; i < 5; i++) {
		num = sl_stack_pop(a);
		printf("Popped item: %d\n", *num);
		free(num);
	}
	print_list(a);
	
	printf("##### Test 2 - sl_stack_destroy - Destroy stack (call destroyfunc for every member).\n");
	sl_stack_destroy(a);
	
	return EXIT_SUCCESS;
}
