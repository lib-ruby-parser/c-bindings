#ifndef LIB_RUBY_PARSER_OPTIONS_H
#define LIB_RUBY_PARSER_OPTIONS_H

#include <stdbool.h>
#include "custom_decoder.h"
#include "token_rewriter.h"

// Options that affect the process of parsing
struct ParserOptions
{
    // Null-terminated name of the file you parse
    char *buffer_name;

    // Debug mode. When enabled forces parser to print all shift/reduce operations. Used for development.
    bool debug;

    // Custom decoder that is used when given input has encoding different from ascii-8bit/utf-8
    struct CustomDecoder *decoder;

    // Flag that enables parser to record tokens. When set to false `ParserResult->tokens` is always empty.
    bool record_tokens;

    // Custom token rewriter.
    struct TokenRewriter *token_rewriter;
};

#endif // LIB_RUBY_PARSER_OPTIONS_H
