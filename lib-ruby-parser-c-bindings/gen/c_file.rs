use super::{CEnum, CStruct};
use lib_ruby_parser_nodes::Node;

pub struct CFile {
    rust_nodes: Vec<Node>,
}

impl CFile {
    pub fn new(rust_nodes: Vec<Node>) -> Self {
        Self { rust_nodes }
    }

    pub fn code(&self) -> String {
        let node_structs = self
            .rust_nodes
            .iter()
            .map(|node| CStruct::new(&node).code())
            .collect::<Vec<_>>()
            .join("\n");

        let node_enum = CEnum::new(&self.rust_nodes).code();

        format!(
            "#ifndef LIB_RUBY_PARSER_GEN_H
#define LIB_RUBY_PARSER_GEN_H

#include <stddef.h>

struct Node;
void node_free(struct Node *node);

struct NodeList
{{
    size_t len;
    struct Node *list;
}};

void node_list_free(struct NodeList *list);

struct Range
{{
    size_t begin_pos;
    size_t end_pos;
}};
void range_free(struct Range *range);
void char_ptr_free(char *range);
{node_structs}

{node_enum}

union InnerNode
{{
{variants}
}};

struct Node
{{
    enum NodeType node_type;
    union InnerNode inner;
}};

void node_free(struct Node *node)
{{
    if (node == NULL) {{
        return;
    }}
    switch (node->node_type)
    {{
{node_free_branches}
    }}
}}

#endif // LIB_RUBY_PARSER_GEN_H
",
            node_structs = node_structs,
            node_enum = node_enum,
            variants = self.variants(),
            node_free_branches = self.node_free_branches_code()
        )
    }

    fn variants(&self) -> String {
        self.rust_nodes
            .iter()
            .map(|node| {
                format!(
                    "    struct {} *_{};",
                    node.struct_name,
                    node.filename.to_lowercase()
                )
            })
            .collect::<Vec<_>>()
            .join("\n")
    }

    fn node_free_branches_code(&self) -> String {
        self.rust_nodes
            .iter()
            .map(|node| {
                format!(
                    "    case NODE_{upper}:
        {lower}_node_free(node->inner._{lower});
        break;",
                    upper = node.filename.to_uppercase(),
                    lower = node.filename.to_lowercase()
                )
            })
            .collect::<Vec<_>>()
            .join("\n")
    }
}
