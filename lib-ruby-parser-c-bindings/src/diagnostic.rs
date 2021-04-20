use lib_ruby_parser::{source::DecodedInput, Diagnostic};
use std::mem::ManuallyDrop;

#[no_mangle]
pub extern "C" fn lib_ruby_parser_diagnostic_render_message(
    diagnostic: ManuallyDrop<Diagnostic>,
) -> *mut std::os::raw::c_char {
    std::ffi::CString::new(diagnostic.render_message())
        .unwrap()
        .into_raw()
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_diagnostic_render(
    diagnostic: ManuallyDrop<Diagnostic>,
    input: ManuallyDrop<DecodedInput>,
) -> *mut std::os::raw::c_char {
    match diagnostic.render(&input) {
        Some(rendered) => std::ffi::CString::new(rendered).unwrap().into_raw(),
        None => std::ptr::null_mut(),
    }
}
