use crate::blob_type;
use std::io::{self, Write};

blob_type!(BlobString, String);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_new_string_owned(ptr: *mut u8, len: usize) -> BlobString {
    println!("Constructing string owned");
    io::stdout().flush().unwrap();

    let s = unsafe { String::from_raw_parts(ptr, len, len) };
    println!("Got {:?}", s);
    io::stdout().flush().unwrap();
    BlobString::from(s)
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_new_string_from_cstr(ptr: *const i8) -> BlobString {
    println!("Constructing string from cstr");
    io::stdout().flush().unwrap();

    let s = unsafe { std::ffi::CStr::from_ptr(ptr) };
    println!("Got {:?}", s);
    io::stdout().flush().unwrap();
    BlobString::from(s.to_str().unwrap_or_default().to_owned())
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_string(s: *mut String) {
    unsafe { std::ptr::drop_in_place(s) }
}
