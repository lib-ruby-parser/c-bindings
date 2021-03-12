#ifndef LIB_RUBY_PARSER_MAGIC_COMMENT_H
#define LIB_RUBY_PARSER_MAGIC_COMMENT_H

#include <stddef.h>
#include <stdint.h>
#include "loc.h"

// Type of the magic comment
typedef enum MagicCommentKind
{
    MAGIC_COMMENT_KIND_ENCODING,
    MAGIC_COMMENT_KIND_FROZEN_STRING_LITERAL,
    MAGIC_COMMENT_KIND_WARN_INDENT,
    MAGIC_COMMENT_KIND_SHAREABLE_CONSTANT_VALUE,
} MagicCommentKind;

// Representation of a magic comment (i.e. a special comment at the top of the file)
typedef struct MagicComment
{
    // Magic comment kind
    MagicCommentKind kind;

    // Location of the key
    //
    // # encoding: foo
    //   ~~~~~~~~
    Loc *key_l;

    // Location of the value
    //
    // # encoding: foo
    //             ~~~
    Loc *value_l;
} MagicComment;

// List of the magic comments
typedef struct MagicCommentList
{
    // Length of the list
    uint32_t len;

    // Pointer to array of magic comments
    MagicComment *list;
} MagicCommentList;

// Destructor of the list of magic comments
void magic_comments_free(MagicCommentList *magic_comments);

#endif // LIB_RUBY_PARSER_MAGIC_COMMENT_H
