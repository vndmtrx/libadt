# Build target for Single Linked List
build/slist.o: lib/slist/slist.c includes/slist.h | build
	$(CC) $(CFLAGS) -c $< -o $@
