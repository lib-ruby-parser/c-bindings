#include "shared_byte_list.h"

#ifdef TEST_ENV

#include "test_helper.h"

LIB_RUBY_PARSER_SharedByteList lib_ruby_parser__test__make_shared_byte_list_foo();

void test_shared_byte_list_fields()
{
    annotate_test;

    LIB_RUBY_PARSER_SharedByteList foo = lib_ruby_parser__test__make_shared_byte_list_foo();
    assert(foo.len == 3);
    assert_str_eq(foo.ptr, "foo", 3);
}

declare_test_group(
    shared_byte_list,
    1,
    test_shared_byte_list_fields);

#endif
