# Compilation rules for lib examples.

# LISTS

include $(addprefix $(EXAMPLES_DIR), lists/build.mk)

# QUEUES
include $(addprefix $(EXAMPLES_DIR), queues/build.mk)

# STACKS
include $(addprefix $(EXAMPLES_DIR), stacks/build.mk)

examples: evaluator topostfix
