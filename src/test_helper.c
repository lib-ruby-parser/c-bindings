#include "test_helper.h"
#include <string.h>
#include "string.h"

void run_tests_as_group(const char *group_name, const test_fn_t *tests, size_t count)
{
    fprintf(stderr, "Running group \"%s\"", group_name);
    fprintf(stderr, " with %lu tests:\n", count);
    for (size_t i = 0; i < count; i++)
    {
        test_fn_t test_fn = tests[i];
        fprintf(stderr, "  - ");
        test_fn();
        fprintf(stderr, "\n");
    }
}
