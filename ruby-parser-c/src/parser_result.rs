use crate::{
    blob_type, bytes::ByteListBlob, parser_options::CParserOptions,
    parser_options::ParserOptionsBlob,
};
#[allow(unused_imports)]
use lib_ruby_parser::{
    nodes::Retry,
    source::{Comment, CommentType, MagicComment, MagicCommentKind},
    source::{DecodedInput, SourceLine},
    Bytes, Diagnostic, DiagnosticMessage, ErrorLevel, LexState, Lexer, Loc, Node, Parser,
    ParserOptions, ParserResult, Token,
};

blob_type!(DecodedInputBlob, DecodedInput);
blob_type!(ParserResultBlob, ParserResult);

#[cfg(test)]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_decoded_input() -> DecodedInputBlob {
    DecodedInputBlob::from(DecodedInput {
        name: String::from("(eval)"),
        lines: vec![
            SourceLine {
                start: 0,
                end: 6,
                ends_with_eof: false,
            },
            SourceLine {
                start: 6,
                end: 8,
                ends_with_eof: true,
            },
        ],
        bytes: vec![b'2', b' ', b'+', b' ', b'2', b'\n', b'4', b'2'],
    })
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_decoded_input(decoded_input: *mut DecodedInput) {
    unsafe { std::ptr::drop_in_place(decoded_input) }
}

#[cfg(test)]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_parser_result() -> ParserResultBlob {
    ParserResultBlob::from(ParserResult {
        ast: Some(Box::new(Node::Retry(Retry {
            expression_l: Loc { begin: 1, end: 2 },
        }))),
        tokens: vec![Token {
            token_type: Lexer::tINTEGER,
            token_value: Bytes::new(vec![b'9']),
            loc: Loc { begin: 3, end: 4 },
            lex_state_before: LexState::default(),
            lex_state_after: LexState::default(),
        }],
        diagnostics: vec![Diagnostic {
            level: ErrorLevel::Warning,
            message: DiagnosticMessage::EndInMethod {},
            loc: Loc { begin: 5, end: 6 },
        }],
        comments: vec![Comment {
            location: Loc { begin: 7, end: 8 },
            kind: CommentType::Inline,
        }],
        magic_comments: vec![MagicComment {
            kind: MagicCommentKind::Encoding,
            key_l: Loc { begin: 9, end: 10 },
            value_l: Loc { begin: 11, end: 12 },
        }],
        input: DecodedInput {
            name: String::from("(eval)"),
            lines: vec![SourceLine {
                start: 10,
                end: 20,
                ends_with_eof: false,
            }],
            bytes: vec![b'2', b' ', b'+', b' ', b'2'],
        },
    })
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_parser_result(parser_result: *mut ParserResult) {
    unsafe { std::ptr::drop_in_place(parser_result) }
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_parse(
    input: ByteListBlob,
    options: ParserOptionsBlob,
) -> ParserResultBlob {
    let options: lib_ruby_parser::ParserOptions = CParserOptions::from(options).into();
    let input: Vec<u8> = input.into();
    let result = Parser::new(input, options).do_parse();
    result.into()
}
