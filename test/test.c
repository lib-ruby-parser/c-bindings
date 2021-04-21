#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "../src/lib-ruby-parser.h"

LIB_RUBY_PARSER_ParserResult parse_code(LIB_RUBY_PARSER_ParserOptions options, const char *code)
{
    LIB_RUBY_PARSER_ByteList input = lib_ruby_parser_make_byte_list(code);
    return lib_ruby_parser_parse(input, options);
}

#define assert_not_null(obj) \
    assert((obj) != NULL)

#define assert_eq(actual, expected) \
    assert((actual) == (expected))

#define assert_no_loc(loc) \
    assert_eq((loc).tag, MAYBE_LOC_NONE);

#define assert_some_loc(loc) \
    assert_eq((loc).tag, MAYBE_LOC_SOME);

#define assert_loc(loc, expected_begin, expected_end) \
    assert_eq((loc).begin, (expected_begin));         \
    assert_eq((loc).end, (expected_end));

#define assert_maybe_loc(loc, expected_begin, expected_end) \
    assert_some_loc(loc);                                   \
    assert_loc((loc).some, (expected_begin), (expected_end));

#define assert_str_eq(actual, expected, len) \
    assert_not_null(actual);                 \
    assert(strncmp(actual, expected, len) == 0);

char *copy_string(const char *source)
{
    uint32_t len = strlen(source);
    char *out = (char *)malloc(len + 1);
    strcpy(out, source);
    return out;
}

void test_parse()
{
    LIB_RUBY_PARSER_ParserOptions options = lib_ruby_parser_default_parser_options();
    LIB_RUBY_PARSER_ParserResult result = parse_code(options, "foo(100, 'baz')");

    LIB_RUBY_PARSER_Node *node;
    LIB_RUBY_PARSER_ByteList byte_list;

    assert_not_null(result.ast);
    node = result.ast;
    assert_eq(node->tag, NODE_SEND);

    LIB_RUBY_PARSER_Send send = node->send;
    assert_eq(send.recv, NULL);
    byte_list = lib_ruby_parser_byte_list_from_string_ptr(send.method_name);
    assert_str_eq((char *)(byte_list.ptr), "foo", 3);
    lib_ruby_parser_free_byte_list(byte_list);

    LIB_RUBY_PARSER_NodeList args = send.args;
    assert_eq(args.len, 2);

    LIB_RUBY_PARSER_Node arg1 = args.ptr[0];
    assert_eq(arg1.tag, NODE_INT);
    LIB_RUBY_PARSER_Int int_ = arg1.int_;
    byte_list = lib_ruby_parser_byte_list_from_string_ptr(int_.value);
    assert_str_eq((char *)byte_list.ptr, "100", 3);
    lib_ruby_parser_free_byte_list(byte_list);
    assert_loc(int_.expression_l, 4, 7);
    assert_no_loc(int_.operator_l);

    LIB_RUBY_PARSER_Node arg2 = args.ptr[1];
    assert_eq(arg2.tag, NODE_STR);

    LIB_RUBY_PARSER_Str str = arg2.str;
    byte_list = lib_ruby_parser_byte_list_from_string_value(str.value);
    assert_str_eq((char *)byte_list.ptr, "baz", 3);
    lib_ruby_parser_free_byte_list(byte_list);
    assert_maybe_loc(str.begin_l, 9, 10);
    assert_maybe_loc(str.end_l, 13, 14);
    assert_loc(str.expression_l, 9, 14);

    assert_no_loc(send.dot_l);
    assert_maybe_loc(send.selector_l, 0, 3);
    assert_maybe_loc(send.begin_l, 3, 4);
    assert_maybe_loc(send.end_l, 14, 15);
    assert_no_loc(send.operator_l);
    assert_loc(send.expression_l, 0, 15);

    lib_ruby_parser_free_parser_result(result);
}

