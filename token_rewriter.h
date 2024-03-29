#ifndef LIB_RUBY_PARSER_TOKEN_REWRITER_H
#define LIB_RUBY_PARSER_TOKEN_REWRITER_H

#include <stdint.h>
#include <stdbool.h>
#include "token.h"
#include "shared_byte_list.h"

typedef enum
{
    LIB_RUBY_PARSER_REWRITE_ACTION_DROP,
    LIB_RUBY_PARSER_REWRITE_ACTION_KEEP
} LIB_RUBY_PARSER_RewriteAction;

typedef struct
{
    enum
    {
        LIB_RUBY_PARSER_LEX_STATE_SET,
        LIB_RUBY_PARSER_LEX_STATE_KEEP
    } tag;
    union
    {
        int32_t set;
    } as;
} LIB_RUBY_PARSER_LexStateAction;

typedef struct
{
    LIB_RUBY_PARSER_Token *rewritten_token;
    LIB_RUBY_PARSER_RewriteAction token_action;
    LIB_RUBY_PARSER_LexStateAction lex_state_action;
} LIB_RUBY_PARSER_TokenRewriterResult;
void LIB_RUBY_PARSER_drop_token_rewriter_result(LIB_RUBY_PARSER_TokenRewriterResult *);

typedef LIB_RUBY_PARSER_TokenRewriterResult (*LIB_RUBY_PARSER_TokenRewriter_Function)(void *state, LIB_RUBY_PARSER_Token *token, LIB_RUBY_PARSER_SharedByteList input);
typedef struct
{
    LIB_RUBY_PARSER_TokenRewriter_Function f;
    void *state;
} LIB_RUBY_PARSER_TokenRewriter;

typedef struct
{
    LIB_RUBY_PARSER_TokenRewriter token_rewriter;
} LIB_RUBY_PARSER_MaybeTokenRewriter;
bool LIB_RUBY_PARSER_maybe_token_rewriter_is_some(const LIB_RUBY_PARSER_MaybeTokenRewriter *maybe_token_rewriter);
bool LIB_RUBY_PARSER_maybe_token_rewriter_is_none(const LIB_RUBY_PARSER_MaybeTokenRewriter *maybe_token_rewriter);

#endif // LIB_RUBY_PARSER_TOKEN_REWRITER_H
