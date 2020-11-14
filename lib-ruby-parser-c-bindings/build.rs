extern crate bindgen;
extern crate lib_ruby_parser_nodes;

use lib_ruby_parser_nodes::{FieldType, Node};
use std::collections::HashMap;
use std::path::Path;

#[derive(Debug, Hash, Eq, PartialEq)]
enum CFieldType {
    NodePtr,
    NodeListPtr,
    RangePtr,
    CharPtr,
    SizeT,
}

impl CFieldType {
    fn list() -> Vec<Self> {
        vec![
            Self::NodePtr,
            Self::NodeListPtr,
            Self::RangePtr,
            Self::CharPtr,
            Self::SizeT,
        ]
    }

    fn c_declaration(&self, method_name: &str) -> String {
        let return_type = match self {
            CFieldType::NodePtr => "struct Node *",
            CFieldType::NodeListPtr => "struct NodeList *",
            CFieldType::RangePtr => "struct Range *",
            CFieldType::CharPtr => "char *",
            CFieldType::SizeT => "size_t ",
        };
        format!(
            "extern {}{}(struct Node *node);\n",
            return_type, method_name
        )
    }

    fn rust_definitions(&self, method_name: &str, meta: &CFieldMeta) -> String {
        let return_type = match self {
            CFieldType::NodePtr => "*mut Node",
            CFieldType::NodeListPtr => "*mut NodeList",
            CFieldType::RangePtr => "*mut Range",
            CFieldType::CharPtr => "*mut u8",
            CFieldType::SizeT => "size_t",
        };
        let default_value = match self {
            CFieldType::NodePtr
            | CFieldType::NodeListPtr
            | CFieldType::RangePtr
            | CFieldType::CharPtr => "std::ptr::null_mut()",
            CFieldType::SizeT => "0 as size_t",
        };
        let body = meta.nodes_with_this_field.iter().map(|node_with_field| {
            let cast_method = &node_with_field.handler;

            format!("        lib_ruby_parser::Node::{node_name}(lib_ruby_parser::nodes::{node_name} {{ {field_name}, .. }}) =>
                {cast_method}({field_name}),", node_name = node_with_field.node_name, field_name = node_with_field.field_name, cast_method = cast_method)
        }).collect::<Vec<_>>().join("\n");
        format!(
            "#[no_mangle]
pub extern \"C\" fn {method_name}(node: *mut Node) -> {return_type} {{
    match node_ptr_to_node_ref(node) {{
{body}
{default_branch}
    }}
}}\n",
            method_name = method_name,
            return_type = return_type,
            body = body,
            default_branch = if method_name == "get_expression_l" {
                // special case, all nodes have `expression_l`
                "".to_owned()
            } else {
                format!("        _ => {},", default_value)
            }
        )
    }
}

impl From<&FieldType> for CFieldType {
    fn from(field_type: &FieldType) -> Self {
        match field_type {
            FieldType::Node => Self::NodePtr,
            FieldType::MaybeNode => Self::NodePtr,
            FieldType::Nodes => Self::NodeListPtr,
            FieldType::Range => Self::RangePtr,
            FieldType::MaybeRange => Self::RangePtr,
            FieldType::Str => Self::CharPtr,
            FieldType::MaybeStr => Self::CharPtr,
            FieldType::Chars => Self::CharPtr,
            FieldType::StringValue => Self::CharPtr,
            FieldType::RawString => Self::CharPtr,
            FieldType::RegexOptions => Self::NodePtr,
            FieldType::U8 => Self::SizeT,
            FieldType::Usize => Self::SizeT,
        }
    }
}

fn handler_for_field_type(field_type: &FieldType) -> &'static str {
    match field_type {
        FieldType::Node => "boxed_node_to_ptr",
        FieldType::MaybeNode => "maybe_boxed_node_to_ptr",
        FieldType::Nodes => "nodes_vec_to_ptr",
        FieldType::Range => "range_to_ptr",
        FieldType::MaybeRange => "maybe_range_to_ptr",
        FieldType::Str => "str_to_ptr",
        FieldType::MaybeStr => "maybe_str_to_ptr",
        FieldType::Chars => "chars_to_ptr",
        FieldType::StringValue => "string_value_to_ptr",
        FieldType::RawString => "str_to_ptr",
        FieldType::RegexOptions => "maybe_boxed_node_to_ptr",
        FieldType::U8 => "u8_to_size_t",
        FieldType::Usize => "usize_to_size_t",
    }
}

fn method_name_for_field_type(field_type: &FieldType, field_name: &str) -> String {
    match field_type {
        FieldType::Node => format!("get_{}_node", field_name),
        FieldType::MaybeNode => format!("get_{}_node", field_name),
        FieldType::Nodes => format!("get_{}_list", field_name),
        FieldType::Range => format!("get_{}", field_name),
        FieldType::MaybeRange => format!("get_{}", field_name),
        FieldType::Str => format!("get_{}_str", field_name),
        FieldType::MaybeStr => format!("get_{}_str", field_name),
        FieldType::Chars => format!("get_{}_str", field_name),
        FieldType::StringValue => format!("get_{}_str", field_name),
        FieldType::RawString => format!("get_{}_str", field_name),
        FieldType::RegexOptions => format!("get_{}_node", field_name),
        FieldType::U8 => format!("get_{}_num", field_name),
        FieldType::Usize => format!("get_{}_num", field_name),
    }
}

struct NodeWithField {
    node_name: String,
    field_name: String,
    handler: String,
}

struct CFieldMeta {
    nodes_with_this_field: Vec<NodeWithField>,
}

struct FieldsRegistry {
    nodes: Vec<Node>,
    inner: HashMap<CFieldType, HashMap<String, CFieldMeta>>,
}

