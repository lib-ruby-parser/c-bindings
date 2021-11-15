#include "../test_helper.h"

void lib_ruby_parser__test__print_build_info();

int main()
{
    lib_ruby_parser__test__print_build_info();
    printf("C build info:\n");
    printf("sizeof(size_t): %d\n", (int)(sizeof(size_t)));
    printf("sizeof(void*): %d\n", (int)(sizeof(void *)));
    printf("\n");

    // run_test_group(bytes);
    // run_test_group(comment);
    // // run_test_group(decoder);
    // // run_test_group(diagnostic);
    // run_test_group(loc);
    // run_test_group(magic_comment);
    // // run_test_group(parser_options);
    // // run_test_group(parser_result);
    // run_test_group(shared_byte_list);
    // run_test_group(source_line);
    // run_test_group(string);
    // // run_test_group(token_rewriter);
    // run_test_group(token);
    return 0;
}
