DL_DEQUE_INC := $(addprefix $(LIB_DIR), deques/dl_deque.c) $(addprefix $(INC_DIR), dl_deque.h) $(DL_LIST_INC)

# Build target for doubly-list-backed deque

$(addprefix $(BUILD_DIR), dl_deque.o): $(DL_DEQUE_INC) | build
	$(CC) $(CLIBFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), dl_deque.a): $(addprefix $(BUILD_DIR), dl_deque.o dl_list.a)
	$(AR) $(ARFLAGS) $@ $^
	$(RL) $@

# Build targets for standalone compilation

dl_deque.a: $(addprefix $(BUILD_DIR), dl_deque.a)

deques: dl_deque.a
