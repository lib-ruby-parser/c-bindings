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
mod diagnostic_message;
pub mod diagnostic_payload;
mod list;
mod loc;
mod magic_comment;
mod node;
mod node_gen;
mod parser_options;
mod parser_result;
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
pub extern "C" fn input_free(input: *mut lib_ruby_parser::source::Input) {
    drop(unsafe { Box::from_raw(input) })
}

#[no_mangle]
pub extern "C" fn input_len(input: *mut lib_ruby_parser::source::Input) -> u32 {
    if let Some(input) = unsafe { input.as_ref() } {
        input.as_bytes().len() as u32
    } else {
        0
    }
}

#[no_mangle]
pub extern "C" fn input_ptr(input: *mut lib_ruby_parser::source::Input) -> *const u8 {
    if let Some(input) = unsafe { input.as_ref() } {
        input.as_bytes().as_ptr()
    } else {
        std::ptr::null()
    }
}

#[no_mangle]
pub extern "C" fn token_name(id: i32) -> *mut i8 {
    let token_name = lib_ruby_parser::token_name(id).to_owned();
    StringPtr::from(token_name).unwrap()
}

#[no_mangle]
pub extern "C" fn diagnostic_render(
    diagnostic: bindings::Diagnostic,
    input: *mut lib_ruby_parser::source::Input,
) -> *mut i8 {
    if let Some(input) = unsafe { input.as_ref() } {
        let rendered = lib_ruby_parser::Diagnostic::from(diagnostic).render(input);
        StringPtr::from(rendered).unwrap()
    } else {
        std::ptr::null_mut()
    }
}

#[no_mangle]
pub extern "C" fn diagnostic_render_message(diagnostic: bindings::Diagnostic) -> *mut i8 {
    let rendered = lib_ruby_parser::Diagnostic::from(diagnostic).render_message();

    StringPtr::from(rendered).unwrap()
}

#[no_mangle]
pub extern "C" fn loc_source(
    loc: *mut bindings::Loc,
    input: *mut lib_ruby_parser::source::Input,
) -> *mut i8 {
    let loc = if let Some(loc) = unsafe { loc.as_ref() } {
        loc
    } else {
        return std::ptr::null_mut();
    };
    let loc = lib_ruby_parser::Loc::from(loc.to_owned());

    let input = if let Some(input) = unsafe { input.as_ref() } {
        input
    } else {
        return std::ptr::null_mut();
    };

    StringPtr::from(loc.source(input)).unwrap()
}

#[no_mangle]
pub extern "C" fn diagnostic_message_free(message: bindings::DiagnosticMessage) {
    diagnostic_message::inner_diagnostic_message_free(message);
}
