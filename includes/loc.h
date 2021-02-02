#ifndef LIB_RUBY_PARSER_LOC_H
#define LIB_RUBY_PARSER_LOC_H

#include <stddef.h>
#include <stdint.h>

struct Loc
{
    uint32_t begin;
    uint32_t end;
};

#endif // LIB_RUBY_PARSER_LOC_H
