#include "token.h"

#ifdef TEST_ENV

#include "test_helper.h"

#define TOKEN_NAME(name, len) name, len
#define TOKEN_VALUE(...) __VA_ARGS__
#define LOC(_begin, _end) (_begin), _end
#define LEX_STATE_BEFORE(...) __VA_ARGS__
#define LEX_STATE_AFTER(...) __VA_ARGS__

#define assert_token(token, _token_name) \
    assert_str_eq(LIB_RUBY_PARSER_token_name(&token), _token_name, strlen(_token_name));

LIB_RUBY_PARSER_Token lib_ruby_parser__test__make_token_eq_loc_12_state_before_3_state_after_4();
test(token_fields, {
    LIB_RUBY_PARSER_Token token = lib_ruby_parser__test__make_token_eq_loc_12_state_before_3_state_after_4();

    assert_token(token, "tEQ");
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
    assert_token(token_list.ptr[0], "tEQ");
    LIB_RUBY_PARSER_drop_token_list(&token_list);
});

declare_test_group(token, 2, token_fields, token_list_fields);

#endif
