#ifndef LIB_RUBY_PARSER_PARSER_OPTIONS_H
#define LIB_RUBY_PARSER_PARSER_OPTIONS_H

#include <stdint.h>
#include <stdbool.h>
#include "string.h"
#include "decoder.h"
#include "token_rewriter.h"

/// @defgroup input Parser Input
/// @brief A set of structs and functions to work with parser input
/// @{
/// @}

/// @brief Equivalent of `lib_ruby_parser::ParserOptions`
/// @ingroup input
typedef struct
{
    LIB_RUBY_PARSER_String buffer_name;
    LIB_RUBY_PARSER_MaybeDecoder decoder;
    LIB_RUBY_PARSER_MaybeTokenRewriter token_rewriter;
    bool record_tokens;
} LIB_RUBY_PARSER_ParserOptions;

/// ParserOptions destructor.
/// Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
/// i.e. it doesn't call `free` on a given pointer.
/// @ingroup input
void LIB_RUBY_PARSER_drop_parser_options(LIB_RUBY_PARSER_ParserOptions *parser_options);

#endif // LIB_RUBY_PARSER_PARSER_OPTIONS_H
