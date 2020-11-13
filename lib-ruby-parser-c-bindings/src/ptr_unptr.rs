use crate::bindings::*;

pub fn ptr_value<T>(value: T) -> *mut T {
    Box::into_raw(Box::new(value))
}

pub fn ptr_parser_result(parser_result: lib_ruby_parser::ParserResult) -> *mut ParserResult {
    ptr_value(parser_result) as *mut ParserResult
}

pub fn unptr_parser_result(
    parser_result_ptr: *mut ParserResult,
) -> Box<lib_ruby_parser::ParserResult> {
    unsafe { Box::from_raw(parser_result_ptr as *mut lib_ruby_parser::ParserResult) }
}

pub fn ptr_node(node: lib_ruby_parser::Node) -> *mut Node {
    ptr_value(node) as *mut Node
}

pub fn unptr_node(node_ptr: *mut Node) -> Box<lib_ruby_parser::Node> {
    unsafe { Box::from_raw(node_ptr as *mut lib_ruby_parser::Node) }
}

pub fn ptr_tokens(tokens: Vec<lib_ruby_parser::Token>) -> *mut Tokens {
    ptr_value(tokens) as *mut Tokens
}

pub fn unptr_tokens(tokens_ptr: *mut Tokens) -> Box<Vec<lib_ruby_parser::Token>> {
    unsafe { Box::from_raw(tokens_ptr as *mut Vec<lib_ruby_parser::Token>) }
}

pub fn ptr_comments(comments: Vec<lib_ruby_parser::source::Comment>) -> *mut Comments {
    ptr_value(comments) as *mut Comments
}

pub fn unptr_comments(comments_ptr: *mut Comments) -> Box<Vec<lib_ruby_parser::source::Comment>> {
    unsafe { Box::from_raw(comments_ptr as *mut Vec<lib_ruby_parser::source::Comment>) }
}

pub fn ptr_magic_comments(
    magic_comments: Vec<lib_ruby_parser::source::MagicComment>,
) -> *mut MagicComments {
    ptr_value(magic_comments) as *mut MagicComments
}

pub fn unptr_magic_comments(
    magic_comments_ptr: *mut MagicComments,
) -> Box<Vec<lib_ruby_parser::source::MagicComment>> {
    unsafe { Box::from_raw(magic_comments_ptr as *mut Vec<lib_ruby_parser::source::MagicComment>) }
}

pub fn ptr_diagnostics(diagnostics: Vec<lib_ruby_parser::Diagnostic>) -> *mut Diagnostics {
    ptr_value(diagnostics) as *mut Diagnostics
}

pub fn unptr_diagnostics(
    diagnostics_ptr: *mut Diagnostics,
) -> Box<Vec<lib_ruby_parser::Diagnostic>> {
    unsafe { Box::from_raw(diagnostics_ptr as *mut Vec<lib_ruby_parser::Diagnostic>) }
}
