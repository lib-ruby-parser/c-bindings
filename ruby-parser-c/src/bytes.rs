use crate::blob_type;
use lib_ruby_parser::Bytes;

blob_type!(BlobByteList, Vec<u8>);
blob_type!(BlobBytes, Bytes);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_byte_list_123() -> BlobByteList {
    BlobByteList::from(vec![1, 2, 3])
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_byte_list(byte_list: *mut Vec<u8>) {
    unsafe { std::ptr::drop_in_place(byte_list) }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_bytes_123() -> BlobBytes {
    BlobBytes::from(Bytes::new(vec![1, 2, 3]))
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_bytes(bytes: *mut Bytes) {
    unsafe { std::ptr::drop_in_place(bytes) }
}
