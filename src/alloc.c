#include "alloc.h"
#include <stdlib.h>

void *lib_ruby_parser__external__alloc(size_t size)
{
    return malloc(size);
}
void lib_ruby_parser__external__free(void *ptr)
{
    free(ptr);
}
