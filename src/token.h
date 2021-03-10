#ifndef LIB_RUBY_PARSER_TOKEN_H
#define LIB_RUBY_PARSER_TOKEN_H

#include <stdint.h>
#include "loc.h"

// Token emitted from the lexer
struct Token
{
    // Internal representation of the token type.
    // It's uniq for different token types, but don't rely on it to
    // be the same across all versions of lib-ruby-parser.
    //
    // You can use it for fast comparison, but better don't persist it.
    int token_type;

    // Value of the token (i.e. "foo" for code "foo")
    char *token_value;

    // Location of the token
    struct Loc *loc;

    // Lex state before reading a token, used by token rewriters.
    int lex_state_before;

    // Lex state after reading a token, used by token rewriters.
    int lex_state_after;
};

// A list of tokens
struct TokenList
{
    // Length of the list
    uint32_t len;

    // Pointer to array of tokens
    struct Token *list;
};

// Destructor of the TokenList
void tokens_free(struct TokenList *tokens);

// Returns a human-readable name of the given token_type.
// `token_type` must be take from the `Token` struct.
char *token_name(int token_type);

#endif // LIB_RUBY_PARSER_TOKEN_H
