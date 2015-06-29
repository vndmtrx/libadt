## Build target for Stack examples

# Queues
build/topostfix.o: examples/stacks/topostfix.c | build
	$(CC) $(CFLAGS) -c $^ -o $@

build/topostfix: examples/stacks/topostfix.o build/sl_stack.o
	$(CC) $(LDFLAGS) $^ -o $@

topostfix: build/topostfix

topostfix_test: topostfix
	echo "123+45+98534" | ./build/$^
	echo "123+45-STRING&8+98534" | ./build/$^

topostfix_vg: topostfix
	echo "123+45+98534-1326847#123276!438947StRiNg222*11111" | valgrind -v --leak-check=full build/$^

