#include <stddef.h>
#include <stdlib.h>
#include "diagnostic.h"
#include "range.h"

void diagnostics_free(struct Diagnostics *diagnostics)
{
    if (diagnostics->len > 0)
    {
        for (uint32_t i = 0; i < diagnostics->len; i++)
        {
            struct Diagnostic diagnostic = diagnostics->list[i];
            free(diagnostic.message);
            range_free(diagnostic.range);
        }
        free(diagnostics->list);
    }
    free(diagnostics);
}
