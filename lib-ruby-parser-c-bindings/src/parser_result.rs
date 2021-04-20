use lib_ruby_parser::ParserResult;
use std::mem::ManuallyDrop;

#[no_mangle]
pub extern "C" fn lib_ruby_parser_debug_fmt_parser_result(
    parser_result: ManuallyDrop<ParserResult>,
) -> *mut std::os::raw::c_char {
    std::ffi::CString::new(format!("{:#?}", *parser_result))
        .unwrap()
        .into_raw()
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_display_fmt_parser_result(
    parser_result: ManuallyDrop<ParserResult>,
) -> *mut std::os::raw::c_char {
    std::ffi::CString::new(format!("{:?}", *parser_result))
        .unwrap()
        .into_raw()
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_free_parser_result(parser_result: ParserResult) {
    drop(parser_result)
}
