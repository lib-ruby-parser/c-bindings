use lib_ruby_parser::{
    c_parse::ForeignParserOptions,
    containers::{List, StringPtr},
    source::{Comment, MagicComment},
    Diagnostic, Loc, Node, ParserResult, Token,
};
use std::mem::ManuallyDrop;

fn singleline_fmt<T: std::fmt::Debug>(t: ManuallyDrop<T>) -> *mut std::os::raw::c_char {
    std::ffi::CString::new(format!("{:?}", *t))
        .unwrap()
        .into_raw()
}

fn miltiline_fmt<T: std::fmt::Debug>(t: ManuallyDrop<T>) -> *mut std::os::raw::c_char {
    std::ffi::CString::new(format!("{:#?}", *t))
        .unwrap()
        .into_raw()
}

// ParserOptions
#[no_mangle]
pub extern "C" fn lib_ruby_parser_singleline_fmt_parser_options(
    parser_options: ManuallyDrop<ForeignParserOptions>,
) -> *mut std::os::raw::c_char {
    singleline_fmt(parser_options)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_multiline_fmt_parser_options(
    parser_options: ManuallyDrop<ForeignParserOptions>,
) -> *mut std::os::raw::c_char {
    miltiline_fmt(parser_options)
}

// ParserResult
#[no_mangle]
pub extern "C" fn lib_ruby_parser_singleline_fmt_parser_result(
    parser_result: ManuallyDrop<ParserResult>,
) -> *mut std::os::raw::c_char {
    singleline_fmt(parser_result)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_multiline_fmt_parser_result(
    parser_result: ManuallyDrop<ParserResult>,
) -> *mut std::os::raw::c_char {
    miltiline_fmt(parser_result)
}

// Node
#[no_mangle]
pub extern "C" fn lib_ruby_parser_singleline_fmt_node(
    node: ManuallyDrop<Node>,
) -> *mut std::os::raw::c_char {
    singleline_fmt(node)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_multiline_fmt_node(
    node: ManuallyDrop<Node>,
) -> *mut std::os::raw::c_char {
    miltiline_fmt(node)
}

// Token
#[no_mangle]
pub extern "C" fn lib_ruby_parser_singleline_fmt_token(
    token: ManuallyDrop<Token>,
) -> *mut std::os::raw::c_char {
    singleline_fmt(token)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_multiline_fmt_token(
    token: ManuallyDrop<Token>,
) -> *mut std::os::raw::c_char {
    miltiline_fmt(token)
}

// Diagnostic
#[no_mangle]
pub extern "C" fn lib_ruby_parser_singleline_fmt_diagnostic(
    diagnostic: ManuallyDrop<Diagnostic>,
) -> *mut std::os::raw::c_char {
    singleline_fmt(diagnostic)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_multiline_fmt_diagnostic(
    diagnostic: ManuallyDrop<Diagnostic>,
) -> *mut std::os::raw::c_char {
    miltiline_fmt(diagnostic)
}

// Comment
#[no_mangle]
pub extern "C" fn lib_ruby_parser_singleline_fmt_comment(
    comment: ManuallyDrop<Comment>,
) -> *mut std::os::raw::c_char {
    singleline_fmt(comment)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_multiline_fmt_comment(
    comment: ManuallyDrop<Comment>,
) -> *mut std::os::raw::c_char {
    miltiline_fmt(comment)
}

// MagicComment
#[no_mangle]
pub extern "C" fn lib_ruby_parser_singleline_fmt_magic_comment(
    magic_comment: ManuallyDrop<MagicComment>,
) -> *mut std::os::raw::c_char {
    singleline_fmt(magic_comment)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_multiline_fmt_magic_comment(
    magic_comment: ManuallyDrop<MagicComment>,
) -> *mut std::os::raw::c_char {
    miltiline_fmt(magic_comment)
}

// Loc
#[no_mangle]
pub extern "C" fn lib_ruby_parser_singleline_fmt_loc(
    loc: ManuallyDrop<Loc>,
) -> *mut std::os::raw::c_char {
    singleline_fmt(loc)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_multiline_fmt_loc(
    loc: ManuallyDrop<Loc>,
) -> *mut std::os::raw::c_char {
    miltiline_fmt(loc)
}

// ByteList
#[no_mangle]
pub extern "C" fn lib_ruby_parser_singleline_fmt_byte_list(
    byte_list: ManuallyDrop<List<u8>>,
) -> *mut std::os::raw::c_char {
    singleline_fmt(byte_list)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_multiline_fmt_byte_list(
    byte_list: ManuallyDrop<List<u8>>,
) -> *mut std::os::raw::c_char {
    miltiline_fmt(byte_list)
}

// StringPtr
#[no_mangle]
pub extern "C" fn lib_ruby_parser_singleline_fmt_string_ptr(
    string_ptr: ManuallyDrop<StringPtr>,
) -> *mut std::os::raw::c_char {
    singleline_fmt(string_ptr)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_multiline_fmt_string_ptr(
    string_ptr: ManuallyDrop<StringPtr>,
) -> *mut std::os::raw::c_char {
    miltiline_fmt(string_ptr)
}
