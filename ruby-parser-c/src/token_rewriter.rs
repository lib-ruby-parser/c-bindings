use crate::blob_type;
use crate::shared_byte_list::BlobSharedByteList;
#[allow(unused_imports)]
use lib_ruby_parser::{
    source::token_rewriter::{LexStateAction, RewriteAction, TokenRewriterResult},
    Bytes, LexState, Lexer, Loc, Token,
};

blob_type!(BlobMaybeTokenRewriter, Option<TokenRewriter>);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_rewrite_action__drop() -> RewriteAction {
    RewriteAction::Drop
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_rewrite_action__keep() -> RewriteAction {
    RewriteAction::Keep
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_lex_state_action__set(
    next_state: i32,
) -> LexStateAction {
    LexStateAction::Set(next_state)
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_lex_state_action__keep() -> LexStateAction {
    LexStateAction::Keep
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_token_rewriter_result() -> TokenRewriterResult {
    TokenRewriterResult {
        rewritten_token: Box::new(Token {
            token_type: Lexer::kDEF,
            token_value: Bytes::new(vec![]),
            loc: Loc { begin: 1, end: 2 },
            lex_state_before: LexState::default(),
            lex_state_after: LexState::default(),
        }),
        token_action: RewriteAction::Keep,
        lex_state_action: LexStateAction::Set(17),
    }
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_token_rewriter_result(
    token_rewriter_result: *mut TokenRewriterResult,
) {
    unsafe { std::ptr::drop_in_place(token_rewriter_result) }
}

#[repr(C)]
pub struct TokenRewriter {
    f: extern "C" fn(token: *mut Token, input: BlobSharedByteList) -> TokenRewriterResult,
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__always_keep_token_rewriter() -> TokenRewriter {
    #[no_mangle]
    pub extern "C" fn lib_ruby_parser__test__always_keep_token_rewriter_fn(
        token: *mut Token,
        _input: BlobSharedByteList,
    ) -> TokenRewriterResult {
        // and return constant output
        TokenRewriterResult {
            rewritten_token: unsafe { Box::from_raw(token) },
            token_action: RewriteAction::Keep,
            lex_state_action: LexStateAction::Keep,
        }
    }
    TokenRewriter {
        f: lib_ruby_parser__test__always_keep_token_rewriter_fn,
    }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__always_rewrite_token_rewriter() -> TokenRewriter {
    #[no_mangle]
    pub extern "C" fn lib_ruby_parser__test__always_rewrite_token_rewriter_fn(
        token: *mut Token,
        _input: BlobSharedByteList,
    ) -> TokenRewriterResult {
        // do cleanup
        unsafe { Box::from_raw(token) };
        // and return constant output
        TokenRewriterResult {
            rewritten_token: Box::new(Token {
                token_type: Lexer::tMINUS,
                token_value: Bytes::new(vec![]),
                loc: Loc { begin: 1, end: 2 },
                lex_state_before: LexState::default(),
                lex_state_after: LexState::default(),
            }),
            token_action: RewriteAction::Keep,
            lex_state_action: LexStateAction::Keep,
        }
    }
    TokenRewriter {
        f: lib_ruby_parser__test__always_rewrite_token_rewriter_fn,
    }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__some_always_keep_token_rewriter() -> BlobMaybeTokenRewriter
{
    BlobMaybeTokenRewriter::from(Some(lib_ruby_parser__test__always_keep_token_rewriter()))
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__none_token_rewriter() -> BlobMaybeTokenRewriter {
    BlobMaybeTokenRewriter::from(None)
}
