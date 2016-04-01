SL_LIST_INC := $(addprefix $(LIB_DIR), lists/sl_list.c) $(addprefix $(INC_DIR), sl_list.h)
DL_LIST_INC := $(addprefix $(LIB_DIR), lists/dl_list.c) $(addprefix $(INC_DIR), dl_list.h)

# Build target for Single Linked List
$(addprefix $(BUILD_DIR), sl_list.o): $(SL_LIST_INC) | build
	$(CC) $(CFLAGS) -c $< -o $@

sl_list.o: $(addprefix $(BUILD_DIR), sl_list.o)

# Build target for Double Linked List
$(addprefix $(BUILD_DIR), dl_list.o): $(DL_LIST_INC) | build
	$(CC) $(CFLAGS) -c $< -o $@

dl_list.o: $(addprefix $(BUILD_DIR), dl_list.o)
