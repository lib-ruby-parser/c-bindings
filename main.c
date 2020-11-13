#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "includes/lib-ruby-parser.h"
#include <assert.h>

int main()
{
    struct ParserResult *result = parse("2 + 2", 5);

    struct Node *node = extract_ast(result);
    // get_tokens(result);

    printf("%s\n", debug_format_parser_result(result));
    printf("%s\n", inspect_format_parser_result(result));
}
