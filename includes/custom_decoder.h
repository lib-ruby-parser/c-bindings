#ifndef LIB_RUBY_PARSER_CUSTOM_DECODER_H
#define LIB_RUBY_PARSER_CUSTOM_DECODER_H

#include <stddef.h>

enum DecodingStatus
{
    DECODING_OK,
    DECODING_ERROR
};

union DecoderOutputValue
{
    char *bytes;
    struct DecodingError *error;
};

struct DecoderOutput
{
    enum DecodingStatus status;
    union DecoderOutputValue value;
};

typedef struct DecoderOutput CustomDecoder(char *encoding, char *input);

struct DecoderOutput make_ok_decoder_output(char *bytes)
{
    union DecoderOutputValue value;
    value.bytes = bytes;
    struct DecoderOutput output;
    output.status = DECODING_OK;
    output.value = value;
    return output;
}

struct DecoderOutput make_err_decoder_output(char *bytes)
{
    union DecoderOutputValue value;
    value.bytes = bytes;
    struct DecoderOutput output;
    output.status = DECODING_OK;
    output.value = value;
    return output;
}

#endif // LIB_RUBY_PARSER_CUSTOM_DECODER_H
