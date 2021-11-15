#include "string.h"
#include <stdlib.h>

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

test(rust_string_fields, {
    LIB_RUBY_PARSER_String foo = lib_ruby_parser__test__make_string_foo();
    assert(foo.len == 3);
    assert_str_eq(foo.ptr, "foo", 3);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&foo);
});

test(owned_string_fields, {
    LIB_RUBY_PARSER_String foo = LIB_RUBY_PARSER_new_string_owned(new_owned_string("foo"), 3);
    assert(foo.len == 3);
    assert_str_eq(foo.ptr, "foo", 3);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&foo);
});

test(copied_string_fields, {
    LIB_RUBY_PARSER_String foo = LIB_RUBY_PARSER_new_string_from_cstr("foo");
    assert(foo.len == 3);
    assert_str_eq(foo.ptr, "foo", 3);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&foo);
});

declare_test_group(string, 3, rust_string_fields, owned_string_fields, copied_string_fields);

#endif
