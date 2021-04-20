use lib_ruby_parser::{
    containers::{Loc, MaybeLoc},
    source::DecodedInput,
};

#[no_mangle]
pub extern "C" fn lib_ruby_parser_loc_size(loc: Loc) -> u32 {
    let size = loc.size() as u32;
    std::mem::forget(loc);
    size
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_loc_source(
    loc: Loc,
    input: DecodedInput,
) -> *mut std::os::raw::c_char {
    let source = loc.source(&input);
    let mut source_ptr = std::ptr::null_mut();

    if let Some(source) = source {
        source_ptr = std::ffi::CString::new(source).unwrap().into_raw();
    }

    std::mem::forget(loc);
    std::mem::forget(input);

    source_ptr
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_maybe_loc_ptr_to_loc_ptr(maybe_loc: MaybeLoc) -> Loc {
    let loc = maybe_loc.clone().unwrap();
    std::mem::forget(maybe_loc);
    loc
}
