#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_H

#include <stddef.h>
#include <stdint.h>
#include "loc.h"
#include "diagnostic_message.h"
#include "input.h"

enum ErrorLevel
{
    ERROR_LEVEL_WARNING,
    ERROR_LEVEL_ERROR
};

struct Diagnostic
{
    enum ErrorLevel level;
    struct DiagnosticMessage message;
    struct Loc *loc;
};

struct Diagnostics
{
    uint32_t len;
    struct Diagnostic *list;
};

void diagnostics_free(struct Diagnostics *diagnostics);
char *diagnostic_render(struct Diagnostic diagnostic, Input *input);
char *diagnostic_render_message(struct Diagnostic diagnostic);

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_H
