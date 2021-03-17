pub struct RustFreeH<'a> {
    nodes: &'a [lib_ruby_parser_nodes::Node],
}

impl<'a> RustFreeH<'a> {
    pub fn new(nodes: &'a [lib_ruby_parser_nodes::Node]) -> Self {
        Self { nodes }
    }

    pub fn write(&self) {
        std::fs::write("../src/rust_free.h", self.contents()).unwrap();
    }

    fn contents(&self) -> String {
        format!(
            "#ifndef LIB_RUBY_PARSER_RUST_FREE_H
#define LIB_RUBY_PARSER_RUST_FREE_H

struct Loc;
void rust_loc_free(struct Loc*);

struct Comment;
void rust_comments_free(struct Comment*);

struct CommentList;
void rust_comment_list_free(struct CommentList*);

struct Diagnostic;
void rust_diagnostics_free(struct Diagnostic*);

struct DiagnosticList;
void rust_diagnostic_list_free(struct DiagnosticList*);

struct MagicComment;
void rust_magic_comments_free(struct MagicComment*);

struct MagicCommentList;
void rust_magic_comment_list_free(struct MagicCommentList*);

void rust_string_free(char *);

union InnerNode;
void rust_inner_node_free(union InnerNode *);

// Nodes start
{node_free_fns}
// Nodes end

struct Node;
void rust_node_free(struct Node*);
void rust_nodes_free(struct Node*);

struct NodeList;
void rust_node_list_free(struct NodeList*);

struct Token;
void rust_tokens_free(struct Token*);

struct TokenList;
void rust_token_list_free(struct TokenList*);

struct ParserResult;
void rust_parser_result_free(struct ParserResult*);

#endif // LIB_RUBY_PARSER_RUST_FREE_H
",
            node_free_fns = self.node_free_fns().join("\n\n")
        )
    }

    fn node_free_fns(&self) -> Vec<String> {
        self.nodes
            .iter()
            .map(|node| {
                format!(
                    "struct {node_struct};
void rust_{lower}_node_free(struct {node_struct}*);",
                    node_struct = node.struct_name,
                    lower = node.filename.to_lowercase()
                )
            })
            .collect()
    }
}
