use crate::blob_type;
use crate::{Decoder, TokenRewriter};

#[repr(C)]
pub struct CParserOptions {
    buffer_name: String,
    decoder: Option<Decoder>,
    token_rewriter: Option<TokenRewriter>,
    record_tokens: bool,
}
blob_type!(ParserOptionsBlob, CParserOptions);

impl From<CParserOptions> for lib_ruby_parser::ParserOptions {
    fn from(options: CParserOptions) -> Self {
        let CParserOptions {
            buffer_name,
            decoder,
            token_rewriter,
            record_tokens,
        } = options;

        let decoder = decoder.map(|decoder| {
            lib_ruby_parser::source::Decoder::new(Box::new(move |encoding, input| {
                (decoder.f)(encoding.into(), input.into()).into()
            }))
        });

        let token_rewriter = token_rewriter.map(|token_rewriter| {
            lib_ruby_parser::source::token_rewriter::TokenRewriter::new(Box::new(
                move |token, input| {
                    let input: &'static [u8] = unsafe { std::mem::transmute(input) };
                    (token_rewriter.f)(Box::leak(token), input.into())
                },
            ))
        });

        lib_ruby_parser::ParserOptions {
            buffer_name,
            decoder,
            token_rewriter,
            record_tokens,
        }
    }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_parser_options() -> ParserOptionsBlob {
    ParserOptionsBlob::from(CParserOptions {
        buffer_name: String::from("(eval)"),
        decoder: None,
        token_rewriter: None,
        record_tokens: true,
    })
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_parser_options(parser_options: *mut CParserOptions) {
    unsafe { std::ptr::drop_in_place(parser_options) }
}
