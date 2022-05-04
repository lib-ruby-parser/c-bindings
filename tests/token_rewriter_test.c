#include "test_helper.h"
#include "../token_rewriter.h"
#include <string.h>
#include <stdlib.h>

LIB_RUBY_PARSER_RewriteAction lib_ruby_parser__test__make_rewrite_action__drop(void);
LIB_RUBY_PARSER_RewriteAction lib_ruby_parser__test__make_rewrite_action__keep(void);
static void test_rewriter_action(void)
{
    annotate_test;

    LIB_RUBY_PARSER_RewriteAction rewrite_action;

    rewrite_action = lib_ruby_parser__test__make_rewrite_action__drop();
    assert_eq(rewrite_action, LIB_RUBY_PARSER_REWRITE_ACTION_DROP);

    rewrite_action = lib_ruby_parser__test__make_rewrite_action__keep();
    assert_eq(rewrite_action, LIB_RUBY_PARSER_REWRITE_ACTION_KEEP);
}

LIB_RUBY_PARSER_LexStateAction lib_ruby_parser__test__make_lex_state_action__set(int32_t next_state);
LIB_RUBY_PARSER_LexStateAction lib_ruby_parser__test__make_lex_state_action__keep(void);
static void test_lex_state_action(void)
{
    annotate_test;

    LIB_RUBY_PARSER_LexStateAction lex_state_action;

    lex_state_action = lib_ruby_parser__test__make_lex_state_action__set(42);
    assert_eq(lex_state_action.tag, LIB_RUBY_PARSER_LEX_STATE_SET);
    assert_eq(lex_state_action.as.set, 42);

    lex_state_action = lib_ruby_parser__test__make_lex_state_action__keep();
    assert_eq(lex_state_action.tag, LIB_RUBY_PARSER_LEX_STATE_KEEP);
}

LIB_RUBY_PARSER_TokenRewriterResult lib_ruby_parser__test__make_token_rewriter_result(void);
static void test_token_rewriter_result(void)
{
    annotate_test;

    LIB_RUBY_PARSER_TokenRewriterResult result = lib_ruby_parser__test__make_token_rewriter_result();
    assert_token(*(result.rewritten_token), "kDEF");
    assert_eq(result.token_action, LIB_RUBY_PARSER_REWRITE_ACTION_KEEP);
    assert_eq(result.lex_state_action.tag, LIB_RUBY_PARSER_LEX_STATE_SET);
    assert_eq(result.lex_state_action.as.set, 17);

    LIB_RUBY_PARSER_drop_token_rewriter_result(&result);
}

LIB_RUBY_PARSER_TokenRewriter lib_ruby_parser__test__always_keep_token_rewriter(void);
LIB_RUBY_PARSER_TokenRewriter lib_ruby_parser__test__always_rewrite_token_rewriter(void);
static void test_token_rewriter(void)
{
    annotate_test;

    LIB_RUBY_PARSER_TokenRewriter token_rewriter;
    LIB_RUBY_PARSER_TokenRewriterResult result;
    LIB_RUBY_PARSER_Token *token;
    const char *INPUT = "foo";
    LIB_RUBY_PARSER_SharedByteList input = {.ptr = INPUT, .len = strlen(INPUT)};

    token_rewriter = lib_ruby_parser__test__always_keep_token_rewriter();
    token = (LIB_RUBY_PARSER_Token *)malloc(sizeof(LIB_RUBY_PARSER_Token));
    token->token_type = 396; // tPLUS
    token->token_value.raw = (LIB_RUBY_PARSER_ByteList){.ptr = NULL, .len = 0, .capacity = 0};
    result = (token_rewriter.f)(token_rewriter.state, token, input);
    assert_token(*(result.rewritten_token), "tPLUS");
    LIB_RUBY_PARSER_drop_token_rewriter_result(&result);

    token_rewriter = lib_ruby_parser__test__always_rewrite_token_rewriter();
    token = (LIB_RUBY_PARSER_Token *)malloc(sizeof(LIB_RUBY_PARSER_Token));
    token->token_type = 396; // tPLUS
    token->token_value.raw = (LIB_RUBY_PARSER_ByteList){.ptr = NULL, .len = 0, .capacity = 0};
    result = (token_rewriter.f)(token_rewriter.state, token, input);
    assert_token(*(result.rewritten_token), "tMINUS");
    LIB_RUBY_PARSER_drop_token_rewriter_result(&result);
}

LIB_RUBY_PARSER_MaybeTokenRewriter lib_ruby_parser__test__some_always_keep_token_rewriter(void);
LIB_RUBY_PARSER_MaybeTokenRewriter lib_ruby_parser__test__none_token_rewriter(void);
static void test_maybe_token_rewriter(void)
{
    annotate_test;

    LIB_RUBY_PARSER_MaybeTokenRewriter maybe_token_rewriter;
    LIB_RUBY_PARSER_TokenRewriter always_keep_token_rewriter = lib_ruby_parser__test__always_keep_token_rewriter();

    maybe_token_rewriter = lib_ruby_parser__test__some_always_keep_token_rewriter();
    assert(LIB_RUBY_PARSER_maybe_token_rewriter_is_some(&maybe_token_rewriter));
    assert_eq(maybe_token_rewriter.token_rewriter.f, always_keep_token_rewriter.f);

    maybe_token_rewriter = lib_ruby_parser__test__none_token_rewriter();
    assert(LIB_RUBY_PARSER_maybe_token_rewriter_is_none(&maybe_token_rewriter));
}

void run_test_group_token_rewriter(void);
void run_test_group_token_rewriter(void)
{
    const test_fn_t tests[] = {
        test_rewriter_action,
        test_lex_state_action,
        test_token_rewriter_result,
        test_token_rewriter,
        test_maybe_token_rewriter,
    };

    run_tests_as_group("token_rewriter", tests, sizeof(tests) / sizeof(test_fn_t));
}
