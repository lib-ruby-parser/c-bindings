use crate::blob_type;
#[allow(unused_imports)]
use lib_ruby_parser::Loc;

blob_type!(MaybeLocBlob, Option<Loc>);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_loc(begin: usize, end: usize) -> Loc {
    Loc { begin, end }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_none_loc() -> MaybeLocBlob {
    MaybeLocBlob::from(None)
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_some_loc(begin: usize, end: usize) -> MaybeLocBlob {
    MaybeLocBlob::from(Some(Loc { begin, end }))
}
