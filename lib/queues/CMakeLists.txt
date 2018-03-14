add_library(sl_queue sl_queue.c)
add_library(dq_queue dq_queue.c)

target_link_libraries(sl_queue sl_list)
target_link_libraries(dq_queue dl_deque)

target_include_directories(sl_queue PUBLIC includes)
target_include_directories(dq_queue PUBLIC includes)

set_target_properties(sl_queue dq_queue PROPERTIES PREFIX "")
