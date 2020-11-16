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
impl fmt::Debug for bindings::Node {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        f.write_str(&unsafe { *self.inner }.to_debug_string(self.node_type))
    }
}

impl fmt::Debug for bindings::Range {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        f.debug_struct("Range")
            .field("begin_pos", &self.begin_pos)
            .field("end_pos", &self.end_pos)
            .finish()
    }
}

impl fmt::Debug for bindings::NodeList {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let nodes = unsafe { std::slice::from_raw_parts(self.list, self.len as usize) };
        f.debug_list().entries(nodes).finish()
    }
}

pub fn debug_str_ptr(ptr: *mut ::std::os::raw::c_char) -> String {
    let bytes = unsafe { std::ffi::CStr::from_ptr(ptr).to_bytes() };
    String::from_utf8_lossy(bytes).into_owned()
}

use to_c::string_to_ptr;

#[no_mangle]
pub extern "C" fn debug_fmt_ast(node: *mut bindings::Node) -> *mut i8 {
    if node.is_null() {
        return string_to_ptr("(null)".to_owned());
    }
    let node = unsafe { *node };
    string_to_ptr(format!("{:#?}", node))
}

#[no_mangle]
pub extern "C" fn token_name(id: i32) -> *mut i8 {
    let token_name = lib_ruby_parser::token_name(id);
    string_to_ptr(token_name)
}
