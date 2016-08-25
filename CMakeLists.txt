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
include_directories(${BOEHM_GC_INCLUDE_DIR})
set(LIBS ${LIBS} ${BOEHM_GC_LIBRARIES})
target_link_libraries(demo ${LIBS})
