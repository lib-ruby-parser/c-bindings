#include "loc.h"

#ifdef TEST_ENV

#include "test_helper.h"

LIB_RUBY_PARSER_Loc lib_ruby_parser__test__make_loc(size_t begin, size_t end);
test(loc_fields, {
    LIB_RUBY_PARSER_Loc loc = lib_ruby_parser__test__make_loc(1, 2);
    LIB_RUBY_PARSER_Loc expected = (LIB_RUBY_PARSER_Loc){.begin = 1, .end = 2};
    assert_loc(loc, expected);
});

LIB_RUBY_PARSER_MaybeLoc lib_ruby_parser__test__make_none_loc(void);
test(none_loc_fields, {
    LIB_RUBY_PARSER_MaybeLoc none_loc = lib_ruby_parser__test__make_none_loc();
    assert_none_loc(none_loc);
});

LIB_RUBY_PARSER_MaybeLoc lib_ruby_parser__test__make_some_loc(size_t begin, size_t end);
test(some_loc_fields, {
    LIB_RUBY_PARSER_MaybeLoc some_loc = lib_ruby_parser__test__make_some_loc(1, 2);
    LIB_RUBY_PARSER_Loc expected = (LIB_RUBY_PARSER_Loc){.begin = 1, .end = 2};
    assert_some_loc(some_loc, expected);
});

declare_test_group(
    loc,
    3,
    loc_fields,
    none_loc_fields,
    some_loc_fields);

#endif
