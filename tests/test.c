#include <stdio.h>
#include <assert.h>
#include "../api.h"
#include <string.h>
#include <stdlib.h>

uint8_t *copy_string(const char *source)
{
    uint32_t len = strlen(source);
    char *out = (char *)malloc(len + 1);
    strcpy(out, source);
    return (uint8_t *)out;
}

LIB_RUBY_PARSER_StringPtr new_string_ptr(const char *code)
{
    LIB_RUBY_PARSER_StringPtr string_ptr = {.ptr = copy_string(code), .len = strlen(code)};
    return string_ptr;
}

LIB_RUBY_PARSER_ByteList new_byte_list(const char *code)
{
    LIB_RUBY_PARSER_ByteList byte_list = {.ptr = copy_string(code), .len = strlen(code)};
    return byte_list;
}

LIB_RUBY_PARSER_ParserOptions default_parser_options()
{
    LIB_RUBY_PARSER_ParserOptions options = {
        .buffer_name = new_string_ptr("(eval)"),
        .debug = false,
        .decoder = {.tag = LIB_RUBY_PARSER_MAYBE_DECODER_NONE, .as = {.nothing = {.dummy = 42}}},
        .token_rewriter = {.tag = LIB_RUBY_PARSER_MAYBE_TOKEN_REWRITER_NONE, .as = {.nothing = {.dummy = 42}}},
        .record_tokens = true};
    return options;
}

LIB_RUBY_PARSER_ParserResult parse(const char *code, LIB_RUBY_PARSER_ParserOptions options)
{
    LIB_RUBY_PARSER_ByteList input = new_byte_list(code);
    LIB_RUBY_PARSER_ParserResult result = lib_ruby_parser__parse(options, input);
    return result;
}

#define assert_not_null(obj) \
    assert((obj) != NULL)

#define assert_eq(actual, expected) \
    assert((actual) == (expected))

#define assert_no_loc(loc) \
    assert_eq((loc).tag, LIB_RUBY_PARSER_MAYBE_LOC_NONE);

#define assert_some_loc(loc) \
    assert_eq((loc).tag, LIB_RUBY_PARSER_MAYBE_LOC_SOME);

#define assert_loc(loc, e_begin, e_end) \
    assert_eq((loc).begin, (e_begin));  \
    assert_eq((loc).end, (e_end));

#define assert_maybe_loc(maybe_loc, e_begin, e_end) \
    assert_some_loc(maybe_loc);                     \
    assert_loc((maybe_loc).as.loc, (e_begin), (e_end));

#define assert_str_eq(string_ptr, literal)                                              \
    {                                                                                   \
        assert_not_null(string_ptr.ptr);                                                \
        assert_eq(strlen(literal), string_ptr.len);                                     \
        assert(strncmp((char *)literal, (char *)string_ptr.ptr, strlen(literal)) == 0); \
    }

void test_parse()
{
    LIB_RUBY_PARSER_ParserOptions options = default_parser_options();
    LIB_RUBY_PARSER_ParserResult result = parse("foo(100, 'baz')", options);

    LIB_RUBY_PARSER_Node *node;

    assert_not_null(result.ast);
    node = result.ast;
    assert_eq(node->tag, LIB_RUBY_PARSER_NODE_SEND);

    LIB_RUBY_PARSER_Send send = node->as.send;
    assert_eq(send.recv, NULL);
    assert_str_eq(send.method_name, "foo");

    LIB_RUBY_PARSER_NodeList args = send.args;
    assert_eq(args.len, 2);

    LIB_RUBY_PARSER_Node arg1 = args.ptr[0];
    assert_eq(arg1.tag, LIB_RUBY_PARSER_NODE_INT);
    LIB_RUBY_PARSER_Int int_ = arg1.as.int_;
    assert_str_eq(int_.value, "100");
    assert_loc(int_.expression_l, 4, 7);
    assert_no_loc(int_.operator_l);

    LIB_RUBY_PARSER_Node arg2 = args.ptr[1];
    assert_eq(arg2.tag, LIB_RUBY_PARSER_NODE_STR);

    LIB_RUBY_PARSER_Str str = arg2.as.str;
    assert_str_eq(str.value.raw, "baz");
    assert_maybe_loc(str.begin_l, 9, 10);
    assert_maybe_loc(str.end_l, 13, 14);
    assert_loc(str.expression_l, 9, 14);

    assert_no_loc(send.dot_l);
    assert_maybe_loc(send.selector_l, 0, 3);
    assert_maybe_loc(send.begin_l, 3, 4);
    assert_maybe_loc(send.end_l, 14, 15);
    assert_no_loc(send.operator_l);
    assert_loc(send.expression_l, 0, 15);

    LIB_RUBY_PARSER_drop_parser_result(&result);
}

