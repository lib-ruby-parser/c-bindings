#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

extern crate lib_ruby_parser;

pub mod bindings;

mod ptr_unptr;

mod parse;
pub use parse::parse;

mod parse_result;
pub use parse_result::*;

mod free;

mod node;

pub fn leak_value<T>(value: T) -> &'static T {
    Box::leak(Box::new(value))
}
