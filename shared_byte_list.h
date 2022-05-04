#ifndef LIB_RUBY_PARSER_SHARED_BYTE_LIST_H
#define LIB_RUBY_PARSER_SHARED_BYTE_LIST_H

#include <stddef.h>

/// @defgroup shared_byte_list Shared Byte List
/// @{
/// @}

/// @brief Equivalent of `&[u8]` in Rust.
/// Holds a constant pointer + length.
/// @ingroup shared_byte_list
typedef struct
{
    const char *ptr;
    size_t len;
} LIB_RUBY_PARSER_SharedByteList;

#endif // LIB_RUBY_PARSER_SHARED_BYTE_LIST_H
