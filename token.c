#include "token.h"

#ifdef TEST_ENV

#include "test_helper.h"

#define assert_token(token, _token_name) \
    assert_str_eq(LIB_RUBY_PARSER_token_name(&token), _token_name, strlen(_token_name));

LIB_RUBY_PARSER_Token lib_ruby_parser__test__make_token_eq(LIB_RUBY_PARSER_Loc loc, uint32_t lex_state_before, uint32_t lex_state_after);
static void test_token_fields()
{
    annotate_test;

    LIB_RUBY_PARSER_Loc loc = {.begin = 1, .end = 2};
    LIB_RUBY_PARSER_Token token = lib_ruby_parser__test__make_token_eq(loc, 3, 4);

    assert_token(token, "tEQ");
    assert_byte_list(token.token_value.raw, 1, MAKE_ARRAY('='));
    assert_loc(token.loc, loc);
    assert_eq(token.lex_state_before, 3);
    assert_eq(token.lex_state_after, 4);

    LIB_RUBY_PARSER_drop_token(&token);
}

LIB_RUBY_PARSER_TokenList lib_ruby_parser__test__make_token_list(LIB_RUBY_PARSER_Token token);
static void test_token_list_fields()
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

void run_test_group_token()
{
    const test_fn_t tests[] = {
        test_token_fields,
        test_token_list_fields,
    };

    run_tests_as_group("token", tests, sizeof(tests) / sizeof(test_fn_t));
}

#endif
