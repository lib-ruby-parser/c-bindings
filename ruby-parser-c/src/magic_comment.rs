use crate::blob_type;
#[allow(unused_imports)]
use lib_ruby_parser::{
    source::{MagicComment, MagicCommentKind},
    Loc,
};

blob_type!(MagicCommentListBlob, Vec<MagicComment>);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_magic_comment_kind_encoding() -> MagicCommentKind {
    MagicCommentKind::Encoding
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_magic_comment_kind_frozen_string_literal(
) -> MagicCommentKind {
    MagicCommentKind::FrozenStringLiteral
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_magic_comment_kind_shareable_constant_value(
) -> MagicCommentKind {
    MagicCommentKind::ShareableConstantValue
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_magic_comment_kind_warn_indent() -> MagicCommentKind {
    MagicCommentKind::WarnIndent
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_magic_comment(
    kind: MagicCommentKind,
    key_l: Loc,
    value_l: Loc,
) -> MagicComment {
    MagicComment {
        kind,
        key_l,
        value_l,
    }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_magic_comment_list(
    magic_comment: MagicComment,
) -> MagicCommentListBlob {
    MagicCommentListBlob::from(vec![magic_comment])
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_magic_comment_list(
    magic_comment_list: *mut Vec<MagicComment>,
) {
    unsafe { std::ptr::drop_in_place(magic_comment_list) }
}
