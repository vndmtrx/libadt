## Build target for Queue examples

# Queues
build/evaluator.o: examples/queues/evaluator.c | build
	$(CC) $(CFLAGS) -c $^ -o $@

build/evaluator: build/evaluator.o build/sl_queue.o
	$(CC) $(LDFLAGS) $^ -o $@

evaluator: build/evaluator

evaluator_test: evaluator
	echo "123+45+98534" | ./build/$^
	echo "123+45-STRING&8+98534" | ./build/$^

evaluator_vg: evaluator
	echo "123+45+98534-1326847#123276!438947StRiNg222*11111" | valgrind -v --leak-check=full build/$^
