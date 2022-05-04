#include "test_helper.h"
#include "../string.h"
#include <string.h>

static char *new_owned_string(const char *s)
{
    char *out = (char *)malloc(strlen(s));
    strncpy(out, s, strlen(s));
    return out;
}

LIB_RUBY_PARSER_String lib_ruby_parser__test__make_string_foo(void);

static void test_rust_string_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_String foo = lib_ruby_parser__test__make_string_foo();
    assert_string_eq(foo, "foo");
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&foo);
}

static void test_owned_string_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_String bar = LIB_RUBY_PARSER_new_string_owned(new_owned_string("bar"), 3);
    assert_string_eq(bar, "bar");
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&bar);
}

static void test_copied_string_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_String baz = LIB_RUBY_PARSER_new_string_from_cstr("baz");
    assert_string_eq(baz, "baz");
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&baz);
}

LIB_RUBY_PARSER_MaybeString lib_ruby_parser__test__make_some_string_foo(void);
LIB_RUBY_PARSER_MaybeString lib_ruby_parser__test__make_none_string(void);

static void test_maybe_string_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_MaybeString maybe_string;

    maybe_string = lib_ruby_parser__test__make_some_string_foo();
    assert(LIB_RUBY_PARSER_maybe_string_is_some(&maybe_string));
    assert_string_eq(maybe_string.string, "foo");
    LIB_RUBY_PARSER_drop_maybe_string(&maybe_string);

    maybe_string = lib_ruby_parser__test__make_none_string();
    assert(LIB_RUBY_PARSER_maybe_string_is_none(&maybe_string));
    LIB_RUBY_PARSER_drop_maybe_string(&maybe_string);
}

void run_test_group_string(void);
void run_test_group_string(void)
{
    const test_fn_t tests[] = {
        test_rust_string_fields,
        test_owned_string_fields,
        test_copied_string_fields,
        test_maybe_string_fields,
    };

    run_tests_as_group("string", tests, sizeof(tests) / sizeof(test_fn_t));
}
