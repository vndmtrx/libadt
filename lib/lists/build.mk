# Build target for Single Linked List
build/slist.o: lib/lists/slist.c includes/slist.h | build
	$(CC) $(CFLAGS) -c $< -o $@

# Build target for Double Linked List
build/dlist.o: lib/lists/dlist.c includes/dlist.h | build
	$(CC) $(CFLAGS) -c $< -o $@
