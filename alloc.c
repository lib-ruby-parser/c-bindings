#include <stdint.h>
#include <stdlib.h>

void *__attribute__((always_inline)) lib_ruby_parser_allocate(uint32_t size)
{
    return malloc(size);
}
void __attribute__((always_inline)) lib_ruby_parser_free(void *ptr)
{
    free(ptr);
}
