# Build target for Single Linked List
build/slist.o: lib/lists/slist.c includes/slist.h | build
	$(CC) $(CFLAGS) -c $< -o $@
