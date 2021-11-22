use crate::blob_type;
use lib_ruby_parser::source::DecodedInput;
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

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_loc_source(
    loc: *const Loc,
    input: *const DecodedInput,
) -> *mut i8 {
    let loc = unsafe { loc.as_ref().unwrap() };
    let input = unsafe { input.as_ref().unwrap() };
    let source = loc.source(input).unwrap();
    std::ffi::CString::new(source).unwrap().into_raw()
}
