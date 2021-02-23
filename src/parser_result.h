#ifndef LIB_RUBY_PARSER_RESULT_H
#define LIB_RUBY_PARSER_RESULT_H

#include <stdint.h>
#include "parser_options.h"
#include "input.h"

struct ParserResult
{
    struct Node *ast;
    struct TokenList *tokens;
    struct Diagnostics *diagnostics;
    struct CommentList *comments;
    struct MagicCommentList *magic_comments;
    Input *input;
};

void parser_result_free(struct ParserResult *parser_result);

extern struct ParserResult *parse(
    struct ParserOptions *options, const char *input, uint32_t length);

#endif // LIB_RUBY_PARSER_RESULT_H
