use lib_ruby_parser::{
    containers::{List, StringPtr},
    StringValue,
};
use std::mem::ManuallyDrop;

type ByteList = List<u8>;

#[no_mangle]
pub extern "C" fn lib_ruby_parser_make_byte_list(input: *const std::os::raw::c_char) -> ByteList {
    let bytes = unsafe { std::ffi::CStr::from_ptr(input) }
        .to_owned()
        .into_bytes();

    List::from(bytes)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_free_byte_list(list: ByteList) {
    drop(list)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_byte_list_from_string_ptr(
    ptr: ManuallyDrop<StringPtr>,
) -> ByteList {
    List::from(ManuallyDrop::into_inner(ptr.clone()))
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_byte_list_from_string_value(
    s: ManuallyDrop<StringValue>,
) -> ByteList {
    List::from(s.bytes.as_bytes())
}
