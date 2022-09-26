use lib_ruby_parser::source::DecodedInput;

#[repr(C)]
pub struct LineCol {
    line: usize,
    col: usize,
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_line_col_for_pos(
    decoded_input: *const DecodedInput,
    pos: usize,
) -> LineCol {
    let decoded_input = unsafe { decoded_input.as_ref().unwrap() };
    if let Some((line, col)) = decoded_input.line_col_for_pos(pos) {
        LineCol { line, col }
    } else {
        LineCol { line: 0, col: 0 }
    }
}
