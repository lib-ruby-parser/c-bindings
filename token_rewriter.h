#ifndef LIB_RUBY_PARSER_TOKEN_REWRITER_H
#define LIB_RUBY_PARSER_TOKEN_REWRITER_H

#include <stdint.h>
#include "token.h"
#include "shared_byte_list.h"

typedef enum LIB_RUBY_PARSER_RewriteAction
{
    LIB_RUBY_PARSER_REWRITE_ACTION_DROP,
    LIB_RUBY_PARSER_REWRITE_ACTION_KEEP
} LIB_RUBY_PARSER_RewriteAction;

typedef struct LIB_RUBY_PARSER_LexStateAction
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

typedef struct LIB_RUBY_PARSER_TokenRewriterResult
{
    LIB_RUBY_PARSER_Token *rewritten_token;
    LIB_RUBY_PARSER_RewriteAction token_action;
    LIB_RUBY_PARSER_LexStateAction lex_state_action;
} LIB_RUBY_PARSER_TokenRewriterResult;
void LIB_RUBY_PARSER_drop_token_rewriter_result(LIB_RUBY_PARSER_TokenRewriterResult *);

struct LIB_RUBY_PARSER_TokenRewriter;
typedef LIB_RUBY_PARSER_TokenRewriterResult (*LIB_RUBY_PARSER_TokenRewriter_Function)(struct LIB_RUBY_PARSER_TokenRewriter *, LIB_RUBY_PARSER_Token *, LIB_RUBY_PARSER_SharedByteList);
typedef struct LIB_RUBY_PARSER_TokenRewriter
{
    LIB_RUBY_PARSER_TokenRewriter_Function rewrite_fn;
} LIB_RUBY_PARSER_TokenRewriter;

typedef struct LIB_RUBY_PARSER_MaybeTokenRewriter
{
    enum
    {
        LIB_RUBY_PARSER_SOME_TOKEN_REWRITER,
        LIB_RUBY_PARSER_NONE_TOKEN_REWRITER
    } tag;

    union
    {
        LIB_RUBY_PARSER_TokenRewriter token_rewriter;
        uint8_t none;
    } as;
} LIB_RUBY_PARSER_MaybeTokenRewriter;

#endif // LIB_RUBY_PARSER_TOKEN_REWRITER_H
