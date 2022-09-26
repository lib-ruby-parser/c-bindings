#include "test_helper.h"
#include "../decoded_input.h"

LIB_RUBY_PARSER_DecodedInput lib_ruby_parser__test__make_decoded_input(void);
static void test_decoded_input(void)
{
    annotate_test;

    LIB_RUBY_PARSER_DecodedInput decoded_input = lib_ruby_parser__test__make_decoded_input();

    assert_string_eq(decoded_input.name, "(eval)");
    assert_eq(decoded_input.lines.len, 2);
    assert_source_line(decoded_input.lines.ptr[0], 0, 6, false);
    assert_source_line(decoded_input.lines.ptr[1], 6, 8, true);
    assert_byte_list(decoded_input.bytes, "2 + 2\n42");

    LIB_RUBY_PARSER_drop_decoded_input(&decoded_input);
}

static void test_decoded_input_line_col(void)
{
    annotate_test;

    LIB_RUBY_PARSER_DecodedInput decoded_input = lib_ruby_parser__test__make_decoded_input();
    LIB_RUBY_PARSER_LineCol l;

    l = LIB_RUBY_PARSER_line_col_for_pos(&decoded_input, 3);
    assert_eq(l.line, 0);
    assert_eq(l.col, 3);

    l = LIB_RUBY_PARSER_line_col_for_pos(&decoded_input, 7);
    assert_eq(l.line, 1);
    assert_eq(l.col, 1);

    LIB_RUBY_PARSER_drop_decoded_input(&decoded_input);
}

void run_test_group_decoded_input(void);
void run_test_group_decoded_input(void)
{
    const test_fn_t tests[] = {
        test_decoded_input,
        test_decoded_input_line_col,
    };

    run_tests_as_group("decoded_input", tests, sizeof(tests) / sizeof(test_fn_t));
}
