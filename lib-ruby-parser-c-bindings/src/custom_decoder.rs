use crate::bindings;
use crate::Ptr;

type CustomState = *mut std::ffi::c_void;

struct CCustomDecoder {
    state: CustomState,
    f: bindings::CustomDecoderFn,
}

impl std::fmt::Debug for CCustomDecoder {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        f.debug_struct("CCustomDecoder").finish()
    }
}

impl lib_ruby_parser::source::CustomDecoder for CCustomDecoder {
    fn decode(
        &self,
        encoding: &str,
        input: &[u8],
    ) -> Result<Vec<u8>, lib_ruby_parser::source::InputError> {
        let f = self.f.as_ref().unwrap();

        let encoding = std::ffi::CString::new(encoding).unwrap();
        let encoding_ptr = encoding.as_bytes_with_nul().as_ptr();

        let output = unsafe {
            f(
                self.state,
                encoding_ptr as *const i8,
                input.as_ptr() as *const i8,
                input.len() as u32,
            )
        };

        output.into()
    }
}

impl CCustomDecoder {
    fn new(state: CustomState, f: bindings::CustomDecoderFn) -> Self {
        Self { state, f }
    }
}

impl From<Ptr<bindings::CustomDecoder>>
    for Option<Box<dyn lib_ruby_parser::source::CustomDecoder>>
{
    fn from(ptr: Ptr<bindings::CustomDecoder>) -> Self {
        let custom_decoder = ptr.unwrap();

        if custom_decoder.is_null() {
            return None;
        }

        let bindings::CustomDecoder { state, decoder } = unsafe { *custom_decoder };

        Some(Box::new(CCustomDecoder::new(state, decoder)))
    }
}

impl From<bindings::DecoderOutputError> for Result<Vec<u8>, lib_ruby_parser::source::InputError> {
    fn from(value: bindings::DecoderOutputError) -> Self {
        let error_message = unsafe { std::ffi::CString::from_raw(value.error_message) }
            .into_string()
            .map_err(|e| {
                lib_ruby_parser::source::InputError::DecodingError(format!(
                    "conversion error {}",
                    e
                ))
            })?;
        Err(lib_ruby_parser::source::InputError::DecodingError(
            error_message,
        ))
    }
}

impl From<bindings::DecoderOutputSuccess> for Result<Vec<u8>, lib_ruby_parser::source::InputError> {
    fn from(value: bindings::DecoderOutputSuccess) -> Self {
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

impl From<bindings::DecoderOutput> for Result<Vec<u8>, lib_ruby_parser::source::InputError> {
    fn from(output: bindings::DecoderOutput) -> Self {
        let value = output.value;

        match output.status {
            bindings::DecodingStatus::DECODING_STATUS_OK => {
                let value = unsafe { value.success };
                value.into()
            }
            bindings::DecodingStatus::DECODING_STATUS_ERROR => {
                let value = unsafe { value.error };
                value.into()
            }
        }
    }
}
