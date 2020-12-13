use super::CField;
use lib_ruby_parser_nodes::{FieldType, Node};

pub struct RustFile {
    nodes: Vec<Node>,
}

impl RustFile {
    pub fn new(nodes: Vec<Node>) -> Self {
        Self { nodes }
    }

    pub fn code(&self) -> String {
        format!(
            "use crate::bindings::*;
use crate::StringPtr;
use crate::ptr_value;
use crate::debug_str_ptr;

impl From<lib_ruby_parser::Node> for Node {{
    fn from(node: lib_ruby_parser::Node) -> Self {{
        match node {{
{branches}
        }}
    }}
}}

{from_impls}

use std::fmt;
{debug_impls}

impl InnerNode {{
    pub fn to_debug_string(&self, node_type: u32) -> String {{
        match node_type {{
{node_enum_to_string_impl}
            _ => panic!(\"unsupported node type {{}}\", node_type)
        }}
    }}
}}


",
            branches = self.branches(),
            from_impls = self
                .nodes
                .iter()
                .map(|node| FromImplementation::new(node).code())
                .collect::<Vec<_>>()
                .join("\n"),
            debug_impls = self
                .nodes
                .iter()
                .map(|node| DebugImplementation::new(node).code())
                .collect::<Vec<_>>()
                .join("\n"),
            node_enum_to_string_impl = self.node_enum_to_string_impl()
        )
    }

    fn branches(&self) -> String {
        self.nodes
            .iter()
            .map(|node| {
                format!(
                    "            lib_ruby_parser::Node::{name}(inner) => Node::from(inner),",
                    name = node.struct_name
                )
            })
            .collect::<Vec<_>>()
            .join("\n")
    }

    fn node_enum_to_string_impl(&self) -> String {
        self.nodes
            .iter()
            .map(|node| {
                format!(
                    "            NodeType_NODE_{enum_name} => format!(\"{{:#?}}\",  unsafe {{ *self._{union_field_name} }}),",
                    enum_name = node.filename.to_uppercase(),
                    union_field_name = node.filename.to_lowercase(),
                )
            })
            .collect::<Vec<_>>()
            .join("\n")
    }
}

struct FromImplementation<'a> {
    node: &'a Node,
}

impl<'a> FromImplementation<'a> {
    pub fn new(node: &'a Node) -> Self {
        Self { node }
    }

    pub fn code(&self) -> String {
        format!(
            "
impl From<lib_ruby_parser::nodes::{name}> for Node {{
    fn from(node: lib_ruby_parser::nodes::{name}) -> Self {{
        let node_type = NodeType_NODE_{enum_name};
{cast_fields}
        let typed_node = {typed_node_name} {{ {fields_list} }};
        let inner = ptr_value(InnerNode {{ _{union_field_name}: ptr_value(typed_node) }});
        Node {{ node_type, inner }}
    }}
}}
",
            name = self.node.struct_name,
            enum_name = self.node.filename.to_uppercase(),
            cast_fields = self.cast_fields(),
            typed_node_name = self.node.struct_name,
            fields_list = self.fields_list(),
            union_field_name = self.node.filename.to_lowercase(),
        )
    }

    pub fn cast_fields(&self) -> String {
        self.node
            .fields
            .iter()
            .map(|field| {
                let field_name = CField::new(field).field_name();

                let get = match field.field_type {
                    FieldType::Node => format!("ptr_value(Node::from(node.{}))", field.field_name),
                    FieldType::Nodes => format!("ptr_value(NodeList::from(node.{}))", field.field_name),
                    FieldType::MaybeNode => format!("if let Some(v) = node.{} {{ ptr_value(Node::from(v)) }} else {{ std::ptr::null_mut() }}", field.field_name),
                    FieldType::Range => format!("ptr_value(Range::from(node.{}))", field.field_name),
                    FieldType::MaybeRange => format!("if let Some(v) = node.{} {{ ptr_value(Range::from(v)) }} else {{ std::ptr::null_mut() }}", field.field_name),
                    FieldType::Str => {
                        format!("StringPtr::from(node.{}).unwrap()", field.field_name)
                    }
                    FieldType::MaybeStr => {
                        format!("StringPtr::from(node.{}).unwrap()", field.field_name)
                    }
                    FieldType::Chars => {
                        format!("StringPtr::from(node.{}).unwrap()", field.field_name)
                    }
                    FieldType::StringValue => {
                        format!("StringPtr::from(node.{}).unwrap()", field.field_name)
                    }
                    FieldType::U8 => format!("node.{} as size_t", field.field_name),
                    FieldType::Usize => format!("node.{} as size_t", field.field_name),
                    FieldType::RawString => {
                        format!("StringPtr::from(node.{}).unwrap()", field.field_name)
                    }
                    FieldType::RegexOptions => format!("if let Some(v) = node.{} {{ ptr_value(Node::from(v)) }} else {{ std::ptr::null_mut() }}", field.field_name),
                };
                format!(
                    "        let {field_name} = {get};",
                    field_name = field_name,
                    get = get
                )
            })
            .collect::<Vec<_>>()
            .join("\n")
    }

