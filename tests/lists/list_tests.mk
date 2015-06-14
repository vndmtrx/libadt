# Build target for Linked List Tests
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
	valgrind -v build/$^
