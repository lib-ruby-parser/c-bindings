#include "../test_helper.h"

#include "../bytes.h"
#include "../comment.h"
#include "../decoder.h"
#include "../diagnostic.h"
#include "../loc.h"
#include "../magic_comment.h"
#include "../nodes.h"
#include "../parser_options.h"
#include "../parser_result.h"
#include "../shared_byte_list.h"
#include "../source_line.h"
#include "../string.h"
#include "../token_rewriter.h"
#include "../token.h"

void lib_ruby_parser__test__print_build_info(void);

int main()
{
    lib_ruby_parser__test__print_build_info();
    fprintf(stderr, "C build info:\n");
    fprintf(stderr, "sizeof(size_t): %d\n", (int)(sizeof(size_t)));
    fprintf(stderr, "sizeof(void*): %d\n", (int)(sizeof(void *)));
    fprintf(stderr, "\n");

    run_test_group_bytes();
    run_test_group_comment();
    run_test_group_decoder();
    // run_test_group_diagnostic();
    run_test_group_loc();
    run_test_group_magic_comment();
    run_test_group_node();
    run_test_group_parser_options();
    // run_test_group_parser_result();
    run_test_group_shared_byte_list();
    run_test_group_source_line();
    run_test_group_string();
    run_test_group_token_rewriter();
    run_test_group_token();
    return 0;
}
