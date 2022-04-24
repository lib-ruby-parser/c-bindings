cmake_minimum_required(VERSION 3.10)

project(lib-ruby-parser C)

if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Debug)
endif()

set(RUST_TARGET "$ENV{RUST_TARGET}")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
   add_compile_definitions(TEST_ENV)
   set(CARGOFLAGS "${CARGOFLAGS}" "--features=tests")
endif()

if(MSVC)
   # set(CMAKE_C_FLAGS, "${CMAKE_C_FLAGS} /bigobj /MT /Zi")
elseif(UNIX)
   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic -Weverything -Wdocumentation")
   # but disable -Wpadded, we inherit Rust layouts
   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-padded")
   # ignore documentation, it has examples of syntax errors on purpose
   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-documentation-unknown-command")
else()
   # Ignore MinGW
endif()

if(UNIX AND NOT APPLE)
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lpthread -ldl -lm")
elseif(APPLE)
   #
elseif(MSVC)
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ws2_32.lib userenv.lib bcrypt.lib")
else()
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lws2_32 -luserenv -lbcrypt")
endif()

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
