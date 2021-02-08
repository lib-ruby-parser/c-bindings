use crate::bindings;
use crate::Ptr;

type CustomState = *mut std::ffi::c_void;

struct CTokenRerwiter {
    state: CustomState,
    rewriter: bindings::TokenRewriterFn,
}

impl std::fmt::Debug for CTokenRerwiter {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        f.write_str("CTokenRerwiter")
    }
}

impl CTokenRerwiter {
    fn new(state: CustomState, rewriter: bindings::TokenRewriterFn) -> Box<Self> {
        Box::new(Self { state, rewriter })
    }
}

impl lib_ruby_parser::token_rewriter::TokenRewriter for CTokenRerwiter {
    fn rewrite_token(
        &mut self,
        token: lib_ruby_parser::Token,
        input: &[u8],
    ) -> (
        lib_ruby_parser::Token,
        lib_ruby_parser::token_rewriter::RewriteAction,
        lib_ruby_parser::token_rewriter::LexStateAction,
    ) {
        let rewriter = self.rewriter.unwrap();
        let bindings::TokenRewriterOutput {
            token,
            token_rewriter_action,
            lex_state_action,
        } = unsafe { rewriter(self.state, token.into(), input.as_ptr() as *const i8) };

        (
            token.into(),
            token_rewriter_action.into(),
            lex_state_action.into(),
        )
    }
}

impl From<bindings::TokenRewriteAction> for lib_ruby_parser::token_rewriter::RewriteAction {
    fn from(token_rewriter_action: bindings::TokenRewriteAction) -> Self {
        match token_rewriter_action {
            bindings::TokenRewriteAction::REWRITE_ACTION_DROP => {
                lib_ruby_parser::token_rewriter::RewriteAction::Drop
            }
            bindings::TokenRewriteAction::REWRITE_ACTION_KEEP => {
                lib_ruby_parser::token_rewriter::RewriteAction::Keep
            }
        }
    }
}

impl From<bindings::LexStateAction> for lib_ruby_parser::token_rewriter::LexStateAction {
    fn from(lex_state_action: bindings::LexStateAction) -> Self {
        match lex_state_action.kind {
            bindings::LexStateActionKind::LEX_STATE_ACTION_KEEP => {
                lib_ruby_parser::token_rewriter::LexStateAction::Keep
            }
            bindings::LexStateActionKind::LEX_STATE_ACTION_SET => {
                lib_ruby_parser::token_rewriter::LexStateAction::Set(
                    unsafe { lex_state_action.value.set }.new_state,
                )
            }
        }
    }
}

impl From<Ptr<bindings::TokenRewriter>>
    for Option<Box<dyn lib_ruby_parser::token_rewriter::TokenRewriter>>
{
    fn from(rewriter: Ptr<bindings::TokenRewriter>) -> Self {
        let rewriter = rewriter.unwrap();

        if rewriter.is_null() {
            return None;
        }
        let rewriter = unsafe { *rewriter };
        let bindings::TokenRewriter { state, rewriter } = rewriter;
        Some(CTokenRerwiter::new(state, rewriter))
    }
}
