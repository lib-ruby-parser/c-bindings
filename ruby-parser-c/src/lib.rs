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

#[cfg(feature = "use_external_allocator")]
mod external_allocator;

mod string;
use string::BlobString;

mod bytes;
use bytes::BlobByteList;

mod loc;

mod token;

mod source_line;

mod comment;

mod shared_byte_list;

mod magic_comment;

blob_type!(BlobParserOptions, ParserOptions);
blob_type!(BlobParserResult, ParserResult);

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_parse(
    options: BlobParserOptions,
    input: BlobByteList,
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

#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__print_build_info() {
    eprintln!(
        "Rust build info:
sizeof(usize) = {}
sizeof(void*) = {}
",
        std::mem::size_of::<usize>(),
        std::mem::size_of::<*mut std::ffi::c_void>()
    );
}
