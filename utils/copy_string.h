#include <string.h>
#include <stdlib.h>

uint8_t *copy_string(const char *source)
{
    uint32_t len = strlen(source);
    char *out = (char *)malloc(len + 1);
    strcpy(out, source);
    return (uint8_t *)out;
}
