use crate::bindings;
use crate::ptr_value;

impl From<lib_ruby_parser::source::Comment> for bindings::Comment {
    fn from(comment: lib_ruby_parser::source::Comment) -> Self {
        Self {
            location: ptr_value(bindings::Loc::from(comment.location)),
        }
    }
}
