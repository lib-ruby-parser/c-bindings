use lib_ruby_parser::c_parse::ForeignParserOptions;

#[no_mangle]
pub extern "C" fn lib_ruby_parser_default_parser_options() -> ForeignParserOptions {
    ForeignParserOptions::default()
}

#[no_mangle]
pub extern "C" fn lib_ruby_parser_free_parser_options(options: ForeignParserOptions) {
    drop(options)
}