    fn fields_list(&self) -> String {
        self.node
            .fields
            .iter()
            .map(|field| CField::new(field).field_name())
            .collect::<Vec<_>>()
            .join(", ")
    }
}

struct DebugImplementation<'a> {
    node: &'a Node,
}

impl<'a> DebugImplementation<'a> {
    pub fn new(node: &'a Node) -> Self {
        Self { node }
    }

    pub fn code(&self) -> String {
        format!(
            "impl fmt::Debug for {struct_name} {{
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {{
        let fmt = &mut f.debug_struct(\"{struct_name}\");
{fields}
        fmt.finish()
    }}
}}
",
            struct_name = self.node.struct_name,
            fields = self.fields()
        )
    }

    fn fields(&self) -> String {
        self.node
            .fields
            .iter()
            .map(|field| {
                let field_name = CField::new(field).field_name();

                let fmt = match field.field_type {
                    FieldType::Node => {
                        format!("fmt.field(\"{field_name}\", unsafe {{ &*self.{field_name} }})", field_name = field_name)
                    }
                    FieldType::Nodes => {
                        format!("fmt.field(\"{field_name}\", unsafe {{ &*self.{field_name} }})", field_name = field_name)
                    }
                    FieldType::MaybeNode => {
                        format!("if self.{field_name}.is_null() {{ fmt.field(\"{field_name}\", &Option::<()>::None) }} else {{ fmt.field(\"{field_name}\", unsafe {{ &*self.{field_name} }})  }}", field_name = field_name)
                    }
                    FieldType::Range => {
                        format!("fmt.field(\"{field_name}\", unsafe {{ &*self.{field_name} }})", field_name = field_name)
                    }
                    FieldType::MaybeRange => {
                        format!("if self.{field_name}.is_null() {{ fmt.field(\"{field_name}\", &Option::<()>::None) }} else {{ fmt.field(\"{field_name}\", unsafe {{ &*self.{field_name} }})  }}", field_name = field_name)
                    }
                    FieldType::Str => {
                        format!("fmt.field(\"{field_name}\", &debug_str_ptr(self.{field_name}))", field_name = field_name)
                    }
                    FieldType::MaybeStr => {
                        format!("fmt.field(\"{field_name}\", &debug_str_ptr(self.{field_name}))", field_name = field_name)
                    }
                    FieldType::Chars => {
                        format!("fmt.field(\"{field_name}\", &debug_str_ptr(self.{field_name}))", field_name = field_name)
                    }
                    FieldType::StringValue => {
                        format!("fmt.field(\"{field_name}\", &debug_str_ptr(self.{field_name}))", field_name = field_name)
                    }
                    FieldType::U8 => {
                        format!("fmt.field(\"{field_name}\", &self.{field_name})", field_name = field_name)
                    }
                    FieldType::Usize => {
                        format!("fmt.field(\"{field_name}\", &self.{field_name})", field_name = field_name)
                    }
                    FieldType::RawString => {
                        format!("fmt.field(\"{field_name}\", &debug_str_ptr(self.{field_name}))", field_name = field_name)
                    }
                    FieldType::RegexOptions => {
                        format!("if self.{field_name}.is_null() {{ fmt.field(\"{field_name}\", &Option::<()>::None) }} else {{ fmt.field(\"{field_name}\", unsafe {{ &*self.{field_name} }})  }}", field_name = field_name)
                    }
                };
                format!(
                    "        let fmt = &mut {};", fmt
                )
            })
            .collect::<Vec<_>>()
            .join("\n")
    }
}
