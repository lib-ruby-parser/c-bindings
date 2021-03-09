#include <stddef.h>
#include <stdlib.h>
#include "diagnostic.h"
#include "loc.h"

void diagnostics_ptr_free(struct Diagnostic *);
void diagnostics_list_free(struct Diagnostics *);

void diagnostics_free(struct Diagnostics *diagnostics)
{
    if (diagnostics->len > 0)
    {
        for (uint32_t i = 0; i < diagnostics->len; i++)
        {
            struct Diagnostic diagnostic = diagnostics->list[i];
            diagnostic_message_free(diagnostic.message);
            loc_free(diagnostic.loc);
        }
        diagnostics_ptr_free(diagnostics->list);
    }
    diagnostics_list_free(diagnostics);
}
