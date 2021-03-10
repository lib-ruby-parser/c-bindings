#ifndef LIB_RUBY_PARSER_COMMENT_H
#define LIB_RUBY_PARSER_COMMENT_H

#include <stddef.h>
#include <stdint.h>
#include "loc.h"

// Representation of the comment in source code
struct Comment
{
    // Location of the comment
    struct Loc *location;
};

// A list of comments
struct CommentList
{
    // Length of the list
    uint32_t len;

    // Pointer to array of comments
    struct Comment *list;
};

// Destructor of the comments list
void comments_free(struct CommentList *comments);

#endif // LIB_RUBY_PARSER_COMMENT_H
