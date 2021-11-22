#ifndef LIB_RUBY_PARSER_PARSER_RESULT_H
#define LIB_RUBY_PARSER_PARSER_RESULT_H

#include "nodes.h"
#include "token.h"
#include "diagnostic.h"
#include "comment.h"
#include "magic_comment.h"
#include "decoded_input.h"

/*
    Equivalent of `lib_ruby_parser::ParserResult`
*/
typedef struct LIB_RUBY_PARSER_ParserResult
{
    /*
        Final AST, nullable.
    */
    LIB_RUBY_PARSER_Node *ast;

    /*
        List of tokens, empty if `parser_options.record_tokens` was set to false
    */
    LIB_RUBY_PARSER_TokenList tokens;

    /*
        List of diagnostics (errors/warnings)
    */
    LIB_RUBY_PARSER_DiagnosticList diagnostics;

    /*
        List of comments
    */
    LIB_RUBY_PARSER_CommentList comments;

    /*
        List of magic comments
    */
    LIB_RUBY_PARSER_MagicCommentList magic_comments;

    /*
        Decoded input

        Sometimes source code has a magic encoding comment
        that forces us to re-encode given source to other encoding.

        In such cases source code on the byte level is different and so
        all locations (LIB_RUBY_PARSER_Loc) refer to that new re-encode byte ranges.

        Thus, always use this re-encoded byte array to compute source code
        of any location.
    */
    LIB_RUBY_PARSER_DecodedInput input;
} LIB_RUBY_PARSER_ParserResult;
/*
    ParserResult destructor.
    Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
    i.e. it doesn't call `free` on a given pointer.
*/
void LIB_RUBY_PARSER_drop_parser_result(LIB_RUBY_PARSER_ParserResult *parser_result);

#ifdef TEST_ENV
void run_test_group_parser_result(void);
#endif

#endif // LIB_RUBY_PARSER_PARSER_RESULT_H
