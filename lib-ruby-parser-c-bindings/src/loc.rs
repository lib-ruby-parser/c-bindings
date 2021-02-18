use crate::bindings;

impl From<lib_ruby_parser::Loc> for bindings::Loc {
    fn from(range: lib_ruby_parser::Loc) -> Self {
        let lib_ruby_parser::Loc { begin, end, .. } = range;
        Self {
            begin: begin as u32,
            end: end as u32,
        }
    }
}
