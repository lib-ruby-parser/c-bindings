#ifndef LIB_RUBY_PARSER_COMMENT_H
#define LIB_RUBY_PARSER_COMMENT_H

#include <stddef.h>
#include "loc.h"

/*
    Equivalent of `lib_ruby_parser::source::CommentType`
*/
typedef enum LIB_RUBY_PARSER_CommentType
{
    LIB_RUBY_PARSER_COMMENT_TYPE_INLINE,
    LIB_RUBY_PARSER_COMMENT_TYPE_DOCUMENT,
    LIB_RUBY_PARSER_COMMENT_TYPE_UNKNOWN,
} LIB_RUBY_PARSER_CommentType;

/*
    Equivalent of `lib_ruby_parser::source::Comment`
*/
typedef struct LIB_RUBY_PARSER_Comment
{
    /*
        Location of the comment
    */
    LIB_RUBY_PARSER_Loc location;

    /*
        Kind of the comment (inline/document/unknown)
    */
    LIB_RUBY_PARSER_CommentType kind;
} LIB_RUBY_PARSER_Comment;

/*
    Equivalent of `Vec<lib_ruby_parser::source::Comment>`
*/
typedef struct LIB_RUBY_PARSER_CommentList
{
    LIB_RUBY_PARSER_Comment *ptr;
    size_t len;
    size_t capacity;
} LIB_RUBY_PARSER_CommentList;

/*
    CommentList destructor.
    Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
    i.e. it doesn't call `free` on a given pointer.
*/
void LIB_RUBY_PARSER_drop_comment_list(LIB_RUBY_PARSER_CommentList *comment_list);

#ifdef TEST_ENV
void run_test_group_comment(void);
#endif

#endif // LIB_RUBY_PARSER_COMMENT_H
