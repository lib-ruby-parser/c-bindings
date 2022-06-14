use crate::blob_type;
#[allow(unused_imports)]
use lib_ruby_parser::{
    source::{Comment, CommentType},
    Loc,
};

blob_type!(CommentListBlob, Vec<Comment>);

#[cfg(test)]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_comment_type_document() -> CommentType {
    CommentType::Document
}

#[cfg(test)]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_comment_type_inline() -> CommentType {
    CommentType::Inline
}

#[cfg(test)]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_comment_type_unknown() -> CommentType {
    CommentType::Unknown
}

#[cfg(test)]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_comment(location: Loc, kind: CommentType) -> Comment {
    Comment { location, kind }
}

#[cfg(test)]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_comment_list(comment: Comment) -> CommentListBlob {
    let mut v = vec![comment];
    v.reserve(10);
    CommentListBlob::from(v)
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_comment_list(comment_list: *mut Vec<Comment>) {
    unsafe { std::ptr::drop_in_place(comment_list) }
}
