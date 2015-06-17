# Build target for Linked List Tests

list_tests: slist_tests dlist_tests

# Single Linked List
build/slist_tests.o: tests/lists/slist_tests.c | build
	$(CC) $(CFLAGS) -c $^ -o $@

build/slist_tests: build/slist_tests.o build/slist.o
	$(LD) $(LDFLAGS) $^ -o $@

slist_tests: build/slist_tests

slist_time: slist_tests
	/usr/bin/time -v build/$^

slist_trace: slist_tests
	strace build/$^

slist_vg: slist_tests
	valgrind -v --leak-check=full build/$^

# Double Linked List
build/dlist_tests.o: tests/lists/dlist_tests.c | build
	$(CC) $(CFLAGS) -c $^ -o $@

build/dlist_tests: build/dlist_tests.o build/dlist.o
	$(LD) $(LDFLAGS) $^ -o $@

dlist_tests: build/dlist_tests

dlist_time: dlist_tests
	/usr/bin/time -v build/$^

dlist_trace: dlist_tests
	strace build/$^

dlist_vg: dlist_tests
	valgrind -v --leak-check=full build/$^
