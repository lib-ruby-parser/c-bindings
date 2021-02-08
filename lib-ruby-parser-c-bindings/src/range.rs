use crate::bindings;

impl From<lib_ruby_parser::source::Range> for bindings::Range {
    fn from(range: lib_ruby_parser::source::Range) -> Self {
        let lib_ruby_parser::source::Range {
            begin_pos, end_pos, ..
        } = range;
        Self {
            begin_pos: begin_pos as u32,
            end_pos: end_pos as u32,
        }
    }
}
