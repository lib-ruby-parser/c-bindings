#include "decoder.h"

bool LIB_RUBY_PARSER_maybe_decoder_is_some(const LIB_RUBY_PARSER_MaybeDecoder *maybe_decoder)
{
    return maybe_decoder->decoder.f != NULL;
}
bool LIB_RUBY_PARSER_maybe_decoder_is_none(const LIB_RUBY_PARSER_MaybeDecoder *maybe_decoder)
{
    return maybe_decoder->decoder.f == NULL;
}
