#include <stdlib.h>
#include "parser_result.h"
#include "token.h"
#include "diagnostic.h"
#include "comment.h"
#include "magic_comment.h"
#include "node.h"

void parser_result_free(ParserResult *parser_result)
{
    if (parser_result->ast != NULL)
    {
        node_free(parser_result->ast);
    }
    tokens_free(parser_result->tokens);
    diagnostics_free(parser_result->diagnostics);
    comments_free(parser_result->comments);
    magic_comments_free(parser_result->magic_comments);
    input_free(parser_result->input);
    free(parser_result);
}
