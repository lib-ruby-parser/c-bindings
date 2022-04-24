link_directories(${CMAKE_BINARY_DIR})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DTEST_ENV")
endif()

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
    test
    COMMAND test-runner
    COMMENT "Running tests..."
)
