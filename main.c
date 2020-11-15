#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "includes/lib-ruby-parser.h"

int main()
{
    struct ParserResult *result = parse("2 + 2", 5);
    parser_result_free(result);
}
