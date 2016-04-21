SL_STACK_INC := $(addprefix $(LIB_DIR), stacks/sl_stack.c) $(addprefix $(INC_DIR), sl_stack.h) $(SL_LIST_INC)
DQ_STACK_INC := $(addprefix $(LIB_DIR), stacks/dq_stack.c) $(addprefix $(INC_DIR), dq_stack.h) $(DL_DEQUE_INC)

# Build target for singly-list-backed stack

$(addprefix $(BUILD_DIR), sl_stack.o): $(SL_STACK_INC) | build
	$(CC) $(CLIBFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), sl_stack.a): $(addprefix $(BUILD_DIR), sl_stack.o sl_list.a)
	$(AR) $(ARFLAGS) $@ $^
	$(RL) $@

# Build target for deque-backed stack

$(addprefix $(BUILD_DIR), dq_stack.o): $(DQ_STACK_INC) | build
	$(CC) $(CLIBFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), dq_stack.a): $(addprefix $(BUILD_DIR), dq_stack.o dl_deque.a)
	$(AR) $(ARFLAGS) $@ $^
	$(RL) $@

# Build targets for standalone compilation

sl_stack.a: $(addprefix $(BUILD_DIR), sl_stack.a)

dq_stack.a: $(addprefix $(BUILD_DIR), dq_stack.a)

stacks: sl_stack.a dq_stack.a
