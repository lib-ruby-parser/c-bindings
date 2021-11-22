#ifndef LIB_RUBY_PARSER_MAGIC_COMMENT_H
#define LIB_RUBY_PARSER_MAGIC_COMMENT_H

#include <stddef.h>
#include "loc.h"

/*
    Equivalent of `lib_ruby_parser::source::MagicCommentKind`
*/
typedef enum LIB_RUBY_PARSER_MagicCommentKind
{
    LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_ENCODING,
    LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_FROZEN_STRING_LITERAL,
    LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_WARN_INDENT,
    LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_SHAREABLE_CONSTANT_VALUE,
} LIB_RUBY_PARSER_MagicCommentKind;

/*
    Equivalent of `lib_ruby_parser::source::MagicComment`
*/
typedef struct LIB_RUBY_PARSER_MagicComment
{
    LIB_RUBY_PARSER_MagicCommentKind kind;
    LIB_RUBY_PARSER_Loc key_l;
    LIB_RUBY_PARSER_Loc value_l;
} LIB_RUBY_PARSER_MagicComment;

/*
    Equivalent of `Vec<lib_ruby_parser::source::MagicComment>`
*/
typedef struct LIB_RUBY_PARSER_MagicCommentList
{
    LIB_RUBY_PARSER_MagicComment *ptr;
    size_t len;
    size_t capacity;
} LIB_RUBY_PARSER_MagicCommentList;

/*
    MagicCommentList destructor.
    Just like Rust/C++ destructor it performs cleanup of "embedded" resources.
    i.e. it doesn't call `free` on a given pointer.
*/
void LIB_RUBY_PARSER_drop_magic_comment_list(LIB_RUBY_PARSER_MagicCommentList *magic_comment_list);

#ifdef TEST_ENV
void run_test_group_magic_comment(void);
#endif

#endif // LIB_RUBY_PARSER_MAGIC_COMMENT_H
