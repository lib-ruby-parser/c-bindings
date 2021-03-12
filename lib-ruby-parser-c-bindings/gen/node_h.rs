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

typedef struct Node Node;
typedef struct Loc Loc;
typedef struct NodeList NodeList;
void node_free(Node *node);

{node_structs}

typedef enum NodeType
{{
    {enum_values}
}} NodeType;

typedef union InnerNode
{{
    {variants}
}} InnerNode;

typedef struct Node
{{
    NodeType node_type;
    InnerNode *inner;
}} Node;

void inner_node_free(InnerNode *inner_node, NodeType node_type);
void node_free(Node *node);

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
            .map(|node| format!("{} *_{};", node.struct_name, node.filename.to_lowercase()))
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
{comment}
typedef struct {struct_name}
{{
    {fields_declaration}
}} {struct_name};

void {name_lower}_node_free({struct_name} *node);",
            comment = self.comment(),
            struct_name = self.node.struct_name,
            fields_declaration = self.fields().join("\n    "),
            name_lower = self.node.filename.to_lowercase(),
        )
    }

    fn comment(&self) -> String {
        self.node
            .comment
            .lines()
            .map(|l| format!("// {}", l).trim_end().to_owned())
            .collect::<Vec<_>>()
            .join("\n")
    }

    fn fields(&self) -> Vec<String> {
        self.node
            .fields
            .iter()
            .flat_map(|f| Field::new(f).declaration())
            .collect()
    }
}
