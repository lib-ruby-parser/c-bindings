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
pub extern "C" fn lib_ruby_parser__test__make_comment(location: Loc, kind: CommentType) -> Comment {
    Comment { location, kind }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_comment_list(comment: Comment) -> BlobCommentList {
    BlobCommentList::from(vec![comment])
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_comment_list(comment_list: *mut Vec<Comment>) {
    unsafe { std::ptr::drop_in_place(comment_list) }
}