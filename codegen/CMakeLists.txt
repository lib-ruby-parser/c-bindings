add_custom_command(
    OUTPUT
        ${SRC_DIR}/messages.h
        ${SRC_DIR}/messages.c
        ${SRC_DIR}/nodes.h
        ${SRC_DIR}/nodes.c
        ${RUST_DIR}/src/message.rs
        ${RUST_DIR}/src/node.rs
    COMMAND
        cd ${CODEGEN_DIR}
            && touch build.rs
            && cargo build
    DEPENDS
        ${CODEGEN_DIR}/codegen/*.rs
        ${CODEGEN_DIR}/Cargo.toml
        ${CODEGEN_DIR}/build.rs
    COMMENT "Generating src/{messages,nodes}.{h,c,rs}..."
)
add_custom_target(
    codegen_nodes_messages
    DEPENDS
        ${SRC_DIR}/messages.h
        ${SRC_DIR}/messages.c
        ${SRC_DIR}/nodes.h
        ${SRC_DIR}/nodes.c
        ${RUST_DIR}/src/message.rs
        ${RUST_DIR}/src/node.rs
)
set_property(SOURCE ${SRC_DIR}/messages.h PROPERTY GENERATED 1)
set_property(SOURCE ${SRC_DIR}/messages.c PROPERTY GENERATED 1)
set_property(SOURCE ${SRC_DIR}/nodes.h PROPERTY GENERATED 1)
set_property(SOURCE ${SRC_DIR}/nodes.c PROPERTY GENERATED 1)
set_property(SOURCE ${RUST_DIR}/message.rs PROPERTY GENERATED 1)
set_property(SOURCE ${RUST_DIR}/node.rs PROPERTY GENERATED 1)

add_custom_command(
    OUTPUT
        ${SRC_DIR}/token_ids.h
    COMMAND
        cd ${CMAKE_SOURCE_DIR}
            && cargo run --example build_token_ids --manifest-path codegen/Cargo.toml
    DEPENDS
        ${CODEGEN_DIR}/examples/build_token_ids.rs
    COMMENT "Generating src/token_ids.h..."
)
set_property(SOURCE ${SRC_DIR}/token_ids.h PROPERTY GENERATED 1)
add_custom_target(
    codegen_token_ids
    DEPENDS
        ${SRC_DIR}/token_ids.h
)
set_property(SOURCE ${SRC_DIR}/token_ids.h PROPERTY GENERATED 1)

add_custom_command(
    OUTPUT
        ${CMAKE_BINARY_DIR}/lib-ruby-parser.h
    COMMAND
        cd ${CMAKE_BINARY_DIR}
            && cargo run --example merge_headers --manifest-path ../codegen/Cargo.toml
    DEPENDS
        ${CODEGEN_DIR}/examples/merge_headers.rs
        ${SRC_DIR}/*.h
        ${SRC_DIR}/token_ids.h
        ${SRC_DIR}/messages.h
        ${SRC_DIR}/nodes.h
    COMMENT "Generating src/lib-ruby-parser.h..."
)
add_custom_target(
    codegen_main_header
    DEPENDS
        ${CMAKE_BINARY_DIR}/lib-ruby-parser.h
)
