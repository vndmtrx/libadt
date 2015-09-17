#Compilation rules for lib items.

#LISTS - Build target for Linked Lists
include $(addprefix $(LIB_DIR), lists/build.mk)

#QUEUES - Build target for Queues
include $(addprefix $(LIB_DIR), queues/build.mk)

#STACKS - Build target for Stacks
include $(addprefix $(LIB_DIR), stacks/build.mk)

#DEQUES - Build target for Deques
include $(addprefix $(LIB_DIR), deques/build.mk)

libs: slist.o dlist.o sl_stack.o sl_queue.o dl_deque.o
