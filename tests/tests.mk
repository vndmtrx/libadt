# Compilation rules for lib tests.

# LISTS
include tests/lists/build.mk

# QUEUES
include tests/queues/build.mk

# STACKS
include tests/stacks/build.mk

mk_tests: list_tests queue_tests stack_tests

vg_tests: slist_vg dlist_vg sl_queue_vg sl_stack_vg
