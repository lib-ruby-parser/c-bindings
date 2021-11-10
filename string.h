#ifndef LIB_RUBY_PARSER_STRING_H
#define LIB_RUBY_PARSER_STRING_H

#include <stddef.h>
#include <stdint.h>

typedef struct LIB_RUBY_PARSER_String
{
    char *ptr;
    size_t len;
    size_t capacity;
} LIB_RUBY_PARSER_String;
void LIB_RUBY_PARSER_drop_string(LIB_RUBY_PARSER_String *string);

typedef struct LIB_RUBY_PARSER_MaybeString
{
    enum
    {
        LIB_RUBY_PARSER_SOME_STRING,
        LIB_RUBY_PARSER_NONE_STRING
    } tag;

    union
    {
        LIB_RUBY_PARSER_String string;
        uint8_t none;
    } as;
} LIB_RUBY_PARSER_MaybeString;
void LIB_RUBY_PARSER_drop_maybe_string(LIB_RUBY_PARSER_MaybeString *maybe_string);

#endif // LIB_RUBY_PARSER_STRING_H
