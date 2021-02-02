#include <string.h>
#include <stdlib.h>
#include "range.h"

void range_free(struct Range *range)
{
    free(range);
}

uint32_t range_size(struct Range *range)
{
    return range->end_pos - range->begin_pos;
}

char *range_source(struct Range *range, const char *input)
{
    if (range->end_pos > strlen(input))
    {
        return NULL;
    }

    uint32_t size = range_size(range);
    char *source = (char *)malloc(size + 1);
    memcpy(source, &input[range->begin_pos], size);
    source[size] = '\0';
    return source;
}
