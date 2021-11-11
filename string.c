#include "string.h"

#ifdef TEST_ENV

#include "test_helper.h"

LIB_RUBY_PARSER_String lib_ruby_parser__test__make_string_foo();

test(string_fields, {
    LIB_RUBY_PARSER_String foo = lib_ruby_parser__test__make_string_foo();
    assert(foo.len == 3);
    assert_str_eq(foo.ptr, "foo", 3);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&foo);
});

declare_test_group(string, 1, string_fields);

#endif
