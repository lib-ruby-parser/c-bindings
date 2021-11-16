#[allow(unused_imports)]
use crate::{blob_type, BlobByteList, BlobString};
use lib_ruby_parser::source::{DecoderResult, InputError};

blob_type!(BlobInputError, InputError);
blob_type!(BlobDecoderResult, DecoderResult);
blob_type!(BlobMaybeDecoder, Option<Decoder>);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_input_error__unsupported_encoding(
    s: BlobString,
) -> BlobInputError {
    BlobInputError::from(InputError::UnsupportedEncoding(String::from(s)))
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_input_error__decoding_error(
    s: BlobString,
) -> BlobInputError {
    BlobInputError::from(InputError::DecodingError(String::from(s)))
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_input_error(input_error: *mut InputError) {
    unsafe { std::ptr::drop_in_place(input_error) }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_decoder_result__ok(
    bytes: BlobByteList,
) -> BlobDecoderResult {
    BlobDecoderResult::from(DecoderResult::Ok(bytes.into()))
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_decoder_result__err(
    err: BlobInputError,
) -> BlobDecoderResult {
    BlobDecoderResult::from(DecoderResult::Err(err.into()))
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_decoder_result(decoder_result: *mut DecoderResult) {
    unsafe { std::ptr::drop_in_place(decoder_result) }
}

#[repr(C)]
pub struct Decoder {
    pub f: extern "C" fn(encoding: BlobString, input: BlobByteList) -> BlobDecoderResult,
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__always_ok_decoder() -> Decoder {
    #[no_mangle]
    pub extern "C" fn lib_ruby_parser__test__always_ok_decoder_fn(
        encoding: BlobString,
        input: BlobByteList,
    ) -> BlobDecoderResult {
        // do cleanup
        drop(String::from(encoding));
        drop(Vec::<u8>::from(input));
        // and return constant output
        BlobDecoderResult::from(DecoderResult::Ok("always_ok".as_bytes().to_vec()))
    }
    Decoder {
        f: lib_ruby_parser__test__always_ok_decoder_fn,
    }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__always_err_decoder() -> Decoder {
    #[no_mangle]
    pub extern "C" fn lib_ruby_parser__test__always_err_decoder_fn(
        encoding: BlobString,
        input: BlobByteList,
    ) -> BlobDecoderResult {
        // do cleanup
        drop(String::from(encoding));
        drop(Vec::<u8>::from(input));
        // and return constant output
        BlobDecoderResult::from(DecoderResult::Err(InputError::DecodingError(String::from(
            "always_err",
        ))))
    }
    Decoder {
        f: lib_ruby_parser__test__always_err_decoder_fn,
    }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__some_always_ok_decoder() -> BlobMaybeDecoder {
    BlobMaybeDecoder::from(Some(lib_ruby_parser__test__always_ok_decoder()))
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__none_decoder() -> BlobMaybeDecoder {
    BlobMaybeDecoder::from(None)
}
