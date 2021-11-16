#include "magic_comment.h"

#ifdef TEST_ENV

#include "test_helper.h"

LIB_RUBY_PARSER_MagicCommentKind lib_ruby_parser__test__make_magic_comment_kind_encoding(void);
LIB_RUBY_PARSER_MagicCommentKind lib_ruby_parser__test__make_magic_comment_kind_frozen_string_literal(void);
LIB_RUBY_PARSER_MagicCommentKind lib_ruby_parser__test__make_magic_comment_kind_warn_indent(void);
LIB_RUBY_PARSER_MagicCommentKind lib_ruby_parser__test__make_magic_comment_kind_shareable_constant_value(void);
static void test_magic_comment_kind_options(void)
{
    annotate_test;

    LIB_RUBY_PARSER_MagicCommentKind magic_comment_kind;

    magic_comment_kind = lib_ruby_parser__test__make_magic_comment_kind_encoding();
    assert_eq(magic_comment_kind, LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_ENCODING);

    magic_comment_kind = lib_ruby_parser__test__make_magic_comment_kind_frozen_string_literal();
    assert_eq(magic_comment_kind, LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_FROZEN_STRING_LITERAL);

    magic_comment_kind = lib_ruby_parser__test__make_magic_comment_kind_warn_indent();
    assert_eq(magic_comment_kind, LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_WARN_INDENT);

    magic_comment_kind = lib_ruby_parser__test__make_magic_comment_kind_shareable_constant_value();
    assert_eq(magic_comment_kind, LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_SHAREABLE_CONSTANT_VALUE);
}

#define assert_magic_comment(comment, _kind, _key_l, _value_l) \
    assert_eq(comment.kind, _kind);                            \
    assert_loc(comment.key_l, _key_l);                         \
    assert_loc(comment.value_l, _value_l)

LIB_RUBY_PARSER_MagicComment lib_ruby_parser__test__make_magic_comment(LIB_RUBY_PARSER_MagicCommentKind kind, LIB_RUBY_PARSER_Loc key_l, LIB_RUBY_PARSER_Loc value_l);
static void test_magic_comment_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_Loc key_l = {.begin = 1, .end = 2};
    LIB_RUBY_PARSER_Loc value_l = {.begin = 3, .end = 4};
    LIB_RUBY_PARSER_MagicComment comment = lib_ruby_parser__test__make_magic_comment(
        LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_FROZEN_STRING_LITERAL, key_l, value_l);

    assert_magic_comment(
        comment,
        LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_FROZEN_STRING_LITERAL, key_l, value_l);
}

LIB_RUBY_PARSER_MagicCommentList lib_ruby_parser__test__make_magic_comment_list(LIB_RUBY_PARSER_MagicComment magic_comment);
static void test_magic_comment_list_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_Loc key_l = {.begin = 1, .end = 2};
    LIB_RUBY_PARSER_Loc value_l = {.begin = 3, .end = 4};
    LIB_RUBY_PARSER_MagicCommentList magic_comment_list = lib_ruby_parser__test__make_magic_comment_list(
        lib_ruby_parser__test__make_magic_comment(
            LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_FROZEN_STRING_LITERAL, key_l, value_l));
    assert_eq(magic_comment_list.len, 1);
    assert_magic_comment(
        magic_comment_list.ptr[0],
        LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_FROZEN_STRING_LITERAL, key_l, value_l);
    LIB_RUBY_PARSER_drop_magic_comment_list(&magic_comment_list);
}

void run_test_group_magic_comment(void)
{
    const test_fn_t tests[] = {
        test_magic_comment_kind_options,
        test_magic_comment_fields,
        test_magic_comment_list_fields,
    };

    run_tests_as_group("magic_comment", tests, sizeof(tests) / sizeof(test_fn_t));
}

#endif
