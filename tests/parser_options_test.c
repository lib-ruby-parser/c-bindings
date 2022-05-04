#include "test_helper.h"
#include "../parser_options.h"

LIB_RUBY_PARSER_ParserOptions lib_ruby_parser__test__make_parser_options(void);

static void test_parser_options(void)
{
    annotate_test;

    LIB_RUBY_PARSER_ParserOptions parser_options = lib_ruby_parser__test__make_parser_options();
    assert_string_eq(parser_options.buffer_name, "(eval)");
    assert(LIB_RUBY_PARSER_maybe_token_rewriter_is_none(&(parser_options.token_rewriter)));
    assert(LIB_RUBY_PARSER_maybe_decoder_is_none(&(parser_options.decoder)));
    assert(parser_options.record_tokens);

    LIB_RUBY_PARSER_drop_parser_options(&parser_options);
}

void run_test_group_parser_options(void);
void run_test_group_parser_options(void)
{
    const test_fn_t tests[] = {
        test_parser_options,
    };

    run_tests_as_group("parser_options", tests, sizeof(tests) / sizeof(test_fn_t));
}
