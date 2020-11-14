use crate::bindings::*;
use crate::ptr_unptr::{ptr_value, unptr_node};
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

#[no_mangle]
pub extern "C" fn get_list_item(list: *mut NodeList, at: usize) -> *mut Node {
    let list = unsafe { *list };
    let mut list = unsafe {
        Vec::from_raw_parts(
            list.head as *mut lib_ruby_parser::Node,
            list.length as usize,
            list.capacity as usize,
        )
    };
    let item = list.get_mut(at).unwrap();

    let ptr: *mut lib_ruby_parser::Node = item;
    std::mem::forget(list);
    ptr as *mut Node
}

pub mod helpers {
    use super::*;

    pub fn node_ptr_to_node_ref(node_ptr: *mut Node) -> &'static mut lib_ruby_parser::Node {
        Box::leak(unptr_node(node_ptr))
    }

    pub fn boxed_node_to_ptr(node: &mut Box<lib_ruby_parser::Node>) -> *mut Node {
        let ptr: *mut lib_ruby_parser::Node = &mut **node;
        ptr as *mut Node
    }

    pub fn maybe_boxed_node_to_ptr(node: &mut Option<Box<lib_ruby_parser::Node>>) -> *mut Node {
        match node {
            Some(node) => boxed_node_to_ptr(node),
            None => std::ptr::null_mut(),
        }
    }

    pub fn nodes_vec_to_ptr(vec: &mut Vec<lib_ruby_parser::Node>) -> *mut NodeList {
        let length = vec.len() as size_t;
        let capacity = vec.capacity() as size_t;
        let head = vec.as_mut_ptr() as *mut Node;
        ptr_value(NodeList {
            length,
            capacity,
            head,
        })
    }

    pub fn range_to_ptr(range: &mut lib_ruby_parser::source::Range) -> *mut Range {
        let ptr: *mut lib_ruby_parser::source::Range = &mut *range;
        ptr as *mut Range
    }

    pub fn maybe_range_to_ptr(
        maybe_range: &mut Option<lib_ruby_parser::source::Range>,
    ) -> *mut Range {
        match maybe_range {
            Some(range) => range_to_ptr(range),
            None => std::ptr::null_mut(),
        }
    }

    pub fn str_to_ptr(s: &mut String) -> *mut u8 {
        s.as_mut_ptr()
    }

    pub fn maybe_str_to_ptr(s: &mut Option<String>) -> *mut u8 {
        match s {
            Some(s) => str_to_ptr(s),
            None => std::ptr::null_mut(),
        }
    }

    pub fn string_value_to_ptr(s: &mut lib_ruby_parser::StringValue) -> *mut u8 {
        s.bytes.as_mut_ptr()
    }

    pub fn chars_to_ptr(chars: &mut Vec<char>) -> *mut u8 {
        chars.as_mut_ptr() as *mut u8
    }

    pub fn nodes_vec_len<T>(vec: &mut Vec<T>) -> size_t {
        vec.len() as size_t
    }

    pub fn u8_to_size_t(v: &mut u8) -> size_t {
        *v as size_t
    }
}
