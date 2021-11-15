#ifndef LIB_RUBY_PARSER_DECODER_H
#define LIB_RUBY_PARSER_DECODER_H

#include "string.h"
#include "bytes.h"

typedef struct LIB_RUBY_PARSER_InputError
{
    enum
    {
        LIB_RUBY_PARSER_INPUT_ERROR_UNSUPPORTED_ENCODING,
        LIB_RUBY_PARSER_INPUT_ERROR_DECODING_ERROR
    } tag;

    union
    {
        LIB_RUBY_PARSER_String unsupported_encoding;
        LIB_RUBY_PARSER_String decoding_error;
    } as;
} LIB_RUBY_PARSER_InputError;
void LIB_RUBY_PARSER_drop_input_error(LIB_RUBY_PARSER_InputError *input_error);

typedef struct LIB_RUBY_PARSER_DecoderResult
{
    enum
    {
        LIB_RUBY_PARSER_DECODER_RESULT_OK,
        LIB_RUBY_PARSER_DECODER_RESULT_ERR
    } tag;

    union
    {
        LIB_RUBY_PARSER_ByteList ok;
        LIB_RUBY_PARSER_InputError err;
    } as;
} LIB_RUBY_PARSER_DecoderResult;
void LIB_RUBY_PARSER_drop_decoder_result(LIB_RUBY_PARSER_DecoderResult *decoder_result);

struct LIB_RUBY_PARSER_Decoder;
typedef LIB_RUBY_PARSER_DecoderResult (*LIB_RUBY_PARSER_Decoder_Function)(LIB_RUBY_PARSER_String, LIB_RUBY_PARSER_ByteList);
typedef struct LIB_RUBY_PARSER_Decoder
{
    LIB_RUBY_PARSER_Decoder_Function f;
} LIB_RUBY_PARSER_Decoder;

typedef struct LIB_RUBY_PARSER_MaybeDecoder
{
    enum
    {
        LIB_RUBY_PARSER_NONE_DECODER = 0,
        LIB_RUBY_PARSER_SOME_DECODER = 1,
    } tag;

    union
    {
        LIB_RUBY_PARSER_Decoder decoder;
        uint8_t none;
    } as;
} LIB_RUBY_PARSER_MaybeDecoder;

#endif // LIB_RUBY_PARSER_DECODER_H
