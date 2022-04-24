if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DTEST_ENV")
endif()

set(
    C_FILES

    ${SRC_DIR}/alloc.c
    ${SRC_DIR}/api.c
    ${SRC_DIR}/bytes.c
    ${SRC_DIR}/comment.c
    ${SRC_DIR}/decoded_input.c
    ${SRC_DIR}/decoder.c
    ${SRC_DIR}/diagnostic.c
    ${SRC_DIR}/loc.c
    ${SRC_DIR}/magic_comment.c
    ${SRC_DIR}/messages.c
    ${SRC_DIR}/nodes.c
    ${SRC_DIR}/parser_options.c
    ${SRC_DIR}/parser_result.c
    ${SRC_DIR}/shared_byte_list.c
    ${SRC_DIR}/source_line.c
    ${SRC_DIR}/string.c
    ${SRC_DIR}/test_helper.c
    ${SRC_DIR}/token.c
    ${SRC_DIR}/token_rewriter.c
)

set(
    H_FILES

    ${SRC_DIR}/alloc.h
    ${SRC_DIR}/api.h
    ${SRC_DIR}/bytes.h
    ${SRC_DIR}/comment.h
    ${SRC_DIR}/decoded_input.h
    ${SRC_DIR}/decoder.h
    ${SRC_DIR}/diagnostic.h
    ${SRC_DIR}/loc.h
    ${SRC_DIR}/magic_comment.h
    ${SRC_DIR}/messages.h
    ${SRC_DIR}/nodes.h
    ${SRC_DIR}/parser_options.h
    ${SRC_DIR}/parser_result.h
    ${SRC_DIR}/shared_byte_list.h
    ${SRC_DIR}/source_line.h
    ${SRC_DIR}/string.h
    ${SRC_DIR}/test_helper.h
    ${SRC_DIR}/token.h
    ${SRC_DIR}/token_ids.h
    ${SRC_DIR}/token_rewriter.h
)

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
