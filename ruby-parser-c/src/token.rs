use crate::blob_type;
#[allow(unused_imports)]
use lib_ruby_parser::{Bytes, LexState, Loc, Token};

blob_type!(BlobToken, Token);
blob_type!(BlobTokenList, Vec<Token>);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_token_eq(
    loc: Loc,
    lex_state_before_i32: i32,
    lex_state_after_i32: i32,
) -> BlobToken {
    let mut lex_state_before = LexState::default();
    lex_state_before.set(lex_state_before_i32);

    let mut lex_state_after = LexState::default();
    lex_state_after.set(lex_state_after_i32);

    let token = Token {
        token_type: 334,
        token_value: Bytes::new(vec![b'=']),
        loc,
        lex_state_before,
        lex_state_after,
    };
    assert_eq!(token.token_name(), "tEQ");
    BlobToken::from(token)
}

#[no_mangle]
#[cfg(feature = "tests")]
pub extern "C" fn LIB_RUBY_PARSER_token_name(token: *mut Token) -> *const u8 {
    let token = unsafe { token.as_ref().unwrap() };
    token.token_name().as_ptr()
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_token(token: *mut Token) {
    unsafe { std::ptr::drop_in_place(token) }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_token_list(token: BlobToken) -> BlobTokenList {
    BlobTokenList::from(vec![Token::from(token)])
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_token_list(token_list: *mut Vec<Token>) {
    unsafe { std::ptr::drop_in_place(token_list) }
}
