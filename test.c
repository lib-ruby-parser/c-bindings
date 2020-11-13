#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "includes/lib-ruby-parser.h"
#include <assert.h>

const char *valid_code = "2 + 2";
const char *invalid_code = "+";

struct ParserResult *parse_code(const char *code)
{
    return parse(code, strlen(code));
}

void test_parse()
{
    struct ParserResult *result;

    result = parse_code(invalid_code);
    assert(result != NULL);
    parser_result_free(result);

    result = parse_code(valid_code);
    assert(result != NULL);
    parser_result_free(result);
}

void test_extract_ast()
{
    struct ParserResult *result;
    struct Node *ast;

    result = parse_code(invalid_code);
    ast = extract_ast(result);
    parser_result_free(result);
    assert(ast == NULL);
    node_free(ast);

    result = parse_code(valid_code);
    ast = extract_ast(result);
    parser_result_free(result);
    assert(ast != NULL);
    node_free(ast);
}

void test_extract_tokens()
{
    struct ParserResult *result;
    struct Tokens *tokens;

    result = parse_code(invalid_code);
    tokens = extract_tokens(result);
    parser_result_free(result);
    assert(tokens != NULL);
    tokens_free(tokens);

    result = parse_code(valid_code);
    tokens = extract_tokens(result);
    parser_result_free(result);
    assert(tokens != NULL);
    tokens_free(tokens);
}

void test_extract_diagnostics()
{
    struct ParserResult *result;
    struct Diagnostics *diagnostics;

    result = parse_code(invalid_code);
    diagnostics = extract_diagnostics(result);
    parser_result_free(result);
    assert(diagnostics != NULL);
    diagnostics_free(diagnostics);

    result = parse_code(valid_code);
    diagnostics = extract_diagnostics(result);
    parser_result_free(result);
    assert(diagnostics != NULL);
    diagnostics_free(diagnostics);
}

void test_extract_comments()
{
    struct ParserResult *result;
    struct Comments *comments;

    result = parse_code(invalid_code);
    comments = extract_comments(result);
    parser_result_free(result);
    assert(comments != NULL);
    comments_free(comments);

    result = parse_code(valid_code);
    comments = extract_comments(result);
    parser_result_free(result);
    assert(comments != NULL);
    comments_free(comments);
}

void test_extract_magic_comments()
{
    struct ParserResult *result;
    struct MagicComments *magic_comments;

    result = parse_code(invalid_code);
    magic_comments = extract_magic_comments(result);
    parser_result_free(result);
    assert(magic_comments != NULL);
    magic_comments_free(magic_comments);

    result = parse_code(valid_code);
    magic_comments = extract_magic_comments(result);
    parser_result_free(result);
    assert(magic_comments != NULL);
    magic_comments_free(magic_comments);
}

void test_debug_format_parser_result()
{
    struct ParserResult *result;
    char *actual, *expected;

    result = parse_code(invalid_code);
    actual = debug_format_parser_result(result);
    expected =
        "ParserResult {\n"
        "    ast: None,\n"
        "    tokens: [\n"
        "        [tUPLUS, String(\"+\"), 0...1],\n"
        "        [EOF, String(\"\"), 1...1],\n"
        "    ],\n"
        "    diagnostics: [\n"
        "        Diagnostic {\n"
        "            level: error,\n"
        "            message: UnexpectedToken(\n"
        "                \"END_OF_INPUT\",\n"
        "            ),\n"
        "            range: 1...1,\n"
        "        },\n"
        "    ],\n"
        "    comments: [],\n"
        "    magic_comments: [],\n"
        "}";
    assert(strcmp(expected, actual) == 0);
    parser_result_free(result);
    free(actual);

    result = parse_code(valid_code);
    actual = debug_format_parser_result(result);
    expected = "ParserResult {\n"
               "    ast: Some(\n"
               "        Send(\n"
               "            Send {\n"
               "                recv: Some(\n"
               "                    Int(\n"
               "                        Int {\n"
               "                            value: \"2\",\n"
               "                            operator_l: None,\n"
               "                            expression_l: 0...1,\n"
               "                        },\n"
               "                    ),\n"
               "                ),\n"
               "                method_name: \"+\",\n"
               "                args: [\n"
               "                    Int(\n"
               "                        Int {\n"
               "                            value: \"2\",\n"
               "                            operator_l: None,\n"
               "                            expression_l: 4...5,\n"
               "                        },\n"
               "                    ),\n"
               "                ],\n"
               "                dot_l: None,\n"
               "                selector_l: Some(\n"
               "                    2...3,\n"
               "                ),\n"
               "                begin_l: None,\n"
               "                end_l: None,\n"
               "                operator_l: None,\n"
               "                expression_l: 0...5,\n"
               "            },\n"
               "        ),\n"
               "    ),\n"
               "    tokens: [\n"
               "        [tINTEGER, String(\"2\"), 0...1],\n"
               "        [tPLUS, String(\"+\"), 2...3],\n"
               "        [tINTEGER, String(\"2\"), 4...5],\n"
               "        [EOF, String(\"\"), 5...5],\n"
               "    ],\n"
               "    diagnostics: [],\n"
               "    comments: [],\n"
               "    magic_comments: [],\n"
               "}";
    assert(strcmp(expected, actual) == 0);
    parser_result_free(result);
    free(actual);
}

int main()
{
    test_parse();

    test_extract_ast();
    test_extract_tokens();
    test_extract_diagnostics();
    test_extract_comments();
    test_extract_magic_comments();

    test_debug_format_parser_result();
    // test_inspect_format_parser_result();
}
