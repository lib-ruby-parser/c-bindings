#ifndef LIB_RUBY_PARSER_TOKEN_REWRITER_H
#define LIB_RUBY_PARSER_TOKEN_REWRITER_H

#include "token.h"

enum TokenRewriteAction
{
    REWRITE_ACTION_DROP,
    REWRITE_ACTION_KEEP,
};

enum LexStateActionKind
{
    LEX_STATE_ACTION_SET,
    LEX_STATE_ACTION_KEEP,
};

union LexStateActionValue
{
    struct
    {
        int new_state;
    } set;

    struct
    {
        int dummy;
    } keep;
};

struct LexStateAction
{
    enum LexStateActionKind kind;
    union LexStateActionValue value;
};

struct TokenRewriterOutput
{
    struct Token token;
    enum TokenRewriteAction token_rewriter_action;
    struct LexStateAction lex_state_action;
};

struct TokenRewriter;

typedef struct TokenRewriterOutput TokenRewriterFn(void *state, struct Token token, const char *input);

struct TokenRewriter
{
    void *state;
    TokenRewriterFn *rewriter;
};

#endif // LIB_RUBY_PARSER_TOKEN_REWRITER_H
