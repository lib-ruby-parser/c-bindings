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

static const char *US_ASCII = "us-ascii";

static void test_input_error_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_InputError input_error;

    input_error = lib_ruby_parser__test__make_input_error__unsupported_encoding(
        LIB_RUBY_PARSER_new_string_from_cstr(US_ASCII));
    assert_eq(input_error.tag, LIB_RUBY_PARSER_INPUT_ERROR_UNSUPPORTED_ENCODING);
    assert_string_eq(input_error.as.unsupported_encoding, US_ASCII);
    LIB_RUBY_PARSER_drop_input_error(&input_error);

    input_error = lib_ruby_parser__test__make_input_error__decoding_error(
        LIB_RUBY_PARSER_new_string_from_cstr("bar"));
    assert_eq(input_error.tag, LIB_RUBY_PARSER_INPUT_ERROR_DECODING_ERROR);
    assert_string_eq(input_error.as.decoding_error, "bar");
    LIB_RUBY_PARSER_drop_input_error(&input_error);
}

LIB_RUBY_PARSER_DecoderResult lib_ruby_parser__test__make_decoder_result__ok(LIB_RUBY_PARSER_ByteList bytes);
LIB_RUBY_PARSER_DecoderResult lib_ruby_parser__test__make_decoder_result__err(LIB_RUBY_PARSER_InputError err);

static void test_decoder_result_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_DecoderResult result;

    result = lib_ruby_parser__test__make_decoder_result__ok(
        LIB_RUBY_PARSER_new_bytes_from_cstr("bar", 3));
    assert_eq(result.tag, LIB_RUBY_PARSER_DECODER_RESULT_OK);
    assert_byte_list(result.as.ok, "bar");
    LIB_RUBY_PARSER_drop_decoder_result(&result);

    result = lib_ruby_parser__test__make_decoder_result__err(
        lib_ruby_parser__test__make_input_error__unsupported_encoding(
            LIB_RUBY_PARSER_new_string_from_cstr(US_ASCII)));
    assert_eq(result.tag, LIB_RUBY_PARSER_DECODER_RESULT_ERR);
    assert_eq(result.as.err.tag, LIB_RUBY_PARSER_INPUT_ERROR_UNSUPPORTED_ENCODING);
    assert_string_eq(result.as.err.as.unsupported_encoding, US_ASCII);
    LIB_RUBY_PARSER_drop_decoder_result(&result);
}

LIB_RUBY_PARSER_Decoder lib_ruby_parser__test__always_ok_decoder(void);
LIB_RUBY_PARSER_Decoder lib_ruby_parser__test__always_err_decoder(void);
static void test_decoder_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_Decoder d;
    LIB_RUBY_PARSER_DecoderResult decoder_result;
    const char *ALWAYS_OK = "always_ok";
    const char *ALWAYS_ERR = "always_err";

    d = lib_ruby_parser__test__always_ok_decoder();
    decoder_result = (d.f)(d.state, LIB_RUBY_PARSER_new_string_from_cstr("utf-8"), LIB_RUBY_PARSER_new_bytes_from_cstr("2 + 2", 5));
    assert_eq(decoder_result.tag, LIB_RUBY_PARSER_DECODER_RESULT_OK);
    assert_byte_list(decoder_result.as.ok, ALWAYS_OK);
    LIB_RUBY_PARSER_drop_decoder_result(&decoder_result);

    d = lib_ruby_parser__test__always_err_decoder();
    decoder_result = (d.f)(d.state, LIB_RUBY_PARSER_new_string_from_cstr("utf-8"), LIB_RUBY_PARSER_new_bytes_from_cstr("2 + 2", 5));
    assert_eq(decoder_result.as.err.tag, LIB_RUBY_PARSER_INPUT_ERROR_DECODING_ERROR);
    assert_string_eq(decoder_result.as.err.as.unsupported_encoding, ALWAYS_ERR);
    LIB_RUBY_PARSER_drop_decoder_result(&decoder_result);
}

LIB_RUBY_PARSER_MaybeDecoder lib_ruby_parser__test__some_always_ok_decoder(void);
LIB_RUBY_PARSER_MaybeDecoder lib_ruby_parser__test__none_decoder(void);
static void test_maybe_decoder_fields(void)
{
    annotate_test;

    LIB_RUBY_PARSER_MaybeDecoder maybe_decoder;
    LIB_RUBY_PARSER_Decoder always_ok_decoder = lib_ruby_parser__test__always_ok_decoder();

    maybe_decoder = lib_ruby_parser__test__some_always_ok_decoder();
    assert(LIB_RUBY_PARSER_maybe_decoder_is_some(&maybe_decoder));
    assert_eq(maybe_decoder.decoder.f, always_ok_decoder.f);

    maybe_decoder = lib_ruby_parser__test__none_decoder();
    assert(LIB_RUBY_PARSER_maybe_decoder_is_none(&maybe_decoder));
}

void run_test_group_decoder(void)
{
    const test_fn_t tests[] = {
        test_input_error_fields,
        test_decoder_result_fields,
        test_decoder_fields,
        test_maybe_decoder_fields,
    };

    run_tests_as_group("decoder", tests, sizeof(tests) / sizeof(test_fn_t));
}

#endif
