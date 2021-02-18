use super::Field;

pub struct NodeC<'a> {
    nodes: &'a [lib_ruby_parser_nodes::Node],
}

impl<'a> NodeC<'a> {
    pub fn new(nodes: &'a [lib_ruby_parser_nodes::Node]) -> Self {
        Self { nodes }
    }

    pub fn write(&self) {
        std::fs::write("../src/node.c", self.contents()).unwrap();
    }

    fn contents(&self) -> String {
        format!(
            "#include <stdlib.h>
#include \"node.h\"

void maybe_node_free(struct Node *node)
{{
    if (node != NULL) {{
        node_free(node);
    }}
}}

void maybe_node_list_free(struct NodeList *list)
{{
    if (list != NULL) {{
        node_list_free(list);
    }}
}}

void maybe_loc_free(struct Loc *loc)
{{
    if (loc != NULL) {{
        loc_free(loc);
    }}
}}

{node_free_fns}

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
",
            node_free_fns = self.node_free_fns().join("\n"),
            inner_node_free_branches = self.inner_node_free_branches().join("\n    ")
        )
    }

    fn node_free_fns(&self) -> Vec<String> {
        self.nodes.iter().map(|n| FreeFn::new(n).code()).collect()
    }

    fn inner_node_free_branches(&self) -> Vec<String> {
        self.nodes
            .iter()
            .map(|node| {
                format!(
                    "case NODE_{upper}:
        {lower}_node_free(inner_node->_{lower});
        break;",
                    upper = node.filename.to_uppercase(),
                    lower = node.filename.to_lowercase()
                )
            })
            .collect()
    }
}

struct FreeFn<'a> {
    node: &'a lib_ruby_parser_nodes::Node,
}

impl<'a> FreeFn<'a> {
    fn new(node: &'a lib_ruby_parser_nodes::Node) -> Self {
        Self { node }
    }

    fn code(&self) -> String {
        format!(
            "
void {name_lower}_node_free(struct {struct_name} *node)
{{
    {free_fields}
    free(node);
}}",
            struct_name = self.node.struct_name,
            name_lower = self.node.filename.to_lowercase(),
            free_fields = self.free_fields().join("\n    ")
        )
    }

    fn free_fields(&self) -> Vec<String> {
        self.node
            .fields
            .iter()
            .filter_map(|f| {
                let f = Field::new(f);
                Some(format!("{}(node->{});", f.free_fn_name()?, f.c_name()))
            })
            .collect()
    }
}
