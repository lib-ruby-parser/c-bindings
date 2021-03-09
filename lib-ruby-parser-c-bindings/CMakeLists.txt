project(rust-bindings)

# 1. run `cargo build ...` to get a static .a library
# 2. convert it into `.o` file to simplify merging it with objects produced from .c files

if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Debug)
endif()
string(TOLOWER ${CMAKE_BUILD_TYPE} RUST_ENV)

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

set(RUST_DIR ${CMAKE_CURRENT_SOURCE_DIR})

if(WIN32)
    set(RUST_OUT_FILE "lib_ruby_parser_c_bindings.lib")
else()
    set(RUST_OUT_FILE "liblib_ruby_parser_c_bindings.a")
endif()

set(RUST_LIB_FILE "${RUST_DIR}/target/${RUST_TARGET}/${RUST_ENV}/${RUST_OUT_FILE}"  CACHE INTERNAL "RUST_OUT_FILE")

file(GLOB RUST_SRC_FILES "${RUST_DIR}/**/*.rs")

add_custom_command(
    OUTPUT ${RUST_LIB_FILE}
    COMMAND cargo build ${CARGOFLAGS}
    WORKING_DIRECTORY ${RUST_DIR}
    DEPENDS ${RUST_SRC_FILES}
    COMMENT "running cargo")
turn_custom_command_into_static_library(lib_ruby_parser_rust_static ${RUST_LIB_FILE})

# Rust object file

# set(RUST_OBJ_FILE "${CMAKE_CURRENT_BINARY_DIR}/rust${CMAKE_C_OUTPUT_EXTENSION}" CACHE INTERNAL "RUST_OBJ_FILE")
# add_custom_command(
#     OUTPUT ${RUST_OBJ_FILE}
#     COMMAND RUST_LIB_FILE=${RUST_LIB_FILE}
#             RUST_OBJ_FILE=${RUST_OBJ_FILE}
#             bash ${CMAKE_SOURCE_DIR}/scripts/static-lib-to-object-${PLATFORM}.sh
#     DEPENDS ${RUST_LIB_FILE}
#     COMMENT "convert Rust static lib into a single object file")
# turn_custom_command_into_static_library(lib_ruby_parser_rust_obj ${RUST_OBJ_FILE})
