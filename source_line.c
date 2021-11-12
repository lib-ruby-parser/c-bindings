#include "source_line.h"

#ifdef TEST_ENV

#include "test_helper.h"

#define assert_source_line(source_line, _start, _end, _ends_with_eof) \
    assert_eq(source_line.start, _start);                             \
    assert_eq(source_line.end, _end);                                 \
    assert_eq(source_line.ends_with_eof, _ends_with_eof);

LIB_RUBY_PARSER_SourceLine lib_ruby_parser__test__make_source_line(size_t begin, size_t end, bool ends_with_eof);
test(source_line_fields, {
    LIB_RUBY_PARSER_SourceLine source_line = lib_ruby_parser__test__make_source_line(1, 2, true);
    assert_source_line(source_line, 1, 2, true);
});

LIB_RUBY_PARSER_SourceLineList lib_ruby_parser__test__make_source_line_list(LIB_RUBY_PARSER_SourceLine source_line);
test(source_line_list_fields, {
    LIB_RUBY_PARSER_SourceLineList source_line_list = lib_ruby_parser__test__make_source_line_list(
        lib_ruby_parser__test__make_source_line(1, 2, true));
    assert_eq(source_line_list.len, 1);
    assert_source_line(source_line_list.ptr[0], 1, 2, true);
    LIB_RUBY_PARSER_drop_source_line_list(&source_line_list);
});

declare_test_group(source_line, 2, source_line_fields, source_line_list_fields);

#endif
