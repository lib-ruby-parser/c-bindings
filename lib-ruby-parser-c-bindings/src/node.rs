use crate::bindings;

impl From<Box<lib_ruby_parser::Node>> for bindings::Node {
    fn from(node: Box<lib_ruby_parser::Node>) -> Self {
        Self::from(*node)
    }
}
