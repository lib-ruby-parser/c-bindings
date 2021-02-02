#ifndef LIB_RUBY_PARSER_COMMENT_H
#define LIB_RUBY_PARSER_COMMENT_H

#include <stddef.h>
#include <stdint.h>
#include "range.h"

struct Comment
{
    struct Range *location;
};

struct CommentList
{
    uint32_t len;
    struct Comment *list;
};

void comments_free(struct CommentList *comments);

#endif // LIB_RUBY_PARSER_COMMENT_H
