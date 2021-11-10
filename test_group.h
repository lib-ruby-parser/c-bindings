#ifndef LIB_RUBY_PARSER_TEST_H
#define LIB_RUBY_PARSER_TEST_H

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

typedef void (*test_fn_t)();

#define declare_test_group(NAME, N, ...)                                \
    test_fn_t NAME##_TESTS[N] = {__VA_ARGS__};                          \
    size_t NAME##_TESTS_COUNT = N;                                      \
    void run_test_group_##NAME()                                        \
    {                                                                   \
        size_t count = NAME##_TESTS_COUNT;                              \
        printf("Running group \"%s\" with %lu tests.\n", #NAME, count); \
        for (size_t i = 0; i < count; i++)                              \
        {                                                               \
            test_fn_t test = NAME##_TESTS[i];                           \
            test();                                                     \
        }                                                               \
    }                                                                   \
    int NAME##_TESTS_ignore = 0

#define run_test_group(NAME)      \
    void run_test_group_##NAME(); \
    run_test_group_##NAME()

#endif // LIB_RUBY_PARSER_TEST_H
