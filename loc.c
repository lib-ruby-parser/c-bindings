#include "loc.h"

#ifdef TEST_ENV

#include "test_helper.h"

void assert_loc(LIB_RUBY_PARSER_Loc left, LIB_RUBY_PARSER_Loc right)
{
    assert_eq(left.begin, right.begin);
    assert_eq(left.end, right.end);
}

void assert_some_loc(LIB_RUBY_PARSER_MaybeLoc maybe_loc, LIB_RUBY_PARSER_Loc loc)
{
    assert_eq(maybe_loc.tag, LIB_RUBY_PARSER_SOME_LOC);
    assert_loc(maybe_loc.as.loc, loc);
}

void assert_none_loc(LIB_RUBY_PARSER_MaybeLoc maybe_loc)
{
    assert_eq(maybe_loc.tag, LIB_RUBY_PARSER_NONE_LOC);
}

LIB_RUBY_PARSER_Loc lib_ruby_parser__test__make_loc(size_t begin, size_t end);
static void test_loc_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_Loc loc = lib_ruby_parser__test__make_loc(1, 2);
    LIB_RUBY_PARSER_Loc expected = (LIB_RUBY_PARSER_Loc){.begin = 1, .end = 2};
    assert_loc(loc, expected);
}

LIB_RUBY_PARSER_MaybeLoc lib_ruby_parser__test__make_none_loc(void);
static void test_none_loc_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_MaybeLoc none_loc = lib_ruby_parser__test__make_none_loc();
    assert_none_loc(none_loc);
}

LIB_RUBY_PARSER_MaybeLoc lib_ruby_parser__test__make_some_loc(size_t begin, size_t end);
static void test_some_loc_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_MaybeLoc some_loc = lib_ruby_parser__test__make_some_loc(1, 2);
    LIB_RUBY_PARSER_Loc expected = (LIB_RUBY_PARSER_Loc){.begin = 1, .end = 2};
    assert_some_loc(some_loc, expected);
}

void run_test_group_loc(void)
{
    const test_fn_t tests[] = {
        test_loc_fields,
        test_none_loc_fields,
        test_some_loc_fields,
    };

    run_tests_as_group("loc", tests, sizeof(tests) / sizeof(test_fn_t));
}

#endif
