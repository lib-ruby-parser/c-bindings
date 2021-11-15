#include "comment.h"

#ifdef TEST_ENV

#include "test_helper.h"

LIB_RUBY_PARSER_CommentType lib_ruby_parser__test__make_comment_type_document();
LIB_RUBY_PARSER_CommentType lib_ruby_parser__test__make_comment_type_inline();
LIB_RUBY_PARSER_CommentType lib_ruby_parser__test__make_comment_type_unknown();
static void test_comment_type_options()
{
    annotate_test;

    LIB_RUBY_PARSER_CommentType comment_type;

    comment_type = lib_ruby_parser__test__make_comment_type_document();
    assert_eq(comment_type, LIB_RUBY_PARSER_COMMENT_TYPE_DOCUMENT);

    comment_type = lib_ruby_parser__test__make_comment_type_inline();
    assert_eq(comment_type, LIB_RUBY_PARSER_COMMENT_TYPE_INLINE);

    comment_type = lib_ruby_parser__test__make_comment_type_unknown();
    assert_eq(comment_type, LIB_RUBY_PARSER_COMMENT_TYPE_UNKNOWN);
}

#define assert_comment(comment, _location, _kind) \
    assert_loc(comment.location, _location);      \
    assert_eq(comment.kind, _kind);

LIB_RUBY_PARSER_Comment lib_ruby_parser__test__make_comment(LIB_RUBY_PARSER_Loc location, LIB_RUBY_PARSER_CommentType kind);
static void test_comment_fields()
{
    annotate_test;

    LIB_RUBY_PARSER_Loc loc = {.begin = 1, .end = 2};
    LIB_RUBY_PARSER_Comment comment = lib_ruby_parser__test__make_comment(
        loc,
        LIB_RUBY_PARSER_COMMENT_TYPE_INLINE);

    assert_comment(comment, loc, LIB_RUBY_PARSER_COMMENT_TYPE_INLINE);
}

LIB_RUBY_PARSER_CommentList lib_ruby_parser__test__make_comment_list(LIB_RUBY_PARSER_Comment comment);
static void test_comment_list_fields()
{
    annotate_test;

    LIB_RUBY_PARSER_Loc loc = {.begin = 1, .end = 2};
    LIB_RUBY_PARSER_CommentList comment_list = lib_ruby_parser__test__make_comment_list(
        lib_ruby_parser__test__make_comment(
            loc,
            LIB_RUBY_PARSER_COMMENT_TYPE_INLINE));
    assert_eq(comment_list.len, 1);
    assert_comment(comment_list.ptr[0], loc, LIB_RUBY_PARSER_COMMENT_TYPE_INLINE);
    LIB_RUBY_PARSER_drop_comment_list(&comment_list);
}

void run_test_group_comment()
{
    const test_fn_t tests[] = {
        test_comment_type_options,
        test_comment_fields,
        test_comment_list_fields,
    };

    run_tests_as_group("comment", tests, sizeof(tests) / sizeof(test_fn_t));
}

#endif
