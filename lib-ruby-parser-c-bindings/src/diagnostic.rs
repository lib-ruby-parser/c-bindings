use lib_ruby_parser::Diagnostic;

#[no_mangle]
pub extern "C" fn lib_ruby_parser_diagnostic_render_message(d: Diagnostic) -> *mut std::os::raw::c_char {
    let s = std::ffi::CString::new(d.render_message()).unwrap();
    std::mem::forget(d);
    s.into_raw()
}
