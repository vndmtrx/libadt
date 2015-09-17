# Build target for doubly-list-backed deque
$(addprefix $(BUILD_DIR), dl_deque.partial): $(addprefix $(LIB_DIR), deques/dl_deque.c) $(addprefix $(INC_DIR), dl_deque.h dlist.h) | build
	$(CC) $(CFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), dl_deque.o): $(addprefix $(BUILD_DIR), dl_deque.partial dlist.o)
	ld $(LDFLAGS) -r $^ -o $@

dl_deque.o: $(addprefix $(BUILD_DIR), dl_deque.o)
