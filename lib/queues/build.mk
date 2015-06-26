# Build target for singly list backed queue
build/sl_queue.o: lib/queues/sl_queue.c includes/sl_queue.h includes/slist.h | build
	$(CC) $(CFLAGS) -c $< -o $@

# Build target for Double Linked List
#build/dlist.o: lib/lists/dlist.c includes/dlist.h | build
#	$(CC) $(CFLAGS) -c $< -o $@
