SL_ITERATOR_INC := $(addprefix $(ALG_DIR), iterators/sl_iterator.c) $(addprefix $(INC_DIR), sl_iterator.h) $(SL_LIST_INC)
DL_ITERATOR_INC := $(addprefix $(ALG_DIR), iterators/dl_iterator.c) $(addprefix $(INC_DIR), dl_iterator.h) $(DL_LIST_INC)

# Build target for Single Linked List Iterator
$(addprefix $(BUILD_DIR), sl_iterator.o): $(SL_ITERATOR_INC) | build
	$(CC) $(CFLAGS) -c $< -o $@

# Build target for Double Linked List Iterator
$(addprefix $(BUILD_DIR), dl_iterator.o): $(DL_ITERATOR_INC) | build
	$(CC) $(CFLAGS) -c $< -o $@

sl_iterator.o: $(addprefix $(BUILD_DIR), sl_iterator.o)

dl_iterator.o: $(addprefix $(BUILD_DIR), dl_iterator.o)
