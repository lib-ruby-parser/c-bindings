#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

extern crate lib_ruby_parser;

pub mod bindings;
use bindings::{ParserOptions, ParserResult};

mod ptr;
pub(crate) use ptr::Ptr;
mod string_ptr;
pub(crate) use string_ptr::StringPtr;

mod comment;
mod custom_decoder;
mod diagnostic;
mod list;
mod magic_comment;
mod node;
mod node_gen;
mod parser_options;
mod parser_result;
mod range;
mod token;
mod token_rewriter;

#[no_mangle]
pub extern "C" fn parse(
    options: *mut ParserOptions,
    input: *const u8,
    length: usize,
) -> *const ParserResult {
    let input = unsafe { std::slice::from_raw_parts(input, length) };

    let options = lib_ruby_parser::ParserOptions::from(Ptr::new(options));
    let parser_result = lib_ruby_parser::Parser::new(input, options).do_parse();

    let parser_result = ParserResult::from(parser_result);
    ptr_value(parser_result)
}

pub fn ptr_value<T>(value: T) -> *mut T {
    Box::into_raw(Box::new(value))
}

#[no_mangle]
pub extern "C" fn token_name(id: i32) -> *mut i8 {
    let token_name = lib_ruby_parser::token_name(id).to_owned();
    StringPtr::from(token_name).unwrap()
}
