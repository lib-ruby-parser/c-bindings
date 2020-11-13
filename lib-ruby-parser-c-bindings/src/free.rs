use crate::bindings::*;
use crate::ptr_unptr::*;

#[no_mangle]
pub extern "C" fn parser_result_free(parser_result: *mut ParserResult) {
    if parser_result.is_null() {
        return;
    }
    drop(unptr_parser_result(parser_result))
}

#[no_mangle]
pub extern "C" fn node_free(node: *mut Node) {
    if node.is_null() {
        return;
    }
    drop(unptr_node(node))
}

#[no_mangle]
pub extern "C" fn tokens_free(tokens: *mut Tokens) {
    if tokens.is_null() {
        return;
    }
    drop(unptr_tokens(tokens))
}

#[no_mangle]
pub extern "C" fn comments_free(comments: *mut Comments) {
    if comments.is_null() {
        return;
    }
    drop(unptr_comments(comments))
}

#[no_mangle]
pub extern "C" fn diagnostics_free(diagnostics: *mut Diagnostics) {
    if diagnostics.is_null() {
        return;
    }
    drop(unptr_diagnostics(diagnostics))
}

#[no_mangle]
pub extern "C" fn magic_comments_free(magic_comments: *mut MagicComments) {
    if magic_comments.is_null() {
        return;
    }
    drop(unptr_magic_comments(magic_comments))
}
