#ifndef LIB_RUBY_PARSER_API_H
#define LIB_RUBY_PARSER_API_H

#include "parser_options.h"
#include "parser_result.h"

LIB_RUBY_PARSER_ParserResult LIB_RUBY_PARSER_parse(
    LIB_RUBY_PARSER_ParserOptions options,
    LIB_RUBY_PARSER_ByteList input);

#ifdef TEST_ENV
void run_test_group_api(void);
#endif

#endif // LIB_RUBY_PARSER_API_H
