use lib_ruby_parser::containers::StringPtr;

#[no_mangle]
pub extern "C" fn lib_ruby_parser_make_string_ptr(input: *const std::os::raw::c_char) -> StringPtr {
    let bytes = unsafe { std::ffi::CStr::from_ptr(input) }
        .to_owned()
        .into_bytes();

    StringPtr::from(bytes)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_free_string_ptr(ptr: StringPtr) {
    drop(ptr)
}
