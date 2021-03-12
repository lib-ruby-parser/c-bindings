#ifndef LIB_RUBY_PARSER_COMMENT_H
#define LIB_RUBY_PARSER_COMMENT_H

#include <stddef.h>
#include <stdint.h>
#include "loc.h"

// Representation of the comment in source code
typedef struct Comment
{
    // Location of the comment
    Loc *location;
} Comment;

// A list of comments
typedef struct CommentList
{
    // Length of the list
    uint32_t len;

    // Pointer to array of comments
    Comment *list;
} CommentList;

// Destructor of the comments list
void comments_free(CommentList *comments);

#endif // LIB_RUBY_PARSER_COMMENT_H
