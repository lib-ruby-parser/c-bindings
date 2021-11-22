#ifndef LIB_RUBY_PARSER_SOURCE_LINE_H
#define LIB_RUBY_PARSER_SOURCE_LINE_H

#include <stddef.h>
#include <stdbool.h>

/*
    `SourceLine` struct from `lib-ruby-parser`
*/
typedef struct LIB_RUBY_PARSER_SourceLine
{
    size_t start;
    size_t end;
    bool ends_with_eof;
} LIB_RUBY_PARSER_SourceLine;

/*
    Equivalent of `Vec<SourceLine>`
*/
typedef struct LIB_RUBY_PARSER_SourceLineList
{
    LIB_RUBY_PARSER_SourceLine *ptr;
    size_t len;
    size_t capacity;
} LIB_RUBY_PARSER_SourceLineList;
/*
    LIB_RUBY_PARSER_SourceLineList destructor.
    Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
    i.e. it doesn't call `free` on a given pointer.
*/
void LIB_RUBY_PARSER_drop_source_line_list(LIB_RUBY_PARSER_SourceLineList *source_line_list);

#ifdef TEST_ENV
void run_test_group_source_line(void);
#endif

#endif // LIB_RUBY_PARSER_SOURCE_LINE_H
