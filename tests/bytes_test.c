#include "test_helper.h"
#include "../bytes.h"
#include <stdlib.h>

LIB_RUBY_PARSER_ByteList lib_ruby_parser__test__make_byte_list(char i1, char i2, char i3);

static void test_byte_list_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_ByteList byte_list = lib_ruby_parser__test__make_byte_list('1', '2', '3');
    assert_byte_list(byte_list, "123");
    LIB_RUBY_PARSER_drop_byte_list(&byte_list);
}

static void test_byte_list_constructors(void)
{
    annotate_test;

    LIB_RUBY_PARSER_ByteList byte_list;

    char *owned = (char *)malloc(4);
    owned[0] = '1';
    owned[1] = '2';
    owned[2] = '3';
    owned[3] = '4';
    byte_list = LIB_RUBY_PARSER_new_bytes_owned(owned, 4);
    assert_byte_list(byte_list, "1234");
    LIB_RUBY_PARSER_drop_byte_list(&byte_list);

    byte_list = LIB_RUBY_PARSER_new_bytes_from_cstr("56789", 5);
    assert_byte_list(byte_list, "56789");
    LIB_RUBY_PARSER_drop_byte_list(&byte_list);
}

LIB_RUBY_PARSER_Bytes lib_ruby_parser__test__make_bytes(char i1, char i2, char i3);
static void test_bytes_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_Bytes bytes = lib_ruby_parser__test__make_bytes('a', 'b', 'c');
    assert_byte_list(bytes.raw, "abc");
    LIB_RUBY_PARSER_drop_bytes(&bytes);
}

void run_test_group_bytes(void);
void run_test_group_bytes(void)
{
    const test_fn_t tests[] = {
        test_byte_list_fields,
        test_byte_list_constructors,
        test_bytes_fields,
    };

    run_tests_as_group("bytes", tests, sizeof(tests) / sizeof(test_fn_t));
}
