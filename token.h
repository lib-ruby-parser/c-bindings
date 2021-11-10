#ifndef LIB_RUBY_PARSER_TOKEN_H
#define LIB_RUBY_PARSER_TOKEN_H

#include "bytes.h"
#include "loc.h"

typedef struct LIB_RUBY_PARSER_Token
{
    int32_t token_type;
    LIB_RUBY_PARSER_Bytes token_value;
    LIB_RUBY_PARSER_Loc loc;
    int32_t lex_state_before;
    int32_t lex_state_after;
} LIB_RUBY_PARSER_Token;
void LIB_RUBY_PARSER_drop_token(LIB_RUBY_PARSER_Token *token);

typedef struct LIB_RUBY_PARSER_TokenList
{
    LIB_RUBY_PARSER_Token *ptr;
    size_t len;
    size_t capacity;
} LIB_RUBY_PARSER_TokenList;
void LIB_RUBY_PARSER_drop_token_list(LIB_RUBY_PARSER_TokenList *token_list);

#endif // LIB_RUBY_PARSER_TOKEN_H
