#ifndef LIB_RUBY_PARSER_MEASURE_H
#define LIB_RUBY_PARSER_MEASURE_H

#include <time.h>
#include <math.h>

long now_in_millis()
{
    struct timespec _t;
    clock_gettime(CLOCK_REALTIME, &_t);
    return _t.tv_sec * 1000 + lround(_t.tv_nsec / 1.0e6);
}

#endif // LIB_RUBY_PARSER_MEASURE_H