#define assert_token(token, e_tok_name, e_tok_value, e_begin, e_end)                \
    {                                                                               \
        LIB_RUBY_PARSER_StringPtr tok_name = lib_ruby_parser__token_name(&(token)); \
        assert_str_eq(tok_name, e_tok_name);                                        \
        assert_str_eq(token.token_value.raw, e_tok_value);                          \
        assert_loc(token.loc, e_begin, e_end);                                      \
        LIB_RUBY_PARSER_drop_string_ptr(&tok_name);                                 \
    }

void test_tokens()
{
    LIB_RUBY_PARSER_ParserOptions options = default_parser_options();
    options.record_tokens = true;
    LIB_RUBY_PARSER_ParserResult result = parse("2 + 3", options);
    LIB_RUBY_PARSER_TokenList tokens = result.tokens;

    assert_eq(tokens.len, 4);

    assert_token(tokens.ptr[0], "tINTEGER", "2", 0, 1);
    assert_token(tokens.ptr[1], "tPLUS", "+", 2, 3);
    assert_token(tokens.ptr[2], "tINTEGER", "3", 4, 5);

    // EOF is special
    LIB_RUBY_PARSER_Token eof = tokens.ptr[3];
    LIB_RUBY_PARSER_StringPtr eof_name = lib_ruby_parser__token_name(&eof);
    assert_str_eq(eof_name, "EOF");
    assert_loc(eof.loc, 5, 5);
    LIB_RUBY_PARSER_drop_string_ptr(&eof_name);

    LIB_RUBY_PARSER_drop_parser_result(&result);
}

#define assert_diagnostic(diagnostic, e_level, e_tag, e_rendered, e_begin, e_end)       \
    {                                                                                   \
        assert_eq((diagnostic).level, e_level);                                         \
        assert_eq((diagnostic).message.tag, e_tag);                                     \
        LIB_RUBY_PARSER_StringPtr rendered;                                             \
        rendered = lib_ruby_parser__render_diagnostic_message(&((diagnostic).message)); \
        assert_str_eq(rendered, e_rendered);                                            \
        LIB_RUBY_PARSER_drop_string_ptr(&rendered);                                     \
        assert_loc((diagnostic).loc, (e_begin), (e_end));                               \
    }

void test_diagnostics()
{
    LIB_RUBY_PARSER_ParserOptions options = default_parser_options();
    LIB_RUBY_PARSER_ParserResult result = parse("self = 1; nil = 2", options);
    LIB_RUBY_PARSER_DiagnosticList diagnostics = result.diagnostics;

    assert_eq(diagnostics.len, 2);

    assert_diagnostic(
        diagnostics.ptr[0],
        LIB_RUBY_PARSER_ERROR_LEVEL_ERROR,
        LIB_RUBY_PARSER_MESSAGE_CANT_ASSIGN_TO_SELF,
        "Can't change the value of self",
        0, 4);

    assert_diagnostic(
        diagnostics.ptr[1],
        LIB_RUBY_PARSER_ERROR_LEVEL_ERROR,
        LIB_RUBY_PARSER_MESSAGE_CANT_ASSIGN_TO_NIL,
        "Can't assign to nil",
        10, 13);

    LIB_RUBY_PARSER_drop_parser_result(&result);
}

