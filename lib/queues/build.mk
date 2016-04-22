SL_QUEUE_INC = $(addprefix $(LIB_DIR), queues/sl_queue.c) $(addprefix $(INC_DIR), sl_queue.h) $(SL_LIST_INC)
DQ_QUEUE_INC = $(addprefix $(LIB_DIR), queues/dq_queue.c) $(addprefix $(INC_DIR), dq_queue.h) $(DL_DEQUE_INC)

SL_QUEUE_OBJ = $(addprefix $(BUILD_DIR), sl_queue.o) $(SL_LIST_OBJ)
DQ_QUEUE_OBJ = $(addprefix $(BUILD_DIR), dq_queue.o) $(DL_DEQUE_OBJ)

# Build target for singly-list-backed queue

$(addprefix $(BUILD_DIR), sl_queue.o): $(SL_QUEUE_INC) | build
	$(CC) $(CLIBFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), sl_queue.a): $(SL_QUEUE_OBJ)
	$(AR) $(ARFLAGS) $@ $^
	$(RL) $@

# Build target for deque-backed queue

$(addprefix $(BUILD_DIR), dq_queue.o): $(DQ_QUEUE_INC) | build
	$(CC) $(CLIBFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), dq_queue.a): $(DQ_QUEUE_OBJ)
	$(AR) $(ARFLAGS) $@ $^
	$(RL) $@

# Build targets for standalone compilation

sl_queue.a: $(addprefix $(BUILD_DIR), sl_queue.a)

dq_queue.a: $(addprefix $(BUILD_DIR), dq_queue.a)

queues: sl_queue.a dq_queue.a
