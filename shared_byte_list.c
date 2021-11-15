#include "shared_byte_list.h"

#ifdef TEST_ENV

#include "test_helper.h"

LIB_RUBY_PARSER_SharedByteList lib_ruby_parser__test__make_shared_byte_list_foo();

static void test_shared_byte_list_fields()
{
    annotate_test;

    LIB_RUBY_PARSER_SharedByteList foo = lib_ruby_parser__test__make_shared_byte_list_foo();
    assert(foo.len == 3);
    assert_str_eq(foo.ptr, "foo", 3);
}

void run_test_group_shared_byte_list()
{
    const test_fn_t tests[] = {
        test_shared_byte_list_fields,
    };

    run_tests_as_group("shared_byte_list", tests, sizeof(tests) / sizeof(test_fn_t));
}

#endif
