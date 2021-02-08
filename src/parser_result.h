#ifndef LIB_RUBY_PARSER_RESULT_H
#define LIB_RUBY_PARSER_RESULT_H

#include <stdint.h>
#include "parser_options.h"

struct ParserResult
{
    struct Node *ast;
    struct TokenList *tokens;
    struct Diagnostics *diagnostics;
    struct CommentList *comments;
    struct MagicCommentList *magic_comments;
    char *input;
    uint32_t input_len;
};

void parser_result_free(struct ParserResult *parser_result);

extern struct ParserResult *parse(
    struct ParserOptions *options, const char *input, uint32_t length);

extern char *token_name(int token_type);

#endif // LIB_RUBY_PARSER_RESULT_H
