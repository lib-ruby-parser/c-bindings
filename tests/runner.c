#include "test_helper.h"

#include "api_test.c"
#include "bytes_test.c"
#include "comment_test.c"
#include "decoded_input_test.c"
#include "decoder_test.c"
#include "diagnostic_test.c"
#include "loc_test.c"
#include "magic_comment_test.c"
#include "messages_test.c"
#include "nodes_test.c"
#include "parser_options_test.c"
#include "parser_result_test.c"
#include "shared_byte_list_test.c"
#include "source_line_test.c"
#include "string_test.c"
#include "token_rewriter_test.c"
#include "token_test.c"

void lib_ruby_parser__test__print_build_info(void);

void run_tests_as_group(const char *group_name, const test_fn_t *tests, size_t count)
{
    fprintf(stderr, "Running group \"%s\"", group_name);
    fprintf(stderr, " with %lu tests:\n", count);
    for (size_t i = 0; i < count; i++)
    {
        test_fn_t test_fn = tests[i];
        fprintf(stderr, "  - ");
        test_fn();
        fprintf(stderr, "\n");
    }
}

int main(void)
{
    lib_ruby_parser__test__print_build_info();
    fprintf(stderr, "C build info:\n");
    fprintf(stderr, "sizeof(size_t): %d\n", (int)(sizeof(size_t)));
    fprintf(stderr, "sizeof(void*): %d\n", (int)(sizeof(void *)));
    fprintf(stderr, "\n");

    run_test_group_bytes();
    run_test_group_comment();
    run_test_group_decoded_input();
    run_test_group_decoder();
    run_test_group_diagnostic();
    run_test_group_loc();
    run_test_group_magic_comment();
    run_test_group_message();
    run_test_group_node();
    run_test_group_parser_options();
    run_test_group_parser_result();
    run_test_group_shared_byte_list();
    run_test_group_source_line();
    run_test_group_string();
    run_test_group_token_rewriter();
    run_test_group_token();
    run_test_group_api();

    printf("All tests are passing!\n");

    return 0;
}
