use crate::blob_type;

blob_type!(BlobSharedByteList, &'static [u8]);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_shared_byte_list_foo() -> BlobSharedByteList {
    const FOO: &str = "foo";

    BlobSharedByteList::from(FOO.as_bytes())
}
