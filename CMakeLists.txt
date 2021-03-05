cmake_minimum_required(VERSION 3.10)

project(lib-ruby-parser-c-bindings)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Debug)
endif()
string(TOLOWER ${CMAKE_BUILD_TYPE} RUST_ENV)

if(WIN32)
    set(PLATFORM "windows")
elseif(APPLE)
    set(PLATFORM "darwin")
elseif(UNIX)
    set(PLATFORM "linux")
else()
    message(ERROR "Unable to recognize platform")
endif()

function(turn_custom_command_into_static_library)
    list(GET ARGV 0 LIB_NAME)
    list(GET ARGV 1 OUTPUT_FILE)

    add_custom_target(${LIB_NAME}_target ALL DEPENDS ${OUTPUT_FILE} COMMENT ${LIB_NAME}_target)
    add_library(${LIB_NAME} STATIC IMPORTED GLOBAL)
    add_dependencies(${LIB_NAME} ${LIB_NAME}_target)
    set_target_properties(${LIB_NAME} PROPERTIES IMPORTED_LOCATION ${OUTPUT_FILE})
endfunction()

# Rust static lib

if(WIN32)
    set(RUST_TARGET x86_64-pc-windows-msvc)
elseif(APPLE)
    set(RUST_TARGET x86_64-apple-darwin)
elseif(UNIX)
    set(RUST_TARGET x86_64-unknown-linux-gnu)
endif()

set(CARGOFLAGS $ENV{CARGOFLAGS})
list(APPEND CARGOFLAGS "--target" ${RUST_TARGET})
if(RUST_ENV STREQUAL "release")
    list(APPEND CARGOFLAGS "--release")
endif()

set(RUST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib-ruby-parser-c-bindings)
if(WIN32)
    set(RUST_OUT_FILE "lib_ruby_parser_c_bindings.lib")
else()
    set(RUST_OUT_FILE "liblib_ruby_parser_c_bindings.a")
endif()

set(RUST_LIB_FILE "${RUST_DIR}/target/${RUST_TARGET}/${RUST_ENV}/${RUST_OUT_FILE}")

file(GLOB RUST_SRC_FILES "lib-ruby-parser-c-bindings/**/*.rs")

add_custom_command(
    OUTPUT ${RUST_LIB_FILE}
    COMMAND cargo build ${CARGOFLAGS}
    WORKING_DIRECTORY ${RUST_DIR}
    DEPENDS ${RUST_SRC_FILES}
    COMMENT "running cargo")
turn_custom_command_into_static_library(lib_ruby_parser_rust_static ${RUST_LIB_FILE})

# Rust object file

set(RUST_OBJ_FILE "${CMAKE_CURRENT_BINARY_DIR}/rust${CMAKE_C_OUTPUT_EXTENSION}")
add_custom_command(
    OUTPUT ${RUST_OBJ_FILE}
    COMMAND RUST_LIB_FILE=${RUST_LIB_FILE}
            RUST_OBJ_FILE=${RUST_OBJ_FILE}
            bash ${CMAKE_CURRENT_SOURCE_DIR}/scripts/static-lib-to-object-${PLATFORM}.sh
    DEPENDS ${RUST_LIB_FILE}
    COMMENT "convert Rust static lib into a single object file")
turn_custom_command_into_static_library(lib_ruby_parser_rust_obj ${RUST_OBJ_FILE})

# C object files

file(GLOB C_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
add_library(c_obj_files OBJECT ${C_SRC_FILES})

# C + Rust static lib

add_library(lib_ruby_parser_full STATIC
    $<TARGET_OBJECTS:c_obj_files>
    $<TARGET_FILE:lib_ruby_parser_rust_obj>)

# lib-ruby-parser.h

set(LIB_RUBY_PARSER_H "lib-ruby-parser.h")

file(GLOB H_FILES "src/*.h")

add_custom_command(
    OUTPUT ${LIB_RUBY_PARSER_H}
    COMMAND bash ${CMAKE_CURRENT_SOURCE_DIR}/scripts/build-headers
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/scripts/build-headers ${H_FILES}
    COMMENT Creating ${LIB_RUBY_PARSER_H})

add_custom_target(header ALL DEPENDS ${LIB_RUBY_PARSER_H})

# test-runner

if(UNIX)
    link_libraries(pthread dl)
endif()

add_executable(test-runner "test.c")
add_dependencies(test-runner header)
target_link_libraries(test-runner lib_ruby_parser_full)

# fuzzer

if(UNIX)
    add_executable(fuzzer "fuzzer/parse.c")
    set(USE_FUZZER "-fsanitize=fuzzer,address")
    set_target_properties(fuzzer PROPERTIES COMPILE_FLAGS ${USE_FUZZER} LINK_FLAGS ${USE_FUZZER})
    add_dependencies(fuzzer header)
    target_link_libraries(fuzzer lib_ruby_parser_full)
endif()

# print env

function(printVar)
    list(GET ARGV 0 VAR_NAME)
    MESSAGE(STATUS "  ${VAR_NAME} = ${${VAR_NAME}}")
endfunction()

MESSAGE(STATUS "ENV:\n--")
printVar(CMAKE_BUILD_TYPE)
printVar(PLATFORM)
printVar(CMAKE_C_COMPILER)
printVar(CMAKE_C_FLAGS)
printVar(CMAKE_C_FLAGS_DEBUG)
printVar(CMAKE_C_FLAGS_RELEASE)
printVar(COMPILE_OPTIONS)
printVar(CMAKE_CURRENT_SOURCE_DIR)
printVar(CMAKE_CURRENT_BINARY_DIR)
printVar(CARGOFLAGS)
printVar(RUST_LIB_FILE)
printVar(CMAKE_EXE_LINKER_FLAGS)
printVar(CMAKE_EXE_LINKER_FLAGS_DEBUG)
printVar(CMAKE_EXE_LINKER_FLAGS_RELEASE)
MESSAGE(STATUS "\n--\n--")

