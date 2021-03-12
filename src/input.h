#ifndef LIB_RUBY_PARSER_INPUT_H
#define LIB_RUBY_PARSER_INPUT_H

#include <stdint.h>

// (Potentially decoded) input that is returned from parsing.
//
// It can be used to
// + get source of any location
// + render a diagnostic message
typedef void Input;

// Destructor of the Input
void input_free(Input *input);

// Returns the length of the input
uint32_t input_len(const Input *input);

// Returns a char* pointer to a given input. It shouldn't be changed.
const char *input_ptr(const Input *input);

#endif // LIB_RUBY_PARSER_INPUT_H
