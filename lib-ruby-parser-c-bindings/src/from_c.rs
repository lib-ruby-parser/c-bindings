use crate::bindings::{
    size_t, DecoderOutput, DecoderOutputError, DecoderOutputSuccess,
    DecodingStatus_DECODING_STATUS_ERROR as DECODING_ERROR,
    DecodingStatus_DECODING_STATUS_OK as DECODING_OK, LexStateActionKind_LEX_STATE_ACTION_KEEP,
    LexStateActionKind_LEX_STATE_ACTION_SET, ParserOptions, Token,
    TokenRewriteAction_REWRITE_ACTION_DROP, TokenRewriteAction_REWRITE_ACTION_KEEP, TokenRewriter,
    TokenRewriterFn, TokenRewriterOutput,
};

use lib_ruby_parser::source::InputError;
use std::ffi::{c_void, CStr, CString};

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
            rewriter
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

type CTokenRerwiterState = *mut c_void;
struct CTokenRerwiter {
    state: CTokenRerwiterState,
    rewriter: TokenRewriterFn,
}

impl std::fmt::Debug for CTokenRerwiter {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        f.write_str("CTokenRerwiter")
    }
}

impl CTokenRerwiter {
    fn new(state: CTokenRerwiterState, rewriter: TokenRewriterFn) -> Box<Self> {
        Box::new(Self { state, rewriter })
    }
}

impl lib_ruby_parser::token_rewriter::TokenRewriter for CTokenRerwiter {
    fn rewrite_token(
        &mut self,
        token: lib_ruby_parser::Token,
        input: &[u8],
    ) -> (
        lib_ruby_parser::Token,
        lib_ruby_parser::token_rewriter::RewriteAction,
        lib_ruby_parser::token_rewriter::LexStateAction,
    ) {
        let rewriter = self.rewriter.unwrap();
        let TokenRewriterOutput {
            token,
            token_rewriter_action,
            lex_state_action,
        } = unsafe { rewriter(self.state, token.into(), input.as_ptr() as *const i8) };

        let token = lib_ruby_parser::Token::from(token);
        let token_rewriter_action = match token_rewriter_action {
            TokenRewriteAction_REWRITE_ACTION_DROP => {
                lib_ruby_parser::token_rewriter::RewriteAction::Drop
            }
            TokenRewriteAction_REWRITE_ACTION_KEEP => {
                lib_ruby_parser::token_rewriter::RewriteAction::Keep
            }
            _ => unreachable!(),
        };
        let lex_state_action = match lex_state_action.kind {
            LexStateActionKind_LEX_STATE_ACTION_KEEP => {
                lib_ruby_parser::token_rewriter::LexStateAction::Keep
            }
            LexStateActionKind_LEX_STATE_ACTION_SET => {
                lib_ruby_parser::token_rewriter::LexStateAction::Set(
                    unsafe { lex_state_action.value.set }.new_state,
                )
            }
            _ => unreachable!(),
        };

        (token, token_rewriter_action, lex_state_action)
    }
}

impl From<TokenRewriter> for Option<Box<dyn lib_ruby_parser::token_rewriter::TokenRewriter>> {
    fn from(rewriter: TokenRewriter) -> Self {
        let TokenRewriter { state, rewriter } = rewriter;
        Some(CTokenRerwiter::new(state, rewriter))
    }
}

impl From<Token> for lib_ruby_parser::Token {
    fn from(token: Token) -> Self {
        let Token {
            token_type,
            token_value,
            loc,
            ..
        } = token;
        let loc = unsafe { Box::from_raw(loc) };
        let token_value: String = unsafe { std::ffi::CString::from_raw(token_value) }
            .into_string()
            .unwrap();

        lib_ruby_parser::Token {
            token_type,
            token_value: lib_ruby_parser::TokenValue::String(token_value),
            loc: lib_ruby_parser::Loc {
                begin: loc.begin as usize,
                end: loc.end as usize,
            },
            lex_state_before: lib_ruby_parser::LexState::default(),
            lex_state_after: lib_ruby_parser::LexState::default(),
        }
    }
}
