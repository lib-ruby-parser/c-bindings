use lib_ruby_parser::ParserResult;

#[no_mangle]
pub extern "C" fn lib_ruby_parser_free_parser_result(parser_result: ParserResult) {
    drop(parser_result)
}
