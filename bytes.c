#include "bytes.h"

#ifdef TEST_ENV

#include "test_helper.h"

LIB_RUBY_PARSER_ByteList lib_ruby_parser__test__make_byte_list(char i1, char i2, char i3);

test(byte_list_fields, {
    LIB_RUBY_PARSER_ByteList byte_list = lib_ruby_parser__test__make_byte_list(1, 2, 3);
    assert_byte_list(byte_list, 3, MAKE_ARRAY(1, 2, 3));
    LIB_RUBY_PARSER_drop_byte_list(&byte_list);
});

LIB_RUBY_PARSER_Bytes lib_ruby_parser__test__make_bytes(char i1, char i2, char i3);
test(bytes_fields, {
    LIB_RUBY_PARSER_Bytes bytes = lib_ruby_parser__test__make_bytes(1, 2, 3);
    assert_byte_list(bytes.raw, 3, MAKE_ARRAY(1, 2, 3));
    LIB_RUBY_PARSER_drop_bytes(&bytes);
});

declare_test_group(bytes, 2, byte_list_fields, bytes_fields);

#endif
