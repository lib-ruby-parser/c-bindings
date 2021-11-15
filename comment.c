#include "comment.h"

#ifdef TEST_ENV

#include "test_helper.h"

LIB_RUBY_PARSER_CommentType lib_ruby_parser__test__make_comment_type_document();
LIB_RUBY_PARSER_CommentType lib_ruby_parser__test__make_comment_type_inline();
LIB_RUBY_PARSER_CommentType lib_ruby_parser__test__make_comment_type_unknown();
test(comment_type_options, {
    LIB_RUBY_PARSER_CommentType comment_type;

    comment_type = lib_ruby_parser__test__make_comment_type_document();
    assert_eq(comment_type, LIB_RUBY_PARSER_COMMENT_TYPE_DOCUMENT);

    comment_type = lib_ruby_parser__test__make_comment_type_inline();
    assert_eq(comment_type, LIB_RUBY_PARSER_COMMENT_TYPE_INLINE);

    comment_type = lib_ruby_parser__test__make_comment_type_unknown();
    assert_eq(comment_type, LIB_RUBY_PARSER_COMMENT_TYPE_UNKNOWN);
});

#define assert_comment(comment, _location, _kind) \
    assert_loc(comment.location, _location);      \
    assert_eq(comment.kind, _kind);

LIB_RUBY_PARSER_Comment lib_ruby_parser__test__make_comment(LIB_RUBY_PARSER_Loc location, LIB_RUBY_PARSER_CommentType kind);
test(comment_fields, {
    LIB_RUBY_PARSER_Loc loc = {.begin = 1, .end = 2};
    LIB_RUBY_PARSER_Comment comment = lib_ruby_parser__test__make_comment(
        loc,
        LIB_RUBY_PARSER_COMMENT_TYPE_INLINE);

    assert_comment(comment, loc, LIB_RUBY_PARSER_COMMENT_TYPE_INLINE);
});

LIB_RUBY_PARSER_CommentList lib_ruby_parser__test__make_comment_list(LIB_RUBY_PARSER_Comment comment);
test(comment_list_fields, {
    LIB_RUBY_PARSER_Loc loc = {.begin = 1, .end = 2};
    LIB_RUBY_PARSER_CommentList comment_list = lib_ruby_parser__test__make_comment_list(
        lib_ruby_parser__test__make_comment(
            loc,
            LIB_RUBY_PARSER_COMMENT_TYPE_INLINE));
    assert_eq(comment_list.len, 1);
    assert_comment(comment_list.ptr[0], loc, LIB_RUBY_PARSER_COMMENT_TYPE_INLINE);
    LIB_RUBY_PARSER_drop_comment_list(&comment_list);
});

declare_test_group(
    comment,
    3,
    comment_type_options,
    comment_fields,
    comment_list_fields);

#endif
