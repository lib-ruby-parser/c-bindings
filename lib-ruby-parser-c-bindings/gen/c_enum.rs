use lib_ruby_parser_nodes::Node;
pub struct CEnum<'a> {
    rust_nodes: &'a Vec<Node>,
}

impl<'a> CEnum<'a> {
    pub fn new(rust_nodes: &'a Vec<Node>) -> Self {
        Self { rust_nodes }
    }

    pub fn code(&self) -> String {
        let enum_definition = self
            .rust_nodes
            .iter()
            .map(|node| format!("    NODE_{},", node.filename.to_uppercase()))
            .collect::<Vec<_>>()
            .join("\n");

        format!(
            "
enum NodeType
{{
{enum_definition}
}};
",
            enum_definition = enum_definition
        )
    }
}
