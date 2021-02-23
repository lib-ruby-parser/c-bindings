use crate::bindings;
use crate::ptr_value;

impl From<lib_ruby_parser::ParserResult> for bindings::ParserResult {
    fn from(parser_result: lib_ruby_parser::ParserResult) -> Self {
        let lib_ruby_parser::ParserResult {
            ast,
            tokens,
            diagnostics,
            comments,
            magic_comments,
            input,
        } = parser_result;

        Self {
            ast: if let Some(ast) = ast {
                ptr_value(bindings::Node::from(Box::new(ast)))
            } else {
                std::ptr::null_mut()
            },
            tokens: ptr_value(bindings::TokenList::from(tokens)),
            diagnostics: ptr_value(bindings::Diagnostics::from(diagnostics)),
            comments: ptr_value(bindings::CommentList::from(comments)),
            magic_comments: ptr_value(bindings::MagicCommentList::from(magic_comments)),
            input: ptr_value(input) as *mut std::ffi::c_void,
        }
    }
}
