## Build target for Queue tests

queue_tests: sl_queue_tests dq_queue_tests
queue_vg_tests: sl_queue_vg dq_queue_vg

# Singly-list-backed Queues
$(addprefix $(BUILD_DIR), sl_queue_tests.o): $(addprefix $(TESTS_DIR), queues/sl_queue_tests.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), sl_queue_tests): $(addprefix $(BUILD_DIR), sl_queue_tests.o sl_queue.a sl_iterator.o)
	$(CC) $(CFLAGS) $^ -o $@

sl_queue_tests: $(addprefix $(BUILD_DIR), sl_queue_tests)

sl_queue_time: sl_queue_tests
	/usr/bin/time -v $(addprefix $(BUILD_DIR), $^)

sl_queue_vg: sl_queue_tests
	@echo "\nSingly-list-backed Queue Valgrind Test"
	@valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^) 2>&1 | grep -i -e "total heap usage" -e "All heap" -e "definitely lost" -e "indirectly lost" -e "ERROR SUMMARY" -e "LEAK SUMMARY" -e "HEAP SUMMARY"
	@echo

# Deque-backed Queues
$(addprefix $(BUILD_DIR), dq_queue_tests.o): $(addprefix $(TESTS_DIR), queues/dq_queue_tests.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), dq_queue_tests): $(addprefix $(BUILD_DIR), dq_queue_tests.o dq_queue.a dl_iterator.o)
	$(CC) $(CFLAGS) $^ -o $@

dq_queue_tests: $(addprefix $(BUILD_DIR), dq_queue_tests)

dq_queue_time: dq_queue_tests
	/usr/bin/time -v $(addprefix $(BUILD_DIR), $^)

dq_queue_vg: dq_queue_tests
	@echo "\nDeque-backed Queue Valgrind Test"
	@valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^) 2>&1 | grep -i -e "total heap usage" -e "All heap" -e "definitely lost" -e "indirectly lost" -e "ERROR SUMMARY" -e "LEAK SUMMARY" -e "HEAP SUMMARY"
	@echo
