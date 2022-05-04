#include "token_rewriter.h"

bool LIB_RUBY_PARSER_maybe_token_rewriter_is_some(const LIB_RUBY_PARSER_MaybeTokenRewriter *maybe_token_rewriter)
{
    return maybe_token_rewriter->token_rewriter.f != NULL;
}
bool LIB_RUBY_PARSER_maybe_token_rewriter_is_none(const LIB_RUBY_PARSER_MaybeTokenRewriter *maybe_token_rewriter)
{
    return maybe_token_rewriter->token_rewriter.f == NULL;
}
