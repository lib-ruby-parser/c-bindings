use lib_ruby_parser::{
    containers::{List, StringPtr},
    source::{Comment, MagicComment},
    Diagnostic, Loc, Node, Token,
};
use std::mem::ManuallyDrop;

fn clone<T: Clone + Sized>(t: ManuallyDrop<T>) -> T {
    ManuallyDrop::into_inner(t.clone())
}

// Node
#[no_mangle]
pub extern "C" fn lib_ruby_parser_clone_node(node: ManuallyDrop<Node>) -> Node {
    clone(node)
}

// Token
#[no_mangle]
pub extern "C" fn lib_ruby_parser_clone_token(token: ManuallyDrop<Token>) -> Token {
    clone(token)
}

// Diagnostic
#[no_mangle]
pub extern "C" fn lib_ruby_parser_clone_diagnostic(
    diagnostic: ManuallyDrop<Diagnostic>,
) -> Diagnostic {
    clone(diagnostic)
}

// Comment
#[no_mangle]
pub extern "C" fn lib_ruby_parser_clone_comment(comment: ManuallyDrop<Comment>) -> Comment {
    clone(comment)
}

// MagicComment
#[no_mangle]
pub extern "C" fn lib_ruby_parser_clone_magic_comment(
    magic_comment: ManuallyDrop<MagicComment>,
) -> MagicComment {
    clone(magic_comment)
}

// Loc
#[no_mangle]
pub extern "C" fn lib_ruby_parser_clone_loc(loc: ManuallyDrop<Loc>) -> Loc {
    clone(loc)
}

// ByteList
#[no_mangle]
pub extern "C" fn lib_ruby_parser_clone_byte_list(byte_list: ManuallyDrop<List<u8>>) -> List<u8> {
    clone(byte_list)
}

// StringPtr
#[no_mangle]
pub extern "C" fn lib_ruby_parser_clone_string_ptr(
    string_ptr: ManuallyDrop<StringPtr>,
) -> StringPtr {
    clone(string_ptr)
}
