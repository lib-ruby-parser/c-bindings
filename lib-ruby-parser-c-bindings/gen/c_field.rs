use super::CFieldType;
use lib_ruby_parser_nodes::Field;

pub struct CField<'a> {
    rust_field: &'a Field,
}

impl<'a> CField<'a> {
    pub fn new(rust_field: &'a Field) -> Self {
        Self { rust_field }
    }

    pub fn declaration_code(&self) -> String {
        format!(
            "    {field_type}{field_name};",
            field_type = CFieldType::new(&self.rust_field.field_type).declaration_code(),
            field_name = self.field_name()
        )
    }

    pub fn free_code(&self) -> Option<String> {
        let c_field_type = CFieldType::new(&self.rust_field.field_type);

        if c_field_type.is_nullable() {
            Some(format!(
                "    if (node->{field} != NULL) {{
        {fn_name}(node->{field});
    }}",
                fn_name = c_field_type.free_fn_name()?,
                field = self.field_name()
            ))
        } else {
            Some(format!(
                "    {fn_name}(node->{field});",
                fn_name = c_field_type.free_fn_name()?,
                field = self.field_name()
            ))
        }
    }

    pub fn field_name(&self) -> String {
        if self.rust_field.field_name == "default" {
            "default_".to_owned()
        } else {
            self.rust_field.field_name.to_owned()
        }
    }
}
