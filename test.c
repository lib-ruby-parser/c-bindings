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

#define assert_range(range, begin, end)    \
    assert_not_null(range);                \
    assert((range)->begin_pos == (begin)); \
    assert((range)->end_pos == (end));

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
    assert(node->node_type == NODE_SEND);

    struct Send *send = assert_not_null(node->inner->_send);

    assert(send->recv == NULL);

    char *mid = send->method_name;
    assert_str_eq(mid, "foo");

    struct NodeList *args = send->args;
    assert(args->len == 2);

    struct Node arg1 = args->list[0];
    assert(arg1.node_type == NODE_INT);
    struct Int *_int = assert_not_null(arg1.inner->_int);
    assert_str_eq(_int->value, "100");
    assert_range(_int->expression_l, 4, 7);
    assert(_int->operator_l == NULL);

    struct Node arg2 = args->list[1];
    assert(arg2.node_type == NODE_STR_);
    struct Str *str = assert_not_null(arg2.inner->_str_);
    assert_str_eq(str->value, "baz");
    assert_range(str->begin_l, 9, 10);
    assert_range(str->end_l, 13, 14);
    assert_range(str->expression_l, 9, 14);

    assert(send->dot_l == NULL);
    assert_range(send->selector_l, 0, 3);
    assert_range(send->begin_l, 3, 4);
    assert_range(send->end_l, 14, 15);
    assert(send->operator_l == NULL);
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

    printf("%s\n", actual);

    parser_result_free(result);
    free(actual);
}

int main()
{
    test_parse();
    test_debug_format();

    printf("all tests passed.\n");
}
