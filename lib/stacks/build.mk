# Build target for singly-list-backed stack
build/sl_stack.o: lib/stacks/sl_stack.c includes/sl_stack.h includes/slist.h | build
	$(CC) $(CFLAGS) -c $< -o $@

# Build target for Double Linked List
#build/dlist.o: lib/lists/dlist.c includes/dlist.h | build
#	$(CC) $(CFLAGS) -c $< -o $@
