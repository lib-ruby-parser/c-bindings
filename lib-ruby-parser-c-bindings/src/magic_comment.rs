use crate::bindings;
use crate::ptr_value;

impl From<lib_ruby_parser::source::MagicComment> for bindings::MagicComment {
    fn from(magic_comment: lib_ruby_parser::source::MagicComment) -> Self {
        let lib_ruby_parser::source::MagicComment {
            kind,
            key_l,
            value_l,
        } = magic_comment;
        let kind = match kind {
            lib_ruby_parser::source::MagicCommentKind::Encoding => {
                bindings::MagicCommentKind::MAGIC_COMMENT_KIND_ENCODING
            }
            lib_ruby_parser::source::MagicCommentKind::FrozenStringLiteral => {
                bindings::MagicCommentKind::MAGIC_COMMENT_KIND_FROZEN_STRING_LITERAL
            }
            lib_ruby_parser::source::MagicCommentKind::WarnIndent => {
                bindings::MagicCommentKind::MAGIC_COMMENT_KIND_WARN_INDENT
            }
            lib_ruby_parser::source::MagicCommentKind::ShareableContstantValue => {
                bindings::MagicCommentKind::MAGIC_COMMENT_KIND_SHAREABLE_CONSTANT_VALUE
            }
        };
        Self {
            kind,
            key_l: ptr_value(bindings::Loc::from(key_l)),
            value_l: ptr_value(bindings::Loc::from(value_l)),
        }
    }
}
