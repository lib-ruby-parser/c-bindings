use lib_ruby_parser::{source::DecodedInput, Diagnostic};

#[no_mangle]
pub extern "C" fn lib_ruby_parser_diagnostic_render_message(
    diagnostic: Diagnostic,
) -> *mut std::os::raw::c_char {
    let ptr = std::ffi::CString::new(diagnostic.render_message())
        .unwrap()
        .into_raw();
    std::mem::forget(diagnostic);
    ptr
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_diagnostic_render(
    diagnostic: Diagnostic,
    input: DecodedInput,
) -> *mut std::os::raw::c_char {
    let ptr = match diagnostic.render(&input) {
        Some(rendered) => std::ffi::CString::new(rendered).unwrap().into_raw(),
        None => std::ptr::null_mut(),
    };
    std::mem::forget(input);
    ptr
}
