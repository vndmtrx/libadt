# Build target for singly-list-backed stack
build/sl_stack.partial: lib/stacks/sl_stack.c includes/sl_stack.h includes/slist.h | build
	$(CC) $(CFLAGS) -c $< -o $@

build/sl_stack.o: build/sl_stack.partial build/slist.o
	ld $(LDFLAGS) -r $^ -o $@

# Build target for Double Linked List
#build/dlist.o: lib/lists/dlist.c includes/dlist.h | build
#	$(CC) $(CFLAGS) -c $< -o $@
