## Build target for Queue examples

# Queues
$(addprefix $(BUILD_DIR), evaluator.o): $(addprefix $(EXAMPLES_DIR), queues/evaluator.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), evaluator): $(addprefix $(BUILD_DIR), evaluator.o sl_queue.o)
	$(CC) $(LDFLAGS) $^ -o $@

evaluator: $(addprefix $(BUILD_DIR), evaluator)

evaluator_test: evaluator
	echo "123+45+98534" | $(addprefix $(BUILD_DIR), $^)
	echo "123+45-STRING&8+98534" | $(addprefix $(BUILD_DIR), $^)

evaluator_vg: evaluator
	echo "123+45+98534-1326847#123276!438947StRiNg222*11111" | valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^)
