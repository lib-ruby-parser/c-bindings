use crate::bindings;

fn vec_to_c_list<T, Target>(vec: Vec<T>, f: fn(T) -> Target) -> (*mut Target, u32) {
    let mut boxed_slice = vec
        .into_iter()
        .map(f)
        .collect::<Vec<_>>()
        .into_boxed_slice();
    let len = boxed_slice.len() as u32;
    let ptr = boxed_slice.as_mut_ptr();
    std::mem::forget(boxed_slice);
    (ptr, len)
}

impl From<Vec<lib_ruby_parser::Token>> for bindings::TokenList {
    fn from(tokens: Vec<lib_ruby_parser::Token>) -> Self {
        let (list, len) = vec_to_c_list(tokens, From::from);
        Self { list, len }
    }
}

impl From<Vec<lib_ruby_parser::Diagnostic>> for bindings::DiagnosticList {
    fn from(diagnostics: Vec<lib_ruby_parser::Diagnostic>) -> Self {
        let (list, len) = vec_to_c_list(diagnostics, From::from);
        Self { list, len }
    }
}

impl From<Vec<lib_ruby_parser::source::Comment>> for bindings::CommentList {
    fn from(comments: Vec<lib_ruby_parser::source::Comment>) -> Self {
        let (list, len) = vec_to_c_list(comments, From::from);
        Self { list, len }
    }
}

impl From<Vec<lib_ruby_parser::source::MagicComment>> for bindings::MagicCommentList {
    fn from(magic_comments: Vec<lib_ruby_parser::source::MagicComment>) -> Self {
        let (list, len) = vec_to_c_list(magic_comments, From::from);
        Self { list, len }
    }
}

impl From<Vec<lib_ruby_parser::Node>> for bindings::NodeList {
    fn from(nodes: Vec<lib_ruby_parser::Node>) -> Self {
        let (list, len) = vec_to_c_list(nodes, From::from);
        Self { list, len }
    }
}
