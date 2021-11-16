#ifndef LIB_RUBY_PARSER_SHARED_BYTE_LIST_H
#define LIB_RUBY_PARSER_SHARED_BYTE_LIST_H

#include <stddef.h>

typedef struct LIB_RUBY_PARSER_SharedByteList
{
    char *ptr;
    size_t len;
} LIB_RUBY_PARSER_SharedByteList;

#ifdef TEST_ENV
void run_test_group_shared_byte_list(void);
#endif

#endif // LIB_RUBY_PARSER_SHARED_BYTE_LIST_H
