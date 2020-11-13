use crate::bindings::*;
use crate::ptr_unptr::unptr_node;
use std::ffi::CString;

#[no_mangle]
pub extern "C" fn inspect_node(ast: *mut Node) -> *mut u8 {
    let ast = unptr_node(ast);
    let mut bytes = CString::new(ast.inspect(0)).unwrap().into_bytes_with_nul();
    let ptr = bytes.as_mut_ptr();
    std::mem::forget(bytes);
    std::mem::forget(ast);
    ptr
}
