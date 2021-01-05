#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

extern crate lib_ruby_parser;

pub mod bindings;
use bindings::{ParserOptions, ParserResult};

mod from_c;

use std::slice;

#[no_mangle]
pub extern "C" fn parse(
    options: *const ParserOptions,
    input: *const u8,
    length: usize,
) -> *const ParserResult {
    let input = unsafe { slice::from_raw_parts(input, length) };

    let options = if options.is_null() {
        lib_ruby_parser::ParserOptions::default()
    } else {
        lib_ruby_parser::ParserOptions::from(unsafe { *options })
    };
    let parser_result = lib_ruby_parser::Parser::new(input, options).do_parse();

    let parser_result = ParserResult::from(parser_result);
    ptr_value(parser_result)
}

mod node_gen;
mod to_c;
pub use to_c::StringPtr;

pub fn ptr_value<T>(value: T) -> *mut T {
    Box::into_raw(Box::new(value))
}

use std::fmt;
impl fmt::Debug for bindings::DecoderOutput {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self.status {
            bindings::DecodingStatus_DECODING_STATUS_OK => {
                let value = unsafe { self.value.success };
                f.write_fmt(format_args!("DecoderOutput({:?})", value))
            }
            bindings::DecodingStatus_DECODING_STATUS_ERROR => {
                let value = unsafe { self.value.error };
                f.write_fmt(format_args!("DecoderOutput({:?})", value))
            }
            _ => panic!("bug"),
        }
    }
}

pub fn debug_str_ptr(ptr: *mut ::std::os::raw::c_char) -> String {
    let bytes = unsafe { std::ffi::CStr::from_ptr(ptr).to_bytes() };
    String::from_utf8_lossy(bytes).into_owned()
}

use to_c::string_to_ptr;

#[no_mangle]
pub extern "C" fn token_name(id: i32) -> *mut i8 {
    let token_name = lib_ruby_parser::token_name(id).to_owned();
    string_to_ptr(token_name)
}
