## Build target for Stack examples

# Queues
$(addprefix $(BUILD_DIR), topostfix.o): $(addprefix $(EXAMPLES_DIR), stacks/topostfix.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), topostfix): $(addprefix $(BUILD_DIR), topostfix.o sl_stack.o)
	$(CC) $(LDFLAGS) $^ -o $@

topostfix: $(addprefix $(BUILD_DIR), topostfix)

topostfix_test: topostfix
	echo "Test: A*B+C -> AB*C+;"
	echo "A*B+C" | $(addprefix $(BUILD_DIR), $^)
	echo "Test: A+B*C -> ABC*+;"
	echo "A+B*C" | $(addprefix $(BUILD_DIR), $^)
	echo "Test: A*(B+C) -> ABC+*;"
	echo "A*(B+C)" | $(addprefix $(BUILD_DIR), $^)
	echo "Test: A-B+C -> AB-C+;"
	echo "A-B+C" | $(addprefix $(BUILD_DIR), $^)
	echo "Test: A*B^C+D -> ABC^*D+;"
	echo "A*B^C+D" | $(addprefix $(BUILD_DIR), $^)
	echo "Test: A*(B+C*D)+E -> ABCD*+*E+;"
	echo "A*(B+C*D)+E" | $(addprefix $(BUILD_DIR), $^)

topostfix_vg: topostfix
	echo "123+45+98534-1326847#123276!438947StRiNg222*11111" | valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^)

