# Build target for singly-list-backed queue
$(addprefix $(BUILD_DIR), sl_queue.partial): $(addprefix $(LIB_DIR), queues/sl_queue.c) $(addprefix $(INC_DIR), sl_queue.h slist.h) | build
	$(CC) $(CFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), sl_queue.o): $(addprefix $(BUILD_DIR), sl_queue.partial slist.o)
	ld $(LDFLAGS) -r $^ -o $@

sl_queue.o: $(addprefix $(BUILD_DIR), sl_queue.o)

# Build target for singly-list-backed queue
$(addprefix $(BUILD_DIR), dq_queue.partial): $(addprefix $(LIB_DIR), queues/dq_queue.c) $(addprefix $(INC_DIR), dq_queue.h dl_deque.h) | build
	$(CC) $(CFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), dq_queue.o): $(addprefix $(BUILD_DIR), dq_queue.partial dl_deque.o)
	ld $(LDFLAGS) -r $^ -o $@

dq_queue.o: $(addprefix $(BUILD_DIR), dq_queue.o)
