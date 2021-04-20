use lib_ruby_parser::ParserResult;

#[no_mangle]
pub extern "C" fn lib_ruby_parser_debug_fmt_parser_result(
    parser_result: ParserResult,
) -> *mut std::os::raw::c_char {
    let ptr = std::ffi::CString::new(format!("{:#?}", parser_result))
        .unwrap()
        .into_raw();
    std::mem::forget(parser_result);
    ptr
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_display_fmt_parser_result(
    parser_result: ParserResult,
) -> *mut std::os::raw::c_char {
    let ptr = std::ffi::CString::new(format!("{:?}", parser_result))
        .unwrap()
        .into_raw();
    std::mem::forget(parser_result);
    ptr
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_free_parser_result(parser_result: ParserResult) {
    drop(parser_result)
}
