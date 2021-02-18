#include <string.h>
#include <stdlib.h>
#include "loc.h"

void loc_free(struct Loc *loc)
{
    free(loc);
}

uint32_t loc_size(struct Loc *loc)
{
    return loc->end - loc->begin;
}

char *loc_source(struct Loc *loc, const char *input)
{
    if (loc->end > strlen(input))
    {
        return NULL;
    }

    uint32_t size = loc_size(loc);
    char *source = (char *)malloc(size + 1);
    memcpy(source, &input[loc->begin], size);
    source[size] = '\0';
    return source;
}
