## Build target for double-ended queue tests

stack_tests: dl_deque_tests

# Deques
$(addprefix $(BUILD_DIR), dl_deque_tests.o): $(addprefix $(TESTS_DIR), stacks/dl_deque_tests.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), dl_deque_tests): $(addprefix $(BUILD_DIR), dl_deque_tests.o dl_deque.o)
	$(CC) $(LDFLAGS) $^ -o $@

dl_deque_tests: $(addprefix $(BUILD_DIR), dl_deque_tests)

dl_deque_time: dl_deque_tests
	/usr/bin/time -v $(addprefix $(BUILD_DIR), $^)

dl_deque_vg: dl_deque_tests
	valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^)

