use lib_ruby_parser::{
    containers::{List, StringPtr},
    StringValue,
};

// make/free fns

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

// conversions

#[no_mangle]
pub extern "C" fn lib_ruby_parser_string_ptr_to_list(ptr: StringPtr) -> List<u8> {
    let list = List::from(ptr.clone());
    std::mem::forget(ptr);
    list
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_string_value_to_list(s: StringValue) -> List<u8> {
    let list = List::from(s.bytes.as_bytes());
    std::mem::forget(s);
    list
}
