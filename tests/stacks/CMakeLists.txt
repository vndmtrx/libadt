add_executable(sl_stack_tests sl_stack_tests.c)
add_executable(dq_stack_tests dq_stack_tests.c)

target_link_libraries(sl_stack_tests sl_stack sl_iterator)
target_link_libraries(dq_stack_tests dq_stack dl_iterator)

add_test(NAME sl_stack_tests COMMAND sl_stack_tests)
add_test(NAME dq_stack_tests COMMAND dq_stack_tests)
