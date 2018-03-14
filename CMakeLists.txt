cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "libadt")

project(${PROJECT_NAME})

include_directories(includes)

add_subdirectory(lib)

add_subdirectory(algorithms)
