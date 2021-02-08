use crate::bindings;
use crate::Ptr;
use std::ffi::CStr;

impl From<Ptr<bindings::ParserOptions>> for lib_ruby_parser::ParserOptions {
    fn from(ptr: Ptr<bindings::ParserOptions>) -> Self {
        let options = ptr.unwrap();

        if options.is_null() {
            return Self::default();
        }

        let options = unsafe { *options };
        let buffer_name = unsafe { CStr::from_ptr(options.buffer_name) }
            .to_str()
            .unwrap()
            .to_owned();
        let debug = options.debug;
        let decoder = Ptr::new(options.decoder).into();
        let record_tokens = options.record_tokens;
        let token_rewriter = Ptr::new(options.token_rewriter).into();

        lib_ruby_parser::ParserOptions {
            buffer_name,
            debug,
            decoder,
            record_tokens,
            token_rewriter,
        }
    }
}
