## Build target for Queue tests

queue_tests: sl_queue_tests

# Queues
$(addprefix $(BUILD_DIR), sl_queue_tests.o): $(addprefix $(TESTS_DIR), queues/sl_queue_tests.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), sl_queue_tests): $(addprefix $(BUILD_DIR), sl_queue_tests.o sl_queue.o)
	$(CC) $(LDFLAGS) $^ -o $@

sl_queue_tests: $(addprefix $(BUILD_DIR), sl_queue_tests)

sl_queue_time: sl_queue_tests
	/usr/bin/time -v $(addprefix $(BUILD_DIR), $^)

sl_queue_vg: sl_queue_tests
	valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^)
