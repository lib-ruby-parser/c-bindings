#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "includes/lib-ruby-parser.h"
#include <assert.h>

const char *invalid_code = "+";

struct ParserResult *parse_code(const char *code)
{
    return parse(code, strlen(code));
}

#define assert_not_null(obj) \
    (assert((obj) != NULL), (obj))

#define assert_eq(actual, expected) \
    assert((actual) == (expected))

#define assert_range(range, begin, end)     \
    assert_not_null(range);                 \
    assert_eq((range)->begin_pos, (begin)); \
    assert_eq((range)->end_pos, (end));

#define assert_str_eq(actual, expected) \
    assert_not_null(actual);            \
    assert(strcmp(actual, expected) == 0);

struct Node *WatchNode = NULL;

void test_parse()
{
    struct ParserResult *result = parse_code("foo(100, 'baz')");
    assert_not_null(result);

    struct Node *node;

    node = assert_not_null(result->ast);
    assert_eq(node->node_type, NODE_SEND);

    struct Send *send = assert_not_null(node->inner->_send);

    assert_eq(send->recv, NULL);

    char *mid = send->method_name;
    assert_str_eq(mid, "foo");

    struct NodeList *args = send->args;
    assert_eq(args->len, 2);

    struct Node arg1 = args->list[0];
    assert_eq(arg1.node_type, NODE_INT);
    struct Int *_int = assert_not_null(arg1.inner->_int);
    assert_str_eq(_int->value, "100");
    assert_range(_int->expression_l, 4, 7);
    assert_eq(_int->operator_l, NULL);

    struct Node arg2 = args->list[1];
    assert_eq(arg2.node_type, NODE_STR_);
    struct Str *str = assert_not_null(arg2.inner->_str_);
    assert_str_eq(str->value, "baz");
    assert_range(str->begin_l, 9, 10);
    assert_range(str->end_l, 13, 14);
    assert_range(str->expression_l, 9, 14);

    assert_eq(send->dot_l, NULL);
    assert_range(send->selector_l, 0, 3);
    assert_range(send->begin_l, 3, 4);
    assert_range(send->end_l, 14, 15);
    assert_eq(send->operator_l, NULL);
    assert_range(send->expression_l, 0, 15);

    parser_result_free(result);
}

void test_debug_format()
{
    struct ParserResult *result = parse_code("2 + 2");
    char *actual = debug_fmt_ast(result->ast);
    char *expected = "Send {\n"
                     "    recv: Int {\n"
                     "        value: \"2\",\n"
                     "        operator_l: None,\n"
                     "        expression_l: Range {\n"
                     "            begin_pos: 0,\n"
                     "            end_pos: 1,\n"
                     "        },\n"
                     "    },\n"
                     "    method_name: \"+\",\n"
                     "    args: [\n"
                     "        Int {\n"
                     "            value: \"2\",\n"
                     "            operator_l: None,\n"
                     "            expression_l: Range {\n"
                     "                begin_pos: 4,\n"
                     "                end_pos: 5,\n"
                     "            },\n"
                     "        },\n"
                     "    ],\n"
                     "    dot_l: None,\n"
                     "    selector_l: Range {\n"
                     "        begin_pos: 2,\n"
                     "        end_pos: 3,\n"
                     "    },\n"
                     "    begin_l: None,\n"
                     "    end_l: None,\n"
                     "    operator_l: None,\n"
                     "    expression_l: Range {\n"
                     "        begin_pos: 0,\n"
                     "        end_pos: 5,\n"
                     "    },\n"
                     "}";

    assert_str_eq(actual, expected);

    parser_result_free(result);
    free(actual);
}

#define assert_token(tok, expected_tok_name, expected_tok_value, expected_begin, expected_end) \
    tok_name = token_name(tok.token_type);                                                     \
    assert_str_eq(tok_name, expected_tok_name);                                                \
    free(tok_name);                                                                            \
    assert_str_eq(tok.token_value, expected_tok_value);                                        \
    assert_not_null(tok.loc);                                                                  \
    assert_eq(tok.loc->begin, expected_begin);                                                 \
    assert_eq(tok.loc->end, expected_end);

void test_tokens()
{
    struct ParserResult *result = parse_code("2 + 3");
    struct Tokens *tokens = result->tokens;

    assert_eq(tokens->len, 4);
    struct Token tok;
    char *tok_name;

    assert_token(tokens->list[0], "tINTEGER", "2", 0, 1);
    assert_token(tokens->list[1], "tPLUS", "+", 2, 3);
    assert_token(tokens->list[2], "tINTEGER", "3", 4, 5);
    assert_token(tokens->list[3], "EOF", "", 5, 5);

    parser_result_free(result);
}

#define assert_diagnostic(diagnostic, expected_level, expected_message, expected_begin, expected_end) \
    assert_eq(diagnostic.level, expected_level);                                                      \
    assert_str_eq(diagnostic.message, expected_message);                                              \
    assert_eq(diagnostic.range.begin_pos, expected_begin);                                            \
    assert_eq(diagnostic.range.end_pos, expected_end);

void test_diagnostics()
{
    struct ParserResult *result = parse_code("self = 1; nil = 2");
    struct Diagnostics *diagnostics = result->diagnostics;

    assert_eq(diagnostics->len, 2);

    assert_diagnostic(diagnostics->list[0], ERROR, "Can't change the value of self", 0, 4);
    assert_diagnostic(diagnostics->list[1], ERROR, "Can't assign to nil", 10, 13);

    parser_result_free(result);
}

void test_comments()
{
    struct ParserResult *result = parse_code("# foo\n# bar\nbaz");
    struct Comments *comments = result->comments;

    assert_eq(comments->len, 2);

    assert_range(&comments->list[0].location, 0, 6);
    assert_range(&comments->list[1].location, 6, 12);

    parser_result_free(result);
}

void test_magic_comments()
{
    struct ParserResult *result = parse_code("# warn-indent: true\n# frozen-string-literal: true\n# encoding: utf-8\n");
    struct MagicComments *magic_comments = result->magic_comments;

    assert_eq(magic_comments->list[0].kind, WARN_INDENT);
    assert_range(&magic_comments->list[0].key_l, 2, 13);
    assert_range(&magic_comments->list[0].value_l, 15, 19);

    assert_eq(magic_comments->list[1].kind, FROZEN_STRING_LITERAL);
    assert_range(&magic_comments->list[1].key_l, 22, 43);
    assert_range(&magic_comments->list[1].value_l, 45, 49);

    assert_eq(magic_comments->list[2].kind, ENCODING);
    assert_range(&magic_comments->list[2].key_l, 52, 60);
    assert_range(&magic_comments->list[2].value_l, 62, 67);

    parser_result_free(result);
}

void test_range()
{
    struct ParserResult *result = parse_code("2 + 2");
    struct Range *expression_l = result->ast->inner->_send->expression_l;

    assert_eq(range_size(expression_l), 5);
    char *source = range_source(expression_l, result->input);
    assert_str_eq(source, "2 + 2");

    free(source);
    parser_result_free(result);
}

int main()
{
    test_parse();
    test_debug_format();
    test_tokens();
    test_diagnostics();
    test_comments();
    test_magic_comments();

    test_range();

    printf("all tests passed.\n");
}
