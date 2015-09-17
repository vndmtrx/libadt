## Build target for stack tests

stack_tests: sl_stack_tests

# Stacks
$(addprefix $(BUILD_DIR), sl_stack_tests.o): $(addprefix $(TESTS_DIR), stacks/sl_stack_tests.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), sl_stack_tests): $(addprefix $(BUILD_DIR), sl_stack_tests.o sl_stack.o)
	$(CC) $(LDFLAGS) $^ -o $@

sl_stack_tests: $(addprefix $(BUILD_DIR), sl_stack_tests)

sl_stack_time: sl_stack_tests
	/usr/bin/time -v $(addprefix $(BUILD_DIR), $^)

sl_stack_vg: sl_stack_tests
	valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^)
