#include <stdint.h>
#include <stdlib.h>

void *lib_ruby_parser_allocate(uint32_t size)
{
    return malloc(size);
}
void lib_ruby_parser_free(void *ptr)
{
    free(ptr);
}
