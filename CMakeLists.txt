project(demo)
cmake_minimum_required(VERSION 3.6)

set(Demo_VERSION_MAJOR 0)

configure_file(
        "${PROJECT_SOURCE_DIR}/main.h.in"
        "${PROJECT_BINARY_DIR}/main.h"
)

include_directories("${PROJECT_BINARY_DIR}")

set(SOURCE_FILES main.c main.h.in)
add_executable(demo ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")
find_package(GC REQUIRED)
target_include_directories(demo PUBLIC ${BOEHM_GC_INCLUDE_DIR})
target_link_libraries(demo ${BOEHM_GC_LIBRARIES})
