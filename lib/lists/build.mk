SL_LIST_INC := $(addprefix $(LIB_DIR), lists/sl_list.c) $(addprefix $(INC_DIR), sl_list.h)
DL_LIST_INC := $(addprefix $(LIB_DIR), lists/dl_list.c) $(addprefix $(INC_DIR), dl_list.h)
CL_LIST_INC := $(addprefix $(LIB_DIR), lists/cl_list.c) $(addprefix $(INC_DIR), cl_list.h)

lists_o: sl_list.o dl_list.o cl_list.o

# Build target for Single Linked List
$(addprefix $(BUILD_DIR), sl_list.o): $(SL_LIST_INC) | build
	$(CC) $(CFLAGS) -c $< -o $@

sl_list.o: $(addprefix $(BUILD_DIR), sl_list.o)

# Build target for Double Linked List
$(addprefix $(BUILD_DIR), dl_list.o): $(DL_LIST_INC) | build
	$(CC) $(CFLAGS) -c $< -o $@

dl_list.o: $(addprefix $(BUILD_DIR), dl_list.o)

# Build target for Circular Linked List
$(addprefix $(BUILD_DIR), cl_list.o): $(CL_LIST_INC) | build
	$(CC) $(CFLAGS) -c $< -o $@

cl_list.o: $(addprefix $(BUILD_DIR), cl_list.o)
