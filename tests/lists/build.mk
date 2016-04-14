# Build target for Linked List Tests

list_tests: sl_list_tests dl_list_tests
list_vg_tests: sl_list_vg dl_list_vg

# Single Linked List
$(addprefix $(BUILD_DIR), sl_list_tests.o): $(addprefix $(TESTS_DIR), lists/sl_list_tests.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), sl_list_tests): $(addprefix $(BUILD_DIR), sl_list_tests.o sl_list.o sl_iterator.o)
	$(CC) $(CFLAGS) $^ -o $@

sl_list_tests: $(addprefix $(BUILD_DIR), sl_list_tests)

sl_list_time: sl_list_tests
	/usr/bin/time -v $(addprefix $(BUILD_DIR), $^)

sl_list_vg: sl_list_tests
	@echo "\nSingly-linked List Valgrind Test"
	@valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^) 2>&1 | grep -i -e "total heap usage" -e "All heap" -e "definitely lost" -e "indirectly lost" -e "ERROR SUMMARY" -e "LEAK SUMMARY" -e "HEAP SUMMARY"
	@echo

# Double Linked List
$(addprefix $(BUILD_DIR), dl_list_tests.o): $(addprefix $(TESTS_DIR), lists/dl_list_tests.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), dl_list_tests): $(addprefix $(BUILD_DIR), dl_list_tests.o dl_list.o dl_iterator.o)
	$(CC) $(CFLAGS) $^ -o $@

dl_list_tests: $(addprefix $(BUILD_DIR), dl_list_tests)

dl_list_time: dl_list_tests
	/usr/bin/time -v $(addprefix $(BUILD_DIR), $^)

dl_list_vg: dl_list_tests
	@echo "\nDoubly-linked List Valgrind Test"
	@valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^) 2>&1 | grep -i -e "total heap usage" -e "All heap" -e "definitely lost" -e "indirectly lost" -e "ERROR SUMMARY" -e "LEAK SUMMARY" -e "HEAP SUMMARY"
	@echo

# Double Circular List
$(addprefix $(BUILD_DIR), cl_list_tests.o): $(addprefix $(TESTS_DIR), lists/cl_list_tests.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), cl_list_tests): $(addprefix $(BUILD_DIR), cl_list_tests.o cl_list.o cl_iterator.o)
	$(CC) $(CFLAGS) $^ -o $@

cl_list_tests: $(addprefix $(BUILD_DIR), cl_list_tests)

cl_list_time: cl_list_tests
	/usr/bin/time -v $(addprefix $(BUILD_DIR), $^)

cl_list_vg: cl_list_tests
	@echo "\nDoubly-linked List Valgrind Test"
	@valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^) 2>&1 | grep -i -e "total heap usage" -e "All heap" -e "definitely lost" -e "indirectly lost" -e "ERROR SUMMARY" -e "LEAK SUMMARY" -e "HEAP SUMMARY"
	@echo
