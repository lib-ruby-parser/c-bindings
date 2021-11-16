#include "source_line.h"

#ifdef TEST_ENV

#include "test_helper.h"

#define assert_source_line(source_line, _start, _end, _ends_with_eof) \
    assert_eq(source_line.start, _start);                             \
    assert_eq(source_line.end, _end);                                 \
    assert_eq(source_line.ends_with_eof, _ends_with_eof)

LIB_RUBY_PARSER_SourceLine lib_ruby_parser__test__make_source_line(size_t begin, size_t end, bool ends_with_eof);
static void test_source_line_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_SourceLine source_line = lib_ruby_parser__test__make_source_line(1, 2, true);
    assert_source_line(source_line, 1, 2, true);
}

LIB_RUBY_PARSER_SourceLineList lib_ruby_parser__test__make_source_line_list(LIB_RUBY_PARSER_SourceLine source_line);
static void test_source_line_list_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_SourceLineList source_line_list = lib_ruby_parser__test__make_source_line_list(
        lib_ruby_parser__test__make_source_line(1, 2, true));
    assert_eq(source_line_list.len, 1);
    assert_source_line(source_line_list.ptr[0], 1, 2, true);
    LIB_RUBY_PARSER_drop_source_line_list(&source_line_list);
}

void run_test_group_source_line(void)
{
    const test_fn_t tests[] = {
        test_source_line_fields,
        test_source_line_list_fields,
    };

    run_tests_as_group("source_line", tests, sizeof(tests) / sizeof(test_fn_t));
}

#endif
