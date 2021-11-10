extern crate lib_ruby_parser;

use lib_ruby_parser::{DiagnosticMessage, Parser, ParserOptions, ParserResult, Token};

#[macro_export]
macro_rules! blob_type {
    ($c_type:ident, $rust_type:ty) => {
        #[repr(C)]
        pub struct $c_type {
            content: [u8; std::mem::size_of::<$rust_type>()],
        }

        impl From<$rust_type> for $c_type {
            fn from(rust: $rust_type) -> $c_type {
                unsafe { std::mem::transmute(rust) }
            }
        }

        impl From<$c_type> for $rust_type {
            fn from(c: $c_type) -> $rust_type {
                unsafe { std::mem::transmute(c) }
            }
        }
    };
}

mod string;
use string::BlobString;

blob_type!(BlobVecU8, Vec<u8>);
blob_type!(BlobParserOptions, ParserOptions);
blob_type!(BlobParserResult, ParserResult);

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_parse(
    options: BlobParserOptions,
    input: BlobVecU8,
) -> BlobParserResult {
    let options: ParserOptions = options.into();
    let input: Vec<u8> = input.into();
    let result = Parser::new(input, options).do_parse();
    result.into()
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser__token_name(token: *const Token) -> BlobString {
    let token = unsafe { (token as *const Token).as_ref().unwrap() };
    let token_name = String::from(token.token_name());
    token_name.into()
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser__render_diagnostic_message(
    message: *const DiagnosticMessage,
) -> BlobString {
    let message = unsafe { (message as *const DiagnosticMessage).as_ref().unwrap() };
    let rendered = String::from(message.render());
    rendered.into()
}
