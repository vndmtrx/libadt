#include <stdio.h>
#include <stdlib.h>

#include <dl_list.h>
#include <dl_iterator.h>

#define QTD 100

void print_list_iter(dl_list_root *list) {
	iterator_d *i = dl_iter_create(list, FORWARD);
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
	dl_list_root *a;
	int *num;

	a = dl_list_create(&free, HEAD);

	printf("##### Test 1 - dl_list_insert_el_next - Insert in the head of the list (without current param)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		dl_list_insert_el_next(a, NULL, num);
	}
	print_list_iter(a);

	printf("##### Test 2 - dl_list_insert_el_next - Insert in the middle of the list (with current param = head)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + QTD;
		dl_list_insert_el_next(a, a->head, num);
	}
	print_list_iter(a);

	printf("##### Test 3 - dl_list_insert_el_next - Insert in the tail of the list (with current param = tail)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + (QTD * 2);
		dl_list_insert_el_next(a, a->tail, num);
	}
	print_list_iter(a);

	printf("##### Test 4 - dl_list_insert_el_prev - Insert in the tail of the list (without current param)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		dl_list_insert_el_prev(a, NULL, num);
	}
	print_list_iter(a);

	printf("##### Test 5 - dl_list_insert_el_prev - Insert in the middle of the list (with current param = tail)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + QTD;
		dl_list_insert_el_prev(a, a->tail, num);
	}
	print_list_iter(a);

	printf("##### Test 6 - dl_list_insert_el_prev - Insert in the head of the list (with current param = head)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + (QTD * 2);
		dl_list_insert_el_prev(a, a->head, num);
	}
	print_list_iter(a);

	printf("##### Test 7 - dl_list_move_el_next - Move head item to middle of the list\n");
	dl_list_move_el_next(a, a->head, dl_list_next(dl_list_next(a->head)));
	print_list_iter(a);

	printf("##### Test 8 - dl_list_move_el_next - Move item to tail of the list\n");
	dl_list_move_el_next(a, dl_list_next(a->head), a->tail);
	print_list_iter(a);

	printf("##### Test 9 - dl_list_move_el_next - Move item to another position\n");
	dl_list_move_el_next(a, dl_list_next(dl_list_next(dl_list_next(a->head))), dl_list_next(a->head));
	print_list_iter(a);

	printf("##### Test 10 - dl_list_move_el_next - Move head to tail (and back again)\n");
	dl_list_move_el_next(a, a->head, a->tail);
	print_list_iter(a);
	dl_list_move_el_next(a, a->tail, a->head);
	print_list_iter(a);

	printf("##### Test 11 - dl_list_move_el_prev - Move head item to middle of the list\n");
	dl_list_move_el_prev(a, a->head, dl_list_next(dl_list_next(a->head)));
	print_list_iter(a);

	printf("##### Test 12 - dl_list_move_el_prev - Move item to tail of the list\n");
	dl_list_move_el_prev(a, dl_list_next(a->head), a->tail);
	print_list_iter(a);

	printf("##### Test 13 - dl_list_move_el_prev - Move item to another position\n");
	dl_list_move_el_prev(a, dl_list_next(dl_list_next(dl_list_next(a->head))), dl_list_next(a->head));
	print_list_iter(a);

	printf("##### Test 14 - dl_list_move_el_prev - Move head to tail (and back again)\n");
	dl_list_move_el_prev(a, a->head, a->tail);
	print_list_iter(a);
	dl_list_move_el_prev(a, a->tail, a->head);
	print_list_iter(a);

	printf("##### Test 15 - dl_list_swap_el - Swap head with other element\n");
	dl_list_swap_el(a, a->head, dl_list_prev(a->tail));
	print_list_iter(a);

	printf("##### Test 16 - dl_list_swap_el - Swap tail with other element\n");
	dl_list_swap_el(a, a->tail, dl_list_next(a->head));
	print_list_iter(a);

	printf("##### Test 17 - dl_list_swap_el - Swap head and tail\n");
	dl_list_swap_el(a, a->head, a->tail);
	print_list_iter(a);

	printf("##### Test 18 - dl_list_swap_el - Swap other elements\n");
	dl_list_swap_el(a, dl_list_next(a->head), dl_list_prev(a->tail));
	print_list_iter(a);

	printf("##### Test 19 - dl_list_rem_el - Remove from the head of the list\n");
	num = dl_list_rem_el(a, a->head);
	print_list_iter(a);
	free(num);

	printf("##### Test 20 - dl_list_rem_el - Remove from the middle of the list\n");
	num = dl_list_rem_el(a, dl_list_prev(dl_list_prev(a->head)));
	print_list_iter(a);
	free(num);

	printf("##### Test 21 - dl_list_rem_el - Remove from the tail of the list\n");
	num = dl_list_rem_el(a, a->tail);
	print_list_iter(a);
	free(num);

	printf("##### Test 22 - dl_list_destroy - Destroy list (call destroyfunc for every member)\n");
	dl_list_destroy(&a);

	return EXIT_SUCCESS;
}
