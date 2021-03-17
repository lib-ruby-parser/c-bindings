#include <stdlib.h>
#include "token.h"
#include "rust_free.h"

void tokens_free(TokenList *tokens)
{
    if (tokens->len > 0)
    {
        for (uint32_t i = 0; i < tokens->len; i++)
        {
            Token token = tokens->list[i];
            rust_string_free(token.token_value);
            rust_loc_free(token.loc);
        }
        rust_tokens_free(tokens->list);
    }
    rust_token_list_free(tokens);
}
