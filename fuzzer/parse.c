#include "../target/lib-ruby-parser.h"

int LLVMFuzzerTestOneInput(const char *Data, size_t Size)
{
    ParserResult *result = parse(NULL, Data, Size);
    parser_result_free(result);
    return 0;
}
