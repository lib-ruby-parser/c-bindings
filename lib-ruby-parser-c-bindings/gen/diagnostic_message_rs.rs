use super::message::{camel_case_to_underscored, MessageField};
use super::Message;

pub struct DiagnosticMessageRs {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl DiagnosticMessageRs {
    pub fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        let messages = registry
            .sections
            .iter()
            .flat_map(|s| s.messages.clone())
            .collect();

        Self { messages }
    }

    pub fn write(&self) {
        std::fs::write("src/diagnostic_message.rs", self.contents()).unwrap();
    }

    fn contents(&self) -> String {
        format!(
            "use crate::bindings;
use crate::diagnostic_payload::*;

impl From<lib_ruby_parser::DiagnosticMessage> for bindings::DiagnosticMessage {{
    fn from(message: lib_ruby_parser::DiagnosticMessage) -> Self {{
        match message {{
            {match_branches_from_rust_to_c}
        }}
    }}
}}

impl From<bindings::DiagnosticMessage> for lib_ruby_parser::DiagnosticMessage {{
    fn from(message: bindings::DiagnosticMessage) -> Self {{
        match message.type_ {{
            {match_branches_from_c_to_rust}
        }}
    }}
}}

pub(crate) fn inner_diagnostic_message_free(message: bindings::DiagnosticMessage) {{
    match message.type_ {{
        {match_branches_for_free_fn},
        _ => {{}}
    }}
}}
",
            match_branches_from_rust_to_c =
                self.match_branches_from_rust_to_c().join(",\n            "),
            match_branches_from_c_to_rust =
                self.match_branches_from_c_to_rust().join(",\n            "),
            match_branches_for_free_fn = self.match_branches_for_free_fn().join("\n        ")
        )
    }

    fn match_branches_from_rust_to_c(&self) -> Vec<String> {
        self.messages
            .iter()
            .map(|m| MatchBranchFromRustToC::new(m).code())
            .collect()
    }

    fn match_branches_from_c_to_rust(&self) -> Vec<String> {
        self.messages
            .iter()
            .map(|m| MatchBranchFromCToRust::new(m).code())
            .collect()
    }

    fn match_branches_for_free_fn(&self) -> Vec<String> {
        self.messages
            .iter()
            .filter(|m| m.fields.len() > 0)
            .map(|m| MatchBranchForFreeFn::new(m).code())
            .collect()
    }
}

struct MatchBranchFromRustToC<'a> {
    message: &'a lib_ruby_parser_nodes::Message,
}

impl<'a> MatchBranchFromRustToC<'a> {
    fn new(message: &'a lib_ruby_parser_nodes::Message) -> Self {
        Self { message }
    }

    fn code(&self) -> String {
        format!(
            "lib_ruby_parser::DiagnosticMessage::{camelcased} {{ {fields_deconstruct} }} => {{
                bindings::DiagnosticMessage {{
                    type_: bindings::DiagnosticMessageType::{screaming_upcased},
                    data: bindings::DiagnosticMessageData {{
                        {union_value}
                    }},
                }}
            }}",
            camelcased = self.message.name,
            fields_deconstruct = self.fields_deconstruct().join(", "),
            screaming_upcased = Message::new(&self.message).enum_value(),
            union_value = self.union_value(),
        )
    }

    fn union_value(&self) -> String {
        if self.message.fields.is_empty() {
            return "other: 42".to_string();
        }

        format!(
            "{lowercased}: bindings::{camelcased} {{ {fields_construct} }},",
            lowercased = camel_case_to_underscored(&self.message.name).to_lowercase(),
            camelcased = self.message.name,
            fields_construct = self.fields_construct().join(", ")
        )
    }

    fn fields_deconstruct(&self) -> Vec<String> {
        self.message.fields.iter().map(|f| f.name.clone()).collect()
    }

    fn fields_construct(&self) -> Vec<String> {
        self.message
            .fields
            .iter()
            .map(|f| {
                let rust_name = f.name.clone();
                let c_name = MessageField::new(f).c_name();

                format!("{}: DiagnosticPayload::new({}).unwrap()", c_name, rust_name)
            })
            .collect()
    }
}

struct MatchBranchFromCToRust<'a> {
    message: &'a lib_ruby_parser_nodes::Message,
}

impl<'a> MatchBranchFromCToRust<'a> {
    fn new(message: &'a lib_ruby_parser_nodes::Message) -> Self {
        Self { message }
    }

    fn code(&self) -> String {
        format!(
            "bindings::DiagnosticMessageType::{screaming_upcased} => {{
                {cast_fields}
                lib_ruby_parser::DiagnosticMessage::{camelcased} {{ {fields_construct} }}
            }}",
            screaming_upcased = Message::new(&self.message).enum_value(),
            cast_fields = self.cast_fields().join("\n                "),
            camelcased = self.message.name,
            fields_construct = self.fields_construct().join(", ")
        )
    }

    fn fields_construct(&self) -> Vec<String> {
        self.message
            .fields
            .iter()
            .map(|f| {
                format!(
                    "{name}: DiagnosticPayload::new({name}).unwrap()",
                    name = f.name.clone()
                )
            })
            .collect()
    }

    fn cast_fields(&self) -> Vec<String> {
        self.message
            .fields
            .iter()
            .map(|f| GetField::new(f, &self.message.name).code())
            .collect()
    }
}

struct GetField<'a> {
    field: &'a lib_ruby_parser_nodes::MessageField,
    struct_name: &'a str,
}

impl<'a> GetField<'a> {
    fn new(field: &'a lib_ruby_parser_nodes::MessageField, struct_name: &'a str) -> Self {
        Self { field, struct_name }
    }

    fn code(&self) -> String {
        format!(
            "let {rust_name} = unsafe {{ message.data.{lower} }}.{c_name};",
            rust_name = self.field.name,
            c_name = MessageField::new(self.field).c_name(),
            lower = camel_case_to_underscored(self.struct_name).to_lowercase()
        )
    }
}

struct MatchBranchForFreeFn<'a> {
    message: &'a lib_ruby_parser_nodes::Message,
}

impl<'a> MatchBranchForFreeFn<'a> {
    fn new(message: &'a lib_ruby_parser_nodes::Message) -> Self {
        Self { message }
    }

    fn code(&self) -> String {
        format!(
            "bindings::DiagnosticMessageType::{screaming_upcased} => {{
            {free_fields}
        }}",
            screaming_upcased = Message::new(&self.message).enum_value(),
            free_fields = self.free_fields().join("\n            ")
        )
    }

    fn free_fields(&self) -> Vec<String> {
        self.message
            .fields
            .iter()
            .map(|f| FreeField::new(f, &self.message.name).code())
            .collect()
    }
}

struct FreeField<'a> {
    field: &'a lib_ruby_parser_nodes::MessageField,
    struct_name: &'a str,
}

impl<'a> FreeField<'a> {
    fn new(field: &'a lib_ruby_parser_nodes::MessageField, struct_name: &'a str) -> Self {
        Self { field, struct_name }
    }

    fn code(&self) -> String {
        match self.field.field_type {
            lib_ruby_parser_nodes::MessageFieldType::Str => {
                format!(
                    "let ptr = unsafe {{ message.data.{lower} }}.{field_name}; unsafe {{ std::ffi::CString::from_raw(ptr) }};",
                    lower = camel_case_to_underscored(self.struct_name).to_lowercase(),
                    field_name = MessageField::new(self.field).c_name()
                )
            }
            lib_ruby_parser_nodes::MessageFieldType::Byte => {
                format!("// free_byte({})", self.field.name)
            }
        }
    }
}
