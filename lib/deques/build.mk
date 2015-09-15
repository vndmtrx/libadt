# Build target for doubly-list-backed deque
build/dl_deque.partial: lib/deques/dl_deque.c includes/dl_deque.h includes/dlist.h | build
	$(CC) $(CFLAGS) -c $< -o $@

build/dl_deque.o: build/dl_deque.partial build/dlist.o
	ld $(LDFLAGS) -r $^ -o $@

# Build target for Double Linked List
#build/dlist.o: lib/lists/dlist.c includes/dlist.h | build
#	$(CC) $(CFLAGS) -c $< -o $@
