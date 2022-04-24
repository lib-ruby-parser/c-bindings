#include "diagnostic.h"

#ifdef TEST_ENV

#include "test_helper.h"
#include <stdlib.h>

LIB_RUBY_PARSER_Diagnostic lib_ruby_parser__test__make_diagnostic(
    LIB_RUBY_PARSER_ErrorLevel level,
    LIB_RUBY_PARSER_DiagnosticMessage message,
    LIB_RUBY_PARSER_Loc loc);
static void test_diagnostic(void)
{
    annotate_test;

    LIB_RUBY_PARSER_Diagnostic diagnostic = lib_ruby_parser__test__make_diagnostic(
        LIB_RUBY_PARSER_ERROR_LEVEL_ERROR,
        (LIB_RUBY_PARSER_DiagnosticMessage){.tag = LIB_RUBY_PARSER_MESSAGE_UNTERMINATED_HEREDOC, .as = {.unterminated_heredoc = {.heredoc_id = LIB_RUBY_PARSER_new_string_from_cstr("foo")}}},
        (LIB_RUBY_PARSER_Loc){.begin = 1, .end = 2});

    assert_eq(diagnostic.level, LIB_RUBY_PARSER_ERROR_LEVEL_ERROR);
    assert_eq(diagnostic.message.tag, LIB_RUBY_PARSER_MESSAGE_UNTERMINATED_HEREDOC);
    assert_string_eq(diagnostic.message.as.unterminated_heredoc.heredoc_id, "foo");
    assert_eq(diagnostic.loc.begin, 1);
    assert_eq(diagnostic.loc.end, 2);

    LIB_RUBY_PARSER_drop_diagnostic(&diagnostic);
}

static void test_diagnostic_render(void)
{
    annotate_test;

    LIB_RUBY_PARSER_Diagnostic diagnostic = {
        .level = LIB_RUBY_PARSER_ERROR_LEVEL_ERROR,
        .message = {
            .tag = LIB_RUBY_PARSER_MESSAGE_UNTERMINATED_HEREDOC,
            .as = {
                .unterminated_heredoc = {
                    .heredoc_id = LIB_RUBY_PARSER_new_string_from_cstr("foo")}}},
        .loc = {.begin = 1, .end = 4}};
    LIB_RUBY_PARSER_SourceLine *lines = (LIB_RUBY_PARSER_SourceLine *)malloc(sizeof(LIB_RUBY_PARSER_SourceLine) * 1);
    lines[0].start = 0;
    lines[0].end = 9;
    lines[0].ends_with_eof = true;
    LIB_RUBY_PARSER_DecodedInput input = {
        .bytes = LIB_RUBY_PARSER_new_bytes_from_cstr("2 + 2 + 3", 9),
        .lines = {.ptr = lines, .len = 1, .capacity = 1},
        .name = LIB_RUBY_PARSER_new_string_from_cstr("(eval)")};

    char *rendered = LIB_RUBY_PARSER_render_diagnostic(&diagnostic, &input);
    const char *expected = "(eval):1:1: error: can't find string \"foo\" anywhere before EOF\n"
                           "(eval):1: 2 + 2 + 3\n"
                           "(eval):1:  ^~~";

    assert_str_eq(rendered, expected);

    free(rendered);
    LIB_RUBY_PARSER_drop_decoded_input(&input);
    LIB_RUBY_PARSER_drop_diagnostic(&diagnostic);
}

LIB_RUBY_PARSER_DiagnosticList lib_ruby_parser__test__make_diagnostic_list(LIB_RUBY_PARSER_Diagnostic diagnostic);
static void test_diagnostic_list(void)
{
    annotate_test;

    LIB_RUBY_PARSER_DiagnosticList diagnostic_list = lib_ruby_parser__test__make_diagnostic_list(
        lib_ruby_parser__test__make_diagnostic(
            LIB_RUBY_PARSER_ERROR_LEVEL_WARNING,
            (LIB_RUBY_PARSER_DiagnosticMessage){.tag = LIB_RUBY_PARSER_MESSAGE_INVALID_CHARACTER_SYNTAX, .as = {.invalid_character_syntax = {.suggestion = LIB_RUBY_PARSER_new_string_from_cstr("bar")}}},
            (LIB_RUBY_PARSER_Loc){.begin = 3, .end = 4}));

    assert_eq(diagnostic_list.len, 1);
    assert_eq(diagnostic_list.ptr[0].level, LIB_RUBY_PARSER_ERROR_LEVEL_WARNING);
    assert_eq(diagnostic_list.ptr[0].message.tag, LIB_RUBY_PARSER_MESSAGE_INVALID_CHARACTER_SYNTAX);
    assert_string_eq(diagnostic_list.ptr[0].message.as.invalid_character_syntax.suggestion, "bar");
    assert_eq(diagnostic_list.ptr[0].loc.begin, 3);
    assert_eq(diagnostic_list.ptr[0].loc.end, 4);

    LIB_RUBY_PARSER_drop_diagnostic_list(&diagnostic_list);
}

void run_test_group_diagnostic(void)
{
    const test_fn_t tests[] = {
        test_diagnostic,
        test_diagnostic_render,
        test_diagnostic_list,
    };

    run_tests_as_group("diagnostic", tests, sizeof(tests) / sizeof(test_fn_t));
}

#endif
