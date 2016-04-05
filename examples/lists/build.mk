## Build target for Queue examples

# Queues
$(addprefix $(BUILD_DIR), sl_tortoise_and_hare.o): $(addprefix $(EXAMPLES_DIR), lists/sl_tortoise_and_hare.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), sl_tortoise_and_hare): $(addprefix $(BUILD_DIR), sl_tortoise_and_hare.o sl_list.o)
	$(CC) $(CFLAGS) $^ -o $@

sl_tortoise_and_hare: $(addprefix $(BUILD_DIR), sl_tortoise_and_hare)
