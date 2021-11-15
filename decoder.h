#ifndef LIB_RUBY_PARSER_DECODER_H
#define LIB_RUBY_PARSER_DECODER_H

#include <stdbool.h>
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
    LIB_RUBY_PARSER_Decoder decoder;
} LIB_RUBY_PARSER_MaybeDecoder;
bool LIB_RUBY_PARSER_maybe_decoder_is_some(const LIB_RUBY_PARSER_MaybeDecoder *maybe_decoder);
bool LIB_RUBY_PARSER_maybe_decoder_is_none(const LIB_RUBY_PARSER_MaybeDecoder *maybe_decoder);

#endif // LIB_RUBY_PARSER_DECODER_H
