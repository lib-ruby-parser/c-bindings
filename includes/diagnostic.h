#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_H

#include <stddef.h>

struct Range;

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
    size_t len;
    struct Diagnostic *list;
};

void diagnostics_free(struct Diagnostics *diagnostics)
{
    if (diagnostics->len > 0)
    {
        for (size_t i = 0; i < diagnostics->len; i++)
        {
            struct Diagnostic diagnostic = diagnostics->list[i];
            free(diagnostic.message);
            range_free(diagnostic.range);
        }
        free(diagnostics->list);
    }
    free(diagnostics);
}

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_H
