#ifndef LIB_RUBY_PARSER_COMMENT_H
#define LIB_RUBY_PARSER_COMMENT_H

#include <stddef.h>

struct Range;

struct Comment
{
    struct Range *location;
};

struct CommentList
{
    size_t len;
    struct Comment *list;
};

void comments_free(struct CommentList *comments)
{
    if (comments->len > 0)
    {
        for (size_t i = 0; i < comments->len; i++)
        {
            struct Comment comment = comments->list[i];
            range_free(comment.location);
        }
        free(comments->list);
    }
    free(comments);
}

#endif // LIB_RUBY_PARSER_COMMENT_H
