pub struct FreeRs<'a> {
    nodes: &'a [lib_ruby_parser_nodes::Node],
}

impl<'a> FreeRs<'a> {
    pub fn new(nodes: &'a [lib_ruby_parser_nodes::Node]) -> Self {
        Self { nodes }
    }

    pub fn write(&self) {
        std::fs::write("src/free.rs", self.contents()).unwrap();
    }

    fn contents(&self) -> String {
        format!(
            "use crate::bindings;
use crate::ptr_free;

fn array_ptr_free<T>(ptr: *mut T, size: usize) {{
    drop(unsafe {{ Vec::from_raw_parts(ptr, size, size) }});
}}

#[no_mangle]
pub extern \"C\" fn input_free(ptr: *mut lib_ruby_parser::source::Input) {{ ptr_free(ptr); }}

#[no_mangle]
pub extern \"C\" fn rust_loc_free(ptr: *mut bindings::Loc) {{ ptr_free(ptr); }}

#[no_mangle]
pub extern \"C\" fn rust_comments_free(ptr: *mut bindings::Comment, size: u32) {{ array_ptr_free(ptr, size as usize); }}

#[no_mangle]
pub extern \"C\" fn rust_comment_list_free(ptr: *mut bindings::CommentList) {{ ptr_free(ptr); }}

#[no_mangle]
pub extern \"C\" fn rust_diagnostics_free(ptr: *mut bindings::Diagnostic, size: u32) {{ array_ptr_free(ptr, size as usize); }}

#[no_mangle]
pub extern \"C\" fn rust_diagnostic_list_free(ptr: *mut bindings::DiagnosticList) {{ ptr_free(ptr); }}

#[no_mangle]
pub extern \"C\" fn rust_magic_comments_free(ptr: *mut bindings::MagicComment, size: u32) {{ array_ptr_free(ptr, size as usize); }}

#[no_mangle]
pub extern \"C\" fn rust_magic_comment_list_free(ptr: *mut bindings::MagicCommentList) {{ ptr_free(ptr); }}

#[no_mangle]
pub extern \"C\" fn rust_string_free(ptr: *mut i8) {{ ptr_free(ptr); }}

#[no_mangle]
pub extern \"C\" fn rust_inner_node_free(ptr: *mut bindings::InnerNode) {{ ptr_free(ptr); }}

// Nodes start
{node_free_fns}
// Nodes end

#[no_mangle]
pub extern \"C\" fn rust_node_free(ptr: *mut bindings::Node) {{ ptr_free(ptr); }}
#[no_mangle]
pub extern \"C\" fn rust_nodes_free(ptr: *mut bindings::Node, size: u32) {{ array_ptr_free(ptr, size as usize); }}

#[no_mangle]
pub extern \"C\" fn rust_node_list_free(ptr: *mut bindings::NodeList) {{ ptr_free(ptr); }}

#[no_mangle]
pub extern \"C\" fn rust_tokens_free(ptr: *mut bindings::Token, size: u32) {{ array_ptr_free(ptr, size as usize); }}

#[no_mangle]
pub extern \"C\" fn rust_token_list_free(ptr: *mut bindings::TokenList) {{ ptr_free(ptr); }}

#[no_mangle]
pub extern \"C\" fn rust_parser_result_free(ptr: *mut bindings::ParserResult) {{ ptr_free(ptr); }}

#[no_mangle]
pub extern \"C\" fn free_token_name(ptr: *mut i8) {{ rust_string_free(ptr); }}

#[no_mangle]
pub extern \"C\" fn free_token_value(ptr: *mut i8) {{ rust_string_free(ptr); }}

#[no_mangle]
pub extern \"C\" fn free_rendered_diagnostic(ptr: *mut i8) {{ rust_string_free(ptr); }}

#[no_mangle]
pub extern \"C\" fn free_diagnostic_message(ptr: *mut i8) {{ rust_string_free(ptr); }}

#[no_mangle]
pub extern \"C\" fn free_loc_source(ptr: *mut i8) {{ rust_string_free(ptr); }}
",
            node_free_fns = self.node_free_fns().join("\n\n")
        )
    }

    fn node_free_fns(&self) -> Vec<String> {
        self.nodes
            .iter()
            .map(|node| {
                format!(
                    "#[no_mangle]
pub extern \"C\" fn rust_{lower}_node_free(ptr: *mut bindings::{node_struct}) {{ ptr_free(ptr); }}",
                    node_struct = node.struct_name,
                    lower = node.filename.to_lowercase()
                )
            })
            .collect()
    }
}
