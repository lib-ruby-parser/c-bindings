#ifndef LIB_RUBY_PARSER_MAGIC_COMMENT_H
#define LIB_RUBY_PARSER_MAGIC_COMMENT_H

#include <stddef.h>

struct Range;

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
    struct Range *key_l;
    struct Range *value_l;
};

struct MagicCommentList
{
    size_t len;
    struct MagicComment *list;
};

void magic_comments_free(struct MagicCommentList *magic_comments)
{
    if (magic_comments->len > 0)
    {
        for (size_t i = 0; i < magic_comments->len; i++)
        {
            struct MagicComment magic_comment = magic_comments->list[i];
            range_free(magic_comment.key_l);
            range_free(magic_comment.value_l);
        }
        free(magic_comments->list);
    }
    free(magic_comments);
}

#endif // LIB_RUBY_PARSER_MAGIC_COMMENT_H
