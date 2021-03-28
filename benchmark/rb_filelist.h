#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char *path;
    char *content;
} FileEntry;

typedef struct
{
    FileEntry *list;
    size_t size;
    size_t capacity;
} FileList;

FileList *list_alloc(size_t initial_size)
{
    FileList *filelist = malloc(sizeof(FileList));
    filelist->size = 0;
    filelist->capacity = initial_size;
    filelist->list = malloc(sizeof(FileEntry) * initial_size);
    return filelist;
}

void list_realloc(FileList *filelist, size_t size)
{
    filelist->capacity = size;
    filelist->list = realloc(filelist->list, sizeof(FileEntry) * size);
}

void list_free(FileList *filelist)
{
    for (size_t i = 0; i < filelist->size; i++)
    {
        free(filelist->list[i].path);
        free(filelist->list[i].content);
    }
    free(filelist->list);
    free(filelist);
}

void list_push(FileList *filelist, FileEntry file)
{
    if (filelist->size + 1 > filelist->capacity)
    {
        list_realloc(filelist, filelist->size * 2);
    }

    filelist->list[filelist->size] = file;
    filelist->size++;
}

char *read_file(const char *path)
{
    FILE *f = fopen(path, "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *fcontent = malloc(fsize + 1);
    fread(fcontent, 1, fsize, f);
    fclose(f);
    fcontent[fsize] = 0;

    return fcontent;
}

char *copy_string(const char *source)
{
    uint32_t len = strlen(source);
    char *out = (char *)malloc(len + 1);
    strcpy(out, source);
    return out;
}

void list_push_file(FileList *filelist, const char *fpath)
{
    char *path = copy_string(fpath);
    char *content = read_file(fpath);
    FileEntry file = {.path = path, .content = content};
    list_push(filelist, file);
}

bool is_rb_file(const char *path)
{
    return strlen(path) > 3 && !strcmp(path + strlen(path) - 3, ".rb");
}

FileList *current_filelist;

int nftw_handler(const char *fpath, const struct stat *sb,
                 int typeflag, struct FTW *ftwbuf)
{
    if (typeflag == FTW_F && is_rb_file(fpath))
    {
        list_push_file(current_filelist, fpath);
    }

    return 0;
}

FileList *get_rb_files_under(char *dir)
{
    current_filelist = list_alloc(10);

    nftw(dir, nftw_handler, 1, 0);

    FileList *result = current_filelist;
    current_filelist = NULL;
    return result;
}
