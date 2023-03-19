#ifndef LIB_RUBY_PARSER_BYTES_H
#define LIB_RUBY_PARSER_BYTES_H

#include <stddef.h>

/// @defgroup bytes Bytes
/// @brief A set of structs and functions to work with byte sequences.
/// `lib-ruby-parser` takes a sequence of `Bytes` as an input.
/// Also some AST nodes that accept non-UTF-8 byte sequence also store `Bytes`.
/// @{
/// @}

/// Representation of a Vec<u8>.
/// `capacity` doesn't matter.
/// @ingroup bytes
typedef struct
{
    /// Capacity of the byte list. Simply ignore this field.
    size_t capacity;

    /// Pointer to beginning of the byte sequence
    /// NOTE: There are no guarantees that byte sequence is valid
    char *ptr;

    /// Length of the byte list
    size_t len;
} LIB_RUBY_PARSER_ByteList;

/// ByteList destructor.
/// Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
/// i.e. it doesn't call `free` on a given pointer.
/// @ingroup bytes
void LIB_RUBY_PARSER_drop_byte_list(LIB_RUBY_PARSER_ByteList *byte_list);

/// Constructs ByteList from ptr+length.
/// Takes ownership, zero-copy.
/// @ingroup bytes
LIB_RUBY_PARSER_ByteList LIB_RUBY_PARSER_new_bytes_owned(char *s, size_t len);

/// Construts ByteList from a constant C stirng.
/// Copies the data, useful for testing.
/// @ingroup bytes
LIB_RUBY_PARSER_ByteList LIB_RUBY_PARSER_new_bytes_from_cstr(const char *s, size_t len);

/// Rerpresentation of `Bytes` struct from lib-ruby-parser.
/// @ingroup bytes
typedef struct
{
    LIB_RUBY_PARSER_ByteList raw;
} LIB_RUBY_PARSER_Bytes;

/// Bytes destructor.
/// Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
/// i.e. it doesn't call `free` on a given pointer.
/// @ingroup bytes
void LIB_RUBY_PARSER_drop_bytes(LIB_RUBY_PARSER_Bytes *bytes);

#endif // LIB_RUBY_PARSER_BYTES_H