impl FieldsRegistry {
    fn new() -> Self {
        let mut inner = HashMap::new();
        inner.insert(CFieldType::NodePtr, HashMap::new());
        inner.insert(CFieldType::NodeListPtr, HashMap::new());
        inner.insert(CFieldType::RangePtr, HashMap::new());
        inner.insert(CFieldType::CharPtr, HashMap::new());
        inner.insert(CFieldType::SizeT, HashMap::new());
        Self {
            nodes: vec![],
            inner,
        }
    }

    fn filled_with_nodes(mut self, nodes: &[Node]) -> Self {
        for node in nodes.iter() {
            for field in node.fields.iter() {
                self.add_field(&field.field_type, &field.field_name, &node.struct_name);
            }
        }
        self.nodes = nodes.to_vec();

        self
    }

    fn add_c_field(
        &mut self,
        c_field_type: &CFieldType,
        field_name: &str,
        handler: &str,
        method_name: &str,
        node_name: &str,
    ) {
        let sub_registry = self.inner.get_mut(&c_field_type).unwrap();
        if !sub_registry.contains_key(method_name) {
            sub_registry.insert(
                method_name.to_owned(),
                CFieldMeta {
                    nodes_with_this_field: vec![],
                },
            );
        }
        let sub_registry = sub_registry.get_mut(method_name).unwrap();
        sub_registry.nodes_with_this_field.push(NodeWithField {
            node_name: node_name.to_owned(),
            field_name: field_name.to_owned(),
            handler: handler.to_owned(),
        });
        sub_registry
            .nodes_with_this_field
            .sort_by(|lhs, rhs| lhs.node_name.cmp(&rhs.node_name));
    }

    fn add_field(&mut self, field_type: &FieldType, field_name: &str, node_name: &str) {
        let c_field_type = CFieldType::from(field_type);
        let handler = handler_for_field_type(field_type);
        let method_name = method_name_for_field_type(field_type, field_name);

        self.add_c_field(&c_field_type, field_name, handler, &method_name, node_name);
    }

    fn get(&self, c_field_type: &CFieldType) -> &HashMap<String, CFieldMeta> {
        self.inner.get(c_field_type).unwrap()
    }

    fn c_declarations(&self) -> String {
        let mut result = "".to_owned();
        for field_type in CFieldType::list().iter() {
            let mut method_names = self.get(field_type).keys().collect::<Vec<_>>();
            method_names.sort();

            for method_name in method_names {
                result.push_str(&field_type.c_declaration(&method_name));
            }
        }
        result
    }

    fn rust_definitions(&self) -> String {
        let mut result = "".to_owned();
        for field_type in CFieldType::list().iter() {
            let mut method_names = self
                .get(field_type)
                .keys()
                .map(|e| e.to_owned())
                .collect::<Vec<_>>();
            method_names.sort();
            for method_name in method_names {
                let meta = self.get(field_type).get(&method_name).unwrap();
                result.push_str(&field_type.rust_definitions(&method_name, meta));
            }
        }

        let matches = self
            .nodes
            .iter()
            .map(|node| {
                format!(
                    "        lib_ruby_parser::Node::{}(_) => NodeType_NODE_{},",
                    node.struct_name,
                    node.filename.to_uppercase()
                )
            })
            .collect::<Vec<_>>()
            .join("\n");

        result.push_str(&format!(
            "
#[no_mangle]
pub extern \"C\" fn node_kind(node: *mut Node) -> u32 {{
    let node = node_ptr_to_node_ref(node);
    match node {{
{}
    }}
}}
",
            matches
        ));

        result
    }
}

fn relative_path(path: &str) -> String {
    Path::new(file!())
        .parent()
        .unwrap()
        .join(path)
        .to_str()
        .unwrap()
        .to_owned()
}

fn build_c_files() {
    let output_path = relative_path("../includes/gen.h");

    let nodes = lib_ruby_parser_nodes::nodes().unwrap();
    let fields_registry = FieldsRegistry::new().filled_with_nodes(&nodes);

    let structs = nodes
        .iter()
        .map(|node| format!("struct {}\n{{\n    char dummy;\n}};", node.struct_name))
        .collect::<Vec<_>>()
        .join("\n");

    let enum_definition = nodes
        .iter()
        .map(|node| format!("    NODE_{},", node.filename.to_uppercase()))
        .collect::<Vec<_>>()
        .join("\n");

    let contents = format!(
        "#ifndef LIB_RUBY_PARSER_GEN_H
#define LIB_RUBY_PARSER_GEN_H

#include <stddef.h>

{structs}
{fns}
enum NodeType
{{
{enum_definition}
}};

#endif // LIB_RUBY_PARSER_GEN_H
",
        structs = structs,
        fns = fields_registry.c_declarations(),
        enum_definition = enum_definition
    );

    std::fs::write(&output_path, contents).unwrap();
}

fn build_rs_files() {
    let nodes = lib_ruby_parser_nodes::nodes().unwrap();
    let fields_registry = FieldsRegistry::new().filled_with_nodes(&nodes);
    let node_gen_rs = relative_path("src/node_gen.rs");

    let contents = format!(
        "use crate::bindings::*;
use crate::node::helpers::*;

{fns}
",
        fns = fields_registry.rust_definitions()
    );

    std::fs::write(&node_gen_rs, contents).unwrap();
}

fn build_bindings() {
    println!("cargo:rerun-if-changed=../includes/types.h");

    let types_h = relative_path("../includes/types.h");

    let bindings = bindgen::Builder::default()
        .header(types_h)
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings");

    let out_path = relative_path("src/bindings.rs");
    bindings
        .write_to_file(out_path)
        .expect("Couldn't write bindings!");
}

fn main() {
    build_c_files();

    build_rs_files();

    build_bindings();
}
