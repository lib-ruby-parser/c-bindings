#include "api.h"

#ifdef TEST_ENV

#include "test_helper.h"

static void test_parse(void)
{
    annotate_test;

    LIB_RUBY_PARSER_ParserOptions options = {
        .buffer_name = LIB_RUBY_PARSER_new_string_from_cstr("(eval)"),
        .decoder = {.decoder = {.f = NULL}},
        .token_rewriter = {.token_rewriter = {.f = NULL}},
        .record_tokens = true};

    LIB_RUBY_PARSER_ByteList input = LIB_RUBY_PARSER_new_bytes_from_cstr("2 + 3", 5);

    LIB_RUBY_PARSER_ParserResult result = LIB_RUBY_PARSER_parse(input, options);

    assert_eq(result.ast->tag, LIB_RUBY_PARSER_NODE_SEND);
    assert_eq(result.tokens.len, 4); // tINT tPLUS tINT EOF
    assert_eq(result.comments.len, 0);
    assert_eq(result.magic_comments.len, 0);
    assert_byte_list(result.input.bytes, "2 + 3");

    LIB_RUBY_PARSER_drop_parser_result(&result);
}

void run_test_group_api(void)
{
    const test_fn_t tests[] = {
        test_parse,
    };

    run_tests_as_group("api", tests, sizeof(tests) / sizeof(test_fn_t));
}

#endif
