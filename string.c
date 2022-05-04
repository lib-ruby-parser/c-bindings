#include "string.h"
#include <stdlib.h>

bool LIB_RUBY_PARSER_maybe_string_is_some(const LIB_RUBY_PARSER_MaybeString *maybe_string)
{
    return maybe_string->string.ptr != NULL;
}
bool LIB_RUBY_PARSER_maybe_string_is_none(const LIB_RUBY_PARSER_MaybeString *maybe_string)
{
    return maybe_string->string.ptr == NULL;
}
