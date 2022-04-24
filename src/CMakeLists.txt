if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DTEST_ENV")
endif()

file(GLOB C_FILES "${SRC_DIR}/*.c")
list(APPEND C_FILES messages.c nodes.c)

file(GLOB H_FILES "${SRC_DIR}/*.h")
list(APPEND H_FILES messages.h nodes.h token_ids.h)

set_property(SOURCE ${SRC_DIR}/messages.c PROPERTY GENERATED 1)
set_property(SOURCE ${SRC_DIR}/nodes.c PROPERTY GENERATED 1)
add_library(c_obj_files STATIC ${C_FILES})
add_dependencies(c_obj_files codegen_token_ids)
add_dependencies(c_obj_files codegen_nodes_messages)

set(STATIC_LIB ${CMAKE_BINARY_DIR}/libruby_parser_c${CMAKE_STATIC_LIBRARY_SUFFIX})

add_custom_command(
    OUTPUT ${STATIC_LIB}
    COMMAND
        cp ${RUST_STATIC_LIB} ${STATIC_LIB}
            && export AR=${CMAKE_AR}
            && export LIB=${STATIC_LIB}
            && export OBJECTS="$<JOIN:$<TARGET_OBJECTS:c_obj_files>,$<SEMICOLON>>"
            && ${ROOT_DIR}/scripts/add_objects_to_lib.sh
    DEPENDS
        lib_ruby_parser_rust
        c_obj_files
    COMMENT "Combining Rust and C code..."
)

add_custom_target(build_libruby_parser_c DEPENDS ${STATIC_LIB})
