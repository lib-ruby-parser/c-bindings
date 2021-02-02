#ifndef LIB_RUBY_PARSER_OPTIONS_H
#define LIB_RUBY_PARSER_OPTIONS_H

#include <stdbool.h>
#include "custom_decoder.h"
#include "token_rewriter.h"

struct ParserOptions
{
    char *buffer_name;
    bool debug;
    CustomDecoder *decoder;
    bool record_tokens;
    struct TokenRewriter *token_rewriter;
};

#endif // LIB_RUBY_PARSER_OPTIONS_H
