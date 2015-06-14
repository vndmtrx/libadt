# Compilation rules for lib tests.

# SLIST
include tests/lists/list_tests.mk

tests: slist_tests

time_tests: slist_time

trace_tests: slist_trace

vg_tests: slist_vg
