# Compilation rules for lib tests.

# LISTS
include $(addprefix $(TESTS_DIR), lists/build.mk)

# QUEUES
include $(addprefix $(TESTS_DIR), queues/build.mk)

# STACKS
include $(addprefix $(TESTS_DIR), stacks/build.mk)

tests: list_tests queue_tests stack_tests

vg_tests: slist_vg dlist_vg sl_queue_vg sl_stack_vg
