# Compilation rules for lib tests.

# SLIST
include tests/lists/build.mk

tests: list_tests

time_tests: slist_time dlist_time

trace_tests: slist_trace dlist_trace

vg_tests: slist_vg dlist_vg
