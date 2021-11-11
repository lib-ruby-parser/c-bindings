#ifndef LIB_RUBY_PARSER_LOC_H
#define LIB_RUBY_PARSER_LOC_H

#include <stddef.h>
#include <stdint.h>

typedef struct LIB_RUBY_PARSER_Loc
{
    size_t begin;
    size_t end;
} LIB_RUBY_PARSER_Loc;

typedef struct LIB_RUBY_PARSER_MaybeLoc
{
    enum
    {
        LIB_RUBY_PARSER_NONE_LOC = 0,
        LIB_RUBY_PARSER_SOME_LOC = 1,
    } tag;

    union
    {
        LIB_RUBY_PARSER_Loc loc;
        uint8_t none;
    } as;
} LIB_RUBY_PARSER_MaybeLoc;

#endif // LIB_RUBY_PARSER_LOC_H
