use crate::blob_type;

blob_type!(BlobString, String);
blob_type!(BlobMaybeString, Option<String>);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_new_string_owned(ptr: *mut u8, len: usize) -> BlobString {
    let s = unsafe { String::from_raw_parts(ptr, len, len) };
    BlobString::from(s)
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_new_string_from_cstr(ptr: *const i8) -> BlobString {
    let s = unsafe { std::ffi::CStr::from_ptr(ptr) };
    BlobString::from(s.to_str().unwrap_or_default().to_owned())
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_string_foo() -> BlobString {
    BlobString::from(String::from("foo"))
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_string(s: *mut String) {
    unsafe { std::ptr::drop_in_place(s) }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_some_string_foo() -> BlobMaybeString {
    BlobMaybeString::from(Some(String::from("foo")))
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_none_string() -> BlobMaybeString {
    BlobMaybeString::from(None)
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_maybe_string(maybe_string: *mut Option<String>) {
    unsafe { std::ptr::drop_in_place(maybe_string) }
}
