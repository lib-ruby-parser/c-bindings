use super::Field;

pub struct NodeH<'a> {
    nodes: &'a [lib_ruby_parser_nodes::Node],
}

impl<'a> NodeH<'a> {
    pub fn new(nodes: &'a [lib_ruby_parser_nodes::Node]) -> Self {
        Self { nodes }
    }

    pub fn write(&self) {
        std::fs::write("../src/node.h", self.contents()).unwrap();
    }

    fn contents(&self) -> String {
        format!(
            "#ifndef LIB_RUBY_PARSER_GEN_H
#define LIB_RUBY_PARSER_GEN_H

#include <stddef.h>
#include <stdint.h>
#include \"node_list.h\"
#include \"loc.h\"

struct Node;
void node_free(struct Node *node);

{node_structs}

enum NodeType
{{
    {enum_values}
}};

union InnerNode
{{
    {variants}
}};

struct Node
{{
    enum NodeType node_type;
    union InnerNode *inner;
}};

void inner_node_free(union InnerNode *inner_node, enum NodeType node_type);
void node_free(struct Node *node);

#endif // LIB_RUBY_PARSER_GEN_H
",
            node_structs = self.node_structs().join("\n\n"),
            enum_values = self.enum_values().join("\n    "),
            variants = self.union_variants().join("\n    "),
        )
    }

    fn enum_values(&self) -> Vec<String> {
        self.nodes
            .iter()
            .map(|node| format!("NODE_{},", node.filename.to_uppercase()))
            .collect()
    }

    fn union_variants(&self) -> Vec<String> {
        self.nodes
            .iter()
            .map(|node| {
                format!(
                    "struct {} *_{};",
                    node.struct_name,
                    node.filename.to_lowercase()
                )
            })
            .collect()
    }

    fn node_structs(&self) -> Vec<String> {
        self.nodes.iter().map(|n| Node::new(n).code()).collect()
    }
}

struct Node<'a> {
    node: &'a lib_ruby_parser_nodes::Node,
}

impl<'a> Node<'a> {
    fn new(node: &'a lib_ruby_parser_nodes::Node) -> Self {
        Self { node }
    }

    fn code(&self) -> String {
        format!(
            "
struct {struct_name}
{{
    {fields_declaration}
}};

void {name_lower}_node_free(struct {struct_name} *node);",
            struct_name = self.node.struct_name,
            fields_declaration = self.fields().join("\n    "),
            name_lower = self.node.filename.to_lowercase(),
        )
    }

    fn fields(&self) -> Vec<String> {
        self.node
            .fields
            .iter()
            .map(|f| Field::new(f).declaration())
            .collect()
    }
}
