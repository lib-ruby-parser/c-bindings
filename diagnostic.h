#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_H

#include <stddef.h>
#include "messages.h"
#include "loc.h"

typedef enum LIB_RUBY_PARSER_ErrorLevel
{
    LIB_RUBY_PARSER_ERROR_LEVEL_WARNING,
    LIB_RUBY_PARSER_ERROR_LEVEL_ERROR
} LIB_RUBY_PARSER_ErrorLevel;

typedef struct LIB_RUBY_PARSER_Diagnostic
{
    LIB_RUBY_PARSER_ErrorLevel level;
    LIB_RUBY_PARSER_DiagnosticMessage message;
    LIB_RUBY_PARSER_Loc loc;
} LIB_RUBY_PARSER_Diagnostic;
void LIB_RUBY_PARSER_drop_diagnostic(LIB_RUBY_PARSER_Diagnostic *diagnostic);

typedef struct LIB_RUBY_PARSER_DiagnosticList
{
    LIB_RUBY_PARSER_Diagnostic *ptr;
    size_t len;
    size_t capacity;
} LIB_RUBY_PARSER_DiagnosticList;
void LIB_RUBY_PARSER_drop_diagnostic_list(LIB_RUBY_PARSER_DiagnosticList *diagnostic_list);

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_H
