#include <stdlib.h>
#include "comment.h"
#include "range.h"

void comments_free(struct CommentList *comments)
{
    if (comments->len > 0)
    {
        for (uint32_t i = 0; i < comments->len; i++)
        {
            struct Comment comment = comments->list[i];
            range_free(comment.location);
        }
        free(comments->list);
    }
    free(comments);
}
