#ifndef LIB_RUBY_PARSER_SOURCE_LINE_H
#define LIB_RUBY_PARSER_SOURCE_LINE_H

#include <stddef.h>
#include <stdbool.h>

/// @defgroup source_line Source Line
/// @{
/// @}

/// @brief `SourceLine` struct from `lib-ruby-parser`
/// @ingroup source_line
typedef struct
{
    size_t start;
    size_t end;
    bool ends_with_eof;
} LIB_RUBY_PARSER_SourceLine;

/// @brief Equivalent of `Vec<SourceLine>`
/// @ingroup source_line
typedef struct
{
    size_t capacity;
    LIB_RUBY_PARSER_SourceLine *ptr;
    size_t len;
} LIB_RUBY_PARSER_SourceLineList;

/// LIB_RUBY_PARSER_SourceLineList destructor.
/// Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
/// i.e. it doesn't call `free` on a given pointer.
/// @ingroup source_line
void LIB_RUBY_PARSER_drop_source_line_list(LIB_RUBY_PARSER_SourceLineList *source_line_list);

#endif // LIB_RUBY_PARSER_SOURCE_LINE_H
