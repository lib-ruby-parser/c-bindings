#include <string.h>
#include <stdlib.h>
#include "loc.h"
#include "rust_free.h"

void loc_free(Loc *loc)
{
    rust_loc_free(loc);
}

uint32_t loc_size(const Loc *loc)
{
    return loc->end - loc->begin;
}
