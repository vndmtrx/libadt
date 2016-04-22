SL_LIST_INC = $(addprefix $(LIB_DIR), lists/sl_list.c) $(addprefix $(INC_DIR), sl_list.h)
DL_LIST_INC = $(addprefix $(LIB_DIR), lists/dl_list.c) $(addprefix $(INC_DIR), dl_list.h)
CL_LIST_INC = $(addprefix $(LIB_DIR), lists/cl_list.c) $(addprefix $(INC_DIR), cl_list.h)

SL_LIST_OBJ = $(addprefix $(BUILD_DIR), sl_list.o)
DL_LIST_OBJ = $(addprefix $(BUILD_DIR), dl_list.o)
CL_LIST_OBJ = $(addprefix $(BUILD_DIR), cl_list.o)

# Build target for Single Linked List

$(addprefix $(BUILD_DIR), sl_list.o): $(SL_LIST_INC) | build
	$(CC) $(CLIBFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), sl_list.a): $(SL_LIST_OBJ)
	$(AR) $(ARFLAGS) $@ $^
	$(RL) $@

# Build target for Double Linked List

$(addprefix $(BUILD_DIR), dl_list.o): $(DL_LIST_INC) | build
	$(CC) $(CLIBFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), dl_list.a): $(DL_LIST_OBJ)
	$(AR) $(ARFLAGS) $@ $^
	$(RL) $@

# Build target for Circular Linked List

$(addprefix $(BUILD_DIR), cl_list.o): $(CL_LIST_INC) | build
	$(CC) $(CLIBFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), cl_list.a): $(CL_LIST_OBJ)
	$(AR) $(ARFLAGS) $@ $^
	$(RL) $@

# Build targets for standalone compilation

sl_list.a: $(addprefix $(BUILD_DIR), sl_list.a)

dl_list.a: $(addprefix $(BUILD_DIR), dl_list.a)

cl_list.a: $(addprefix $(BUILD_DIR), cl_list.a)

lists: sl_list.a dl_list.a cl_list.a
