#![feature(allocator_api)]

extern crate lib_ruby_parser;

mod allocator;
mod byte_list;
mod diagnostic;
mod loc;
mod parser_options;
mod parser_result;
mod string_ptr;
mod token;

use lib_ruby_parser::c_parse::ForeignParserOptions;
use lib_ruby_parser::{containers::List, Parser, ParserOptions, ParserResult};

#[no_mangle]
pub extern "C" fn lib_ruby_parser_parse(
    input: List<u8>,
    options: ForeignParserOptions,
) -> ParserResult {
    let options = ParserOptions::from(options);
    Parser::new(input, options).do_parse()
}
