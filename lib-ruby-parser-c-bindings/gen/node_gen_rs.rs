use super::Field;

pub struct NodeGenRs<'a> {
    nodes: &'a [lib_ruby_parser_nodes::Node],
}

impl<'a> NodeGenRs<'a> {
    pub fn new(nodes: &'a [lib_ruby_parser_nodes::Node]) -> Self {
        Self { nodes }
    }

    pub fn write(&self) {
        std::fs::write("src/node_gen.rs", self.contents()).unwrap();
    }

    pub fn contents(&self) -> String {
        format!(
            "use crate::bindings::*;
use crate::StringPtr;
use crate::ptr_value;

impl From<lib_ruby_parser::Node> for Node {{
    fn from(node: lib_ruby_parser::Node) -> Self {{
        match node {{
            {branches}
        }}
    }}
}}

{from_impls}
",
            branches = self.match_node_branches().join(",\n            "),
            from_impls = self.from_impls().join("\n\n"),
        )
    }

    fn match_node_branches(&self) -> Vec<String> {
        self.nodes
            .iter()
            .map(|node| {
                format!(
                    "lib_ruby_parser::Node::{}(inner) => Node::from(inner)",
                    node.struct_name
                )
            })
            .collect()
    }

    fn from_impls(&self) -> Vec<String> {
        self.nodes
            .iter()
            .map(|n| FromImplementation::new(n).code())
            .collect()
    }
}

struct FromImplementation<'a> {
    node: &'a lib_ruby_parser_nodes::Node,
}

impl<'a> FromImplementation<'a> {
    pub fn new(node: &'a lib_ruby_parser_nodes::Node) -> Self {
        Self { node }
    }

    pub fn code(&self) -> String {
        format!(
            "impl From<lib_ruby_parser::nodes::{name}> for Node {{
    fn from(node: lib_ruby_parser::nodes::{name}) -> Self {{
        let node_type = NodeType_NODE_{enum_name};
        {cast_fields}
        let typed_node = {typed_node_name} {{ {fields_list} }};
        let inner = ptr_value(InnerNode {{ _{union_field_name}: ptr_value(typed_node) }});
        Node {{ node_type, inner }}
    }}
}}",
            name = self.node.struct_name,
            enum_name = self.node.filename.to_uppercase(),
            cast_fields = self.cast_fields().join("\n        "),
            typed_node_name = self.node.struct_name,
            fields_list = self.fields_list().join(", "),
            union_field_name = self.node.filename.to_lowercase(),
        )
    }

    pub fn cast_fields(&self) -> Vec<String> {
        self.node
            .fields
            .iter()
            .map(|field| CastField::new(field).code())
            .collect()
    }

    fn fields_list(&self) -> Vec<String> {
        self.node
            .fields
            .iter()
            .map(|field| Field::new(field).c_name())
            .collect()
    }
}

struct CastField<'a> {
    field: &'a lib_ruby_parser_nodes::Field,
}

impl<'a> CastField<'a> {
    fn new(field: &'a lib_ruby_parser_nodes::Field) -> Self {
        Self { field }
    }

    fn code(&self) -> String {
        use lib_ruby_parser_nodes::FieldType;
        let c_name = Field::new(&self.field).c_name();
        let rust_name = &self.field.field_name;

        let get = match self.field.field_type {
            FieldType::Node => format!("ptr_value(Node::from(node.{}))", rust_name),

            FieldType::Nodes => format!("ptr_value(NodeList::from(node.{}))", rust_name),

            FieldType::MaybeNode | FieldType::RegexOptions => format!(
                "\
                if let Some(v) = node.{} {{ \
                    ptr_value(Node::from(v)) \
                }} else {{ \
                    std::ptr::null_mut() \
                }}",
                rust_name
            ),

            FieldType::Loc => format!("ptr_value(Loc::from(node.{}))", rust_name),

            FieldType::MaybeLoc => format!(
                "\
                if let Some(v) = node.{} {{ \
                    ptr_value(Loc::from(v)) \
                }} else {{ \
                    std::ptr::null_mut() \
                }}",
                rust_name
            ),

            FieldType::Str
            | FieldType::MaybeStr
            | FieldType::Chars
            | FieldType::StringValue
            | FieldType::RawString => {
                format!("StringPtr::from(node.{}).unwrap()", rust_name)
            }

            FieldType::U8 | FieldType::Usize => format!("node.{} as u32", rust_name),
        };
        format!("let {} = {};", c_name, get)
    }
}
