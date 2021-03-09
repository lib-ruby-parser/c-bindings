#include <stdlib.h>
#include "token.h"

void str_ptr_free(char *);
void loc_free(struct Loc *loc);

void tokens_free(struct TokenList *tokens)
{
    if (tokens->len > 0)
    {
        for (uint32_t i = 0; i < tokens->len; i++)
        {
            struct Token token = tokens->list[i];
            str_ptr_free(token.token_value);
            loc_free(token.loc);
        }
        free(tokens->list);
    }
    free(tokens);
}
