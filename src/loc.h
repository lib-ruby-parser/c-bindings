#ifndef LIB_RUBY_PARSER_LOC_H
#define LIB_RUBY_PARSER_LOC_H

#include <stddef.h>
#include <stdint.h>
#include "input.h"

// Representation of the begin..end range of the source code
struct Loc
{
    // Begin of the location
    uint32_t begin;

    // End of the location
    uint32_t end;
};

// Desctructor of the location.
void loc_free(struct Loc *loc);

// Returns the size of the location (loc->end - loc->begin)
uint32_t loc_size(const struct Loc *loc);

// Returns the source code of the location (i.e. code from `begin` to `end`)
char *loc_source(const struct Loc *loc, const Input *input);

#endif // LIB_RUBY_PARSER_LOC_H
