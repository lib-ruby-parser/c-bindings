#ifndef LIB_RUBY_PARSER_SHARED_BYTE_LIST_H
#define LIB_RUBY_PARSER_SHARED_BYTE_LIST_H

#include <stddef.h>

typedef struct LIB_RUBY_PARSER_SharedByteList
{
    char *ptr;
    size_t len;
} LIB_RUBY_PARSER_SharedByteList;

#endif // LIB_RUBY_PARSER_SHARED_BYTE_LIST_H
