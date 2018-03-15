add_library(dl_deque dl_deque.c)

target_link_libraries(dl_deque dl_list)

target_include_directories(dl_deque PUBLIC includes)

set_target_properties(dl_deque PROPERTIES PREFIX "${PROJECT_NAME}_")
