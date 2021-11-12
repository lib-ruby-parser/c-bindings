#include "../test_helper.h"

int main()
{
    run_test_group(bytes);
    run_test_group(comment);
    // run_test_group(decoder);
    // run_test_group(diagnostic);
    run_test_group(loc);
    // run_test_group(magic_comment);
    // run_test_group(parser_options);
    // run_test_group(parser_result);
    run_test_group(shared_byte_list);
    run_test_group(source_line);
    run_test_group(string);
    // run_test_group(token_rewriter);
    run_test_group(token);
    return 0;
}
