#include <stdio.h>
#include <stdlib.h>

#include <slist.h>

#define QTD 20

void print_el(list_node *node) {
	printf("(");
	if (node != NULL) {
		printf("'%d', ", *((int *) node->data));
		
		if (node->next != NULL) {
			printf("%d", *((int *) node->next->data));
		} else {
			printf("NULL");
		}
	} else {
		printf("NULL");
	}
	printf(") ");
}

void print_list(slist_root *list) {
	list_node *node = list->head;
	printf("[");
	if (list_size(list) > 0) {
		do {
			print_el(node);
			node = node->next;
		} while (node != NULL);
	}
	printf("]\n");
}

int main() {
	slist_root *a;
	int *num;
	
	a = slist_create(&free);
	
	printf("##### Test 1 - slist_insert_el_next - Insert in the head of the list (without current param)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		slist_insert_el_next(a, NULL, num);
	}
	print_list(a);
	
	printf("##### Test 2 - slist_insert_el_next - Insert in the middle of the list (with current param = head)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + QTD;
		slist_insert_el_next(a, a->head, num);
	}
	print_list(a);
	
	printf("##### Test 3 - slist_insert_el_next - Insert in the tail of the list (with current param = tail)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + (QTD * 2);
		slist_insert_el_next(a, a->tail, num);
	}
	print_list(a);
	
	printf("##### Test 4 - slist_move_el - Move head item to middle of the list\n");
	slist_move_el(a, a->head, a->head->next->next);
	print_list(a);
	
	printf("#####  Test 5 - slist_move_el - Move item to tail of the list\n");
	slist_move_el(a, a->head->next, a->tail);
	print_list(a);
	
	printf("##### Test 6 - slist_move_el - Move item to another position\n");
	slist_move_el(a, a->head->next->next->next, a->head->next);
	print_list(a);
	
	printf("##### Test 7 - slist_move_el - Move head to tail (and back again)\n");
	slist_move_el(a, a->head, a->tail);
	print_list(a);
	slist_move_el(a, a->tail, a->head);
	print_list(a);
	
	printf("##### Test 8 - slist_swap_el - Swap two items on the list\n");
	slist_swap_el(a, a->head->next->next, a->head->next->next->next->next);
	print_list(a);
	slist_swap_el(a, a->head, a->head->next->next->next);
	print_list(a);
	slist_swap_el(a, a->head->next->next, a->tail);
	print_list(a);
	
	printf("##### Test 9 - slist_swap_el - Swap head and tail on the list\n");
	slist_swap_el(a, a->head, a->tail);
	print_list(a);
	slist_swap_el(a, a->tail, a->head);
	print_list(a);
	
	printf("##### Test 10 - slist_rem_el - Remove from the head of the list\n");
	num = slist_rem_el(a, a->head);
	print_list(a);
	free(num);
	
	printf("##### Test 11 - slist_rem_el - Remove from the middle of the list\n");
	num = slist_rem_el(a, a->head->next->next);
	print_list(a);
	free(num);
	
	printf("##### Test 12 - slist_rem_el - Remove from the tail of the list\n");
	num = slist_rem_el(a, a->tail);
	print_list(a);
	free(num);
	
	printf("##### Test 13 - slist_destroy - Destroy list (call destroyfunc for every member)\n");
	slist_destroy(a);
	
	return EXIT_SUCCESS;
}
