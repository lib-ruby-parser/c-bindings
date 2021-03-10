#ifndef LIB_RUBY_PARSER_MAGIC_COMMENT_H
#define LIB_RUBY_PARSER_MAGIC_COMMENT_H

#include <stddef.h>
#include <stdint.h>
#include "loc.h"

// Type of the magic comment
enum MagicCommentKind
{
    MAGIC_COMMENT_KIND_ENCODING,
    MAGIC_COMMENT_KIND_FROZEN_STRING_LITERAL,
    MAGIC_COMMENT_KIND_WARN_INDENT,
    MAGIC_COMMENT_KIND_SHAREABLE_CONSTANT_VALUE,
};

// Representation of a magic comment (i.e. a special comment at the top of the file)
struct MagicComment
{
    // Magic comment kind
    enum MagicCommentKind kind;

    // Location of the key
    //
    // # encoding: foo
    //   ~~~~~~~~
    struct Loc *key_l;

    // Location of the value
    //
    // # encoding: foo
    //             ~~~
    struct Loc *value_l;
};

// List of the magic comments
struct MagicCommentList
{
    // Length of the list
    uint32_t len;

    // Pointer to array of magic comments
    struct MagicComment *list;
};

// Destructor of the list of magic comments
void magic_comments_free(struct MagicCommentList *magic_comments);

#endif // LIB_RUBY_PARSER_MAGIC_COMMENT_H
