#ifndef LIB_RUBY_PARSER_COMMENT_H
#define LIB_RUBY_PARSER_COMMENT_H

#include <stddef.h>
#include "loc.h"

typedef enum LIB_RUBY_PARSER_CommentType
{
    LIB_RUBY_PARSER_COMMENT_TYPE_INLINE,
    LIB_RUBY_PARSER_COMMENT_TYPE_DOCUMENT,
    LIB_RUBY_PARSER_COMMENT_TYPE_UNKNOWN,
} LIB_RUBY_PARSER_CommentType;

typedef struct LIB_RUBY_PARSER_Comment
{
    LIB_RUBY_PARSER_Loc location;
    LIB_RUBY_PARSER_CommentType kind;
} LIB_RUBY_PARSER_Comment;

typedef struct LIB_RUBY_PARSER_CommentList
{
    LIB_RUBY_PARSER_Comment *ptr;
    size_t len;
    size_t capacity;
} LIB_RUBY_PARSER_CommentList;
void LIB_RUBY_PARSER_drop_comment_list(LIB_RUBY_PARSER_CommentList *comment_list);

#ifdef TEST_ENV
void run_test_group_comment(void);
#endif

#endif // LIB_RUBY_PARSER_COMMENT_H
