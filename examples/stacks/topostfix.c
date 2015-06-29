#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <sl_stack.h>

void print_list(sl_stack_root *stack) {
	slist_node *node = stack->head;
	printf("[");
	if (sl_stack_size(stack) > 0) {
		do {
			printf("%d, ", *((char *) node->data));
			node = node->next;
		} while (node != NULL);
	}
	printf("]\n");
}

int precedence(char op) {
	if (op == '(') {
		return 0;
	} else if (op == '+' || op == '-') {
		return 1;
	} else if (op == '*' || op == '/') {
		return 2;
	} else if (op == '^') {
		return 3;
	}else {
		return -1;
	}
}

int isoperator(char c) {
	return (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/' || c == '^') ? 1 : 0;
}

int main(int argc, char *argv[]) {
	char c;
	char *cm, *cs;
	
	sl_stack_root *stack = (sl_stack_root *) malloc(sizeof(sl_stack_root));
	sl_stack_create(stack, &free);
	
	while ((c = fgetc(stdin)) != EOF) {
		if (isalpha(c) || isdigit(c)) {
			printf("%c", c);
		} else {
			if (c == '(') {
				cm = (char *) malloc(sizeof(char));
				*cm = c;
				
				sl_stack_push(stack, cm);
			} else if (c == ')') {
				cs = sl_stack_pop(stack);
				while (*cs != '(') {
					printf("%c", *cs);
					free(cs);
					if ((cs = sl_stack_pop(stack)) == NULL) return EXIT_FAILURE;
				}
			} else if (isoperator(c)) {
				while (sl_stack_size(stack) > 0) {
					cs = sl_stack_peek(stack);
					if (precedence(*cs) >= precedence(c)) {
						printf("%c", *cs);
						free(cs);
						cs = sl_stack_pop(stack);
					} else {
						break;
					}
				}
				
				cm = (char *) malloc(sizeof(char));
				*cm = c;
				
				sl_stack_push(stack, cm);
				//print_list(stack);
			} else {
				while (sl_stack_size(stack) > 0) {
					cs = sl_stack_pop(stack);
					printf("%c", *cs);
					free(cs);
				}
			}
		}
	}
	
	free(stack);
	printf("\n");
	
	return EXIT_SUCCESS;
}
