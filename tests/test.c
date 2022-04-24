#include "../src/test_helper.h"

#include "../src/bytes.h"
#include "../src/comment.h"
#include "../src/decoded_input.h"
#include "../src/decoder.h"
#include "../src/diagnostic.h"
#include "../src/loc.h"
#include "../src/magic_comment.h"
#include "../src/messages.h"
#include "../src/nodes.h"
#include "../src/parser_options.h"
#include "../src/parser_result.h"
#include "../src/shared_byte_list.h"
#include "../src/source_line.h"
#include "../src/string.h"
#include "../src/token_rewriter.h"
#include "../src/token.h"
#include "../src/api.h"

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
