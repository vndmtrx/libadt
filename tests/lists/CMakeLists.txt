add_executable(sl_list_tests sl_list_tests.c)
add_executable(dl_list_tests dl_list_tests.c)
add_executable(cl_list_tests cl_list_tests.c)

target_link_libraries(sl_list_tests sl_list sl_iterator)
target_link_libraries(dl_list_tests dl_list dl_iterator)
target_link_libraries(cl_list_tests cl_list cl_iterator)

add_test(NAME sl_list_tests COMMAND sl_list_tests)
add_test(NAME dl_list_tests COMMAND dl_list_tests)
add_test(NAME cl_list_tests COMMAND cl_list_tests)
