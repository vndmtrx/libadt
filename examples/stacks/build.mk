## Build target for Stack examples

# Queues
build/topostfix.o: examples/stacks/topostfix.c | build
	$(CC) $(CFLAGS) -c $^ -o $@

build/topostfix: build/topostfix.o build/sl_stack.o
	$(CC) $(LDFLAGS) $^ -o $@

topostfix: build/topostfix

topostfix_test: topostfix
	echo "Test: A*B+C -> AB*C+;"
	echo "A*B+C" | ./build/$^
	echo "Test: A+B*C -> ABC*+;"
	echo "A+B*C" | ./build/$^
	echo "Test: A*(B+C) -> ABC+*;"
	echo "A*(B+C)" | ./build/$^
	echo "Test: A-B+C -> AB-C+;"
	echo "A-B+C" | ./build/$^
	echo "Test: A*B^C+D -> ABC^*D+;"
	echo "A*B^C+D" | ./build/$^
	echo "Test: A*(B+C*D)+E -> ABCD*+*E+;"
	echo "A*(B+C*D)+E" | ./build/$^

topostfix_vg: topostfix
	echo "123+45+98534-1326847#123276!438947StRiNg222*11111" | valgrind -v --leak-check=full build/$^

