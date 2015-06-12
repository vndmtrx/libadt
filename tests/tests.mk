# Compilation rules for lib tests.

# SLIST
include tests/slist/slist_test.mk

tests: test1

time_test: runtest1

strace_test: tracetest1

valgrind_test: valgrindtest1
