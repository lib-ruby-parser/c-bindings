pub struct StringPtr {
    ptr: *mut i8,
}

impl StringPtr {
    pub fn unwrap(self) -> *mut i8 {
        self.ptr
    }
}

impl From<String> for StringPtr {
    fn from(s: String) -> Self {
        Self {
            ptr: string_to_ptr(s),
        }
    }
}

impl From<Option<String>> for StringPtr {
    fn from(maybe_s: Option<String>) -> Self {
        if let Some(s) = maybe_s {
            StringPtr::from(s)
        } else {
            StringPtr {
                ptr: std::ptr::null_mut(),
            }
        }
    }
}

impl From<Vec<char>> for StringPtr {
    fn from(chars: Vec<char>) -> Self {
        StringPtr::from(chars.iter().collect::<String>())
    }
}

impl From<lib_ruby_parser::StringValue> for StringPtr {
    fn from(string_value: lib_ruby_parser::StringValue) -> Self {
        let mut str_bytes = string_value.bytes.raw;
        str_bytes.push(0);
        Self {
            ptr: vec_to_ptr(str_bytes),
        }
    }
}

pub fn string_to_ptr(s: String) -> *mut i8 {
    let mut bytes = std::ffi::CString::new(s).unwrap().into_bytes_with_nul();
    let ptr = bytes.as_mut_ptr();
    std::mem::forget(bytes);
    ptr as *mut i8
}

fn vec_to_ptr(vec: Vec<u8>) -> *mut i8 {
    let mut boxed_slice = vec.into_boxed_slice();
    let ptr = boxed_slice.as_mut_ptr();
    std::mem::forget(boxed_slice);
    ptr as *mut i8
}
