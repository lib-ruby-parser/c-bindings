use crate::bindings;
use crate::ptr_value;

fn input_to_ptr(input: lib_ruby_parser::source::Input) -> *mut i8 {
    let mut bytes = std::ffi::CString::new(input.as_bytes())
        .unwrap()
        .into_bytes_with_nul();
    let ptr = bytes.as_mut_ptr();
    std::mem::forget(bytes);
    ptr as *mut i8
}

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
            input_len: input.as_bytes().len() as u32,
            input: input_to_ptr(input),
        }
    }
}
