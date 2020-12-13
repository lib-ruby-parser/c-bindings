#ifndef LIB_RUBY_PARSER_OPTIONS_H
#define LIB_RUBY_PARSER_OPTIONS_H

#include <stdbool.h>
#include "custom_decoder.h"

struct ParserOptions
{
    char *buffer_name;
    bool debug;
    CustomDecoder *decoder;
};

#endif // LIB_RUBY_PARSER_OPTIONS_H
