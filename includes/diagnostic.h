#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_H

#include <stddef.h>
#include <stdint.h>
#include "range.h"

enum ErrorLevel
{
    ERROR_LEVEL_WARNING,
    ERROR_LEVEL_ERROR
};

struct Diagnostic
{
    enum ErrorLevel level;
    char *message;
    struct Range *range;
};

struct Diagnostics
{
    uint32_t len;
    struct Diagnostic *list;
};

void diagnostics_free(struct Diagnostics *diagnostics);

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_H
