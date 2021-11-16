#ifndef LIB_RUBY_PARSER_TEST_HELPER_H
#define LIB_RUBY_PARSER_TEST_HELPER_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include <assert.h>

typedef void (*test_fn_t)(void);

#define annotate_test fprintf(stderr, __func__)

void run_tests_as_group(const char *group_name, const test_fn_t *tests, size_t count);

// assertion helpers

#define assert_eq(a, b) assert((a) == (b))

#define assert_str_eq(_actual, _expected) \
    assert_eq(strncmp(_actual, _expected, strlen(_expected)), 0)

#define assert_byte_list(_byte_list, _str)   \
    assert_eq(_byte_list.len, strlen(_str)); \
    assert_str_eq(_byte_list.ptr, _str)

#define assert_string_eq(_string, _s)   \
    assert_eq(_string.len, strlen(_s)); \
    assert(strncmp(_string.ptr, _s, strlen(_s)) == 0)

#define assert_token(_token, _token_name) \
    assert_str_eq(LIB_RUBY_PARSER_token_name(&_token), _token_name)

#define assert_loc(_left, _right)         \
    assert_eq(_left.begin, _right.begin); \
    assert_eq(_left.end, _right.end)

#define assert_some_loc(_maybe_loc, _loc)                \
    assert_eq(_maybe_loc.tag, LIB_RUBY_PARSER_SOME_LOC); \
    assert_loc(_maybe_loc.as.loc, _loc)

#define assert_none_loc(_maybe_loc) \
    assert_eq(_maybe_loc.tag, LIB_RUBY_PARSER_NONE_LOC)

#define assert_source_line(source_line, _start, _end, _ends_with_eof) \
    assert_eq(source_line.start, _start);                             \
    assert_eq(source_line.end, _end);                                 \
    assert_eq(source_line.ends_with_eof, _ends_with_eof)

#define assert_comment(_comment, _location, _kind) \
    assert_loc(_comment.location, _location);      \
    assert_eq(_comment.kind, _kind)

#define assert_magic_comment(_magic_comment, _kind, _key_l, _value_l) \
    assert_eq(_magic_comment.kind, _kind);                            \
    assert_loc(_magic_comment.key_l, _key_l);                         \
    assert_loc(_magic_comment.value_l, _value_l)

#endif // LIB_RUBY_PARSER_TEST_HELPER_H
