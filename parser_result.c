#include "parser_result.h"

#ifdef TEST_ENV

#include "test_helper.h"

LIB_RUBY_PARSER_DecodedInput lib_ruby_parser__test__make_decoded_input(void);
static void test_decoded_input(void)
{
    annotate_test;

    LIB_RUBY_PARSER_DecodedInput decoded_input = lib_ruby_parser__test__make_decoded_input();

    assert_string_eq(decoded_input.name, "(eval)");
    assert_eq(decoded_input.lines.len, 1);
    assert_source_line(decoded_input.lines.ptr[0], 10, 20, false);
    assert_byte_list(decoded_input.bytes, "2 + 2");

    LIB_RUBY_PARSER_drop_decoded_input(&decoded_input);
}

LIB_RUBY_PARSER_ParserResult lib_ruby_parser__test__make_parser_result(void);
static void test_parser_result(void)
{
    annotate_test;

    LIB_RUBY_PARSER_ParserResult parser_result = lib_ruby_parser__test__make_parser_result();

    // ast
    assert_eq(parser_result.ast->tag, LIB_RUBY_PARSER_NODE_RETRY);
    assert_loc(parser_result.ast->as.retry.expression_l, 1, 2);

    // tokens
    assert_eq(parser_result.tokens.len, 1);
    assert_token(parser_result.tokens.ptr[0], "tINTEGER");

    // diagnostics
    assert_eq(parser_result.diagnostics.len, 1);
    assert_eq(parser_result.diagnostics.ptr[0].level, LIB_RUBY_PARSER_ERROR_LEVEL_WARNING);
    assert_eq(parser_result.diagnostics.ptr[0].message.tag, LIB_RUBY_PARSER_MESSAGE_END_IN_METHOD);
    assert_loc(parser_result.diagnostics.ptr[0].loc, 5, 6);

    // comments
    assert_eq(parser_result.comments.len, 1);
    assert_eq(parser_result.comments.ptr[0].kind, LIB_RUBY_PARSER_COMMENT_TYPE_INLINE);
    assert_loc(parser_result.comments.ptr[0].location, 7, 8);

    // magic comments
    assert_eq(parser_result.magic_comments.len, 1);
    assert_eq(parser_result.magic_comments.ptr[0].kind, LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_ENCODING);
    assert_loc(parser_result.magic_comments.ptr[0].key_l, 9, 10);
    assert_loc(parser_result.magic_comments.ptr[0].value_l, 11, 12);

    // decoded input
    assert_string_eq(parser_result.input.name, "(eval)");
    assert_eq(parser_result.input.lines.len, 1);
    assert_source_line(parser_result.input.lines.ptr[0], 10, 20, false);
    assert_byte_list(parser_result.input.bytes, "2 + 2");

    LIB_RUBY_PARSER_drop_parser_result(&parser_result);
}

void run_test_group_parser_result(void)
{
    const test_fn_t tests[] = {
        test_decoded_input,
        test_parser_result,
    };

    run_tests_as_group("parser_result", tests, sizeof(tests) / sizeof(test_fn_t));
}

#endif
