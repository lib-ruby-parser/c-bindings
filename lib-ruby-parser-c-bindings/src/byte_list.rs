use lib_ruby_parser::{
    containers::{List, StringPtr},
    StringValue,
};
use std::mem::ManuallyDrop;

#[no_mangle]
pub extern "C" fn lib_ruby_parser_make_byte_list(input: *const std::os::raw::c_char) -> List<u8> {
    let bytes = unsafe { std::ffi::CStr::from_ptr(input) }
        .to_owned()
        .into_bytes();

    List::from(bytes)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_free_byte_list(list: List<u8>) {
    drop(list)
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_byte_list_from_string_ptr(
    ptr: ManuallyDrop<StringPtr>,
) -> List<u8> {
    List::from(ManuallyDrop::into_inner(ptr.clone()))
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_byte_list_from_string_value(
    s: ManuallyDrop<StringValue>,
) -> List<u8> {
    List::from(s.bytes.as_bytes())
}
