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
	@echo "\nSingly-list-backed Queue Valgrind Test"
	@valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^) 2>&1 | grep -i -e "total heap usage" -e "All heap" -e "definitely lost" -e "indirectly lost" -e "ERROR SUMMARY" -e "LEAK SUMMARY" -e "HEAP SUMMARY"
	@echo
