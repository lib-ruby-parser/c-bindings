#include <stddef.h>
#include <stdlib.h>
#include "diagnostic.h"
#include "loc.h"

void diagnostics_free(struct DiagnosticList *diagnostics)
{
    if (diagnostics->len > 0)
    {
        for (uint32_t i = 0; i < diagnostics->len; i++)
        {
            struct Diagnostic diagnostic = diagnostics->list[i];
            diagnostic_message_free(diagnostic.message);
            loc_free(diagnostic.loc);
        }
        free(diagnostics->list);
    }
    free(diagnostics);
}
