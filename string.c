#include "string.h"

#ifdef TEST_ENV

#include "test_helper.h"

test(string_fields, {
    LIB_RUBY_PARSER_String foo = LIB_RUBY_PARSER_new_string("foo");
    assert(foo.len == 3);
    assert_str_eq(foo.ptr, "foo", 3);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&foo);
});

declare_test_group(string, 1, string_fields);

#endif
