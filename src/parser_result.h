#ifndef LIB_RUBY_PARSER_RESULT_H
#define LIB_RUBY_PARSER_RESULT_H

#include <stdint.h>
#include "parser_options.h"
#include "node.h"
#include "token.h"
#include "diagnostic.h"
#include "comment.h"
#include "magic_comment.h"
#include "input.h"

// Output of the parser
typedef struct ParserResult
{
    // AST
    Node *ast;

    // List of tokens, empty if ParserOptions->record_tokens was set to false.
    TokenList *tokens;

    // List of diagnostic messages (warnings or errors)
    DiagnosticList *diagnostics;

    // List of all comments
    CommentList *comments;

    // List of all magic comments
    MagicCommentList *magic_comments;

    // Decoded input, should be used to get source of locations and to render diagnostic messages
    Input *input;
} ParserResult;

// Destructor of the ParserResult
void parser_result_free(ParserResult *parser_result);

// Parses given `input` according to given `options`
extern ParserResult *parse(ParserOptions *options, const char *input, uint32_t length);

#endif // LIB_RUBY_PARSER_RESULT_H
