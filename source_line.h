#ifndef LIB_RUBY_PARSER_SOURCE_LINE_H
#define LIB_RUBY_PARSER_SOURCE_LINE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct LIB_RUBY_PARSER_SourceLine
{
    size_t start;
    size_t end;
    bool ends_with_eof;
} LIB_RUBY_PARSER_SourceLine;

typedef struct LIB_RUBY_PARSER_SourceLineList
{
    LIB_RUBY_PARSER_SourceLine *ptr;
    size_t len;
    size_t capacity;
} LIB_RUBY_PARSER_SourceLineList;
void LIB_RUBY_PARSER_drop_source_line_list(LIB_RUBY_PARSER_SourceLineList *source_line_list);

#endif // LIB_RUBY_PARSER_SOURCE_LINE_H
