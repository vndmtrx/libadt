#include <stdio.h>
#include <stdlib.h>

#include <slist.h>

int main() {
	slist_root a;
	slist_create(&a, &free);
	return EXIT_SUCCESS;
}
