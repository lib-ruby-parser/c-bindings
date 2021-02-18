use lib_ruby_parser_nodes::Field;

pub struct NodeField<'a> {
    rust_field: &'a Field,
}

impl<'a> NodeField<'a> {
    pub fn new(rust_field: &'a Field) -> Self {
        Self { rust_field }
    }

    pub fn field_name(&self) -> String {
        if self.rust_field.field_name == "default" {
            "default_".to_owned()
        } else {
            self.rust_field.field_name.to_owned()
        }
    }
}