void test_comments()
{
    LIB_RUBY_PARSER_ParserOptions options = default_parser_options();
    LIB_RUBY_PARSER_ParserResult result = parse("# foo\n# bar\nbaz", options);
    LIB_RUBY_PARSER_CommentList comments = result.comments;

    assert_eq(comments.len, 2);

    assert_loc(comments.ptr[0].location, 0, 6);
    assert_loc(comments.ptr[1].location, 6, 12);

    LIB_RUBY_PARSER_drop_parser_result(&result);
}

void test_magic_comments()
{
    LIB_RUBY_PARSER_ParserOptions options = default_parser_options();
    LIB_RUBY_PARSER_ParserResult result = parse("# warn-indent: true\n# frozen-string-literal: true\n# encoding: utf-8\n", options);
    LIB_RUBY_PARSER_MagicCommentList magic_comments = result.magic_comments;

    assert_eq(magic_comments.ptr[0].kind, LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_WARN_INDENT);
    assert_loc(magic_comments.ptr[0].key_l, 2, 13);
    assert_loc(magic_comments.ptr[0].value_l, 15, 19);

    assert_eq(magic_comments.ptr[1].kind, LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_FROZEN_STRING_LITERAL);
    assert_loc(magic_comments.ptr[1].key_l, 22, 43);
    assert_loc(magic_comments.ptr[1].value_l, 45, 49);

    assert_eq(magic_comments.ptr[2].kind, LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_ENCODING);
    assert_loc(magic_comments.ptr[2].key_l, 52, 60);
    assert_loc(magic_comments.ptr[2].value_l, 62, 67);

    LIB_RUBY_PARSER_drop_parser_result(&result);
}

