#ifndef LIB_RUBY_PARSER_CUSTOM_DECODER_H
#define LIB_RUBY_PARSER_CUSTOM_DECODER_H

#include <stddef.h>

enum DecodingStatus
{
    DECODING_STATUS_OK,
    DECODING_STATUS_ERROR
};

struct DecoderOutputSuccess
{
    char *bytes;
    size_t len;
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

typedef struct DecoderOutput CustomDecoder(const char *encoding, const char *input, size_t len);

struct DecoderOutput decode_ok(char *bytes, size_t len)
{
    return (struct DecoderOutput){
        .status = DECODING_STATUS_OK,
        .value = {
            .success = {
                .bytes = bytes,
                .len = len}}};
}

struct DecoderOutput decode_err(char *error_message)
{
    return (struct DecoderOutput){
        .status = DECODING_STATUS_ERROR,
        .value = {
            .error = {
                .error_message = error_message}}};
}

#endif // LIB_RUBY_PARSER_CUSTOM_DECODER_H
