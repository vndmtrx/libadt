add_library(sl_stack sl_stack.c)
add_library(dq_stack dq_stack.c)

target_link_libraries(sl_stack sl_list)
target_link_libraries(dq_stack dl_deque)

target_include_directories(sl_stack PUBLIC includes)
target_include_directories(dq_stack PUBLIC includes)

set_target_properties(sl_stack dq_stack PROPERTIES PREFIX "")
