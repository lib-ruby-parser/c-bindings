#ifndef LIB_RUBY_PARSER_TOKEN_H
#define LIB_RUBY_PARSER_TOKEN_H

#include <stdlib.h>

struct Loc;

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
    size_t len;
    struct Token *list;
};

void tokens_free(struct TokenList *tokens)
{
    if (tokens->len > 0)
    {
        for (size_t i = 0; i < tokens->len; i++)
        {
            struct Token token = tokens->list[i];
            free(token.token_value);
            free(token.loc);
        }
        free(tokens->list);
    }
    free(tokens);
}

#endif // LIB_RUBY_PARSER_TOKEN_H
