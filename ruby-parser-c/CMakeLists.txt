set(CARGOFLAGS "${CARGOFLAGS}" "--target" "${RUST_TARGET}")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(RUST_ENV "debug")
else()
    set(RUST_ENV, "release")
    set(CARGOFLAGS "${CARGOFLAGS}" "--release")
endif()

if(RUST_TARGET STREQUAL "x86_64-apple-darwin")
    set(STATIC_LIB_FILE libruby_parser_c.a)
elseif(RUST_TARGET STREQUAL "x86_64-unknown-linux-gnu")
    set(STATIC_LIB_FILE libruby_parser_c.a)
elseif(RUST_TARGET STREQUAL "x86_64-pc-windows-gnu")
    set(STATIC_LIB_FILE libruby_parser_c.a)
elseif(RUST_TARGET STREQUAL "x86_64-pc-windows-msvc")
    set(STATIC_LIB_FILE ruby_parser_c.a)
else()
    message(FATAL_ERROR "RUST_TARGET must be set")
endif()

add_custom_command(
    OUTPUT
        ${RUST_DIR}/lib_ruby_parser_c${CMAKE_STATIC_LIBRARY_SUFFIX}
    WORKING_DIRECTORY ${RUST_DIR}
    COMMAND
        ${CMAKE_COMMAND} -E env "RUSTFLAGS=${RUSTFLAGS}" cargo build ${CARGOFLAGS}
            && ls -l target/${RUST_TARGET}
            && ls -l target/${RUST_TARGET}/${RUST_ENV}
            && cp target/${RUST_TARGET}/${RUST_ENV}/${STATIC_LIB_FILE} lib_ruby_parser_c${CMAKE_STATIC_LIBRARY_SUFFIX}
    DEPENDS
        ${RUST_DIR}/src/*.rs
        ${RUST_DIR}/src/node.rs
        ${RUST_DIR}/src/message.rs
        ${RUST_DIR}/Cargo.toml
    COMMENT "Compiling rust parser..."
)
set(RUST_STATIC_LIB ${RUST_DIR}/lib_ruby_parser_c${CMAKE_STATIC_LIBRARY_SUFFIX})
set(RUST_STATIC_LIB ${RUST_DIR}/lib_ruby_parser_c${CMAKE_STATIC_LIBRARY_SUFFIX} PARENT_SCOPE)

add_custom_target(lib_ruby_parser_rust DEPENDS ${RUST_STATIC_LIB})
