#ifndef LIB_RUBY_PARSER_DECODED_INPUT_H
#define LIB_RUBY_PARSER_DECODED_INPUT_H

#include "string.h"
#include "source_line.h"
#include "bytes.h"

/*
    Equivalent of `lib_ruby_parser::source::DecodedInput`
*/
typedef struct LIB_RUBY_PARSER_DecodedInput
{
    LIB_RUBY_PARSER_String name;
    LIB_RUBY_PARSER_SourceLineList lines;
    LIB_RUBY_PARSER_ByteList bytes;
} LIB_RUBY_PARSER_DecodedInput;

/*
    DecodedInput destructor.
    Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
    i.e. it doesn't call `free` on a given pointer.
*/
void LIB_RUBY_PARSER_drop_decoded_input(LIB_RUBY_PARSER_DecodedInput *decoded_input);

#ifdef TEST_ENV
void run_test_group_decoded_input(void);
#endif

#endif // LIB_RUBY_PARSER_DECODED_INPUT_H
