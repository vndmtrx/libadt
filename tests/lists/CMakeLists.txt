add_executable(sl_list_test_new sl_list_test_new.c)
target_link_libraries(sl_list_test_new sl_list sl_iterator ${CHECK_LIBRARIES} pthread)
add_test(NAME sl_list_test_new COMMAND sl_list_test_new WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Testing)
add_custom_target(valgrind_sl_list_test_new
  COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:sl_list_test_new>
  DEPENDS sl_list_test_new
)

add_executable(sl_list_tests sl_list_tests.c)
add_executable(dl_list_tests dl_list_tests.c)
add_executable(cl_list_tests cl_list_tests.c)

target_link_libraries(sl_list_tests sl_list sl_iterator ${CHECK_LIBRARIES} pthread)
target_link_libraries(dl_list_tests dl_list dl_iterator ${CHECK_LIBRARIES} pthread)
target_link_libraries(cl_list_tests cl_list cl_iterator ${CHECK_LIBRARIES} pthread)

add_test(NAME sl_list_tests COMMAND sl_list_tests WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Testing)
add_test(NAME dl_list_tests COMMAND dl_list_tests WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Testing)
add_test(NAME cl_list_tests COMMAND cl_list_tests WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Testing)

add_custom_target(valgrind_sl_list_tests
  COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:sl_list_tests>
  DEPENDS sl_list_tests
)
add_custom_target(valgrind_dl_list_tests
  COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:dl_list_tests>
  DEPENDS dl_list_tests
)
add_custom_target(valgrind_cl_list_tests
  COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:cl_list_tests>
  DEPENDS cl_list_tests
)
