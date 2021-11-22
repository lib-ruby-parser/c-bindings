#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_H

#include <stddef.h>
#include "messages.h"
#include "loc.h"

/*
    Equivalent of `lib_ruby_parser::ErrorLevel`
*/
typedef enum LIB_RUBY_PARSER_ErrorLevel
{
    LIB_RUBY_PARSER_ERROR_LEVEL_WARNING,
    LIB_RUBY_PARSER_ERROR_LEVEL_ERROR
} LIB_RUBY_PARSER_ErrorLevel;

/*
    Equivalent of `lib_ruby_parser::Diagnostic`
*/
typedef struct LIB_RUBY_PARSER_Diagnostic
{
    /*
        Level of the diagnostic (error/warning)
    */
    LIB_RUBY_PARSER_ErrorLevel level;

    /*
        Message of the diagnsotic
    */
    LIB_RUBY_PARSER_DiagnosticMessage message;

    /*
        Location of the diagnostic
    */
    LIB_RUBY_PARSER_Loc loc;
} LIB_RUBY_PARSER_Diagnostic;
/*
    Diagnostic destructor.
    Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
    i.e. it doesn't call `free` on a given pointer.
*/
void LIB_RUBY_PARSER_drop_diagnostic(LIB_RUBY_PARSER_Diagnostic *diagnostic);

/*
    Equivalent of `Vec<lib_ruby_parser::Diagnostic`
*/
typedef struct LIB_RUBY_PARSER_DiagnosticList
{
    LIB_RUBY_PARSER_Diagnostic *ptr;
    size_t len;
    size_t capacity;
} LIB_RUBY_PARSER_DiagnosticList;
/*
    DiagnosticList destructor.
    Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
    i.e. it doesn't call `free` on a given pointer.
*/
void LIB_RUBY_PARSER_drop_diagnostic_list(LIB_RUBY_PARSER_DiagnosticList *diagnostic_list);

#ifdef TEST_ENV
void run_test_group_diagnostic(void);
#endif

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_H
