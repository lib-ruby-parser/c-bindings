#ifndef LIB_RUBY_PARSER_COMMENT_H
#define LIB_RUBY_PARSER_COMMENT_H

#include <stddef.h>
#include "loc.h"

/// @defgroup comments Comments
/// @brief Everything related to source comments
/// @{
/// @}

/// @brief Equivalent of `lib_ruby_parser::source::CommentType`
/// @ingroup comments
typedef enum
{
    /// Inline variant (like `# foo`)
    LIB_RUBY_PARSER_COMMENT_TYPE_INLINE,
    /// Document variant (like `=begin ... =end`)
    LIB_RUBY_PARSER_COMMENT_TYPE_DOCUMENT,
    /// Unknown variant
    LIB_RUBY_PARSER_COMMENT_TYPE_UNKNOWN,
} LIB_RUBY_PARSER_CommentType;

/// @brief Equivalent of `lib_ruby_parser::source::Comment`
/// @ingroup comments
typedef struct
{
    /// Location of the comment
    LIB_RUBY_PARSER_Loc location;

    /// Kind of the comment (inline/document/unknown)
    LIB_RUBY_PARSER_CommentType kind;
} LIB_RUBY_PARSER_Comment;

/// @brief Equivalent of `Vec<lib_ruby_parser::source::Comment>`
/// @ingroup comments
typedef struct
{
    /// Pointer to beginning of the comments list
    LIB_RUBY_PARSER_Comment *ptr;
    /// Capacity
    size_t capacity;
    /// Length of the array
    size_t len;
} LIB_RUBY_PARSER_CommentList;

/// @brief CommentList destructor.
/// Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
/// i.e. it doesn't call `free` on a given pointer.
/// @ingroup comments
void LIB_RUBY_PARSER_drop_comment_list(LIB_RUBY_PARSER_CommentList *comment_list);

#endif // LIB_RUBY_PARSER_COMMENT_H
