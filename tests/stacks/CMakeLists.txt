add_executable(sl_stack_tests sl_stack_tests.c)
add_executable(dq_stack_tests dq_stack_tests.c)

target_link_libraries(sl_stack_tests sl_stack sl_iterator ${CHECK_LIBRARIES} pthread)
target_link_libraries(dq_stack_tests dq_stack dl_iterator ${CHECK_LIBRARIES} pthread)

add_test(NAME sl_stack_tests COMMAND sl_stack_tests WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Testing)
add_test(NAME dq_stack_tests COMMAND dq_stack_tests WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Testing)

add_custom_target(valgrind_sl_stack_tests
  COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:sl_stack_tests>
  DEPENDS sl_stack_tests
)
add_custom_target(valgrind_dq_stack_tests
  COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:dq_stack_tests>
  DEPENDS dq_stack_tests
)
