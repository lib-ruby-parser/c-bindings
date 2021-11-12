use crate::blob_type;
use lib_ruby_parser::source::SourceLine;

blob_type!(BlobSourceLineList, Vec<SourceLine>);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_source_line(
    start: usize,
    end: usize,
    ends_with_eof: bool,
) -> SourceLine {
    SourceLine {
        start,
        end,
        ends_with_eof,
    }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_source_line_list(
    source_line: SourceLine,
) -> BlobSourceLineList {
    BlobSourceLineList::from(vec![source_line])
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_source_line_list(source_line_list: *mut Vec<SourceLine>) {
    unsafe { std::ptr::drop_in_place(source_line_list) }
}
