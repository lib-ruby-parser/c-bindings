#include "string.h"
#include <stdlib.h>

void lib_ruby_parser_internal_free_string(char *s)
{
    free(s);
}

#ifdef TEST_ENV

#include "test_helper.h"
#include <string.h>

char *new_owned_string(const char *s)
{
    fprintf(stderr, "new_owned_string called\n");
    char *out = (char *)malloc(strlen(s) + 1);
    strcpy(out, s);
    fprintf(stderr, "new_owned_string completed\n");
    return out;
}

test(owned_string_fields, {
    LIB_RUBY_PARSER_String foo = LIB_RUBY_PARSER_new_string_owned(new_owned_string("foo"), 3);
    fprintf(stderr, "Constructed owned string\n");
    assert(foo.len == 3);
    assert_str_eq(foo.ptr, "foo", 3);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&foo);
    fprintf(stderr, "finishing owned string test\n");
});

test(copied_string_fields, {
    LIB_RUBY_PARSER_String foo = LIB_RUBY_PARSER_new_string_from_cstr("foo");
    fprintf(stderr, "Constructed copied string\n");
    assert(foo.len == 3);
    assert_str_eq(foo.ptr, "foo", 3);
    // capacity doesn't matter
    LIB_RUBY_PARSER_drop_string(&foo);
    fprintf(stderr, "finishing copied string test\n");
});

declare_test_group(string, 2, owned_string_fields, copied_string_fields);

#endif
