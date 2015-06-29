#include <stdio.h>
#include <stdlib.h>

#include <dlist.h>

#define QTD 10

void print_el(dlist_node *node) {
	printf("(");
	if (node != NULL) {
		if (node->prev != NULL) {
			printf("%d", *((int *) node->prev->data));
		} else {
			printf("NULL");
		}
		
		printf(", '%d', ", *((int *) node->data));
		
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

void print_list(dlist_root *list) {
	dlist_node *node = list->head;
	printf("List size: %d. Items: [", list->size);
	if (dlist_size(list) > 0) {
		do {
			print_el(node);
			node = node->next;
		} while (node != NULL);
	}
	printf("]\n");
}

int main() {
	dlist_root *a;
	int *num;
	
	a = (dlist_root *) malloc(sizeof(dlist_root));
	dlist_create(a, &free);
	
	printf("##### Test 1 - dlist_insert_el_next - Insert in the head of the list (without current param)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		dlist_insert_el_next(a, NULL, num);
	}
	print_list(a);
	
	printf("##### Test 2 - dlist_insert_el_next - Insert in the middle of the list (with current param = head)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + QTD;
		dlist_insert_el_next(a, a->head, num);
	}
	print_list(a);
	
	printf("##### Test 3 - dlist_insert_el_next - Insert in the tail of the list (with current param = tail)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + (QTD * 2);
		dlist_insert_el_next(a, a->tail, num);
	}
	print_list(a);
	
	printf("##### Test 4 - dlist_insert_el_prev - Insert in the tail of the list (without current param)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		dlist_insert_el_prev(a, NULL, num);
	}
	print_list(a);
	
	printf("##### Test 5 - dlist_insert_el_prev - Insert in the middle of the list (with current param = tail)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + QTD;
		dlist_insert_el_prev(a, a->tail, num);
	}
	print_list(a);
	
	printf("##### Test 6 - dlist_insert_el_prev - Insert in the head of the list (with current param = head)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + (QTD * 2);
		dlist_insert_el_prev(a, a->head, num);
	}
	print_list(a);
	
	printf("##### Test 7 - dlist_move_el_next - Move head item to middle of the list\n");
	dlist_move_el_next(a, a->head, a->head->next->next);
	print_list(a);
	
	printf("##### Test 8 - dlist_move_el_next - Move item to tail of the list\n");
	dlist_move_el_next(a, a->head->next, a->tail);
	print_list(a);
	
	printf("##### Test 9 - dlist_move_el_next - Move item to another position\n");
	dlist_move_el_next(a, a->head->next->next->next, a->head->next);
	print_list(a);
	
	printf("##### Test 10 - dlist_move_el_next - Move head to tail (and back again)\n");
	dlist_move_el_next(a, a->head, a->tail);
	print_list(a);
	dlist_move_el_next(a, a->tail, a->head);
	print_list(a);
	
	printf("##### Test 11 - dlist_move_el_prev - Move head item to middle of the list\n");
	dlist_move_el_prev(a, a->head, a->head->next->next);
	print_list(a);
	
	printf("##### Test 12 - dlist_move_el_prev - Move item to tail of the list\n");
	dlist_move_el_prev(a, a->head->next, a->tail);
	print_list(a);
	
	printf("##### Test 13 - dlist_move_el_prev - Move item to another position\n");
	dlist_move_el_prev(a, a->head->next->next->next, a->head->next);
	print_list(a);
	
	printf("##### Test 14 - dlist_move_el_prev - Move head to tail (and back again)\n");
	dlist_move_el_prev(a, a->head, a->tail);
	print_list(a);
	dlist_move_el_prev(a, a->tail, a->head);
	print_list(a);
	
	printf("##### Test 15 - dlist_swap_el - Swap head with other element\n");
	dlist_swap_el(a, a->head, a->tail->prev);
	print_list(a);
	
	printf("##### Test 16 - dlist_swap_el - Swap tail with other element\n");
	dlist_swap_el(a, a->tail, a->head->next);
	print_list(a);
	
	printf("##### Test 17 - dlist_swap_el - Swap head and tail\n");
	dlist_swap_el(a, a->head, a->tail);
	print_list(a);
	
	printf("##### Test 18 - dlist_swap_el - Swap other elements\n");
	dlist_swap_el(a, a->head->next, a->tail->prev);
	print_list(a);
	
	printf("##### Test 19 - dlist_rem_el - Remove from the head of the list\n");
	num = dlist_rem_el(a, a->head);
	print_list(a);
	free(num);
	
	printf("##### Test 20 - dlist_rem_el - Remove from the middle of the list\n");
	num = dlist_rem_el(a, a->head->next->next);
	print_list(a);
	free(num);
	
	printf("##### Test 21 - dlist_rem_el - Remove from the tail of the list\n");
	num = dlist_rem_el(a, a->tail);
	print_list(a);
	free(num);
	
	printf("##### Test 22 - dlist_destroy - Destroy list (call destroyfunc for every member)\n");
	dlist_destroy(a);
	print_list(a);
	
	free(a);
	return EXIT_SUCCESS;
}