void test_all_nodes()
{
    FILE *f = fopen("tests/all_nodes.rb", "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *fcontent = malloc(fsize + 1);
    fread(fcontent, 1, fsize, f);
    fclose(f);
    fcontent[fsize] = 0;

    LIB_RUBY_PARSER_ParserOptions options = default_parser_options();
    LIB_RUBY_PARSER_ParserResult result = parse(fcontent, options);
    assert_not_null(result.ast);
    LIB_RUBY_PARSER_drop_parser_result(&result);

    free(fcontent);
}

const char *decoded_source = "# encoding: us-ascii\n3";
const char *decoding_error = "only US-ASCII is supported";

LIB_RUBY_PARSER_DecoderResult do_decode(LIB_RUBY_PARSER_Decoder *decoder, LIB_RUBY_PARSER_StringPtr encoding, LIB_RUBY_PARSER_ByteList input)
{
    (void)decoder;

    LIB_RUBY_PARSER_drop_byte_list(&input);

    char *encoding_ptr = (char *)encoding.ptr;

    bool is_us_ascii = (encoding.len == strlen("us-ascii")) && (strncmp(encoding_ptr, "us-ascii", strlen("us-ascii")) == 0);
    LIB_RUBY_PARSER_drop_string_ptr(&encoding);

    if (is_us_ascii)
    {
        LIB_RUBY_PARSER_ByteList decoded = new_byte_list(decoded_source);
        LIB_RUBY_PARSER_DecoderResult result = {
            .tag = LIB_RUBY_PARSER_DECODER_RESULT_OK,
            .as = {.ok = decoded}};
        return result;
    }

    LIB_RUBY_PARSER_InputError input_error = {
        .tag = LIB_RUBY_PARSER_INPUT_ERROR_DECODING_ERROR,
        .as = {.decoding_error = new_string_ptr(decoding_error)}};
    LIB_RUBY_PARSER_DecoderResult result = {
        .tag = LIB_RUBY_PARSER_DECODER_RESULT_ERR,
        .as = {.err = input_error}};
    return result;
}

void test_custom_decoder_ok()
{
    LIB_RUBY_PARSER_ParserOptions options = default_parser_options();
    options.decoder = ((LIB_RUBY_PARSER_MaybeDecoder){
        .tag = LIB_RUBY_PARSER_MAYBE_DECODER_SOME,
        .as = {.decoder = {.f = do_decode}}});
    LIB_RUBY_PARSER_ParserResult result = parse("# encoding: us-ascii\n2", options);

    LIB_RUBY_PARSER_Node *node = result.ast;
    assert_not_null(node);
    assert_eq(node->tag, LIB_RUBY_PARSER_NODE_INT);
    assert_str_eq(node->as.int_.value, "3");

    LIB_RUBY_PARSER_drop_parser_result(&result);
}

void test_custom_decoder_err()
{
    LIB_RUBY_PARSER_ParserOptions options = default_parser_options();
    options.decoder = ((LIB_RUBY_PARSER_MaybeDecoder){
        .tag = LIB_RUBY_PARSER_MAYBE_DECODER_SOME,
        .as = {.decoder = {.f = do_decode}}});
    LIB_RUBY_PARSER_ParserResult result = parse("# encoding: koi8-r\n2", options);

    assert_eq(result.ast, NULL);
    assert_eq(result.diagnostics.len, 1);
    assert_diagnostic(
        result.diagnostics.ptr[0],
        LIB_RUBY_PARSER_ERROR_LEVEL_ERROR,
        LIB_RUBY_PARSER_MESSAGE_ENCODING_ERROR,
        "encoding error: DecodingError(\"only US-ASCII is supported\")",
        12, 18);

    LIB_RUBY_PARSER_drop_parser_result(&result);
}

LIB_RUBY_PARSER_TokenRewriterResult do_rewrite(LIB_RUBY_PARSER_TokenRewriter *self, LIB_RUBY_PARSER_Token *token, LIB_RUBY_PARSER_SharedByteList input)
{
    (void)self;
    (void)input;

    LIB_RUBY_PARSER_ByteList token_bytes = token->token_value.raw;
    char *token_ptr = (char *)token_bytes.ptr;
    bool is_two = (token_bytes.len == strlen("2")) && (strncmp(token_ptr, "2", 1) == 0);

    if (is_two)
    {
        // rewrite "2" to "3"
        LIB_RUBY_PARSER_drop_byte_list(&token_bytes);
        token->token_value.raw = new_byte_list("3");
    }

    LIB_RUBY_PARSER_LexStateAction lex_state_action = {.tag = LIB_RUBY_PARSER_LEX_STATE_KEEP};
    LIB_RUBY_PARSER_TokenRewriterResult result = {
        .rewritten_token = token,
        .token_action = LIB_RUBY_PARSER_REWRITE_ACTION_KEEP,
        .lex_state_action = lex_state_action};
    return result;
}

void test_token_rewriter()
{
    LIB_RUBY_PARSER_ParserOptions options = default_parser_options();
    options.token_rewriter = ((LIB_RUBY_PARSER_MaybeTokenRewriter){
        .tag = LIB_RUBY_PARSER_MAYBE_TOKEN_REWRITER_SOME,
        .as = {.token_rewriter = {.rewrite_f = do_rewrite}}});
    LIB_RUBY_PARSER_ParserResult result = parse("1 + 2", options);

    LIB_RUBY_PARSER_TokenList tokens = result.tokens;

    assert_eq(tokens.len, 4);
    assert_token(tokens.ptr[0], "tINTEGER", "1", 0, 1);
    assert_token(tokens.ptr[1], "tPLUS", "+", 2, 3);
    assert_token(tokens.ptr[2], "tINTEGER", "3", 4, 5);

    LIB_RUBY_PARSER_drop_parser_result(&result);
}

int main()
{
    printf("Statring test suite\n");

#define test(name)                    \
    printf("Running test_%s", #name); \
    test_##name();                    \
    printf("... OK\n");

    test(parse);
    test(tokens);
    test(diagnostics);
    test(comments);
    test(magic_comments);

    test(all_nodes);

    test(custom_decoder_ok);
    test(custom_decoder_err);

    test(token_rewriter);

    printf("all tests passed.\n");
}
