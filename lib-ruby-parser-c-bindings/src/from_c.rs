use crate::bindings::{
    size_t, DecoderOutput, DecoderOutputError, DecoderOutputSuccess,
    DecodingStatus_DECODING_STATUS_ERROR as DECODING_ERROR,
    DecodingStatus_DECODING_STATUS_OK as DECODING_OK, ParserOptions, TokenRewriter,
};

use lib_ruby_parser::source::InputError;
use std::ffi::{CStr, CString};

impl From<DecoderOutputError> for Result<Vec<u8>, InputError> {
    fn from(value: DecoderOutputError) -> Self {
        let error_message = unsafe { CString::from_raw(value.error_message) }
            .into_string()
            .map_err(|e| InputError::DecodingError(format!("conversion error {}", e)))?;
        Err(InputError::DecodingError(error_message))
    }
}

impl From<DecoderOutputSuccess> for Result<Vec<u8>, InputError> {
    fn from(value: DecoderOutputSuccess) -> Self {
        let bytes = unsafe {
            Vec::from_raw_parts(
                value.bytes as *mut u8,
                value.len as usize,
                value.len as usize,
            )
        };
        Ok(bytes)
    }
}

impl From<DecoderOutput> for Result<Vec<u8>, InputError> {
    fn from(output: DecoderOutput) -> Self {
        let value = output.value;

        match output.status {
            DECODING_OK => {
                let value = unsafe { value.success };
                value.into()
            }
            DECODING_ERROR => {
                let value = unsafe { value.error };
                value.into()
            }
            _ => Err(InputError::DecodingError(
                "invalid decoder output status".to_string(),
            )),
        }
    }
}

impl From<ParserOptions> for lib_ruby_parser::ParserOptions {
    fn from(options: ParserOptions) -> Self {
        let buffer_name = unsafe { CStr::from_ptr(options.buffer_name) }
            .to_str()
            .unwrap()
            .to_owned();
        let debug = options.debug;
        let decoder = match options.decoder {
            Some(decoder) => {
                let decode = move |encoding: &str, input: &[u8]| -> Result<Vec<u8>, InputError> {
                    let encoding = CString::new(encoding).unwrap();
                    let encoding_ptr = encoding.as_bytes_with_nul().as_ptr();

                    let output = unsafe {
                        decoder(
                            encoding_ptr as *const i8,
                            input.as_ptr() as *const i8,
                            input.len() as size_t,
                        )
                    };

                    let result = output.into();

                    result
                };
                lib_ruby_parser::source::CustomDecoder::new(Box::new(decode))
            }
            None => lib_ruby_parser::source::CustomDecoder::default(),
        };
        let record_tokens = options.record_tokens;
        let token_rewriter = if options.token_rewriter.is_null() {
            None
        } else {
            let rewriter = unsafe { *options.token_rewriter }.into();
            Some(rewriter)
        };

        lib_ruby_parser::ParserOptions {
            buffer_name,
            debug,
            decoder,
            record_tokens,
            token_rewriter,
        }
    }
}

impl From<TokenRewriter> for Box<dyn lib_ruby_parser::token_rewriter::TokenRewriter> {
    fn from(_: TokenRewriter) -> Self {
        todo!()
    }
}
