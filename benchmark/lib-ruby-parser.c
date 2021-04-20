#include <time.h>
#include "benchmark/rb_filelist.h"
#include "src/lib-ruby-parser.h"

int main()
{
    char *input_dir = getenv("INPUT_DIR");
    if (input_dir == NULL)
    {
        printf("\nNo INPUT_DIR provided.\n\nUsage: INPUT_DIR=path/to/dir make benchmark\n");
        return 1;
    }
    FileList *filelist = get_rb_files_under(input_dir);

    clock_t start = clock();
    for (size_t i = 0; i < filelist->size; i++)
    {
        LIB_RUBY_PARSER_ParserOptions options = lib_ruby_parser_default_parser_options();
        options.buffer_name = lib_ruby_parser_make_string_ptr(filelist->list[i].path);
        LIB_RUBY_PARSER_ByteList input = lib_ruby_parser_make_byte_list(filelist->list[i].content);
        lib_ruby_parser_parse(input, options);
    }
    clock_t end = clock();

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f (files: %lu)\n", cpu_time_used, filelist->size);

    list_free(filelist);

    return 0;
}
