#ifndef LIB_RUBY_PARSER_SHARED_BYTE_LIST_H
#define LIB_RUBY_PARSER_SHARED_BYTE_LIST_H

#include <stddef.h>

/*
    Equivalent of `&[u8]` in Rust.
    Holds a constant pointer + length.
*/
typedef struct LIB_RUBY_PARSER_SharedByteList
{
    const char *ptr;
    size_t len;
} LIB_RUBY_PARSER_SharedByteList;

#ifdef TEST_ENV
void run_test_group_shared_byte_list(void);
#endif

#endif // LIB_RUBY_PARSER_SHARED_BYTE_LIST_H
