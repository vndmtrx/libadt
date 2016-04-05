SL_STACK_INC := $(addprefix $(LIB_DIR), stacks/sl_stack.c) $(addprefix $(INC_DIR), sl_stack.h) $(SL_LIST_INC)
DQ_STACK_INC := $(addprefix $(LIB_DIR), stacks/dq_stack.c) $(addprefix $(INC_DIR), dq_stack.h) $(DL_DEQUE_INC)

# Build target for singly-list-backed stack
$(addprefix $(BUILD_DIR), sl_stack.partial): $(SL_STACK_INC) | build
	$(CC) $(CFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), sl_stack.o): $(addprefix $(BUILD_DIR), sl_stack.partial sl_list.o)
	$(LD) $(LDFLAGS) -r $^ -o $@

sl_stack.o: $(addprefix $(BUILD_DIR), sl_stack.o)

# Build target for deque-backed stack
$(addprefix $(BUILD_DIR), dq_stack.partial): $(DQ_STACK_INC) | build
	$(CC) $(CFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), dq_stack.o): $(addprefix $(BUILD_DIR), dq_stack.partial dl_deque.o)
	$(LD) $(LDFLAGS) -r $^ -o $@

dq_stack.o: $(addprefix $(BUILD_DIR), dq_stack.o)
