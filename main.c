#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "includes/lib-ruby-parser.h"
#include <assert.h>

int main()
{
    struct ParserResult *result = parse("2 + 2", 5);
    printf("%s\n", debug_format_parser_result(result));
    parser_result_free(result);
}
