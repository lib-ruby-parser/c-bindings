use crate::blob_type;

blob_type!(BlobString, String);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_string_foo() -> BlobString {
    BlobString::from(String::from("foo"))
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_string(s: *mut String) {
    unsafe { std::ptr::drop_in_place(s) }
}
