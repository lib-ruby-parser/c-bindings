use crate::blob_type;

blob_type!(SharedByteListBlob, &'static [u8]);

#[cfg(test)]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_shared_byte_list_foo() -> SharedByteListBlob {
    const FOO: &str = "foo";

    SharedByteListBlob::from(FOO.as_bytes())
}
