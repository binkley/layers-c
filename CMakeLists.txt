cmake_minimum_required(VERSION 3.6)
project(demo)

set(Demo_VERSION_MAJOR 0)

configure_file(
        "${PROJECT_SOURCE_DIR}/main.h.in"
        "${PROJECT_BINARY_DIR}/main.h"
)

include_directories("${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c++ main.h.in)
add_executable(demo ${SOURCE_FILES})
