#ifndef LIB_RUBY_PARSER_RESULT_H
#define LIB_RUBY_PARSER_RESULT_H

#include <stdint.h>
#include "parser_options.h"
#include "input.h"

// Output of the parser
struct ParserResult
{
    // AST
    struct Node *ast;

    // List of tokens, empty if ParserOptions->record_tokens was set to false.
    struct TokenList *tokens;

    // List of diagnostic messages (warnings or errors)
    struct DiagnosticList *diagnostics;

    // List of all comments
    struct CommentList *comments;

    // List of all magic comments
    struct MagicCommentList *magic_comments;

    // Decoded input, should be used to get source of locations and to render diagnostic messages
    Input *input;
};

// Destructor of the ParserResult
void parser_result_free(struct ParserResult *parser_result);

// Parses given `input` according to given `options`
extern struct ParserResult *parse(
    struct ParserOptions *options, const char *input, uint32_t length);

#endif // LIB_RUBY_PARSER_RESULT_H
