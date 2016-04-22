#Compilation rules for lib items.

#LISTS - Build target for Linked Lists
include $(addprefix $(LIB_DIR), lists/build.mk)

#DEQUES - Build target for Deques
include $(addprefix $(LIB_DIR), deques/build.mk)

#QUEUES - Build target for Queues
include $(addprefix $(LIB_DIR), queues/build.mk)

#STACKS - Build target for Stacks
include $(addprefix $(LIB_DIR), stacks/build.mk)

libs: lists deques stacks queues
