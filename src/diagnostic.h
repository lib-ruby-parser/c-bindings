#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_H

#include <stddef.h>
#include <stdint.h>
#include "loc.h"
#include "diagnostic_message.h"
#include "input.h"

// Enum of the error level of the diagnostic (warning or error)
enum ErrorLevel
{
    ERROR_LEVEL_WARNING,
    ERROR_LEVEL_ERROR
};

struct Diagnostic
{
    // Error level (i.e. warning or error)
    enum ErrorLevel level;

    // Message of the diagnostic
    struct DiagnosticMessage message;

    // Location of the diagnostic
    struct Loc *loc;
};

// A list of diagnostics
struct DiagnosticList
{
    // Length of the list
    uint32_t len;

    // Pointer to array of diagnostics
    struct Diagnostic *list;
};

// Destructor of the diagnostics list
void diagnostics_free(struct DiagnosticList *diagnostics);

// Renders given diagnostic into a string
char *diagnostic_render(struct Diagnostic diagnostic, Input *input);

// Renders a message of the given diagnostic into a string
char *diagnostic_render_message(struct Diagnostic diagnostic);

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_H
