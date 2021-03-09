#include <stddef.h>
#include <stdlib.h>
#include "magic_comment.h"

void magic_comments_ptr_free(struct MagicComment *);
void magic_comment_list_free(struct MagicCommentList *);

void magic_comments_free(struct MagicCommentList *magic_comments)
{
    if (magic_comments->len > 0)
    {
        for (uint32_t i = 0; i < magic_comments->len; i++)
        {
            struct MagicComment magic_comment = magic_comments->list[i];
            loc_free(magic_comment.key_l);
            loc_free(magic_comment.value_l);
        }
        magic_comments_ptr_free(magic_comments->list);
    }
    magic_comment_list_free(magic_comments);
}
