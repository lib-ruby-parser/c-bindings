#ifndef LIB_RUBY_PARSER_MEASURE_H
#define LIB_RUBY_PARSER_MEASURE_H

#include <time.h>
#include <math.h>

long now_in_millis(void);

long now_in_millis(void)
{
    struct timespec _t;
    clock_gettime(CLOCK_REALTIME, &_t);
    return _t.tv_sec * 1000 + lround((double)_t.tv_nsec / 1.0e6);
}

#endif // LIB_RUBY_PARSER_MEASURE_H
