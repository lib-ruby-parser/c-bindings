#ifndef LIB_RUBY_PARSER_H
#define LIB_RUBY_PARSER_H

#include <stddef.h>
#include "types.h"
#include "gen.h"

extern struct ParserResult *parse(
    const char *input, size_t length);

extern void parser_result_free(struct ParserResult *parser_result);

extern char *debug_format_parser_result(struct ParserResult *parser_result);

extern struct Node *extract_ast(struct ParserResult *parser_result);
extern struct Tokens *extract_tokens(struct ParserResult *parser_result);
extern struct Diagnostics *extract_diagnostics(struct ParserResult *parser_result);
extern struct Comments *extract_comments(struct ParserResult *parser_result);
extern struct MagicComments *extract_magic_comments(struct ParserResult *parser_result);

extern void node_free(struct Node *node);
extern void tokens_free(struct Tokens *tokens);
extern void diagnostics_free(struct Diagnostics *diagnostics);
extern void comments_free(struct Comments *comments);
extern void magic_comments_free(struct MagicComments *magic_comments);

extern char *inspect_node(struct Node *node);

#endif // LIB_RUBY_PARSER_H
