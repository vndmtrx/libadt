## Build target for stack tests

stack_tests: sl_stack_tests

# Stacks
$(addprefix $(BUILD_DIR), sl_stack_tests.o): $(addprefix $(TESTS_DIR), stacks/sl_stack_tests.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), sl_stack_tests): $(addprefix $(BUILD_DIR), sl_stack_tests.o sl_stack.o sl_iterator.o)
	$(CC) $(CFLAGS) $^ -o $@

sl_stack_tests: $(addprefix $(BUILD_DIR), sl_stack_tests)

sl_stack_time: sl_stack_tests
	/usr/bin/time -v $(addprefix $(BUILD_DIR), $^)

sl_stack_vg: sl_stack_tests
	@echo "\nSingly-list-backed Stack Valgrind Test"
	@valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^) 2>&1 | grep -i -e "total heap usage" -e "All heap" -e "definitely lost" -e "indirectly lost" -e "ERROR SUMMARY" -e "LEAK SUMMARY" -e "HEAP SUMMARY"
	@echo
