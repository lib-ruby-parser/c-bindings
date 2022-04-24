link_directories(${CMAKE_BINARY_DIR})

add_executable(
    test-runner
    test.c
)
if(MSVC)
    # For MSVC lib are passed by full name
    set(LIB_NAME libruby_parser_c)
else()
    # For other compilers -l<lib name without "lib" prefix>
    set(LIB_NAME ruby_parser_c)
endif()
target_link_libraries(
    test-runner
    ${LIB_NAME}
)
add_dependencies(test-runner build_libruby_parser_c)

add_custom_target(
    test
    COMMAND test-runner
    COMMENT "Running tests..."
)
