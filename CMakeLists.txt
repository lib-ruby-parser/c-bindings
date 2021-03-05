cmake_minimum_required(VERSION 3.10)

project(lib-ruby-parser-c-bindings)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

IF( NOT CMAKE_BUILD_TYPE )
   SET( CMAKE_BUILD_TYPE Debug )
ENDIF()
string(TOLOWER ${CMAKE_BUILD_TYPE} RUST_ENV)

# Rust static lib

if(WIN32)
    set(RUST_TARGET "x86_64-pc-windows-msvc")
elseif(CMAKE_SYSTEM_NAME STREQUAL Darwin)
    set(RUST_TARGET "x86_64-apple-darwin")
else()
    set(RUST_TARGET "x86_64-unknown-linux-gnu")
endif()

SET(CARGOFLAGS $ENV{CARGOFLAGS})
LIST(APPEND CARGOFLAGS "--target" ${RUST_TARGET})
if(RUST_ENV STREQUAL "release")
    LIST(APPEND CARGOFLAGS "--release")
ENDIF()

SET(RUST_DIR "lib-ruby-parser-c-bindings")
IF(WIN32)
    SET(RUST_OUT_FILE "lib_ruby_parser_c_bindings.lib")
ELSE()
    SET(RUST_OUT_FILE "liblib_ruby_parser_c_bindings.a")
ENDIF()

SET(RUST_LIB_FILE "${RUST_DIR}/target/${RUST_TARGET}/${RUST_ENV}/${RUST_OUT_FILE}")

file(GLOB RUST_SRC_FILES "lib-ruby-parser-c-bindings/**/*.rs")

add_custom_command(
    OUTPUT ${RUST_LIB_FILE}
    COMMAND cargo build ${CARGOFLAGS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${RUST_DIR}
    DEPENDS ${RUST_SRC_FILES}
    COMMENT "running cargo")
add_custom_target(
    lib_ruby_parser_rust_target DEPENDS ${RUST_LIB_FILE}
    COMMENT "lib_ruby_parser_rust_target")
add_library(lib_ruby_parser_rust STATIC IMPORTED GLOBAL)
add_dependencies(lib_ruby_parser_rust lib_ruby_parser_rust_target)
set_target_properties(lib_ruby_parser_rust PROPERTIES IMPORTED_LOCATION ${RUST_LIB_FILE})

# C object files

file(GLOB C_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
add_library(all_o OBJECT ${C_SRC_FILES})
list(APPEND C_OBJ_FILES $<JOIN:$<TARGET_OBJECTS:all_o>,$<SEMICOLON>>)

# C + Rust static lib

IF(WIN32)
    add_custom_command(
        lib-ruby-parser-full-static ALL
        COMMAND lib.exe ws2_32.lib advapi32.lib userenv.lib /OUT:lib-ruby-parser.lib ${C_OBJ_FILES}
        DEPENDS all_o
        COMMAND_EXPAND_LISTS
    )
ELSE()
    SET(MERGED_C_OBJECTS "lib-ruby-parser-c-merged.o")
    add_custom_command(
        OUTPUT ${MERGED_C_OBJECTS}
        COMMAND ${CMAKE_LINKER} -r -o ${MERGED_C_OBJECTS} ${C_OBJ_FILES}
        DEPENDS all_o
        COMMAND_EXPAND_LISTS
    )
    add_custom_target(lib_ruby_parser_c_merged_target DEPENDS ${MERGED_C_OBJECTS})
    add_library(lib_ruby_parser_c_merged STATIC IMPORTED GLOBAL)
    add_dependencies(lib_ruby_parser_c_merged lib_ruby_parser_c_merged_target)
    set_target_properties(lib_ruby_parser_c_merged PROPERTIES IMPORTED_LOCATION ${MERGED_C_OBJECTS})

    SET(FULL_STATIC_LIB "ruby-parser-full-static.a")
    add_custom_command(
        OUTPUT ${FULL_STATIC_LIB}

        COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/$<TARGET_LINKER_FILE:lib_ruby_parser_rust> ${FULL_STATIC_LIB}
        COMMAND ar -rv ${FULL_STATIC_LIB} ${MERGED_C_OBJECTS}

        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}

        DEPENDS
            ${RUST_LIB_FILE}
            ${MERGED_C_OBJECTS}

        COMMENT "Linking ruby-parser-full-static.a"
    )
    add_custom_target(lib_ruby_parser_full_target DEPENDS ${FULL_STATIC_LIB})
    add_library(lib_ruby_parser_full STATIC IMPORTED GLOBAL)
    add_dependencies(lib_ruby_parser_full lib_ruby_parser_full_target)
    set_target_properties(lib_ruby_parser_full PROPERTIES IMPORTED_LOCATION ${FULL_STATIC_LIB})
ENDIF()

# lib-ruby-parser.h

SET(LIB_RUBY_PARSER_H "lib-ruby-parser.h")

file(GLOB H_FILES "src/*.h")

add_custom_command(
    OUTPUT ${LIB_RUBY_PARSER_H}
    COMMAND ./build-headers
    COMMENT Creating ${LIB_RUBY_PARSER_H}
    DEPENDS build-headers ${H_FILES}
)

add_custom_target(header ALL
    DEPENDS ${LIB_RUBY_PARSER_H}
)

# test-runner

add_executable(test-runner "test.c")
add_dependencies(test-runner header)
target_link_libraries(test-runner lib_ruby_parser_full)

# fuzzer

add_executable(fuzzer "fuzzer/parse.c")
set_target_properties(fuzzer PROPERTIES COMPILE_FLAGS "-fsanitize=fuzzer,address")
set_target_properties(fuzzer PROPERTIES LINK_FLAGS "-fsanitize=fuzzer,address")
add_dependencies(fuzzer header)
target_link_libraries(fuzzer lib_ruby_parser_full)

# print env

function(printVar)
    list(GET ARGV 0 VAR_NAME)
    MESSAGE(STATUS "  ${VAR_NAME} = ${${VAR_NAME}}")
endfunction()

MESSAGE(STATUS "ENV:\n--")
printVar(CMAKE_BUILD_TYPE)
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

