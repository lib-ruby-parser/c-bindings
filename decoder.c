#include "decoder.h"

bool LIB_RUBY_PARSER_maybe_decoder_is_some(const LIB_RUBY_PARSER_MaybeDecoder *maybe_decoder)
{
    return maybe_decoder->decoder.f != NULL;
}
bool LIB_RUBY_PARSER_maybe_decoder_is_none(const LIB_RUBY_PARSER_MaybeDecoder *maybe_decoder)
{
    return maybe_decoder->decoder.f == NULL;
}

#ifdef TEST_ENV

#include "test_helper.h"

LIB_RUBY_PARSER_InputError lib_ruby_parser__test__make_input_error__unsupported_encoding(
    LIB_RUBY_PARSER_String unsupported_encoding);

LIB_RUBY_PARSER_InputError lib_ruby_parser__test__make_input_error__decoding_error(
    LIB_RUBY_PARSER_String decoding_error);

const char *US_ASCII = "us-ascii";

test(input_error_fields, {
    LIB_RUBY_PARSER_InputError input_error;

    input_error = lib_ruby_parser__test__make_input_error__unsupported_encoding(
        LIB_RUBY_PARSER_new_string_from_cstr(US_ASCII));
    assert_eq(input_error.tag, LIB_RUBY_PARSER_INPUT_ERROR_UNSUPPORTED_ENCODING);
    assert_eq(input_error.as.unsupported_encoding.len, strlen(US_ASCII));
    assert_str_eq(input_error.as.unsupported_encoding.ptr, US_ASCII, strlen(US_ASCII));
    LIB_RUBY_PARSER_drop_input_error(&input_error);

    input_error = lib_ruby_parser__test__make_input_error__decoding_error(
        LIB_RUBY_PARSER_new_string_from_cstr("bar"));
    assert_eq(input_error.tag, LIB_RUBY_PARSER_INPUT_ERROR_DECODING_ERROR);
    assert_eq(input_error.as.decoding_error.len, strlen("bar"));
    assert_str_eq(input_error.as.decoding_error.ptr, "bar", strlen("bar"));
    LIB_RUBY_PARSER_drop_input_error(&input_error);
});

LIB_RUBY_PARSER_DecoderResult lib_ruby_parser__test__make_decoder_result__ok(LIB_RUBY_PARSER_ByteList bytes);
LIB_RUBY_PARSER_DecoderResult lib_ruby_parser__test__make_decoder_result__err(LIB_RUBY_PARSER_InputError err);

test(decoder_result_fields, {
    LIB_RUBY_PARSER_DecoderResult result;

    result = lib_ruby_parser__test__make_decoder_result__ok(
        LIB_RUBY_PARSER_new_bytes_from_cstr("bar", 3));
    assert_eq(result.tag, LIB_RUBY_PARSER_DECODER_RESULT_OK);
    assert_eq(result.as.ok.len, 3);
    assert_str_eq(result.as.ok.ptr, "bar", 3);
    LIB_RUBY_PARSER_drop_decoder_result(&result);

    result = lib_ruby_parser__test__make_decoder_result__err(
        lib_ruby_parser__test__make_input_error__unsupported_encoding(
            LIB_RUBY_PARSER_new_string_from_cstr(US_ASCII)));
    assert_eq(result.tag, LIB_RUBY_PARSER_DECODER_RESULT_ERR);
    assert_eq(result.as.err.tag, LIB_RUBY_PARSER_INPUT_ERROR_UNSUPPORTED_ENCODING);
    assert_eq(result.as.err.as.unsupported_encoding.len, strlen(US_ASCII));
    assert_str_eq(result.as.err.as.unsupported_encoding.ptr, US_ASCII, strlen(US_ASCII));
    LIB_RUBY_PARSER_drop_decoder_result(&result);
});

LIB_RUBY_PARSER_Decoder lib_ruby_parser__test__always_ok_decoder();
LIB_RUBY_PARSER_Decoder lib_ruby_parser__test__always_err_decoder();
test(decoder_fields, {
    LIB_RUBY_PARSER_Decoder d;
    LIB_RUBY_PARSER_DecoderResult decoder_result;
    const char *ALWAYS_OK = "always_ok";
    const char *ALWAYS_ERR = "always_err";

    d = lib_ruby_parser__test__always_ok_decoder();
    decoder_result = (d.f)(LIB_RUBY_PARSER_new_string_from_cstr("utf-8"), LIB_RUBY_PARSER_new_bytes_from_cstr("2 + 2", 5));
    assert_eq(decoder_result.tag, LIB_RUBY_PARSER_DECODER_RESULT_OK);
    assert_eq(decoder_result.as.ok.len, strlen(ALWAYS_OK));
    assert_str_eq(decoder_result.as.ok.ptr, ALWAYS_OK, strlen(ALWAYS_OK));
    LIB_RUBY_PARSER_drop_decoder_result(&decoder_result);

    d = lib_ruby_parser__test__always_err_decoder();
    decoder_result = (d.f)(LIB_RUBY_PARSER_new_string_from_cstr("utf-8"), LIB_RUBY_PARSER_new_bytes_from_cstr("2 + 2", 5));
    assert_eq(decoder_result.as.err.tag, LIB_RUBY_PARSER_INPUT_ERROR_DECODING_ERROR);
    assert_eq(decoder_result.as.err.as.unsupported_encoding.len, strlen(ALWAYS_ERR));
    assert_str_eq(decoder_result.as.err.as.unsupported_encoding.ptr, ALWAYS_ERR, strlen(ALWAYS_ERR));
    LIB_RUBY_PARSER_drop_decoder_result(&decoder_result);
});

LIB_RUBY_PARSER_MaybeDecoder lib_ruby_parser__test__some_always_ok_decoder();
LIB_RUBY_PARSER_MaybeDecoder lib_ruby_parser__test__none_decoder();
test(maybe_decoder_fields, {
    LIB_RUBY_PARSER_MaybeDecoder maybe_decoder;
    LIB_RUBY_PARSER_Decoder always_ok_decoder = lib_ruby_parser__test__always_ok_decoder();

    maybe_decoder = lib_ruby_parser__test__some_always_ok_decoder();
    assert(LIB_RUBY_PARSER_maybe_decoder_is_some(&maybe_decoder));
    assert_eq(maybe_decoder.decoder.f, always_ok_decoder.f);

    maybe_decoder = lib_ruby_parser__test__none_decoder();
    assert(LIB_RUBY_PARSER_maybe_decoder_is_none(&maybe_decoder));
});

declare_test_group(
    decoder,
    4,
    input_error_fields,
    decoder_result_fields,
    decoder_fields,
    maybe_decoder_fields);

#endif
