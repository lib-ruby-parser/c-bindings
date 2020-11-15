#ifndef LIB_RUBY_PARSER_H
#define LIB_RUBY_PARSER_H

#include <stddef.h>
#include "types.h"
#include "gen.h"

#define free1(ptr)                \
    printf("freeing %s\n", #ptr); \
    free(ptr);

extern struct ParserResult *parse(
    const char *input, size_t length);

void tokens_free(struct Tokens *tokens)
{
    if (tokens->len > 0)
    {
        for (size_t i = 0; i < tokens->len; i++)
        {
            struct Token token = tokens->list[i];
            free1(token.token_value);
            free1(token.loc);
        }
        free1(tokens->list);
    }
    free1(tokens);
}
void diagnostics_free(struct Diagnostics *diagnostics)
{
    if (diagnostics->len > 0)
    {
        free1(diagnostics->list);
    }
    free1(diagnostics);
}
void comments_free(struct Comments *comments)
{
    if (comments->len > 0)
    {
        free1(comments->list);
    }
    free1(comments);
}
void magic_comments_free(struct MagicComments *magic_comments)
{
    if (magic_comments->len > 0)
    {
        free1(magic_comments->list);
    }
    free1(magic_comments);
}

void parser_result_free(struct ParserResult *parser_result)
{
    if (parser_result->ast != NULL)
    {
        node_free(parser_result->ast);
        free(parser_result->ast);
    }
    tokens_free(parser_result->tokens);
    diagnostics_free(parser_result->diagnostics);
    comments_free(parser_result->comments);
    magic_comments_free(parser_result->magic_comments);
    free1(parser_result);
}

void char_ptr_free(char *char_ptr)
{
    free1(char_ptr);
}

void node_list_free(struct NodeList *node_list)
{
    if (node_list->len > 0)
    {
        for (size_t i = 0; i < node_list->len; i++)
        {
            node_free(&node_list->list[i]);
            printf("node_free is done\n");
        }
        free1(node_list->list);
    }
    free1(node_list);
}

void range_free(struct Range *range)
{
    if (range == NULL)
    {
        return;
    }
    free1(range);
}

#endif // LIB_RUBY_PARSER_H
