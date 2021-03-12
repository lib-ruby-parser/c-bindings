#include <stddef.h>
#include <stdlib.h>
#include "magic_comment.h"

void magic_comments_free(MagicCommentList *magic_comments)
{
    if (magic_comments->len > 0)
    {
        for (uint32_t i = 0; i < magic_comments->len; i++)
        {
            MagicComment magic_comment = magic_comments->list[i];
            loc_free(magic_comment.key_l);
            loc_free(magic_comment.value_l);
        }
        free(magic_comments->list);
    }
    free(magic_comments);
}
