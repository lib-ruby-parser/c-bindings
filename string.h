#ifndef LIB_RUBY_PARSER_STRING_H
#define LIB_RUBY_PARSER_STRING_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct LIB_RUBY_PARSER_String
{
    char *ptr;
    size_t len;
    size_t capacity;
} LIB_RUBY_PARSER_String;
LIB_RUBY_PARSER_String LIB_RUBY_PARSER_new_string_owned(char *s, size_t len);
LIB_RUBY_PARSER_String LIB_RUBY_PARSER_new_string_from_cstr(const char *s);
void LIB_RUBY_PARSER_drop_string(LIB_RUBY_PARSER_String *string);

typedef struct LIB_RUBY_PARSER_MaybeString
{
    LIB_RUBY_PARSER_String string;
} LIB_RUBY_PARSER_MaybeString;
bool LIB_RUBY_PARSER_maybe_string_is_some(const LIB_RUBY_PARSER_MaybeString *maybe_string);
bool LIB_RUBY_PARSER_maybe_string_is_none(const LIB_RUBY_PARSER_MaybeString *maybe_string);
void LIB_RUBY_PARSER_drop_maybe_string(LIB_RUBY_PARSER_MaybeString *maybe_string);

#endif // LIB_RUBY_PARSER_STRING_H
