## Build target for stack tests

stack_tests: sl_stack_tests

# Stacks
build/sl_stack_tests.o: tests/stacks/sl_stack_tests.c | build
	$(CC) $(CFLAGS) -c $^ -o $@

build/sl_stack_tests: build/sl_stack_tests.o build/sl_stack.o
	$(CC) $(LDFLAGS) $^ -o $@

sl_stack_tests: build/sl_stack_tests

sl_stack_time: sl_stack_tests
	/usr/bin/time -v build/$^

sl_stack_vg: sl_stack_tests
	valgrind -v --leak-check=full build/$^
