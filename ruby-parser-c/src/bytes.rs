use crate::blob_type;
use lib_ruby_parser::Bytes;

blob_type!(ByteListBlob, Vec<u8>);
blob_type!(BytesBlob, Bytes);

#[cfg(test)]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_byte_list(i1: u8, i2: u8, i3: u8) -> ByteListBlob {
    let mut v = vec![i1, i2, i3];
    v.reserve(10);
    ByteListBlob::from(v)
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_byte_list(byte_list: *mut Vec<u8>) {
    unsafe { std::ptr::drop_in_place(byte_list) }
}

#[cfg(test)]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_bytes(i1: u8, i2: u8, i3: u8) -> BytesBlob {
    BytesBlob::from(Bytes::new(vec![i1, i2, i3]))
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_bytes(bytes: *mut Bytes) {
    unsafe { std::ptr::drop_in_place(bytes) }
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_new_bytes_owned(ptr: *mut u8, len: usize) -> ByteListBlob {
    let v = unsafe { Vec::from_raw_parts(ptr, len, len) };
    ByteListBlob::from(v)
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_new_bytes_from_cstr(ptr: *const u8, len: usize) -> ByteListBlob {
    let slice = unsafe { std::slice::from_raw_parts(ptr, len) };
    ByteListBlob::from(slice.to_owned())
}
