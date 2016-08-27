cmake_minimum_required(VERSION 3.6)
project(demo)

set(Demo_VERSION_MAJOR 0)

configure_file(
        "${PROJECT_SOURCE_DIR}/main.h.in"
        "${PROJECT_BINARY_DIR}/main.h"
)

include_directories("${PROJECT_BINARY_DIR}")

set(SOURCE_FILES main.c main.h.in)
add_executable(demo ${SOURCE_FILES})

#set(EP_LIBHL_DIR "${CMAKE_CURRENT_BINARY_DIR}/EP_LibHL")
#set(GENERATED_DIR "${CMAKE_BINARY_DIR}/generated")
#file(MAKE_DIRECTORY ${GENERATED_DIR})
#file(WRITE ${GENERATED_DIR}/CMakeLists.txt
#        "cmake_minimum_required(VERSION 3.6)\n"
#        "project(LibHL)\n"
#        "file (GLOB SOURCES src/*.c)\n"
#        "include_directories (src)\n"
#        "add_library (hl STATIC ${SOURCES})\n")

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/include)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include(ExternalProject)
ExternalProject_Add(LibHL
        GIT_REPOSITORY https://github.com/xant/libhl.git
        GIT_TAG libhl-3.1
        BUILD_IN_SOURCE 1
#        UPDATE_COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/generated/CMakeLists.txt ${EP_LIBHL_DIR}/src/libhl
        CONFIGURE_COMMAND sh -c "cd build$<SEMICOLON>./configure --verbose --prefix=${CMAKE_BINARY_DIR}"
        BUILD_COMMAND sh -c "cd build$<SEMICOLON>make"
        INSTALL_COMMAND sh -c "cd build$<SEMICOLON>make install"
        )
add_dependencies(demo LibHL)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")
find_package(GC REQUIRED)
target_include_directories(demo PUBLIC ${BOEHM_GC_INCLUDE_DIR})
target_link_libraries(demo ${BOEHM_GC_LIBRARIES} ${CMAKE_BINARY_DIR}/lib/libhl.a)
