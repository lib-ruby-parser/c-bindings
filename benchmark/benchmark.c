#include <stdio.h>
#include "../api.h"
#include "rb_filelist.h"
#include "measure.h"

int main()
{
    char *filelist_path = getenv("FILELIST_PATH");
    if (filelist_path == NULL)
    {
        printf("\nNo FILELIST_PATH provided.\n\nUsage: FILELIST_PATH=path/to/filelist ./path/to/exe\n");
        return 1;
    }
    FileList *filelist = read_filelist(filelist_path);

    // printf("total files: %lu\n", filelist->size);

    long start = now_in_millis();
    for (size_t i = 0; i < filelist->size; i++)
    {
        FileEntry *entry = &(filelist->list[i]);

        LIB_RUBY_PARSER_ByteList input = {.ptr = entry->content, .len = entry->content_len, .capacity = entry->content_len};
        LIB_RUBY_PARSER_ParserOptions options = {
            .buffer_name = {.ptr = entry->path, .len = entry->path_len},
            .debug = false,
            .decoder = {.tag = LIB_RUBY_PARSER_MAYBE_DECODER_NONE, .as = {.nothing = {.dummy = 42}}},
            .record_tokens = false,
            .token_rewriter = {.tag = LIB_RUBY_PARSER_MAYBE_TOKEN_REWRITER_NONE, .as = {.nothing = {.dummy = 42}}}};

        entry->content = NULL;
        entry->path = NULL;

        LIB_RUBY_PARSER_ParserResult result = lib_ruby_parser__parse(options, input);
        LIB_RUBY_PARSER_drop_parser_result(&result);
    }
    long end = now_in_millis();
    double delta = (double)(end - start) / 1000;

    printf("%f\n", delta);

    list_free(filelist);
    return 0;
}
