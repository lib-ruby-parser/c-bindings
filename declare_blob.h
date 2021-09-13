#ifndef LIB_RUBY_PARSER_EXTERNAL_C_DECLARE_BLOB_H
#define LIB_RUBY_PARSER_EXTERNAL_C_DECLARE_BLOB_H

#include <stdint.h>

#define DECLARE_BLOB_FOR(VALUE)      \
    typedef struct VALUE##_BLOB      \
    {                                \
        uint8_t data[sizeof(VALUE)]; \
    } VALUE##_BLOB;                  \
                                     \
    typedef union                    \
    {                                \
        VALUE as_value;              \
        VALUE##_BLOB as_blob;        \
    } VALUE##_BLOB_UNION;
#endif // LIB_RUBY_PARSER_EXTERNAL_C_DECLARE_BLOB_H
