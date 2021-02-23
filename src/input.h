#ifndef LIB_RUBY_PARSER_INPUT_H
#define LIB_RUBY_PARSER_INPUT_H

#include <stdint.h>

typedef void Input;

void input_free(Input *input);
uint32_t input_len(Input *input);
const char *input_ptr(Input *input);

#endif // LIB_RUBY_PARSER_INPUT_H
