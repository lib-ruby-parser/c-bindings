#ifndef LIB_RUBY_PARSER_CUSTOM_DECODER_H
#define LIB_RUBY_PARSER_CUSTOM_DECODER_H

#include <stddef.h>
#include <stdint.h>

// Decoding status that must be returned from your custom decoder
enum DecodingStatus
{
    DECODING_STATUS_OK,
    DECODING_STATUS_ERROR
};

// Payload of the "DECODING_STATUS_OK" result
struct DecoderOutputSuccess
{
    // Pointer to decoded input
    char *bytes;

    // Length of decoded input
    uint32_t len;
};

// Payoad of the "DECODING_STATUS_ERROR" result
struct DecoderOutputError
{
    // Null-terminated error message that must be returned from the parser
    char *error_message;
};

// A union of ok/error decoding results
union DecoderOutputValue
{
    // Ok variant
    struct DecoderOutputSuccess success;

    // Error variant
    struct DecoderOutputError error;
};

// Tagged union, a combination of status+value from your custom decoder
struct DecoderOutput
{
    // Tag
    enum DecodingStatus status;

    // Value
    union DecoderOutputValue value;
};

// Type of the function that performs decoding.
//
// Takes "custom state" + "recognized encoding" + "original input"
// Returns "DecoderOutput" (i.e. Error("reason") or Ok(decoded input))
typedef struct DecoderOutput CustomDecoderFn(void *state, const char *encoding, const char *input, uint32_t len);

// Custom decoder that must be set on `ParserOptions` to perform
// decoding of non-ascii-or-utf-8 input
struct CustomDecoder
{
    // Custom state of your decoded. Can be NULL if you don't need it.
    void *state;

    // Pointer to decoding function
    CustomDecoderFn *decoder;
};

// Helper function, returns Ok(bytes)
struct DecoderOutput decode_ok(char *bytes, uint32_t len);

// Helper function, returns Error(error_message)
struct DecoderOutput decode_err(char *error_message);

#endif // LIB_RUBY_PARSER_CUSTOM_DECODER_H
