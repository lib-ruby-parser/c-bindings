#include <stdio.h>
#include "../lib-ruby-parser.h"
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

        LIB_RUBY_PARSER_ByteList input = LIB_RUBY_PARSER_new_bytes_owned(entry->content, entry->content_len);
        LIB_RUBY_PARSER_ParserOptions options = {
            .buffer_name = LIB_RUBY_PARSER_new_string_owned(entry->path, entry->path_len),
            .decoder = {.decoder = {.f = NULL}},
            .record_tokens = false,
            .token_rewriter = {.token_rewriter = {.f = NULL}}};

        entry->content = NULL;
        entry->path = NULL;

        LIB_RUBY_PARSER_ParserResult result = LIB_RUBY_PARSER_parse(options, input);
        LIB_RUBY_PARSER_drop_parser_result(&result);
    }
    long end = now_in_millis();
    double delta = (double)(end - start) / 1000;

    printf("%f\n", delta);

    list_free(filelist);
    return 0;
}
