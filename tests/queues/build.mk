## Build target for Queue tests

queue_tests: sl_queue_tests

# Queues
build/sl_queue_tests.o: tests/queues/sl_queue_tests.c | build
	$(CC) $(CFLAGS) -c $^ -o $@

build/sl_queue_tests: build/sl_queue_tests.o build/sl_queue.o
	$(CC) $(LDFLAGS) $^ -o $@

sl_queue_tests: build/sl_queue_tests

sl_queue_time: sl_queue_tests
	/usr/bin/time -v build/$^

sl_queue_vg: sl_queue_tests
	valgrind -v --leak-check=full build/$^
