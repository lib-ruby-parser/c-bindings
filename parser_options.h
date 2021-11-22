#ifndef LIB_RUBY_PARSER_PARSER_OPTIONS_H
#define LIB_RUBY_PARSER_PARSER_OPTIONS_H

#include <stdint.h>
#include <stdbool.h>
#include "string.h"
#include "decoder.h"
#include "token_rewriter.h"

/*
    Equivalent of `lib_ruby_parser::ParserOptions`
*/
typedef struct LIB_RUBY_PARSER_ParserOptions
{
    LIB_RUBY_PARSER_String buffer_name;
    LIB_RUBY_PARSER_MaybeDecoder decoder;
    LIB_RUBY_PARSER_MaybeTokenRewriter token_rewriter;
    bool record_tokens;
} LIB_RUBY_PARSER_ParserOptions;

/*
    ParserOptions destructor.
    Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
    i.e. it doesn't call `free` on a given pointer.
*/
void LIB_RUBY_PARSER_drop_parser_options(LIB_RUBY_PARSER_ParserOptions *parser_options);

#ifdef TEST_ENV
void run_test_group_parser_options(void);
#endif

#endif // LIB_RUBY_PARSER_PARSER_OPTIONS_H
