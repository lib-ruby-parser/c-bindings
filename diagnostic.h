#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_H

#include <stddef.h>
#include "messages.h"
#include "loc.h"
#include "decoded_input.h"

/// @defgroup diagnostic Diagnostic
/// @brief A set of structs and functions to work with diagnostics
/// @{
/// @}

/// Equivalent of `lib_ruby_parser::ErrorLevel`
/// @ingroup diagnostic
typedef enum
{
    LIB_RUBY_PARSER_ERROR_LEVEL_WARNING,
    LIB_RUBY_PARSER_ERROR_LEVEL_ERROR
} LIB_RUBY_PARSER_ErrorLevel;

/// Equivalent of `lib_ruby_parser::Diagnostic`
/// @ingroup diagnostic
typedef struct
{
    /// Level of the diagnostic (error/warning)
    LIB_RUBY_PARSER_ErrorLevel level;

    /// Message of the diagnsotic
    LIB_RUBY_PARSER_DiagnosticMessage message;

    /// Location of the diagnostic
    LIB_RUBY_PARSER_Loc loc;
} LIB_RUBY_PARSER_Diagnostic;

/// Render given diagnsostic on a given source input.
/// Equivalent of lib_ruby_parser::Diagnostic::render.
/// Return owned NULL-terminated string.
/// @ingroup diagnostic
char *LIB_RUBY_PARSER_render_diagnostic(
    const LIB_RUBY_PARSER_Diagnostic *diagnostic,
    const LIB_RUBY_PARSER_DecodedInput *input);

/// Diagnostic destructor.
/// Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
/// i.e. it doesn't call `free` on a given pointer.
/// @ingroup diagnostic
void LIB_RUBY_PARSER_drop_diagnostic(LIB_RUBY_PARSER_Diagnostic *diagnostic);

/// Equivalent of `Vec<lib_ruby_parser::Diagnostic`
/// @ingroup diagnostic
typedef struct
{
    size_t capacity;
    LIB_RUBY_PARSER_Diagnostic *ptr;
    size_t len;
} LIB_RUBY_PARSER_DiagnosticList;

/// DiagnosticList destructor.
/// Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
/// i.e. it doesn't call `free` on a given pointer.
/// @ingroup diagnostic
void LIB_RUBY_PARSER_drop_diagnostic_list(LIB_RUBY_PARSER_DiagnosticList *diagnostic_list);

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_H
