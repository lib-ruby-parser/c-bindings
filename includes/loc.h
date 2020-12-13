#ifndef LIB_RUBY_PARSER_LOC_H
#define LIB_RUBY_PARSER_LOC_H

#include <stddef.h>

struct Loc
{
    size_t begin;
    size_t end;
};

#endif // LIB_RUBY_PARSER_LOC_H
