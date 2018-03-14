project(iterators)

add_library(sl_iterator sl_iterator.c)
add_library(dl_iterator dl_iterator.c)

target_link_libraries(sl_iterator sl_list)
target_link_libraries(dl_iterator dl_list)

target_include_directories(sl_iterator PUBLIC includes)
target_include_directories(dl_iterator PUBLIC includes)

set_target_properties(sl_iterator dl_iterator PROPERTIES PREFIX "")
