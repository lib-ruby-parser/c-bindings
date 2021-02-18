use crate::bindings;
use crate::ptr_value;
use crate::StringPtr;

impl From<bindings::Token> for lib_ruby_parser::Token {
    fn from(token: bindings::Token) -> Self {
        let bindings::Token {
            token_type,
            token_value,
            loc,
            ..
        } = token;
        let loc = unsafe { Box::from_raw(loc) };
        let token_value: String = unsafe { std::ffi::CString::from_raw(token_value) }
            .into_string()
            .unwrap();

        lib_ruby_parser::Token {
            token_type,
            token_value: lib_ruby_parser::Bytes::new(token_value.into_bytes()),
            loc: lib_ruby_parser::Loc {
                begin: loc.begin as usize,
                end: loc.end as usize,
            },
            lex_state_before: lib_ruby_parser::LexState::default(),
            lex_state_after: lib_ruby_parser::LexState::default(),
        }
    }
}

impl From<lib_ruby_parser::Token> for bindings::Token {
    fn from(token: lib_ruby_parser::Token) -> Self {
        let lib_ruby_parser::Token {
            token_type,
            token_value,
            loc,
            ..
        } = token;
        let token_value = StringPtr::from(token_value.to_string_lossy()).unwrap();

        let loc = ptr_value(bindings::Loc {
            begin: loc.begin as u32,
            end: loc.end as u32,
        });

        bindings::Token {
            token_type,
            token_value,
            loc,

            lex_state_before: 0,
            lex_state_after: 0,
        }
    }
}
