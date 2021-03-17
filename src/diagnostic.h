#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_H

#include <stddef.h>
#include <stdint.h>
#include "loc.h"
#include "diagnostic_message.h"
#include "input.h"

// Enum of the error level of the diagnostic (warning or error)
typedef enum ErrorLevel
{
    ERROR_LEVEL_WARNING,
    ERROR_LEVEL_ERROR
} ErrorLevel;

typedef struct Diagnostic
{
    // Error level (i.e. warning or error)
    ErrorLevel level;

    // Message of the diagnostic
    DiagnosticMessage message;

    // Location of the diagnostic
    Loc *loc;
} Diagnostic;

// A list of diagnostics
typedef struct DiagnosticList
{
    // Length of the list
    uint32_t len;

    // Pointer to array of diagnostics
    Diagnostic *list;
} DiagnosticList;

// Destructor of the diagnostics list
void diagnostics_free(DiagnosticList *diagnostics);

// Renders given diagnostic into a string
//
// To free its output better use platform-independent `free_rendered_diagnostic`.
char *diagnostic_render(Diagnostic diagnostic, Input *input);

// Renders a message of the given diagnostic into a string
//
// To free its output better use platform-independent `free_diagnostic_message`.
char *diagnostic_render_message(Diagnostic diagnostic);

// Destructor of the rendered diagnostic.
// On some platforms it's possible to use `free` instead of this method,
// however, Rust allocator is not always compatible with C allocator.
void free_rendered_diagnostic(char *rendered);

// Destructor of the diagnostic message.
// On some platforms it's possible to use `free` instead of this method,
// however, Rust allocator is not always compatible with C allocator.
void free_diagnostic_message(char *message);

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_H
