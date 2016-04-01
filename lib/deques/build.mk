DL_DEQUE_INC := $(addprefix $(LIB_DIR), deques/dl_deque.c) $(addprefix $(INC_DIR), dl_deque.h) $(DL_LIST_INC)

# Build target for doubly-list-backed deque
$(addprefix $(BUILD_DIR), dl_deque.partial): $(DL_DEQUE_INC) | build
	$(CC) $(CFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), dl_deque.o): $(addprefix $(BUILD_DIR), dl_deque.partial dl_list.o)
	ld $(LDFLAGS) -r $^ -o $@

dl_deque.o: $(addprefix $(BUILD_DIR), dl_deque.o)
