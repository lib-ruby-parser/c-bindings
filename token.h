#ifndef LIB_RUBY_PARSER_TOKEN_H
#define LIB_RUBY_PARSER_TOKEN_H

#include "bytes.h"
#include "loc.h"
#include "token_ids.h"

/// @defgroup token Token
/// @{
/// @}

/// Equivalent of `lib_ruby_parser::Token`
/// @ingroup token
typedef struct
{
    int32_t token_type;
    LIB_RUBY_PARSER_Bytes token_value;
    LIB_RUBY_PARSER_Loc loc;
    int32_t lex_state_before;
    int32_t lex_state_after;
} LIB_RUBY_PARSER_Token;

/// Returns token name (like "kDEF") for a given token.
/// @ingroup token
char *LIB_RUBY_PARSER_token_name(const LIB_RUBY_PARSER_Token *token);

/// Token destructor.
/// Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
/// i.e. it doesn't call `free` on a given pointer.
/// @ingroup token
void LIB_RUBY_PARSER_drop_token(LIB_RUBY_PARSER_Token *token);

/// @brief Equivalent of `Vec<lib_ruby_parser::Token>`
/// @ingroup token
typedef struct
{
    size_t capacity;
    LIB_RUBY_PARSER_Token *ptr;
    size_t len;
} LIB_RUBY_PARSER_TokenList;

/// TokenList destructor.
/// Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
/// i.e. it doesn't call `free` on a given pointer.
/// @ingroup token
void LIB_RUBY_PARSER_drop_token_list(LIB_RUBY_PARSER_TokenList *token_list);

#endif // LIB_RUBY_PARSER_TOKEN_H
