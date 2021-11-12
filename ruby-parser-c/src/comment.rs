use crate::blob_type;
#[allow(unused_imports)]
use lib_ruby_parser::{
    source::{Comment, CommentType},
    Loc,
};

blob_type!(BlobCommentList, Vec<Comment>);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_comment_type_document() -> CommentType {
    CommentType::Document
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_comment_type_inline() -> CommentType {
    CommentType::Inline
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_comment_type_unknown() -> CommentType {
    CommentType::Unknown
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_comment_1_2_inline() -> Comment {
    Comment {
        location: Loc { begin: 1, end: 2 },
        kind: CommentType::Inline,
    }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_comment_list() -> BlobCommentList {
    BlobCommentList::from(vec![lib_ruby_parser__test__make_comment_1_2_inline()])
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_comment_list(comment_list: *mut Vec<Comment>) {
    unsafe { std::ptr::drop_in_place(comment_list) }
}
