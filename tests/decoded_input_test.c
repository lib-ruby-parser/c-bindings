#include "test_helper.h"
#include "../decoded_input.h"

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

void run_test_group_decoded_input(void);
void run_test_group_decoded_input(void)
{
    const test_fn_t tests[] = {
        test_decoded_input,
    };

    run_tests_as_group("decoded_input", tests, sizeof(tests) / sizeof(test_fn_t));
}
