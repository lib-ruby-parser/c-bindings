#ifndef LIB_RUBY_PARSER_LOC_H
#define LIB_RUBY_PARSER_LOC_H

#include <stddef.h>
#include <stdint.h>
#include "decoded_input.h"

/*
    `Loc` struct from `lib-ruby-parser`
*/
typedef struct LIB_RUBY_PARSER_Loc
{
    size_t begin;
    size_t end;
} LIB_RUBY_PARSER_Loc;

/*
    Returns source code of the given location.
    Equivalent of `lib_ruby_parser::Loc::source`
*/
char *LIB_RUBY_PARSER_loc_source(const LIB_RUBY_PARSER_Loc *loc, const LIB_RUBY_PARSER_DecodedInput *input);

/*
    Equivalent of `Option<Loc>`
*/
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

#ifdef TEST_ENV
void run_test_group_loc(void);
#endif

#endif // LIB_RUBY_PARSER_LOC_H
