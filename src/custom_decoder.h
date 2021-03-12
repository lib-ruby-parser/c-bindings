#ifndef LIB_RUBY_PARSER_CUSTOM_DECODER_H
#define LIB_RUBY_PARSER_CUSTOM_DECODER_H

#include <stddef.h>
#include <stdint.h>

// Decoding status that must be returned from your custom decoder
typedef enum DecodingStatus
{
    DECODING_STATUS_OK,
    DECODING_STATUS_ERROR
} DecodingStatus;

// Payload of the "DECODING_STATUS_OK" result
typedef struct DecoderOutputSuccess
{
    // Pointer to decoded input
    char *bytes;

    // Length of decoded input
    uint32_t len;
} DecoderOutputSuccess;

// Payoad of the "DECODING_STATUS_ERROR" result
typedef struct DecoderOutputError
{
    // Null-terminated error message that must be returned from the parser
    char *error_message;
} DecoderOutputError;

// A union of ok/error decoding results
typedef union DecoderOutputValue
{
    // Ok variant
    DecoderOutputSuccess success;

    // Error variant
    DecoderOutputError error;
} DecoderOutputValue;

// Tagged union, a combination of status+value from your custom decoder
typedef struct DecoderOutput
{
    // Tag
    DecodingStatus status;

    // Value
    DecoderOutputValue value;
} DecoderOutput;

// Type of the function that performs decoding.
//
// Takes "custom state" + "recognized encoding" + "original input"
// Returns "DecoderOutput" (i.e. Error("reason") or Ok(decoded input))
typedef DecoderOutput CustomDecoderFn(void *state, const char *encoding, const char *input, uint32_t len);

// Custom decoder that must be set on `ParserOptions` to perform
// decoding of non-ascii-or-utf-8 input
typedef struct CustomDecoder
{
    // Custom state of your decoded. Can be NULL if you don't need it.
    void *state;

    // Pointer to decoding function
    CustomDecoderFn *decoder;
} CustomDecoder;

// Helper function, returns Ok(bytes)
DecoderOutput decode_ok(char *bytes, uint32_t len);

// Helper function, returns Error(error_message)
DecoderOutput decode_err(char *error_message);

#endif // LIB_RUBY_PARSER_CUSTOM_DECODER_H
