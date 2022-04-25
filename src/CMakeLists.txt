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
set(STATIC_LIB ${CMAKE_BINARY_DIR}/libruby_parser_c${CMAKE_STATIC_LIBRARY_SUFFIX} PARENT_SCOPE)

add_custom_command(
    OUTPUT ${STATIC_LIB}
    COMMAND cp ${RUST_STATIC_LIB} ${STATIC_LIB}
    COMMAND bash ${ROOT_DIR}/scripts/add_objects_to_lib.sh ${CMAKE_AR} ${STATIC_LIB} \"$<JOIN:$<TARGET_OBJECTS:c_obj_files>,$<SEMICOLON>>\"
    DEPENDS
        lib_ruby_parser_rust_target
        c_obj_files
    COMMENT "Combining Rust and C code..."
)

add_custom_target(lib_ruby_parser_c_target DEPENDS ${STATIC_LIB})
