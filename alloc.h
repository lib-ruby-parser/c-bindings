#ifndef LIB_RUBY_PARSER_ALLOC_H
#define LIB_RUBY_PARSER_ALLOC_H

#include <stddef.h>

void *lib_ruby_parser__external__alloc(size_t size);
void lib_ruby_parser__external__free(void *ptr);

#endif // LIB_RUBY_PARSER_ALLOC_H
