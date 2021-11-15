#include "string.h"

#ifdef TEST_ENV

#include "test_helper.h"
#include <string.h>
#include <stdlib.h>

char *new_owned_string(const char *s)
{
    char *out = (char *)malloc(strlen(s) + 1);
    strcpy(out, s);
    return out;
}

test(owned_string_fields, {
    LIB_RUBY_PARSER_String foo = LIB_RUBY_PARSER_new_string_owned(new_owned_string("foo"), 3);
    assert(foo.len == 3);
    assert_str_eq(foo.ptr, "foo", 3);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&foo);
});

test(copied_string_fields, {
    LIB_RUBY_PARSER_String foo = LIB_RUBY_PARSER_new_string_from_cstr("foo");
    assert(foo.len == 3);
    assert_str_eq(foo.ptr, "foo", 3);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&foo);
});

declare_test_group(string, 2, owned_string_fields, copied_string_fields);

#endif
