#include <stdlib.h>
#include "comment.h"
#include "loc.h"

void comments_free(CommentList *comments)
{
    if (comments->len > 0)
    {
        for (uint32_t i = 0; i < comments->len; i++)
        {
            Comment comment = comments->list[i];
            loc_free(comment.location);
        }
        free(comments->list);
    }
    free(comments);
}
