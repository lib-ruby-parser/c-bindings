pub struct Message<'a> {
    message: &'a lib_ruby_parser_nodes::Message,
}

impl<'a> Message<'a> {
    pub fn new(message: &'a lib_ruby_parser_nodes::Message) -> Self {
        Self { message }
    }

    pub fn enum_value(&self) -> String {
        camel_case_to_underscored(&self.message.name).to_uppercase()
    }

    pub fn struct_definition(&self) -> String {
        let fields = self
            .message
            .fields
            .iter()
            .map(|f| MessageField::new(f).declaration())
            .collect::<Vec<_>>();

        if fields.is_empty() {
            return format!(
                "typedef struct {name} {{}} {name};",
                name = self.message.name
            );
        }

        format!(
            "typedef struct {struct_name} {{
    {fields}
}} {struct_name};",
            struct_name = self.message.name,
            fields = fields.join("\n    ")
        )
    }

    pub fn union_definition(&self) -> String {
        format!(
            "{} {};",
            self.message.name,
            camel_case_to_underscored(&self.message.name).to_lowercase()
        )
    }
}

pub struct MessageField<'a> {
    field: &'a lib_ruby_parser_nodes::MessageField,
}

impl<'a> MessageField<'a> {
    pub fn new(field: &'a lib_ruby_parser_nodes::MessageField) -> Self {
        Self { field }
    }

    pub fn declaration(&self) -> String {
        format!("{}{};", self.c_type(), self.c_name())
    }

    pub fn c_name(&self) -> String {
        match &self.field.name[..] {
            "operator" => "operator_",
            other => other,
        }
        .to_owned()
    }

    pub fn c_type(&self) -> &str {
        match self.field.field_type {
            lib_ruby_parser_nodes::MessageFieldType::Str => "char *",
            lib_ruby_parser_nodes::MessageFieldType::Byte => "char ",
        }
    }
}

pub fn camel_case_to_underscored(s: &str) -> String {
    let mut words = vec![];
    let mut word = String::from("");

    for c in s.chars() {
        if c.is_uppercase() {
            // flush
            words.push(word);
            word = String::from("");
        }
        word.push(c);
    }

    words.push(word);

    words
        .into_iter()
        .filter(|w| !w.is_empty())
        .collect::<Vec<_>>()
        .join("_")
}
