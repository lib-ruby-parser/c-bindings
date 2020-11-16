#ifndef LIB_RUBY_PARSER_H
#define LIB_RUBY_PARSER_H

#include <stddef.h>
#include "types.h"
#include "gen.h"

extern struct ParserResult *parse(
    const char *input, size_t length);

void tokens_free(struct Tokens *tokens)
{
    if (tokens->len > 0)
    {
        for (size_t i = 0; i < tokens->len; i++)
        {
            struct Token token = tokens->list[i];
            free(token.token_value);
            free(token.loc);
        }
        free(tokens->list);
    }
    free(tokens);
}
void diagnostics_free(struct Diagnostics *diagnostics)
{
    if (diagnostics->len > 0)
    {
        for (size_t i = 0; i < diagnostics->len; i++)
        {
            struct Diagnostic diagnostic = diagnostics->list[i];
            free(diagnostic.message);
        }
        free(diagnostics->list);
    }
    free(diagnostics);
}
void comments_free(struct Comments *comments)
{
    if (comments->len > 0)
    {
        free(comments->list);
    }
    free(comments);
}
void magic_comments_free(struct MagicComments *magic_comments)
{
    if (magic_comments->len > 0)
    {
        free(magic_comments->list);
    }
    free(magic_comments);
}

void parser_result_free(struct ParserResult *parser_result)
{
    if (parser_result->ast != NULL)
    {
        node_free(parser_result->ast);
    }
    tokens_free(parser_result->tokens);
    diagnostics_free(parser_result->diagnostics);
    comments_free(parser_result->comments);
    magic_comments_free(parser_result->magic_comments);
    free(parser_result->input);
    free(parser_result);
}

void char_ptr_free(char *char_ptr)
{
    free(char_ptr);
}

void node_free(struct Node *node)
{
    inner_node_free(node->inner, node->node_type);
    free(node);
}

void node_list_free(struct NodeList *node_list)
{
    if (node_list->len > 0)
    {
        for (size_t i = 0; i < node_list->len; i++)
        {
            struct Node node = node_list->list[i];
            inner_node_free(node.inner, node.node_type);
        }
        free(node_list->list);
    }
    free(node_list);
}

void range_free(struct Range *range)
{
    if (range == NULL)
    {
        return;
    }
    free(range);
}

extern char *debug_fmt_ast(struct Node *node);
extern char *token_name(int token_type);

#endif // LIB_RUBY_PARSER_H
