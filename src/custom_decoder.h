#ifndef LIB_RUBY_PARSER_CUSTOM_DECODER_H
#define LIB_RUBY_PARSER_CUSTOM_DECODER_H

#include <stddef.h>
#include <stdint.h>

enum DecodingStatus
{
    DECODING_STATUS_OK,
    DECODING_STATUS_ERROR
};

struct DecoderOutputSuccess
{
    char *bytes;
    uint32_t len;
};

struct DecoderOutputError
{
    char *error_message;
};

union DecoderOutputValue
{
    struct DecoderOutputSuccess success;
    struct DecoderOutputError error;
};

struct DecoderOutput
{
    enum DecodingStatus status;
    union DecoderOutputValue value;
};

typedef struct DecoderOutput CustomDecoderFn(void *state, const char *encoding, const char *input, uint32_t len);

struct CustomDecoder
{
    void *state;
    CustomDecoderFn *decoder;
};

struct DecoderOutput decode_ok(char *bytes, uint32_t len);
struct DecoderOutput decode_err(char *error_message);

#endif // LIB_RUBY_PARSER_CUSTOM_DECODER_H
