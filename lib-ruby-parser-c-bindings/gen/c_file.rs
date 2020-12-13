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
void maybe_node_free(struct Node *node)
{{
    if (node != NULL) {{
        node_free(node);
    }}
}}

struct NodeList;
void node_list_free(struct NodeList *list);
void maybe_node_list_free(struct NodeList *list)
{{
    if (list != NULL) {{
        node_list_free(list);
    }}
}}

struct Range;
void range_free(struct Range *range);
void maybe_range_free(struct Range *range)
{{
    if (range != NULL) {{
        range_free(range);
    }}
}}

{node_structs}

{node_enum}

union InnerNode
{{
{variants}
}};

struct Node
{{
    enum NodeType node_type;
    union InnerNode *inner;
}};

void inner_node_free(union InnerNode *inner_node, enum NodeType node_type)
{{
    switch (node_type)
    {{
{inner_node_free_branches}
    }}
    free(inner_node);
}}

void node_free(struct Node *node)
{{
    inner_node_free(node->inner, node->node_type);
    free(node);
}}

#endif // LIB_RUBY_PARSER_GEN_H
",
            node_structs = node_structs,
            node_enum = node_enum,
            variants = self.variants(),
            inner_node_free_branches = self.inner_node_free_branches_code()
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

    fn inner_node_free_branches_code(&self) -> String {
        self.rust_nodes
            .iter()
            .map(|node| {
                format!(
                    "    case NODE_{upper}:
        {lower}_node_free(inner_node->_{lower});
        break;",
                    upper = node.filename.to_uppercase(),
                    lower = node.filename.to_lowercase()
                )
            })
            .collect::<Vec<_>>()
            .join("\n")
    }
}
