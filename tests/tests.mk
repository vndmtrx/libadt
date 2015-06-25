# Compilation rules for lib tests.

# LISTS
include tests/lists/build.mk

# QUEUES
include tests/queues/build.mk

# STACKS
include tests/stacks/build.mk

tests: list_tests

time_tests: slist_time dlist_time

trace_tests: slist_trace dlist_trace

vg_tests: slist_vg dlist_vg
