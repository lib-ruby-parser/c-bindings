use crate::blob_type;
use lib_ruby_parser::source::SourceLine;

blob_type!(BlobSourceLineList, Vec<SourceLine>);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_source_line_1_2_true() -> SourceLine {
    SourceLine {
        start: 1,
        end: 2,
        ends_with_eof: true,
    }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_source_line_list() -> BlobSourceLineList {
    BlobSourceLineList::from(vec![lib_ruby_parser__test__make_source_line_1_2_true()])
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_source_line_list(source_line_list: *mut Vec<SourceLine>) {
    unsafe { std::ptr::drop_in_place(source_line_list) }
}
