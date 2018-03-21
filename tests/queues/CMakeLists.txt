add_executable(sl_queue_tests sl_queue_tests.c)
add_executable(dq_queue_tests dq_queue_tests.c)

target_link_libraries(sl_queue_tests sl_queue sl_iterator ${CHECK_LIBRARIES} pthread)
target_link_libraries(dq_queue_tests dq_queue dl_iterator ${CHECK_LIBRARIES} pthread)

add_test(NAME sl_queue_tests COMMAND sl_queue_tests WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Testing)
add_test(NAME dq_queue_tests COMMAND dq_queue_tests WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Testing)


add_custom_target(valgrind_sl_queue_tests
  COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:sl_queue_tests>
  DEPENDS sl_queue_tests
)
add_custom_target(valgrind_dq_queue_tests
  COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:dq_queue_tests>
  DEPENDS dq_queue_tests
)
