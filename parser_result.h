#ifndef LIB_RUBY_PARSER_PARSER_RESULT_H
#define LIB_RUBY_PARSER_PARSER_RESULT_H

#include "string.h"
#include "source_line.h"
#include "bytes.h"
#include "nodes.h"
#include "token.h"
#include "diagnostic.h"
#include "comment.h"
#include "magic_comment.h"

typedef struct LIB_RUBY_PARSER_DecodedInput
{
    LIB_RUBY_PARSER_String name;
    LIB_RUBY_PARSER_SourceLineList lines;
    LIB_RUBY_PARSER_ByteList bytes;
} LIB_RUBY_PARSER_DecodedInput;
void LIB_RUBY_PARSER_drop_decoded_input(LIB_RUBY_PARSER_DecodedInput *decoded_input);

// ParserResult
typedef struct LIB_RUBY_PARSER_ParserResult
{
    LIB_RUBY_PARSER_Node *ast;
    LIB_RUBY_PARSER_TokenList tokens;
    LIB_RUBY_PARSER_DiagnosticList diagnostics;
    LIB_RUBY_PARSER_CommentList comments;
    LIB_RUBY_PARSER_MagicCommentList magic_comments;
    LIB_RUBY_PARSER_DecodedInput input;
} LIB_RUBY_PARSER_ParserResult;
void LIB_RUBY_PARSER_drop_parser_result(LIB_RUBY_PARSER_ParserResult *parser_result);

#endif // LIB_RUBY_PARSER_PARSER_RESULT_H
