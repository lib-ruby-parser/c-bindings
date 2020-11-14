use crate::bindings::*;
use std::ffi::CString;

fn range_ptr_to_ref(range: *mut Range) -> &'static mut lib_ruby_parser::source::Range {
    Box::leak(unsafe { Box::from_raw(range as *mut lib_ruby_parser::source::Range) })
}

#[no_mangle]
pub extern "C" fn range_begin(range: *mut Range) -> size_t {
    range_ptr_to_ref(range).begin_pos as size_t
}

#[no_mangle]
pub extern "C" fn range_end(range: *mut Range) -> size_t {
    range_ptr_to_ref(range).end_pos as size_t
}

#[no_mangle]
pub extern "C" fn range_source(range: *mut Range) -> *mut u8 {
    match range_ptr_to_ref(range).source() {
        Some(source) => {
            let mut bytes = CString::new(source).unwrap().into_bytes_with_nul();
            let ptr = bytes.as_mut_ptr();
            std::mem::forget(bytes);
            ptr
        }
        None => std::ptr::null_mut(),
    }
}
