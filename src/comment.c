#include <stdlib.h>
#include "comment.h"
#include "loc.h"

void comments_ptr_free(struct Comment *);
void comment_list_free(struct CommentList *);

void comments_free(struct CommentList *comments)
{
    if (comments->len > 0)
    {
        for (uint32_t i = 0; i < comments->len; i++)
        {
            struct Comment comment = comments->list[i];
            loc_free(comment.location);
        }
        comments_ptr_free(comments->list);
    }
    comment_list_free(comments);
}
