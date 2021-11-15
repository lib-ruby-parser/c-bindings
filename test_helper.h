#ifndef LIB_RUBY_PARSER_TEST_HELPER_H
#define LIB_RUBY_PARSER_TEST_HELPER_H

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

typedef void (*test_fn_t)();

#define annotate_test fprintf(stderr, __func__)

void run_tests_as_group(const char *group_name, const test_fn_t *tests, size_t count);

// assertion helpers

#define assert_eq(a, b) assert((a) == (b))

#define assert_str_eq(a, b, len) \
    assert_eq(strncmp(a, b, len), 0);

#define assert_loc(loc, _expected)             \
    assert_eq((loc).begin, (_expected).begin); \
    assert_eq((loc).end, (_expected).end);

#define assert_some_loc(_loc, _expected)             \
    assert_eq((_loc).tag, LIB_RUBY_PARSER_SOME_LOC); \
    assert_loc((_loc).as.loc, _expected);

#define assert_none_loc(_loc) \
    assert_eq((_loc).tag, LIB_RUBY_PARSER_NONE_LOC);

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
    /* ignore capacity */

#endif // LIB_RUBY_PARSER_TEST_HELPER_H
