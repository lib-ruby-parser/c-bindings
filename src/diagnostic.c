#include <stddef.h>
#include <stdlib.h>
#include "diagnostic.h"
#include "loc.h"
#include "rust_free.h"

void diagnostics_free(DiagnosticList *diagnostics)
{
    if (diagnostics->len > 0)
    {
        for (uint32_t i = 0; i < diagnostics->len; i++)
        {
            Diagnostic diagnostic = diagnostics->list[i];
            diagnostic_message_free(diagnostic.message);
            loc_free(diagnostic.loc);
        }
        rust_diagnostics_free(diagnostics->list);
    }
    rust_diagnostic_list_free(diagnostics);
}
