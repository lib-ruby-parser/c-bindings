#ifndef LIB_RUBY_PARSER_PARSER_OPTIONS_H
#define LIB_RUBY_PARSER_PARSER_OPTIONS_H

#include <stdint.h>
#include <stdbool.h>
#include "string.h"
#include "decoder.h"
#include "token_rewriter.h"

typedef struct LIB_RUBY_PARSER_ParserOptions
{
    LIB_RUBY_PARSER_String buffer_name;
    uint8_t debug;
    LIB_RUBY_PARSER_MaybeDecoder decoder;
    LIB_RUBY_PARSER_MaybeTokenRewriter token_rewriter;
    bool record_tokens;
} LIB_RUBY_PARSER_ParserOptions;
void LIB_RUBY_PARSER_drop_parser_options(LIB_RUBY_PARSER_ParserOptions *parser_options);

#endif // LIB_RUBY_PARSER_PARSER_OPTIONS_H
