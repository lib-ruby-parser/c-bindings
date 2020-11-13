extern crate lib_ruby_parser;
use crate::bindings::*;
use crate::ptr_unptr::ptr_parser_result;
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
    ptr_parser_result(parser_result)
}
