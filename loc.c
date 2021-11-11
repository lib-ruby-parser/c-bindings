#include "loc.h"

#ifdef TEST_ENV

#include "test_helper.h"

LIB_RUBY_PARSER_Loc lib_ruby_parser__test__make_loc_12();
test(loc_fields, {
    LIB_RUBY_PARSER_Loc loc = lib_ruby_parser__test__make_loc_12();
    assert(loc.begin == 1);
    assert(loc.end == 2);
});

LIB_RUBY_PARSER_MaybeLoc lib_ruby_parser__test__make_none_loc();
test(none_loc_fields, {
    LIB_RUBY_PARSER_MaybeLoc none_loc = lib_ruby_parser__test__make_none_loc();
    assert(none_loc.tag == LIB_RUBY_PARSER_NONE_LOC);
});

LIB_RUBY_PARSER_MaybeLoc lib_ruby_parser__test__make_some_loc_12();
test(some_loc_fields, {
    LIB_RUBY_PARSER_MaybeLoc some_loc = lib_ruby_parser__test__make_some_loc_12();
    assert(some_loc.tag == LIB_RUBY_PARSER_SOME_LOC);
    assert(some_loc.as.loc.begin == 1);
    assert(some_loc.as.loc.end == 2);
});

declare_test_group(loc, 3, loc_fields, none_loc_fields, some_loc_fields);

#endif
