#include "string.h"

#ifdef TEST_ENV

#include "test_helper.h"

LIB_RUBY_PARSER_String lib_ruby_parser__test__make_string_foo();

void test_fields()
{
    LIB_RUBY_PARSER_String foo = lib_ruby_parser__test__make_string_foo();
    assert(foo.len == 3);
    assert(strncmp(foo.ptr, "foo", 3) == 0);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&foo);
}

declare_test_group(string, 1, test_fields);

#endif
