cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "libadt")

project(${PROJECT_NAME})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Werror -Wextra -std=c11 -coverage -O0")

include_directories(includes)

add_subdirectory(lib)

add_subdirectory(algorithms)
