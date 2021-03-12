#ifndef LIB_RUBY_PARSER_TOKEN_REWRITER_H
#define LIB_RUBY_PARSER_TOKEN_REWRITER_H

#include "token.h"

typedef enum TokenRewriteAction
{
    REWRITE_ACTION_DROP,
    REWRITE_ACTION_KEEP,
} TokenRewriteAction;

typedef enum LexStateActionKind
{
    LEX_STATE_ACTION_SET,
    LEX_STATE_ACTION_KEEP,
} LexStateActionKind;

typedef union LexStateActionValue
{
    struct
    {
        int new_state;
    } set;

    struct
    {
        int dummy;
    } keep;
} LexStateActionValue;

typedef struct LexStateAction
{
    LexStateActionKind kind;
    LexStateActionValue value;
} LexStateAction;

typedef struct TokenRewriterOutput
{
    Token token;
    TokenRewriteAction token_rewriter_action;
    LexStateAction lex_state_action;
} TokenRewriterOutput;

typedef struct TokenRewriter TokenRewriter;

typedef struct TokenRewriterOutput TokenRewriterFn(void *state, Token token, const char *input);

typedef struct TokenRewriter
{
    void *state;
    TokenRewriterFn *rewriter;
} TokenRewriter;

#endif // LIB_RUBY_PARSER_TOKEN_REWRITER_H
