use crate::bindings;

impl From<lib_ruby_parser::Loc> for bindings::Loc {
    fn from(loc: lib_ruby_parser::Loc) -> Self {
        Self {
            begin: loc.begin as u32,
            end: loc.end as u32,
        }
    }
}

impl From<bindings::Loc> for lib_ruby_parser::Loc {
    fn from(loc: bindings::Loc) -> Self {
        Self {
            begin: loc.begin as usize,
            end: loc.end as usize,
        }
    }
}
