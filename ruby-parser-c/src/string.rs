use crate::blob_type;

blob_type!(BlobString, String);

extern "C" {
    fn lib_ruby_parser_internal_free_string(ptr: *mut u8);
}

// #[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_new_string_owned(ptr: *mut u8, len: usize) -> BlobString {
    eprintln!("Constructing string owned");

    let s = unsafe { String::from_raw_parts(ptr, len, len) };
    eprintln!("Got {:?}", s);
    BlobString::from(s)
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_new_string_from_cstr(ptr: *const i8) -> BlobString {
    eprintln!("Constructing string from cstr");

    let s = unsafe { std::ffi::CStr::from_ptr(ptr) };
    eprintln!("Got {:?}", s);
    BlobString::from(s.to_str().unwrap_or_default().to_owned())
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_string(s: *mut String) {
    let ptr = unsafe { s.as_mut().unwrap() };
    unsafe { lib_ruby_parser_internal_free_string(ptr.as_mut_ptr()) }
    // unsafe { std::ptr::drop_in_place(s) }
}
