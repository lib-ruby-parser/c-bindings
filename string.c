#include "string.h"
#include <stdlib.h>

bool LIB_RUBY_PARSER_maybe_string_is_some(const LIB_RUBY_PARSER_MaybeString *maybe_string)
{
    return maybe_string->string.ptr != NULL;
}
bool LIB_RUBY_PARSER_maybe_string_is_none(const LIB_RUBY_PARSER_MaybeString *maybe_string)
{
    return maybe_string->string.ptr == NULL;
}

#ifdef TEST_ENV

#include "test_helper.h"
#include <string.h>

char *new_owned_string(const char *s)
{
    char *out = (char *)malloc(strlen(s));
    strncpy(out, s, strlen(s));
    return out;
}

LIB_RUBY_PARSER_String lib_ruby_parser__test__make_string_foo();

void test_rust_string_fields()
{
    annotate_test;

    LIB_RUBY_PARSER_String foo = lib_ruby_parser__test__make_string_foo();
    assert_eq(foo.len, 3);
    assert_str_eq(foo.ptr, "foo", 3);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&foo);
}

void test_owned_string_fields()
{
    annotate_test;

    LIB_RUBY_PARSER_String foo = LIB_RUBY_PARSER_new_string_owned(new_owned_string("foo"), 3);
    assert_eq(foo.len, 3);
    assert_str_eq(foo.ptr, "foo", 3);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&foo);
}

void test_copied_string_fields()
{
    annotate_test;

    LIB_RUBY_PARSER_String foo = LIB_RUBY_PARSER_new_string_from_cstr("foo");
    assert_eq(foo.len, 3);
    assert_str_eq(foo.ptr, "foo", 3);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&foo);
}

LIB_RUBY_PARSER_MaybeString lib_ruby_parser__test__make_some_string_foo();
LIB_RUBY_PARSER_MaybeString lib_ruby_parser__test__make_none_string();

void test_maybe_string_fields()
{
    annotate_test;

    LIB_RUBY_PARSER_MaybeString maybe_string;

    maybe_string = lib_ruby_parser__test__make_some_string_foo();
    assert(LIB_RUBY_PARSER_maybe_string_is_some(&maybe_string));
    assert_eq(maybe_string.string.len, 3);
    assert_str_eq(maybe_string.string.ptr, "foo", 3);
    LIB_RUBY_PARSER_drop_maybe_string(&maybe_string);

    maybe_string = lib_ruby_parser__test__make_none_string();
    assert(LIB_RUBY_PARSER_maybe_string_is_none(&maybe_string));
    LIB_RUBY_PARSER_drop_maybe_string(&maybe_string);
}

declare_test_group(
    string,
    4,
    test_rust_string_fields,
    test_owned_string_fields,
    test_copied_string_fields,
    test_maybe_string_fields);

#endif
