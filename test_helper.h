#ifndef LIB_RUBY_PARSER_TEST_HELPER_H
#define LIB_RUBY_PARSER_TEST_HELPER_H

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <assert.h>

typedef void (*test_fn_t)(void);

#define annotate_test fprintf(stderr, __func__)

void run_tests_as_group(const char *group_name, const test_fn_t *tests, size_t count);

// assertion helpers

#define assert_eq(a, b) assert((a) == (b))

void assert_str_eq(const char *lhs, const char *rhs, size_t len);

#define MAKE_ARRAY(...) __VA_ARGS__

#define assert_byte_list(_byte_list, _len, ...)        \
    /* assert len */                                   \
    assert_eq((_byte_list).len, _len);                 \
    /* assert items */                                 \
    {                                                  \
        char _bytes[] = {__VA_ARGS__};                 \
        for (size_t i = 0; i < _len; i++)              \
        {                                              \
            assert_eq((_byte_list).ptr[i], _bytes[i]); \
        }                                              \
    }                                                  \
    /* ignore capacity */                              \
    assert_eq(1, 1)

#endif // LIB_RUBY_PARSER_TEST_HELPER_H
