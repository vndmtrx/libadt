add_library(sl_list sl_list.c)
add_library(dl_list dl_list.c)
add_library(cl_list cl_list.c)

target_include_directories(sl_list PUBLIC includes)
target_include_directories(dl_list PUBLIC includes)
target_include_directories(cl_list PUBLIC includes)

set_target_properties(sl_list dl_list cl_list PROPERTIES PREFIX "${PRJ_NAME}_")
