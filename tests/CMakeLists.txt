message(INFO " CMAKE_C_COMPILER = ${CMAKE_C_COMPILER}")

set(CFLAGS "${CFLAGS} ${CMAKE_C_FLAGS} ${CMAKE_EXE_LINKER_FLAGS}")

if(MSVC)
    set(COMPILE_TEST_RUNNER
        "${CMAKE_C_COMPILER} ${CFLAGS} ${TESTS_DIR}/test.c ${STATIC_LIB} /link /OUT:${CMAKE_BINARY_DIR}/test-runner"
    )
    separate_arguments(COMPILE_TEST_RUNNER UNIX_COMMAND "${COMPILE_TEST_RUNNER}")
else()
    # Clang/GCC/MinGW
    set(COMPILE_TEST_RUNNER
        "${CMAKE_C_COMPILER} ${TESTS_DIR}/test.c ${STATIC_LIB} ${CFLAGS} -o ${CMAKE_BINARY_DIR}/test-runner"
    )
    separate_arguments(COMPILE_TEST_RUNNER UNIX_COMMAND "${COMPILE_TEST_RUNNER}")
endif()
add_custom_command(
    OUTPUT
        ${CMAKE_BINARY_DIR}/test-runner
    WORKING_DIRECTORY ${RUST_DIR}
    COMMAND
        ${COMPILE_TEST_RUNNER}
    DEPENDS
        ${TESTS_DIR}/test.c
        lib_ruby_parser_c_target
    COMMENT "Compiling test.c..."
    VERBATIM
)
set(TEST_RUNNER ${CMAKE_BINARY_DIR}/test-runner)
add_custom_target(test_runner_target DEPENDS ${TEST_RUNNER})

add_test(NAME test COMMAND ${TEST_RUNNER})
list(APPEND CMAKE_CTEST_ARGUMENTS "--verbose")


# add_executable(
#     test-runner
#     test.c
# )
# if(MSVC)
#     # For MSVC lib are passed by full name
#     set(LIB_NAME libruby_parser_c)
# else()
#     # For other compilers -l<lib name without "lib" prefix>
#     set(LIB_NAME ruby_parser_c)
# endif()
# target_link_libraries(
#     test-runner
#     ${LIB_NAME}
# )
# add_dependencies(test-runner lib_ruby_parser_c_target)

# add_custom_target(
#     test
#     COMMAND test-runner
#     COMMENT "Running tests..."
# )
