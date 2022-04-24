link_directories(${CMAKE_BINARY_DIR})

add_executable(
    test-runner
    test.c
)
target_link_libraries(
    test-runner
    ruby_parser_c
)
add_dependencies(test-runner build_libruby_parser_c)

add_custom_target(
    run-tests
    COMMAND test-runner
    COMMENT "Running tests..."
)
