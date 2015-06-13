# Build target for Single Linked List Tests
build/test1.o: tests/slist/test1.c | build
	$(CC) $(CFLAGS) -c $^ -o $@

build/test1: build/test1.o build/slist.o
	$(LD) $(LDFLAGS) $^ -o $@

test1: build/test1

runtest1: test1
	/usr/bin/time -v build/$^

tracetest1: test1
	strace build/$^

valgrindtest1: test1
	valgrind -v --leak-check=full build/$^
