use lib_ruby_parser::token_name;

#[no_mangle]
pub extern "C" fn lib_ruby_parser_token_name(token_id: i32) -> *mut std::os::raw::c_char {
    std::ffi::CString::new(token_name(token_id))
        .unwrap()
        .into_raw()
}
