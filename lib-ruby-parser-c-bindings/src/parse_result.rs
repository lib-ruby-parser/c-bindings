use crate::bindings::*;
use crate::ptr_unptr::{
    ptr_comments, ptr_diagnostics, ptr_magic_comments, ptr_node, ptr_tokens, unptr_parser_result,
};
use std::ffi::CString;

fn unwrap_parser_result_ptr(
    ptr: *mut ParserResult,
) -> Option<&'static mut lib_ruby_parser::ParserResult> {
    if ptr.is_null() {
        return None;
    }
    let data = unptr_parser_result(ptr);
    Some(Box::leak(data))
}

#[no_mangle]
pub extern "C" fn debug_format_parser_result(parser_result: *mut ParserResult) -> *mut u8 {
    match unwrap_parser_result_ptr(parser_result) {
        Some(data) => {
            let mut bytes = CString::new(format!("{:#?}", data))
                .unwrap()
                .into_bytes_with_nul();
            let ptr = bytes.as_mut_ptr();
            std::mem::forget(bytes);
            ptr
        }
        None => std::ptr::null_mut(),
    }
}

#[no_mangle]
pub extern "C" fn extract_ast(parser_result: *mut ParserResult) -> *mut Node {
    if let Some(data) = unwrap_parser_result_ptr(parser_result) {
        match std::mem::take(&mut data.ast) {
            Some(ast) => ptr_node(ast),
            None => std::ptr::null_mut(),
        }
    } else {
        std::ptr::null_mut()
    }
}

#[no_mangle]
pub extern "C" fn extract_tokens(parser_result: *mut ParserResult) -> *mut Tokens {
    match unwrap_parser_result_ptr(parser_result) {
        Some(data) => ptr_tokens(std::mem::take(&mut data.tokens)),
        None => std::ptr::null_mut(),
    }
}

#[no_mangle]
pub extern "C" fn extract_diagnostics(parser_result: *mut ParserResult) -> *mut Diagnostics {
    match unwrap_parser_result_ptr(parser_result) {
        Some(data) => ptr_diagnostics(std::mem::take(&mut data.diagnostics)),
        None => std::ptr::null_mut(),
    }
}

#[no_mangle]
pub extern "C" fn extract_comments(parser_result: *mut ParserResult) -> *mut Comments {
    match unwrap_parser_result_ptr(parser_result) {
        Some(data) => ptr_comments(std::mem::take(&mut data.comments)),
        None => std::ptr::null_mut(),
    }
}

#[no_mangle]
pub extern "C" fn extract_magic_comments(parser_result: *mut ParserResult) -> *mut MagicComments {
    match unwrap_parser_result_ptr(parser_result) {
        Some(data) => ptr_magic_comments(std::mem::take(&mut data.magic_comments)),
        None => std::ptr::null_mut(),
    }
}
