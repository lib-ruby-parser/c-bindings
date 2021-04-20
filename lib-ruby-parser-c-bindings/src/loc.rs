use lib_ruby_parser::{
    containers::{Loc, MaybeLoc},
    source::DecodedInput,
};
use std::mem::ManuallyDrop;

#[no_mangle]
pub extern "C" fn lib_ruby_parser_loc_size(loc: ManuallyDrop<Loc>) -> u32 {
    loc.size() as u32
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_loc_source(
    loc: ManuallyDrop<Loc>,
    input: ManuallyDrop<DecodedInput>,
) -> *mut std::os::raw::c_char {
    match loc.source(&input) {
        Some(source) => std::ffi::CString::new(source).unwrap().into_raw(),
        None => std::ptr::null_mut(),
    }
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_maybe_loc_ptr_to_loc_ptr(
    maybe_loc: ManuallyDrop<MaybeLoc>,
) -> Loc {
    ManuallyDrop::into_inner(maybe_loc.clone()).unwrap()
}
