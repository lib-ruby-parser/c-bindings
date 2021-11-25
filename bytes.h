#ifndef LIB_RUBY_PARSER_BYTES_H
#define LIB_RUBY_PARSER_BYTES_H

#include <stddef.h>

/*
    Representation of a Vec<u8>.
    `capacity` doesn't matter.
*/
typedef struct LIB_RUBY_PARSER_ByteList
{
    char *ptr;
    size_t capacity;
    size_t len;
} LIB_RUBY_PARSER_ByteList;
/*
    ByteList destructor.
    Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
    i.e. it doesn't call `free` on a given pointer.
*/
void LIB_RUBY_PARSER_drop_byte_list(LIB_RUBY_PARSER_ByteList *byte_list);
/*
    Constructs ByteList from ptr+length.
    Takes ownership, zero-copy.
*/
LIB_RUBY_PARSER_ByteList LIB_RUBY_PARSER_new_bytes_owned(char *s, size_t len);
/*
    Construts ByteList from a constant C stirng.
    Copies the data, useful for testing.
*/
LIB_RUBY_PARSER_ByteList LIB_RUBY_PARSER_new_bytes_from_cstr(const char *s, size_t len);

/*
    Rerpresentation of `Bytes` struct from lib-ruby-parser.
*/
typedef struct LIB_RUBY_PARSER_Bytes
{
    LIB_RUBY_PARSER_ByteList raw;
} LIB_RUBY_PARSER_Bytes;
/*
    Bytes destructor.
    Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
    i.e. it doesn't call `free` on a given pointer.
*/
void LIB_RUBY_PARSER_drop_bytes(LIB_RUBY_PARSER_Bytes *bytes);

#ifdef TEST_ENV
void run_test_group_bytes(void);
#endif

#endif // LIB_RUBY_PARSER_BYTES_H
