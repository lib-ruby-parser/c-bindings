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

# C + Rust static lib

set(LIB_RUBY_PARSER_FULL "lib_ruby_parser_full${CMAKE_STATIC_LIBRARY_SUFFIX}")
if(WIN32)
    set(PLATFORM "windows")
elseif(APPLE)
    set(PLATFORM "darwin")
elseif(UNIX)
    set(PLATFORM "linux")
else()
    message(ERROR "Unable to recognize platform")
endif()
add_custom_command(
    OUTPUT ${LIB_RUBY_PARSER_FULL}
    COMMAND
        ${CMAKE_COMMAND} -E env
        "CLIB=$<TARGET_FILE:c_obj_files>"
        "RUSTLIB=$<TARGET_FILE:lib_ruby_parser_rust_static>"
        "OUTFILE=${LIB_RUBY_PARSER_FULL}"
        bash ${CMAKE_SOURCE_DIR}/scripts/merge-static-libs-${PLATFORM}.sh
    DEPENDS ${RUST_SRC_FILES}
    COMMENT "merging static libs")
add_custom_target(lib_ruby_parser_full_target ALL DEPENDS ${LIB_RUBY_PARSER_FULL} COMMENT lib_ruby_parser_full_target)
add_library(lib_ruby_parser_full STATIC IMPORTED GLOBAL)
add_dependencies(lib_ruby_parser_full lib_ruby_parser_full_target)
set_target_properties(lib_ruby_parser_full PROPERTIES IMPORTED_LOCATION ${LIB_RUBY_PARSER_FULL})

# lib-ruby-parser.h

file(GLOB H_FILES "src/*.h")
add_custom_command(
    OUTPUT lib-ruby-parser.h
    COMMAND bash ${CMAKE_SOURCE_DIR}/scripts/build-headers
    DEPENDS ${CMAKE_SOURCE_DIR}/scripts/build-headers ${H_FILES}
    COMMENT Creating lib-ruby-parser.h)
add_custom_target(header ALL DEPENDS lib-ruby-parser.h)
