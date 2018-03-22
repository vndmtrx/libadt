#include <stdio.h>
#include <stdlib.h>

#include <sl_list.h>
#include <sl_iterator.h>

#define QTD 100

void print_list_iter(sl_list_root *list) {
	iterator_s *i = sl_iter_create(list);
	printf("[");
	if (i != NULL) {
		do {
			printf("'%d', ", *((int *) sl_iter_item(i)));
		} while (sl_iter_next(i));
	};
	printf("]\n");
	sl_iter_free(&i);
}

int main() {
	sl_list_root *a;
	int *num;

	a = sl_list_create(&free, HEAD);

	printf("##### Test 1 - sl_list_insert_el_next - Insert in the head of the list (without current param)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		sl_list_insert_el_next(a, NULL, num);
	}
	print_list_iter(a);

	printf("##### Test 2 - sl_list_insert_el_next - Insert in the middle of the list (with current param = head)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + QTD;
		sl_list_insert_el_next(a, a->head, num);
	}
	print_list_iter(a);

	printf("##### Test 3 - sl_list_insert_el_next - Insert in the tail of the list (with current param = tail)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + (QTD * 2);
		sl_list_insert_el_next(a, a->tail, num);
	}
	print_list_iter(a);

	printf("##### Test 4 - sl_list_move_el - Move head item to middle of the list\n");
	sl_list_move_el(a, a->head, sl_list_next(sl_list_next(a->head)));
	print_list_iter(a);

	printf("#####  Test 5 - sl_list_move_el - Move item to tail of the list\n");
	sl_list_move_el(a, sl_list_next(a->head), a->tail);
	print_list_iter(a);

	printf("##### Test 6 - sl_list_move_el - Move item to another position\n");
	sl_list_move_el(a, sl_list_next(sl_list_next(sl_list_next(a->head))), sl_list_next(a->head));
	print_list_iter(a);

	printf("##### Test 7 - sl_list_move_el - Move head to tail (and back again)\n");
	sl_list_move_el(a, a->head, a->tail);
	print_list_iter(a);
	sl_list_move_el(a, a->tail, a->head);
	print_list_iter(a);

	printf("##### Test 8 - sl_list_swap_el - Swap two items on the list\n");
	sl_list_swap_el(a, sl_list_next(sl_list_next(a->head)), sl_list_next(sl_list_next(sl_list_next(a->head))));
	print_list_iter(a);
	sl_list_swap_el(a, a->head, sl_list_next(sl_list_next(sl_list_next(a->head))));
	print_list_iter(a);
	sl_list_swap_el(a, sl_list_next(sl_list_next(a->head)), a->tail);
	print_list_iter(a);

	printf("##### Test 9 - sl_list_swap_el - Swap head and tail on the list\n");
	sl_list_swap_el(a, a->head, a->tail);
	print_list_iter(a);
	sl_list_swap_el(a, a->tail, a->head);
	print_list_iter(a);

	printf("##### Test 10 - sl_list_rem_el - Remove from the head of the list\n");
	num = sl_list_rem_el(a, a->head);
	print_list_iter(a);
	free(num);

	printf("##### Test 11 - sl_list_rem_el - Remove from the middle of the list\n");
	num = sl_list_rem_el(a, sl_list_next(sl_list_next(a->head)));
	print_list_iter(a);
	free(num);

	printf("##### Test 12 - sl_list_rem_el - Remove from the tail of the list\n");
	num = sl_list_rem_el(a, a->tail);
	print_list_iter(a);
	free(num);

	printf("##### Test 13 - sl_list_destroy - Destroy list (call destroyfunc for every member)\n");
	sl_list_destroy(&a);

	return EXIT_SUCCESS;
}
