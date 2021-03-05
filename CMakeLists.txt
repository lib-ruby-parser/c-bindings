cmake_minimum_required(VERSION 3.10)

project(lib-ruby-parser-c-bindings)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(VERBOSE true)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib-ruby-parser-c-bindings)
add_subdirectory(${CMAKE_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_SOURCE_DIR}/tests)
add_subdirectory(${CMAKE_SOURCE_DIR}/fuzzer)

# Mark Rust obj as generated here,
# otherwise $<TARGET_FILE:lib_ruby_parser_rust_obj> it not visible in this file;
# It will be fixed in 3.20: https://gitlab.kitware.com/cmake/cmake/-/issues/18399#note_ad47edaeb097e80453e660e157730850235f7849
set_source_files_properties(${RUST_OBJ_FILE} PROPERTIES GENERATED 1)

# C + Rust static lib
add_library(lib_ruby_parser_full STATIC
    $<TARGET_OBJECTS:c_obj_files> $<TARGET_FILE:lib_ruby_parser_rust_obj>)

# this it also required because Rust obj is "generated out of nowhere"
# by marking it as "generated" manually above
add_dependencies(lib_ruby_parser_full lib_ruby_parser_rust_obj_target)

# lib-ruby-parser.h

file(GLOB H_FILES "src/*.h")
add_custom_command(
    OUTPUT lib-ruby-parser.h
    COMMAND bash ${CMAKE_CURRENT_SOURCE_DIR}/scripts/build-headers
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/scripts/build-headers ${H_FILES}
    COMMENT Creating lib-ruby-parser.h)
add_custom_target(header ALL DEPENDS lib-ruby-parser.h)
