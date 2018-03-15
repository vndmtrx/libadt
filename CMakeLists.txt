cmake_minimum_required(VERSION 3.0)

set(PRJ_NAME "libadt")

project(${PRJ_NAME})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Wextra -std=c11 -coverage -O0")

include_directories(includes)

add_subdirectory(lib)

add_subdirectory(algorithms)

enable_testing()

add_subdirectory(examples)

add_subdirectory(tests)
