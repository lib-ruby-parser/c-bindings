extern crate lib_ruby_parser;

mod alloc;

use lib_ruby_parser::{
    blobs::{Blob, HasBlob},
    containers::{ExternalList as List, ExternalStringPtr as StringPtr},
    DiagnosticMessage, Parser, ParserOptions, ParserResult, Token,
};
type ByteList = List<u8>;

#[no_mangle]
pub extern "C" fn lib_ruby_parser__internal__parse(
    options: Blob<ParserOptions>,
    input: Blob<ByteList>,
) -> Blob<ParserResult> {
    let options = ParserOptions::from_blob(options);
    let input = List::<u8>::from_blob(input);
    let result = Parser::new(input, options).do_parse();
    result.into_blob()
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser__internal__token_name(
    token: *const Blob<Token>,
) -> Blob<StringPtr> {
    let token = unsafe { (token as *const Token).as_ref().unwrap() };
    let token_name = StringPtr::from(token.token_name());
    token_name.into_blob()
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser__internal__render_diagnostic_message(
    message: *const Blob<DiagnosticMessage>,
) -> Blob<StringPtr> {
    let message = unsafe { (message as *const DiagnosticMessage).as_ref().unwrap() };
    let rendered = StringPtr::from(message.render());
    rendered.into_blob()
}
