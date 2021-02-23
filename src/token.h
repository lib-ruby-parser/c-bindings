#ifndef LIB_RUBY_PARSER_TOKEN_H
#define LIB_RUBY_PARSER_TOKEN_H

#include <stdint.h>
#include "loc.h"

struct Token
{
    int token_type;
    char *token_value;
    struct Loc *loc;

    int lex_state_before;
    int lex_state_after;
};

struct TokenList
{
    uint32_t len;
    struct Token *list;
};

void tokens_free(struct TokenList *tokens);
char *token_name(int token_type);

#endif // LIB_RUBY_PARSER_TOKEN_H
