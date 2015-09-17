# Build target for Linked List Tests

list_tests: slist_tests dlist_tests

# Single Linked List
$(addprefix $(BUILD_DIR), slist_tests.o): $(addprefix $(TESTS_DIR), lists/slist_tests.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), slist_tests): $(addprefix $(BUILD_DIR), slist_tests.o slist.o)
	$(CC) $(LDFLAGS) $^ -o $@

slist_tests: $(addprefix $(BUILD_DIR), slist_tests)

slist_time: slist_tests
	/usr/bin/time -v $(addprefix $(BUILD_DIR), $^)

slist_vg: slist_tests
	valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^)

# Double Linked List
$(addprefix $(BUILD_DIR), dlist_tests.o): $(addprefix $(TESTS_DIR), lists/dlist_tests.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), dlist_tests): $(addprefix $(BUILD_DIR), dlist_tests.o dlist.o)
	$(CC) $(LDFLAGS) $^ -o $@

dlist_tests: $(addprefix $(BUILD_DIR), dlist_tests)

dlist_time: dlist_tests
	/usr/bin/time -v $(addprefix $(BUILD_DIR), $^)

dlist_vg: dlist_tests
	valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^)
