#include "bytes.h"

#ifdef TEST_ENV

#include "test_group.h"

LIB_RUBY_PARSER_ByteList lib_ruby_parser__test__make_byte_list_123();

void test_byte_list_fields()
{
    LIB_RUBY_PARSER_ByteList byte_list = lib_ruby_parser__test__make_byte_list_123();
    assert(byte_list.len == 3);
    assert(byte_list.ptr[0] == 1);
    assert(byte_list.ptr[1] == 2);
    assert(byte_list.ptr[2] == 3);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_byte_list(&byte_list);
}

LIB_RUBY_PARSER_Bytes lib_ruby_parser__test__make_bytes_123();
void test_bytes_fields()
{
    LIB_RUBY_PARSER_Bytes bytes = lib_ruby_parser__test__make_bytes_123();
    assert(bytes.raw.len == 3);
    assert(bytes.raw.ptr[0] == 1);
    assert(bytes.raw.ptr[1] == 2);
    assert(bytes.raw.ptr[2] == 3);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_bytes(&bytes);
}

declare_test_group(bytes, 2, test_byte_list_fields, test_bytes_fields);

#endif
