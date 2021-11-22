#ifndef LIB_RUBY_PARSER_STRING_H
#define LIB_RUBY_PARSER_STRING_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/*
    Representation of a String.
    `ptr` is NOT NULL-terminated.
    `capacity` doesn't matter.
*/
typedef struct LIB_RUBY_PARSER_String
{
    char *ptr;
    size_t len;
    size_t capacity;
} LIB_RUBY_PARSER_String;
/*
    Constructs String from ptr+length.
    Takes ownership, zero-copy.
*/
LIB_RUBY_PARSER_String LIB_RUBY_PARSER_new_string_owned(char *s, size_t len);
/*
    Construts String from a constant NULL-terminated C stirng.
    Copies the data, useful for testing.
*/
LIB_RUBY_PARSER_String LIB_RUBY_PARSER_new_string_from_cstr(const char *s);
/*
    String destructor.
    Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
    i.e. it doesn't call `free` on a given pointer.
*/
void LIB_RUBY_PARSER_drop_string(LIB_RUBY_PARSER_String *string);

/*
    Rerpresentation of Option<String>.
    Rust has a Option<non-null ptr> optimization that None is NULL on the byte level.
    Thus, it's not a tagged enum.
    To check whether it's a Some(String) or None use helpers:
    + LIB_RUBY_PARSER_maybe_string_is_some
    + LIB_RUBY_PARSER_maybe_string_is_none
*/
typedef struct LIB_RUBY_PARSER_MaybeString
{
    LIB_RUBY_PARSER_String string;
} LIB_RUBY_PARSER_MaybeString;
/*
    Returns `true` if given pointer is `Some(String)`
*/
bool LIB_RUBY_PARSER_maybe_string_is_some(const LIB_RUBY_PARSER_MaybeString *maybe_string);
/*
    Returns `true` if given pointer is `None`
*/
bool LIB_RUBY_PARSER_maybe_string_is_none(const LIB_RUBY_PARSER_MaybeString *maybe_string);
/*
    MaybeString destructor.
    Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
    i.e. it doesn't call `free` on a given pointer.
*/
void LIB_RUBY_PARSER_drop_maybe_string(LIB_RUBY_PARSER_MaybeString *maybe_string);

#ifdef TEST_ENV
void run_test_group_string(void);
#endif

#endif // LIB_RUBY_PARSER_STRING_H
