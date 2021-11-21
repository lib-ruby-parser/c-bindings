extern crate lib_ruby_parser;

#[macro_export]
macro_rules! blob_type {
    ($c_type:ident, $rust_type:ty) => {
        #[repr(C)]
        #[derive(Debug)]
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

mod bytes;

mod loc;

mod token;

mod source_line;

mod comment;

mod shared_byte_list;

mod magic_comment;

mod decoder;
pub use decoder::Decoder;

mod token_rewriter;
pub use token_rewriter::TokenRewriter;

mod parser_options;

mod message;
mod node;

mod diagnostic;

mod parser_result;

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
