#include "loc.h"

#ifdef TEST_ENV

#include "test_helper.h"

LIB_RUBY_PARSER_Loc lib_ruby_parser__test__make_loc(size_t begin, size_t end);
static void test_loc_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_Loc loc = lib_ruby_parser__test__make_loc(1, 2);
    assert_loc(loc, 1, 2);
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
    assert_some_loc(some_loc, 1, 2);
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
