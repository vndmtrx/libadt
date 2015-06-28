## Build target for Queue tests

# Queues
build/evaluator.o: examples/queues/evaluator.c | build
	$(CC) $(CFLAGS) -c $^ -o $@

build/evaluator: examples/queues/evaluator.o build/sl_queue.o
	$(CC) $(LDFLAGS) $^ -o $@

evaluator: build/evaluator

test_evaluator: evaluator
	echo "123+45+98534" | ./build/$^
	echo "123+45-STRING&8+98534" | ./build/$^
