#include <string.h>
#include <stdlib.h>
#include "loc.h"

void loc_free(struct Loc *loc)
{
    free(loc);
}

uint32_t loc_size(const struct Loc *loc)
{
    return loc->end - loc->begin;
}
