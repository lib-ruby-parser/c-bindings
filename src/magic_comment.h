#ifndef LIB_RUBY_PARSER_MAGIC_COMMENT_H
#define LIB_RUBY_PARSER_MAGIC_COMMENT_H

#include <stddef.h>
#include <stdint.h>
#include "loc.h"

enum MagicCommentKind
{
    ENCODING,
    FROZEN_STRING_LITERAL,
    WARN_INDENT,
    SHAREABLE_CONSTANT_VALUE,
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
