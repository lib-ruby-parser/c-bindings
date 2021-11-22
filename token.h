#ifndef LIB_RUBY_PARSER_TOKEN_H
#define LIB_RUBY_PARSER_TOKEN_H

#include "bytes.h"
#include "loc.h"
#include "token_ids.h"

/*
    Equivalent of `lib_ruby_parser::Token`
*/
typedef struct LIB_RUBY_PARSER_Token
{
    int32_t token_type;
    LIB_RUBY_PARSER_Bytes token_value;
    LIB_RUBY_PARSER_Loc loc;
    int32_t lex_state_before;
    int32_t lex_state_after;
} LIB_RUBY_PARSER_Token;
/*
    Returns token name (like "kDEF") for a given token.
*/
char *LIB_RUBY_PARSER_token_name(const LIB_RUBY_PARSER_Token *token);
/*
    Token destructor.
    Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
    i.e. it doesn't call `free` on a given pointer.
*/
void LIB_RUBY_PARSER_drop_token(LIB_RUBY_PARSER_Token *token);

/*
    Equivalent of `Vec<lib_ruby_parser::Token>`
*/
typedef struct LIB_RUBY_PARSER_TokenList
{
    LIB_RUBY_PARSER_Token *ptr;
    size_t len;
    size_t capacity;
} LIB_RUBY_PARSER_TokenList;
/*
    TokenList destructor.
    Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
    i.e. it doesn't call `free` on a given pointer.
*/
void LIB_RUBY_PARSER_drop_token_list(LIB_RUBY_PARSER_TokenList *token_list);

#ifdef TEST_ENV
void run_test_group_token(void);
#endif

#endif // LIB_RUBY_PARSER_TOKEN_H
