#ifndef LIB_RUBY_PARSER_MAGIC_COMMENT_H
#define LIB_RUBY_PARSER_MAGIC_COMMENT_H

#include <stddef.h>
#include "loc.h"

typedef enum LIB_RUBY_PARSER_MagicCommentKind
{
    LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_ENCODING,
    LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_FROZEN_STRING_LITERAL,
    LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_WARN_INDENT,
    LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_SHAREABLE_CONSTANT_VALUE,
} LIB_RUBY_PARSER_MagicCommentKind;

// MagicComment
typedef struct LIB_RUBY_PARSER_MagicComment
{
    LIB_RUBY_PARSER_MagicCommentKind kind;
    LIB_RUBY_PARSER_Loc key_l;
    LIB_RUBY_PARSER_Loc value_l;
} LIB_RUBY_PARSER_MagicComment;
typedef struct LIB_RUBY_PARSER_MagicCommentList
{
    LIB_RUBY_PARSER_MagicComment *ptr;
    size_t len;
    size_t capacity;
} LIB_RUBY_PARSER_MagicCommentList;
void LIB_RUBY_PARSER_drop_magic_comment_list(LIB_RUBY_PARSER_MagicCommentList *magic_comment_list);

#endif // LIB_RUBY_PARSER_MAGIC_COMMENT_H
