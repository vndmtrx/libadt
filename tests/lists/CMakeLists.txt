add_executable(sl_list_tests sl_list_tests.c)

target_link_libraries(sl_list_tests sl_list sl_iterator)

add_test(NAME sl_list_tests COMMAND sl_list_tests)
