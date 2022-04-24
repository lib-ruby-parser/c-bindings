#include "token.h"

#ifdef TEST_ENV

#include "test_helper.h"
#include <string.h>
#include <stdlib.h>

LIB_RUBY_PARSER_Token lib_ruby_parser__test__make_token_eq(LIB_RUBY_PARSER_Loc loc, uint32_t lex_state_before, uint32_t lex_state_after);
static void test_token_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_Token token = lib_ruby_parser__test__make_token_eq((LIB_RUBY_PARSER_Loc){.begin = 1, .end = 2}, 3, 4);

    assert_eq(token.token_type, LIB_RUBY_PARSER_TOKEN_tEQ);
    assert_token(token, "tEQ");
    assert_byte_list(token.token_value.raw, "=");
    assert_loc(token.loc, 1, 2);
    assert_eq(token.lex_state_before, 3);
    assert_eq(token.lex_state_after, 4);

    LIB_RUBY_PARSER_drop_token(&token);
}

LIB_RUBY_PARSER_TokenList lib_ruby_parser__test__make_token_list(LIB_RUBY_PARSER_Token token);
static void test_token_list_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_TokenList token_list = lib_ruby_parser__test__make_token_list(
        lib_ruby_parser__test__make_token_eq(
            (LIB_RUBY_PARSER_Loc){.begin = 1, .end = 2},
            3, 4));
    assert_eq(token_list.len, 1);
    assert_token(token_list.ptr[0], "tEQ");
    LIB_RUBY_PARSER_drop_token_list(&token_list);
}

void run_test_group_token(void)
{
    const test_fn_t tests[] = {
        test_token_fields,
        test_token_list_fields,
    };

    run_tests_as_group("token", tests, sizeof(tests) / sizeof(test_fn_t));
}

#endif
