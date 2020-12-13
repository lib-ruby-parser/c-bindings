#ifndef LIB_RUBY_PARSER_H
#define LIB_RUBY_PARSER_H

#include <stddef.h>
#include <string.h>

#include "gen.h"
#include "types.h"

extern struct ParserResult *parse(
    const char *input, size_t length);

extern char *debug_fmt_ast(struct Node *node);
extern char *token_name(int token_type);

#endif // LIB_RUBY_PARSER_H
