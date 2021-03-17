#include <stddef.h>
#include <stdlib.h>
#include "magic_comment.h"
#include "rust_free.h"

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
        rust_magic_comments_free(magic_comments->list);
    }
    rust_magic_comment_list_free(magic_comments);
}
