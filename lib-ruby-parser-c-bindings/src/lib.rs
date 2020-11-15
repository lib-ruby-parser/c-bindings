#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

extern crate lib_ruby_parser;

pub mod bindings;
use bindings::ParserResult;

use std::slice;

#[no_mangle]
pub extern "C" fn parse(input: *const u8, length: usize) -> *const ParserResult {
    let input = unsafe { slice::from_raw_parts(input, length) };
    let options = lib_ruby_parser::ParserOptions {
        ..Default::default()
    };
    let parser_result = lib_ruby_parser::Parser::new(input, options)
        .unwrap()
        .do_parse();

    let parser_result = ParserResult::from(parser_result);
    ptr_value(parser_result)
}

mod node_gen;
mod to_c;
pub use to_c::StringPtr;

pub fn ptr_value<T>(value: T) -> *mut T {
    Box::into_raw(Box::new(value))
}