#define assert_token(tok, expected_tok_name, expected_tok_value, expected_begin, expected_end)          \
    {                                                                                                   \
        char *tok_name = lib_ruby_parser_token_name(tok.token_type);                                    \
        assert_eq(strlen(tok_name), strlen(expected_tok_name));                                         \
        assert_str_eq(tok_name, expected_tok_name, strlen(tok_name));                                   \
        free(tok_name);                                                                                 \
        assert_eq(tok.token_value.raw.len, strlen(expected_tok_value));                                 \
        assert_str_eq((char *)tok.token_value.raw.ptr, expected_tok_value, strlen(expected_tok_value)); \
        assert_loc(tok.loc, expected_begin, expected_end);                                              \
    }

void test_tokens()
{
    LIB_RUBY_PARSER_ParserOptions options = lib_ruby_parser_default_parser_options();
    options.record_tokens = true;
    LIB_RUBY_PARSER_ParserResult result = parse_code(options, "2 + 3");
    LIB_RUBY_PARSER_TokenList tokens = result.tokens;

    assert_eq(tokens.len, 4);

    assert_token(tokens.ptr[0], "tINTEGER", "2", 0, 1);
    assert_token(tokens.ptr[1], "tPLUS", "+", 2, 3);
    assert_token(tokens.ptr[2], "tINTEGER", "3", 4, 5);
    assert_token(tokens.ptr[3], "EOF", "", 5, 5);

    lib_ruby_parser_free_parser_result(result);
}

#define assert_diagnostic(diagnostic, expected_level, expected_message, expected_begin, expected_end) \
    {                                                                                                 \
        assert_eq(diagnostic.level, expected_level);                                                  \
        char *message = lib_ruby_parser_diagnostic_render_message(diagnostic);                        \
        assert_eq(strlen(message), strlen(expected_message));                                         \
        assert_str_eq(message, expected_message, strlen(expected_message));                           \
        free(message);                                                                                \
        assert_loc(diagnostic.loc, (expected_begin), (expected_end));                                 \
    }

void test_diagnostics()
{
    LIB_RUBY_PARSER_ParserOptions options = lib_ruby_parser_default_parser_options();
    LIB_RUBY_PARSER_ParserResult result = parse_code(options, "self = 1; nil = 2");
    LIB_RUBY_PARSER_DiagnosticList diagnostics = result.diagnostics;

    assert_eq(diagnostics.len, 2);

    assert_diagnostic(diagnostics.ptr[0], ERROR_LEVEL_ERROR, "Can't change the value of self", 0, 4);
    assert_diagnostic(diagnostics.ptr[1], ERROR_LEVEL_ERROR, "Can't assign to nil", 10, 13);

    lib_ruby_parser_free_parser_result(result);
}

void test_comments()
{
    LIB_RUBY_PARSER_ParserOptions options = lib_ruby_parser_default_parser_options();
    LIB_RUBY_PARSER_ParserResult result = parse_code(options, "# foo\n# bar\nbaz");
    LIB_RUBY_PARSER_CommentList comments = result.comments;

    assert_eq(comments.len, 2);

    assert_loc(comments.ptr[0].location, 0, 6);
    assert_loc(comments.ptr[1].location, 6, 12);

    lib_ruby_parser_free_parser_result(result);
}

void test_magic_comments()
{
    LIB_RUBY_PARSER_ParserOptions options = lib_ruby_parser_default_parser_options();
    LIB_RUBY_PARSER_ParserResult result = parse_code(options, "# warn-indent: true\n# frozen-string-literal: true\n# encoding: utf-8\n");
    LIB_RUBY_PARSER_MagicCommentList magic_comments = result.magic_comments;

    assert_eq(magic_comments.ptr[0].kind, MAGIC_COMMENT_KIND_WARN_INDENT);
    assert_loc(magic_comments.ptr[0].key_l, 2, 13);
    assert_loc(magic_comments.ptr[0].value_l, 15, 19);

    assert_eq(magic_comments.ptr[1].kind, MAGIC_COMMENT_KIND_FROZEN_STRING_LITERAL);
    assert_loc(magic_comments.ptr[1].key_l, 22, 43);
    assert_loc(magic_comments.ptr[1].value_l, 45, 49);

    assert_eq(magic_comments.ptr[2].kind, MAGIC_COMMENT_KIND_ENCODING);
    assert_loc(magic_comments.ptr[2].key_l, 52, 60);
    assert_loc(magic_comments.ptr[2].value_l, 62, 67);

    lib_ruby_parser_free_parser_result(result);
}

