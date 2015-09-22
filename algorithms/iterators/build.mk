# Build target for Single Linked List
$(addprefix $(BUILD_DIR), sl_iterator.o): $(addprefix $(ALG_DIR), iterators/sl_iterator.c) $(addprefix $(INC_DIR), sl_iterator.h) | build
	$(CC) $(CFLAGS) -c $< -o $@

# Build target for Double Linked List
$(addprefix $(BUILD_DIR), dl_iterator.o): $(addprefix $(ALG_DIR), iterators/dl_iterator.c) $(addprefix $(INC_DIR), dl_iterator.h) | build
	$(CC) $(CFLAGS) -c $< -o $@

sl_iterator.o: $(addprefix $(BUILD_DIR), sl_iterator.o)

dl_iterator.o: $(addprefix $(BUILD_DIR), dl_iterator.o)
