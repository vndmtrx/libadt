# Build target for Single Linked List
$(addprefix $(BUILD_DIR), slist.o): $(addprefix $(LIB_DIR), lists/slist.c) $(addprefix $(INC_DIR), slist.h) | build
	$(CC) $(CFLAGS) -c $< -o $@

# Build target for Double Linked List
$(addprefix $(BUILD_DIR), dlist.o): $(addprefix $(LIB_DIR), lists/dlist.c) $(addprefix $(INC_DIR), dlist.h) | build
	$(CC) $(CFLAGS) -c $< -o $@

slist.o: $(addprefix $(BUILD_DIR), slist.o)

dlist.o: $(addprefix $(BUILD_DIR), dlist.o)
