# Compilation rules for lib tests.

# LISTS
include $(addprefix $(TESTS_DIR), lists/build.mk)

# QUEUES
include $(addprefix $(TESTS_DIR), queues/build.mk)

# STACKS
include $(addprefix $(TESTS_DIR), stacks/build.mk)

# DEQUES
include $(addprefix $(TESTS_DIR), deques/build.mk)

tests: list_tests queue_tests stack_tests deque_tests

vg_tests: list_vg_tests deque_vg_tests queue_vg_tests stack_vg_tests
