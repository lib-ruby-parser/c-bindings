#include "bytes.h"

#ifdef TEST_ENV

#include "test_helper.h"
#include <stdlib.h>

LIB_RUBY_PARSER_ByteList lib_ruby_parser__test__make_byte_list(char i1, char i2, char i3);

static void test_byte_list_fields()
{
    annotate_test;

    LIB_RUBY_PARSER_ByteList byte_list = lib_ruby_parser__test__make_byte_list(1, 2, 3);
    assert_byte_list(byte_list, 3, MAKE_ARRAY(1, 2, 3));
    LIB_RUBY_PARSER_drop_byte_list(&byte_list);
}

static void test_byte_list_constructors()
{
    annotate_test;

    LIB_RUBY_PARSER_ByteList byte_list;

    char *owned = (char *)malloc(4);
    owned[0] = '1';
    owned[1] = '2';
    owned[2] = '3';
    owned[3] = '4';
    byte_list = LIB_RUBY_PARSER_new_bytes_owned(owned, 4);
    assert_byte_list(byte_list, 4, MAKE_ARRAY('1', '2', '3', '4'));
    LIB_RUBY_PARSER_drop_byte_list(&byte_list);

    byte_list = LIB_RUBY_PARSER_new_bytes_from_cstr("56789", 5);
    assert_byte_list(byte_list, 5, MAKE_ARRAY('5', '6', '7', '8', '9'));
    LIB_RUBY_PARSER_drop_byte_list(&byte_list);
}

LIB_RUBY_PARSER_Bytes lib_ruby_parser__test__make_bytes(char i1, char i2, char i3);
static void test_bytes_fields()
{
    annotate_test;

    LIB_RUBY_PARSER_Bytes bytes = lib_ruby_parser__test__make_bytes(1, 2, 3);
    assert_byte_list(bytes.raw, 3, MAKE_ARRAY(1, 2, 3));
    LIB_RUBY_PARSER_drop_bytes(&bytes);
}

void run_test_group_bytes()
{
    const test_fn_t tests[] = {
        test_byte_list_fields,
        test_byte_list_constructors,
        test_bytes_fields,
    };

    run_tests_as_group("bytes", tests, sizeof(tests) / sizeof(test_fn_t));
}

#endif
