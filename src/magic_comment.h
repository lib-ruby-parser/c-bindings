#ifndef LIB_RUBY_PARSER_MAGIC_COMMENT_H
#define LIB_RUBY_PARSER_MAGIC_COMMENT_H

#include <stddef.h>
#include <stdint.h>
#include "loc.h"

enum MagicCommentKind
{
    MAGIC_COMMENT_KIND_ENCODING,
    MAGIC_COMMENT_KIND_FROZEN_STRING_LITERAL,
    MAGIC_COMMENT_KIND_WARN_INDENT,
    MAGIC_COMMENT_KIND_SHAREABLE_CONSTANT_VALUE,
};

struct MagicComment
{
    enum MagicCommentKind kind;
    struct Loc *key_l;
    struct Loc *value_l;
};

struct MagicCommentList
{
    uint32_t len;
    struct MagicComment *list;
};

void magic_comments_free(struct MagicCommentList *magic_comments);

#endif // LIB_RUBY_PARSER_MAGIC_COMMENT_H
