#include <stdlib.h>
#include <stdio.h>
#include "parser_result.h"
#include "token.h"
#include "diagnostic.h"
#include "comment.h"
#include "magic_comment.h"
#include "node.h"

void parser_result_free_(struct ParserResult *);

void parser_result_free(struct ParserResult *parser_result)
{
    printf("parser_result_free(1)\n");
    if (parser_result->ast != NULL)
    {
        printf("parser_result_free(2)\n");
        node_free(parser_result->ast);
    }
    printf("parser_result_free(3)\n");
    tokens_free(parser_result->tokens);
    printf("parser_result_free(4)\n");
    diagnostics_free(parser_result->diagnostics);
    printf("parser_result_free(5)\n");
    comments_free(parser_result->comments);
    printf("parser_result_free(6)\n");
    magic_comments_free(parser_result->magic_comments);
    printf("parser_result_free(7)\n");
    input_free(parser_result->input);
    printf("parser_result_free(8)\n");
    parser_result_free_(parser_result);
    printf("parser_result_free(9)\n");
}
