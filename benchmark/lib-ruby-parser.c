#include <time.h>
#include "benchmark/rb_filelist.h"
#include "target/lib-ruby-parser.h"

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
        ParserOptions options = {.buffer_name = filelist->list[i].path};
        parse(&options, filelist->list[i].content);
    }
    clock_t end = clock();

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f (files: %lu)\n", cpu_time_used, filelist->size);

    list_free(filelist);

    return 0;
}
