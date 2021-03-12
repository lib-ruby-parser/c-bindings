#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "../target/lib-ruby-parser.h"

ParserResult *parse_code(ParserOptions *options, const char *code)
{
    return parse(options, code, strlen(code));
}

#define assert_not_null(obj) \
    (assert((obj) != NULL), (obj))

#define assert_eq(actual, expected) \
    assert((actual) == (expected))

#define assert_loc(loc, expected_begin, expected_end) \
    assert_not_null(loc);                             \
    assert_eq((loc)->begin, (expected_begin));        \
    assert_eq((loc)->end, (expected_end));

#define assert_str_eq(actual, expected) \
    assert_not_null(actual);            \
    assert(strcmp(actual, expected) == 0);

Node *WatchNode = NULL;

void test_parse()
{
    ParserResult *result = parse_code(NULL, "foo(100, 'baz')");
    assert_not_null(result);

    Node *node;

    node = assert_not_null(result->ast);
    assert_eq(node->node_type, NODE_SEND);

    Send *send = assert_not_null(node->inner->_send);

    assert_eq(send->recv, NULL);

    char *mid = send->method_name;
    assert_str_eq(mid, "foo");

    NodeList *args = send->args;
    assert_eq(args->len, 2);

    Node arg1 = args->list[0];
    assert_eq(arg1.node_type, NODE_INT);
    Int *_int = assert_not_null(arg1.inner->_int);
    assert_str_eq(_int->value, "100");
    assert_loc(_int->expression_l, 4, 7);
    assert_eq(_int->operator_l, NULL);

    Node arg2 = args->list[1];
    assert_eq(arg2.node_type, NODE_STR_);
    Str *str = assert_not_null(arg2.inner->_str_);
    assert_str_eq(str->value, "baz");
    assert_loc(str->begin_l, 9, 10);
    assert_loc(str->end_l, 13, 14);
    assert_loc(str->expression_l, 9, 14);

    assert_eq(send->dot_l, NULL);
    assert_loc(send->selector_l, 0, 3);
    assert_loc(send->begin_l, 3, 4);
    assert_loc(send->end_l, 14, 15);
    assert_eq(send->operator_l, NULL);
    assert_loc(send->expression_l, 0, 15);

    parser_result_free(result);
}

#define assert_token(tok, expected_tok_name, expected_tok_value, expected_begin, expected_end) \
    {                                                                                          \
        char *tok_name = token_name(tok.token_type);                                           \
        assert_str_eq(tok_name, expected_tok_name);                                            \
        free(tok_name);                                                                        \
        assert_str_eq(tok.token_value, expected_tok_value);                                    \
        assert_not_null(tok.loc);                                                              \
        assert_eq(tok.loc->begin, expected_begin);                                             \
        assert_eq(tok.loc->end, expected_end);                                                 \
    }

void test_tokens()
{
    ParserResult *result = parse_code(NULL, "2 + 3");
    TokenList *tokens = result->tokens;

    assert_eq(tokens->len, 4);

    assert_token(tokens->list[0], "tINTEGER", "2", 0, 1);
    assert_token(tokens->list[1], "tPLUS", "+", 2, 3);
    assert_token(tokens->list[2], "tINTEGER", "3", 4, 5);
    assert_token(tokens->list[3], "EOF", "", 5, 5);

    parser_result_free(result);
}

#define assert_diagnostic(diagnostic, expected_level, expected_message, expected_begin, expected_end) \
    {                                                                                                 \
        assert_eq(diagnostic.level, expected_level);                                                  \
        char *message = diagnostic_render_message(diagnostic);                                        \
        assert_str_eq(message, expected_message);                                                     \
        free(message);                                                                                \
        assert_eq(diagnostic.loc->begin, expected_begin);                                             \
        assert_eq(diagnostic.loc->end, expected_end);                                                 \
    }

void test_diagnostics()
{
    ParserResult *result = parse_code(NULL, "self = 1; nil = 2");
    DiagnosticList *diagnostics = result->diagnostics;

    assert_eq(diagnostics->len, 2);

    assert_diagnostic(diagnostics->list[0], ERROR_LEVEL_ERROR, "Can't change the value of self", 0, 4);
    assert_diagnostic(diagnostics->list[1], ERROR_LEVEL_ERROR, "Can't assign to nil", 10, 13);

    parser_result_free(result);
}

void test_comments()
{
    ParserResult *result = parse_code(NULL, "# foo\n# bar\nbaz");
    CommentList *comments = result->comments;

    assert_eq(comments->len, 2);

    assert_loc(comments->list[0].location, 0, 6);
    assert_loc(comments->list[1].location, 6, 12);

    parser_result_free(result);
}

