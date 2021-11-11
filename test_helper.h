#ifndef LIB_RUBY_PARSER_TEST_HELPER_H
#define LIB_RUBY_PARSER_TEST_HELPER_H

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

typedef void (*test_fn_t)();

#define test(NAME, ...)            \
    void NAME()                    \
    {                              \
        printf("  - %s\n", #NAME); \
        __VA_ARGS__                \
    }                              \
    int NAME##TEST_ignore = 1

#define declare_test_group(NAME, N, ...)                                \
    test_fn_t NAME##_TESTS[N] = {__VA_ARGS__};                          \
    size_t NAME##_TESTS_COUNT = N;                                      \
    void run_test_group_##NAME()                                        \
    {                                                                   \
        size_t count = NAME##_TESTS_COUNT;                              \
        printf("Running group \"%s\" with %lu tests.\n", #NAME, count); \
        for (size_t i = 0; i < count; i++)                              \
        {                                                               \
            test_fn_t test_fn = NAME##_TESTS[i];                        \
            test_fn();                                                  \
        }                                                               \
    }                                                                   \
    int NAME##_TESTS_ignore = 0

#define run_test_group(NAME)      \
    void run_test_group_##NAME(); \
    run_test_group_##NAME()

#endif // LIB_RUBY_PARSER_TEST_HELPER_H
