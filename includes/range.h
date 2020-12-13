#ifndef LIB_RUBY_PARSER_RANGE_H
#define LIB_RUBY_PARSER_RANGE_H

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

struct Range
{
    size_t begin_pos;
    size_t end_pos;
};

void range_free(struct Range *range)
{
    free(range);
}

size_t range_size(struct Range *range)
{
    return range->end_pos - range->begin_pos;
}

char *range_source(struct Range *range, const char *input)
{
    if (range->end_pos > strlen(input))
    {
        return NULL;
    }

    size_t size = range_size(range);
    char *source = (char *)malloc(size + 1);
    memcpy(source, &input[range->begin_pos], size);
    source[size] = '\0';
    return source;
}

#endif // LIB_RUBY_PARSER_RANGE_H