void test_magic_comments()
{
    ParserResult *result = parse_code(NULL, "# warn-indent: true\n# frozen-string-literal: true\n# encoding: utf-8\n");
    MagicCommentList *magic_comments = result->magic_comments;

    assert_eq(magic_comments->list[0].kind, MAGIC_COMMENT_KIND_WARN_INDENT);
    assert_loc(magic_comments->list[0].key_l, 2, 13);
    assert_loc(magic_comments->list[0].value_l, 15, 19);

    assert_eq(magic_comments->list[1].kind, MAGIC_COMMENT_KIND_FROZEN_STRING_LITERAL);
    assert_loc(magic_comments->list[1].key_l, 22, 43);
    assert_loc(magic_comments->list[1].value_l, 45, 49);

    assert_eq(magic_comments->list[2].kind, MAGIC_COMMENT_KIND_ENCODING);
    assert_loc(magic_comments->list[2].key_l, 52, 60);
    assert_loc(magic_comments->list[2].value_l, 62, 67);

    parser_result_free(result);
}

void test_loc()
{
    ParserResult *result = parse_code(NULL, "2 + 2");
    Loc *expression_l = result->ast->inner->_send->expression_l;

    assert_eq(loc_size(expression_l), 5);
    char *source = loc_source(expression_l, result->input);
    assert_str_eq(source, "2 + 2");

    Loc invalid = {.begin = 0, .end = 10000};
    assert_eq(loc_source(&invalid, result->input), NULL);

    free(source);
    parser_result_free(result);
}

void test_all_nodes()
{
    char *fcontent = NULL;
    int fsize = 0;
    FILE *fp;

    fp = fopen("all_nodes.rb", "r");

    assert_not_null(fp);

    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    fcontent = malloc(fsize + 1);
    fread(fcontent, 1, fsize, fp);
    fcontent[fsize] = '\0';

    ParserResult *result = parse_code(NULL, fcontent);
    assert_not_null(result->ast);

    parser_result_free(result);
    free(fcontent);
    fclose(fp);
}

char *decoded_source = "# encoding: us-ascii\n3";
const char *decoding_error = "only US-ASCII is supported";

char *copy_string(const char *source)
{
    uint32_t len = strlen(source);
    char *out = (char *)malloc(len + 1);
    strcpy(out, source);
    return out;
}

DecoderOutput do_decode(void *state, const char *encoding, const char *input, uint32_t len)
{
    (void)state;
    (void)encoding;
    (void)input;
    (void)len;
    assert_str_eq("foo", state);
    if (strcmp(encoding, "US-ASCII") == 0)
    {
        return decode_ok(copy_string(decoded_source), strlen(decoded_source));
    }

    return decode_err(copy_string(decoding_error));
}

void test_custom_decoder_ok()
{
    CustomDecoder decoder = {.state = (void *)"foo", .decoder = do_decode};
    ParserOptions options = {.buffer_name = "(test_custom_decoder_ok)", .debug = false, .decoder = &decoder};
    ParserResult *result = parse_code(&options, "# encoding: us-ascii\n2");

    Node *node = assert_not_null(result->ast);
    assert_eq(node->node_type, NODE_INT);
    assert_str_eq(node->inner->_int->value, "3");

    parser_result_free(result);
}

void test_custom_decoder_err()
{
    CustomDecoder decoder = {.state = (void *)"foo", .decoder = do_decode};
    ParserOptions options = {.buffer_name = "(test_custom_decoder_err)", .debug = false, .decoder = &decoder};
    ParserResult *result = parse_code(&options, "# encoding: koi8-r\n2");

    assert_eq(result->ast, NULL);
    assert_eq(result->diagnostics->len, 1);
    char *message = diagnostic_render_message(result->diagnostics->list[0]);
    assert_str_eq("encoding error: DecodingError(\"only US-ASCII is supported\")", message);
    free(message);

    parser_result_free(result);
}

const char *three = "3";
TokenRewriterOutput rewrite_token(void *state, Token token, const char *input)
{
    (void)state;
    (void)input;
    if (strcmp(token.token_value, "2") == 0)
    {
        // rewrite "2" to "3"
        free(token.token_value);
        token.token_value = copy_string(three);
    }

    TokenRewriterOutput output = {
        .token = token,
        .token_rewriter_action = REWRITE_ACTION_KEEP,
        .lex_state_action = {
            .kind = LEX_STATE_ACTION_KEEP}};
    return output;
}

void test_token_rewriter()
{
    TokenRewriter token_rewriter = {
        .rewriter = rewrite_token,
        .state = NULL,
    };
    ParserOptions options = {
        .buffer_name = "(test_token_rewriter)",
        .debug = false,
        .token_rewriter = &token_rewriter,
        .record_tokens = true};
    ParserResult *result = parse_code(&options, "1 + 2");

    TokenList *tokens = result->tokens;

    assert_eq(tokens->len, 4);

    assert_token(tokens->list[0], "tINTEGER", "1", 0, 1);
    assert_token(tokens->list[1], "tPLUS", "+", 2, 3);
    assert_token(tokens->list[2], "tINTEGER", "3", 4, 5);
    assert_token(tokens->list[3], "EOF", "", 5, 5);

    parser_result_free(result);
}

int main()
{
#define test(name)                    \
    printf("Running test_%s", #name); \
    test_##name();                    \
    printf("... OK\n");

    test(parse);
    test(tokens);
    test(diagnostics);
    test(comments);
    test(magic_comments);

    test(loc);

    test(all_nodes);

    test(custom_decoder_ok);
    test(custom_decoder_err);

    test(token_rewriter);

    printf("all tests passed.\n");
}
