#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

#include <sl_queue.h>

#define digit(d) (d-'0')

int main(int argc, char *argv[]) {
	char c;
	char *cm;
	long num;
	sl_queue_root *queue = (sl_queue_root *) malloc(sizeof(sl_queue_root));
	sl_queue_create(queue, &free);
	
	while ((c = fgetc(stdin)) != EOF) {
		if (isdigit(c)) {
			cm = (char *) malloc(sizeof(char));
			*cm = c;
			sl_queue_push(queue, cm);
		} else {
			num = 0;
			int num_converted = 0;
			
			while (sl_queue_size(queue) > 0) {
				if (num < (LONG_MAX/10)) {
					num_converted = 1;
					sl_queue_pop(queue, (void *) &cm);
					num = (num * 10) + digit(*cm);
					free(cm);
				} else {
					perror("Number is longer than 'long' type.\n");
					return EXIT_FAILURE;
				}
			}
			
			if (num_converted == 1) {
				printf("NUMBER: (%li).\n", num);
			}
			
			if (c != '\n') {
				printf("CHARACTER: (%c).\n", c);
			}
		}
	}
	
	sl_queue_create(queue, &free);
	free(queue);
	
	return EXIT_SUCCESS;
}