void test_loc()
{
    LIB_RUBY_PARSER_ParserOptions options = lib_ruby_parser_default_parser_options();
    LIB_RUBY_PARSER_ParserResult result = parse_code(options, "2 + 2");
    LIB_RUBY_PARSER_Loc expression_l = result.ast->send.expression_l;

    assert_eq(lib_ruby_parser_loc_size(expression_l), 5);
    char *source = lib_ruby_parser_loc_source(expression_l, result.input);
    assert_str_eq(source, "2 + 2", 5);
    free(source);

    LIB_RUBY_PARSER_Loc invalid = {.begin = 0, .end = 10000};
    assert_eq(lib_ruby_parser_loc_source(invalid, result.input), NULL);

    lib_ruby_parser_free_parser_result(result);
}

void test_all_nodes()
{
    FILE *f = fopen("all_nodes.rb", "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *fcontent = malloc(fsize + 1);
    fread(fcontent, 1, fsize, f);
    fclose(f);
    fcontent[fsize] = 0;

    LIB_RUBY_PARSER_ParserOptions options = lib_ruby_parser_default_parser_options();
    LIB_RUBY_PARSER_ParserResult result = parse_code(options, fcontent);
    assert_not_null(result.ast);
    lib_ruby_parser_free_parser_result(result);

    free(fcontent);
}

char *decoded_source = "# encoding: us-ascii\n3";
const char *decoding_error = "only US-ASCII is supported";

LIB_RUBY_PARSER_CustomDecoderResult do_decode(LIB_RUBY_PARSER_StringPtr encoding, LIB_RUBY_PARSER_ByteList input, void *state)
{
    (void)state;

    lib_ruby_parser_free_byte_list(input);

    char *encoding_ptr = (char *)encoding.ptr;

    bool is_us_ascii = (encoding.len == strlen("us-ascii")) && (strncmp(encoding_ptr, "us-ascii", strlen("us-ascii")) == 0);
    lib_ruby_parser_free_string_ptr(encoding);

    if (is_us_ascii)
    {
        LIB_RUBY_PARSER_ByteList decoded = lib_ruby_parser_make_byte_list(decoded_source);
        LIB_RUBY_PARSER_CustomDecoderResult result = {
            .tag = CUSTOM_DECODER_RESULT_OK,
            .ok = decoded};
        return result;
    }

    LIB_RUBY_PARSER_InputError input_error = {
        .tag = INPUT_ERROR_DECODING_ERROR,
        .decoding_error = lib_ruby_parser_make_string_ptr(decoding_error)};
    LIB_RUBY_PARSER_CustomDecoderResult result = {
        .tag = CUSTOM_DECODER_RESULT_ERR,
        .err = input_error};
    return result;
}

void test_custom_decoder_ok()
{
    LIB_RUBY_PARSER_ParserOptions options = lib_ruby_parser_default_parser_options();
    lib_ruby_parser_free_string_ptr(options.buffer_name);
    options.buffer_name = lib_ruby_parser_make_string_ptr("(test_custom_decoder_ok)");
    options.debug = LIB_RUBY_PARSER_NONE;
    LIB_RUBY_PARSER_ForeignCustomDecoder decoder = {
        .dummy = false,
        .f = do_decode,
        .state = NULL};
    options.decoder = decoder;
    LIB_RUBY_PARSER_ParserResult result = parse_code(options, "# encoding: us-ascii\n2");

    assert_not_null(result.ast);
    LIB_RUBY_PARSER_MaybeNodePtr node = result.ast;
    assert_eq(node->tag, NODE_INT);

    LIB_RUBY_PARSER_ByteList int_value = lib_ruby_parser_byte_list_from_string_ptr(node->int_.value);
    assert_str_eq((char *)(int_value.ptr), "3", 1);
    lib_ruby_parser_free_byte_list(int_value);

    lib_ruby_parser_free_parser_result(result);
}

void test_custom_decoder_err()
{
    LIB_RUBY_PARSER_ParserOptions options = lib_ruby_parser_default_parser_options();
    lib_ruby_parser_free_string_ptr(options.buffer_name);
    options.buffer_name = lib_ruby_parser_make_string_ptr("(test_custom_decoder_err)");
    options.debug = LIB_RUBY_PARSER_NONE;
    LIB_RUBY_PARSER_ForeignCustomDecoder decoder = {
        .dummy = false,
        .f = do_decode,
        .state = NULL};
    options.decoder = decoder;
    LIB_RUBY_PARSER_ParserResult result = parse_code(options, "# encoding: koi8-r\n2");

    assert_eq(result.ast, NULL);
    assert_eq(result.diagnostics.len, 1);
    assert_diagnostic(result.diagnostics.ptr[0], ERROR_LEVEL_ERROR, "encoding error: DecodingError(\"only US-ASCII is supported\")", 12, 18);

    lib_ruby_parser_free_parser_result(result);
}

LIB_RUBY_PARSER_TokenRewriterResult rewrite_token(LIB_RUBY_PARSER_TokenPtr token, LIB_RUBY_PARSER_SharedByteList input, void *state)
{
    (void)input;
    (void)state;

    LIB_RUBY_PARSER_ByteList token_bytes = token.ptr->token_value.raw;
    char *token_ptr = (char *)token_bytes.ptr;
    bool is_two = (token_bytes.len == strlen("2")) && (strncmp(token_ptr, "2", 1) == 0);

    if (is_two)
    {
        // rewrite "2" to "3"
        lib_ruby_parser_free_byte_list(token_bytes);
        token.ptr->token_value.raw = lib_ruby_parser_make_byte_list("3");
    }

    LIB_RUBY_PARSER_LexStateAction lex_state_action = {.tag = LEX_STATE_ACTION_KEEP};
    LIB_RUBY_PARSER_TokenRewriterResult result = {
        .rewritten_token = token,
        .token_action = REWRITE_ACTION_KEEP,
        .lex_state_action = lex_state_action};
    return result;
}

void test_token_rewriter()
{
    LIB_RUBY_PARSER_ForeignTokenRewriter token_rewriter = {
        .f = rewrite_token,
        .dummy = false,
        .state = NULL};
    LIB_RUBY_PARSER_ParserOptions options = lib_ruby_parser_default_parser_options();
    lib_ruby_parser_free_string_ptr(options.buffer_name);
    options.buffer_name = lib_ruby_parser_make_string_ptr("(test_token_rewriter)");
    options.debug = LIB_RUBY_PARSER_NONE;
    options.token_rewriter = token_rewriter;
    options.record_tokens = true;
    LIB_RUBY_PARSER_ParserResult result = parse_code(options, "1 + 2");

    LIB_RUBY_PARSER_TokenList tokens = result.tokens;

    assert_eq(tokens.len, 4);

    assert_token(tokens.ptr[0], "tINTEGER", "1", 0, 1);
    assert_token(tokens.ptr[1], "tPLUS", "+", 2, 3);
    assert_token(tokens.ptr[2], "tINTEGER", "3", 4, 5);
    assert_token(tokens.ptr[3], "EOF", "", 5, 5);

    lib_ruby_parser_free_parser_result(result);
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

    test(loc);

    test(all_nodes);

    test(custom_decoder_ok);
    test(custom_decoder_err);

    test(token_rewriter);

    printf("all tests passed.\n");
}
