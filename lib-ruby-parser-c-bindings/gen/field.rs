use lib_ruby_parser_nodes::FieldType;

pub struct Field<'a> {
    field: &'a lib_ruby_parser_nodes::Field,
}

impl<'a> Field<'a> {
    pub fn new(field: &'a lib_ruby_parser_nodes::Field) -> Self {
        Self { field }
    }

    pub fn c_name(&self) -> String {
        if self.field.field_name == "default" {
            "default_".to_owned()
        } else {
            self.field.field_name.to_owned()
        }
    }

    pub fn c_type(&self) -> &str {
        match self.field.field_type {
            FieldType::Node | FieldType::MaybeNode | FieldType::RegexOptions => "struct Node *",

            FieldType::Nodes => "struct NodeList *",

            FieldType::Loc | FieldType::MaybeLoc => "struct Loc *",

            FieldType::Str
            | FieldType::MaybeStr
            | FieldType::Chars
            | FieldType::StringValue
            | FieldType::RawString => "char *",

            FieldType::U8 | FieldType::Usize => "uint32_t ",
        }
    }

    pub fn free_fn_name(&self) -> Option<&'static str> {
        match self.field.field_type {
            FieldType::Node | FieldType::MaybeNode | FieldType::RegexOptions => {
                Some("maybe_node_free")
            }

            FieldType::Nodes => Some("maybe_node_list_free"),

            FieldType::Loc | FieldType::MaybeLoc => Some("maybe_loc_free"),

            FieldType::Str
            | FieldType::MaybeStr
            | FieldType::Chars
            | FieldType::StringValue
            | FieldType::RawString => Some("str_ptr_free"),

            FieldType::U8 | FieldType::Usize => None,
        }
    }

    pub fn declaration(&self) -> Vec<String> {
        let mut lines = self.comment();
        lines.push(format!("{}{};", self.c_type(), self.c_name()));
        lines
    }

    fn comment(&self) -> Vec<String> {
        self.field
            .comment
            .lines()
            .map(|l| format!("// {}", l).trim_end().to_owned())
            .collect()
    }
}
