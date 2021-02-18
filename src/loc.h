#ifndef LIB_RUBY_PARSER_LOC_H
#define LIB_RUBY_PARSER_LOC_H

#include <stddef.h>
#include <stdint.h>

struct Loc
{
    uint32_t begin;
    uint32_t end;
};

void loc_free(struct Loc *loc);
uint32_t loc_size(struct Loc *loc);
char *loc_source(struct Loc *loc, const char *input);

#endif // LIB_RUBY_PARSER_LOC_H
