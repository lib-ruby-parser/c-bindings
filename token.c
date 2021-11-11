#include "token.h"

#ifdef TEST_ENV

#include "test_helper.h"

LIB_RUBY_PARSER_Token lib_ruby_parser__test__make_token_eq_loc_12_state_before_3_state_after_4();
test(token_fields, {
    LIB_RUBY_PARSER_Token token = lib_ruby_parser__test__make_token_eq_loc_12_state_before_3_state_after_4();
    assert_str_eq(LIB_RUBY_PARSER_token_name(&token), "tEQ", 3);
    assert_byte_list(token.token_value.raw, 1, MAKE_ARRAY('='));
    assert_loc(token.loc, 1, 2);
    assert_eq(token.lex_state_before, 3);
    assert_eq(token.lex_state_after, 4);

    LIB_RUBY_PARSER_drop_token(&token);
});

LIB_RUBY_PARSER_TokenList lib_ruby_parser__test__make_token_list_1();
test(token_list_fields, {
    LIB_RUBY_PARSER_TokenList token_list = lib_ruby_parser__test__make_token_list_1();
    assert_eq(token_list.len, 1);
    assert_str_eq(LIB_RUBY_PARSER_token_name(&token_list.ptr[0]), "tEQ", 3);
    LIB_RUBY_PARSER_drop_token_list(&token_list);
});

declare_test_group(token, 2, token_fields, token_list_fields);

#endif
