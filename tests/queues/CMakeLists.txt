add_executable(sl_queue_tests sl_queue_tests.c)
add_executable(dq_queue_tests dq_queue_tests.c)

target_link_libraries(sl_queue_tests sl_queue sl_iterator)
target_link_libraries(dq_queue_tests dq_queue dl_iterator)

add_test(NAME sl_queue_tests COMMAND sl_queue_tests)
add_test(NAME dq_queue_tests COMMAND dq_queue_tests)
