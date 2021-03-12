#include <stdlib.h>
#include "token.h"

void tokens_free(TokenList *tokens)
{
    if (tokens->len > 0)
    {
        for (uint32_t i = 0; i < tokens->len; i++)
        {
            Token token = tokens->list[i];
            free(token.token_value);
            free(token.loc);
        }
        free(tokens->list);
    }
    free(tokens);
}
