#include <stdio.h>
#include "api.h"
#include "utils/rb_filelist.h"
#include "utils/measure.h"

int main()
{
    char *input_dir = getenv("INPUT_DIR");
    if (input_dir == NULL)
    {
        printf("\nNo INPUT_DIR provided.\n\nUsage: INPUT_DIR=path/to/dir make benchmark\n");
        return 1;
    }
    FileList *filelist = get_rb_files_under(input_dir);
    printf("total files: %lu\n", filelist->size);

    long start = now_in_millis();
    for (size_t i = 0; i < filelist->size; i++)
    {
        FileEntry entry = filelist->list[i];

        LIB_RUBY_PARSER_ByteList input = {.ptr = entry.content, .len = entry.content_len, .capacity = entry.content_len};
        LIB_RUBY_PARSER_ParserOptions options = {
            .buffer_name = {.ptr = entry.path, .len = entry.path_len},
            .debug = false,
            .decoder = {.tag = LIB_RUBY_PARSER_MAYBE_DECODER_NONE, .as = {.nothing = {.dummy = 42}}},
            .record_tokens = false,
            .token_rewriter = {.tag = LIB_RUBY_PARSER_MAYBE_TOKEN_REWRITER_NONE, .as = {.nothing = {.dummy = 42}}}};

        (&(filelist->list[i]))->content = NULL;
        (&(filelist->list[i]))->path = NULL;

        LIB_RUBY_PARSER_ParserResult result = lib_ruby_parser__parse(options, input);
        LIB_RUBY_PARSER_drop_parser_result(&result);
    }
    long end = now_in_millis();

    printf("Time taken: %lu\n", end - start);

    list_free(filelist);
    return 0;
}
