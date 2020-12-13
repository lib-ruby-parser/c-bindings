#ifndef LIB_RUBY_PARSER_RESULT_H
#define LIB_RUBY_PARSER_RESULT_H

struct Node;
void node_free(struct Node *node);

struct TokenList;
void tokens_free(struct TokenList *tokens);

struct Diagnostics;
void diagnostics_free(struct Diagnostics *diagnostics);

struct CommentList;
void comments_free(struct CommentList *comments);

struct MagicCommentList;
void magic_comments_free(struct MagicCommentList *magic_comments);

struct ParserResult
{
    struct Node *ast;
    struct TokenList *tokens;
    struct Diagnostics *diagnostics;
    struct CommentList *comments;
    struct MagicCommentList *magic_comments;
    char *input;
};

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

#endif // LIB_RUBY_PARSER_RESULT_H
