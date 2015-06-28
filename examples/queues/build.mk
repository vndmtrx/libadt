## Build target for Queue tests

queue_tests: sl_queue_tests

# Queues
build/evaluator.o: examples/queues/evaluator.c | build
	$(CC) $(CFLAGS) -c $^ -o $@

build/evaluator: examples/queues/evaluator.o build/sl_queue.o
	$(CC) $(LDFLAGS) $^ -o $@

evaluator: build/evaluator
