#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char *path;
    size_t path_len;

    char *content;
    size_t content_len;
} FileEntry;

typedef struct
{
    FileEntry *list;
    size_t size;
    size_t capacity;
} FileList;

FileList *read_filelist(const char *path);
void list_free(FileList *filelist);

static FileList *list_alloc(size_t initial_size)
{
    FileList *filelist = malloc(sizeof(FileList));
    filelist->size = 0;
    filelist->capacity = initial_size;
    filelist->list = malloc(sizeof(FileEntry) * initial_size);
    return filelist;
}

static void list_realloc(FileList *filelist, size_t size)
{
    filelist->capacity = size;
    filelist->list = realloc(filelist->list, sizeof(FileEntry) * size);
}

void list_free(FileList *filelist)
{
    for (size_t i = 0; i < filelist->size; i++)
    {
        FileEntry entry = filelist->list[i];
        if (entry.path != NULL)
        {
            free(entry.path);
        }
        if (entry.content != NULL)
        {
            free(entry.content);
        }
    }
    free(filelist->list);
    free(filelist);
}

static void list_push(FileList *filelist, FileEntry file)
{
    if (filelist->size + 1 > filelist->capacity)
    {
        list_realloc(filelist, filelist->size * 2);
    }

    filelist->list[filelist->size] = file;
    filelist->size++;
}

static char *read_file(const char *path)
{
    FILE *f = fopen(path, "rb");
    fseek(f, 0, SEEK_END);
    size_t fsize = (size_t)ftell(f);
    fseek(f, 0, SEEK_SET);

    char *fcontent = (char *)malloc(fsize + 1);
    fread(fcontent, 1, fsize, f);
    fclose(f);
    fcontent[fsize] = 0;

    return fcontent;
}

static char *copy_string(const char *source)
{
    size_t len = strlen(source);
    char *out = (char *)malloc(len + 1);
    strcpy(out, source);
    return out;
}

static void list_push_file(FileList *filelist, const char *fpath)
{
    char *path = copy_string(fpath);
    char *content = read_file(fpath);
    FileEntry file = {
        .path = path,
        .path_len = strlen(path),

        .content = content,
        .content_len = strlen(content),
    };
    list_push(filelist, file);
}

FileList *read_filelist(const char *path)
{
    FileList *list = list_alloc(10);

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(path, "r");
    if (fp == NULL)
        return NULL;

    while ((read = getline(&line, &len, fp)) != -1)
    {
        if (line[read - 1] == '\n')
        {
            line[read - 1] = 0;
        }
        list_push_file(list, line);
    }

    fclose(fp);
    if (line)
    {
        free(line);
    }

    return list;
}
