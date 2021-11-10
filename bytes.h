#ifndef LIB_RUBY_PARSER_BYTES_H
#define LIB_RUBY_PARSER_BYTES_H

#include <stddef.h>

typedef struct LIB_RUBY_PARSER_ByteList
{
    char *ptr;
    size_t len;
    size_t capacity;
} LIB_RUBY_PARSER_ByteList;
void LIB_RUBY_PARSER_drop_byte_list(LIB_RUBY_PARSER_ByteList *byte_list);

typedef struct LIB_RUBY_PARSER_Bytes
{
    LIB_RUBY_PARSER_ByteList raw;
} LIB_RUBY_PARSER_Bytes;
void LIB_RUBY_PARSER_drop_bytes(LIB_RUBY_PARSER_Bytes *bytes);

#endif // LIB_RUBY_PARSER_BYTES_H
