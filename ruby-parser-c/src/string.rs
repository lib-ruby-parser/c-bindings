use crate::blob_type;

blob_type!(BlobString, String);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_new_string(ptr: *const i8) -> BlobString {
    let s = unsafe { std::ffi::CStr::from_ptr(ptr) }
        .to_str()
        .unwrap_or_else(|_e| "");
    BlobString::from(s.to_owned())
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_string(s: *mut String) {
    unsafe { std::ptr::drop_in_place(s) }
}
