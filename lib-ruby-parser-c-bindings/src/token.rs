use lib_ruby_parser::{token_name, Token};
use std::mem::ManuallyDrop;

#[no_mangle]
pub extern "C" fn lib_ruby_parser_token_name(token_id: i32) -> *mut std::os::raw::c_char {
    let s = std::ffi::CString::new(token_name(token_id)).unwrap();
    s.into_raw()
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_clone_token(token: ManuallyDrop<Token>) -> Token {
    ManuallyDrop::into_inner(token.clone())
}
