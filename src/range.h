#ifndef LIB_RUBY_PARSER_RANGE_H
#define LIB_RUBY_PARSER_RANGE_H

#include <stddef.h>
#include <stdint.h>

struct Range
{
    uint32_t begin_pos;
    uint32_t end_pos;
};

void range_free(struct Range *range);
uint32_t range_size(struct Range *range);
char *range_source(struct Range *range, const char *input);

#endif // LIB_RUBY_PARSER_RANGE_H
