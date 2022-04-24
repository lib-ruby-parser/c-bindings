cmake_minimum_required(VERSION 3.10)

project(lib-ruby-parser)

if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Debug)
endif()

# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#     set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DTEST_ENV")
# endif()

set(RUST_TARGET "x86_64-apple-darwin")

set(ROOT_DIR    ${CMAKE_SOURCE_DIR})
set(CODEGEN_DIR ${ROOT_DIR}/codegen)
set(SRC_DIR     ${ROOT_DIR}/src)
set(TESTS_DIR   ${ROOT_DIR}/tests)
set(RUST_DIR    ${ROOT_DIR}/ruby-parser-c)

add_subdirectory(codegen)
add_subdirectory(ruby-parser-c)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(benchmark)
