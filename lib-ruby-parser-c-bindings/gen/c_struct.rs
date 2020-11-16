use super::CField;
use lib_ruby_parser_nodes::Node;

pub struct CStruct<'a> {
    rust_node: &'a Node,
    c_fields: Vec<CField<'a>>,
}

impl<'a> CStruct<'a> {
    pub fn new(rust_node: &'a Node) -> Self {
        Self {
            c_fields: rust_node
                .fields
                .iter()
                .map(|field| CField::new(field))
                .collect::<Vec<_>>(),
            rust_node,
        }
    }

    pub fn code(&self) -> String {
        format!(
            "
struct {struct_name}
{{
{fields_declaration}
}};

void {name_lower}_node_free(struct {struct_name} *node)
{{
{free_fields}
    free(node);
}}",
            struct_name = self.rust_node.struct_name,
            fields_declaration = self.fields_declaration(),
            name_lower = self.rust_node.filename.to_lowercase(),
            free_fields = self.free_fields_code()
        )
    }

    pub fn fields_declaration(&self) -> String {
        self.c_fields
            .iter()
            .map(CField::declaration_code)
            .collect::<Vec<_>>()
            .join("\n")
    }

    pub fn free_fields_code(&self) -> String {
        self.c_fields
            .iter()
            .map(CField::free_code)
            .filter_map(|code| code)
            .collect::<Vec<_>>()
            .join("\n")
    }
}
