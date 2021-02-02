use crate::bindings::*;
use crate::ptr_value;
use std::ffi::CString;

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

pub fn string_to_ptr(s: String) -> *mut i8 {
    let mut bytes = CString::new(s).unwrap().into_bytes_with_nul();
    let ptr = bytes.as_mut_ptr();
    std::mem::forget(bytes);
    ptr as *mut i8
}

fn vec_to_ptr(vec: Vec<u8>) -> *mut i8 {
    let mut boxed_slice = vec.into_boxed_slice();
    let ptr = boxed_slice.as_mut_ptr();
    std::mem::forget(boxed_slice);
    ptr as *mut i8
}

fn input_to_ptr(input: lib_ruby_parser::source::buffer::Input) -> *mut i8 {
    let mut bytes = CString::new(input.bytes).unwrap().into_bytes_with_nul();
    let ptr = bytes.as_mut_ptr();
    std::mem::forget(bytes);
    ptr as *mut i8
}

impl From<lib_ruby_parser::ParserResult> for ParserResult {
    fn from(parser_result: lib_ruby_parser::ParserResult) -> Self {
        let lib_ruby_parser::ParserResult {
            ast,
            tokens,
            diagnostics,
            comments,
            magic_comments,
            input,
        } = parser_result;

        ParserResult {
            ast: if let Some(ast) = ast {
                ptr_value(Node::from(Box::new(ast)))
            } else {
                std::ptr::null_mut()
            },
            tokens: ptr_value(TokenList::from(tokens)),
            diagnostics: ptr_value(Diagnostics::from(diagnostics)),
            comments: ptr_value(CommentList::from(comments)),
            magic_comments: ptr_value(MagicCommentList::from(magic_comments)),
            input: input_to_ptr(input),
        }
    }
}

impl From<Vec<lib_ruby_parser::Token>> for TokenList {
    fn from(tokens: Vec<lib_ruby_parser::Token>) -> Self {
        let (list, len) = vec_to_c_list(tokens, Token::from);
        TokenList { list, len }
    }
}

impl From<lib_ruby_parser::Token> for Token {
    fn from(token: lib_ruby_parser::Token) -> Self {
        let lib_ruby_parser::Token {
            token_type,
            token_value,
            loc,
            ..
        } = token;
        let token_value = string_to_ptr(token_value.to_string_lossy());

        let loc = ptr_value(Loc {
            begin: loc.begin as u32,
            end: loc.end as u32,
        });

        Token {
            token_type,
            token_value,
            loc,

            lex_state_before: 0,
            lex_state_after: 0,
        }
    }
}

impl From<Vec<lib_ruby_parser::Diagnostic>> for Diagnostics {
    fn from(diagnostics: Vec<lib_ruby_parser::Diagnostic>) -> Self {
        let (list, len) = vec_to_c_list(diagnostics, Diagnostic::from);
        Diagnostics { list, len }
    }
}

impl From<lib_ruby_parser::Diagnostic> for Diagnostic {
    fn from(diagnostic: lib_ruby_parser::Diagnostic) -> Self {
        let level = match diagnostic.level {
            lib_ruby_parser::ErrorLevel::Warning => ErrorLevel_ERROR_LEVEL_WARNING,
            lib_ruby_parser::ErrorLevel::Error => ErrorLevel_ERROR_LEVEL_ERROR,
        };
        let message = string_to_ptr(diagnostic.render_message());
        Diagnostic {
            level,
            message,
            range: ptr_value(Range::from(diagnostic.range)),
        }
    }
}

impl From<Vec<lib_ruby_parser::source::Comment>> for CommentList {
    fn from(comments: Vec<lib_ruby_parser::source::Comment>) -> Self {
        let (list, len) = vec_to_c_list(comments, Comment::from);
        CommentList { list, len }
    }
}

impl From<lib_ruby_parser::source::Comment> for Comment {
    fn from(comment: lib_ruby_parser::source::Comment) -> Self {
        Comment {
            location: ptr_value(Range::from(comment.location)),
        }
    }
}

impl From<Vec<lib_ruby_parser::source::MagicComment>> for MagicCommentList {
    fn from(magic_comments: Vec<lib_ruby_parser::source::MagicComment>) -> Self {
        let (list, len) = vec_to_c_list(magic_comments, MagicComment::from);
        MagicCommentList { list, len }
    }
}

impl From<lib_ruby_parser::source::MagicComment> for MagicComment {
    fn from(magic_comment: lib_ruby_parser::source::MagicComment) -> Self {
        let lib_ruby_parser::source::MagicComment {
            kind,
            key_l,
            value_l,
        } = magic_comment;
        let kind = match kind {
            lib_ruby_parser::source::MagicCommentKind::Encoding => MagicCommentKind_ENCODING,
            lib_ruby_parser::source::MagicCommentKind::FrozenStringLiteral => {
                MagicCommentKind_FROZEN_STRING_LITERAL
            }
            lib_ruby_parser::source::MagicCommentKind::WarnIndent => MagicCommentKind_WARN_INDENT,
            lib_ruby_parser::source::MagicCommentKind::ShareableContstantValue => {
                MagicCommentKind_SHAREABLE_CONSTANT_VALUE
            }
        };
        MagicComment {
            kind,
            key_l: ptr_value(Range::from(key_l)),
            value_l: ptr_value(Range::from(value_l)),
        }
    }
}

impl From<lib_ruby_parser::source::Range> for Range {
    fn from(range: lib_ruby_parser::source::Range) -> Self {
        let lib_ruby_parser::source::Range {
            begin_pos, end_pos, ..
        } = range;
        Range {
            begin_pos: begin_pos as u32,
            end_pos: end_pos as u32,
        }
    }
}

impl From<Vec<lib_ruby_parser::Node>> for NodeList {
    fn from(nodes: Vec<lib_ruby_parser::Node>) -> Self {
        let (list, len) = vec_to_c_list(nodes, Node::from);
        NodeList { list, len }
    }
}

impl From<Box<lib_ruby_parser::Node>> for Node {
    fn from(node: Box<lib_ruby_parser::Node>) -> Self {
        Node::from(*node)
    }
}

pub struct StringPtr {
    ptr: *mut i8,
}

impl StringPtr {
    pub fn unwrap(self) -> *mut i8 {
        self.ptr
    }
}

impl From<String> for StringPtr {
    fn from(s: String) -> Self {
        Self {
            ptr: string_to_ptr(s),
        }
    }
}

impl From<Option<String>> for StringPtr {
    fn from(maybe_s: Option<String>) -> Self {
        if let Some(s) = maybe_s {
            StringPtr::from(s)
        } else {
            StringPtr {
                ptr: std::ptr::null_mut(),
            }
        }
    }
}

impl From<Vec<char>> for StringPtr {
    fn from(chars: Vec<char>) -> Self {
        StringPtr::from(chars.iter().collect::<String>())
    }
}

impl From<lib_ruby_parser::StringValue> for StringPtr {
    fn from(string_value: lib_ruby_parser::StringValue) -> Self {
        let mut str_bytes = string_value.bytes;
        str_bytes.push(0);
        Self {
            ptr: vec_to_ptr(str_bytes),
        }
    }
}
