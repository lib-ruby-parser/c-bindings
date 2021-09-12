use crate::codegen::helpers;
use lib_ruby_parser_bindings::helpers::messages::fields::field_name;

fn contents() -> String {
    let messages = lib_ruby_parser_nodes::messages();

    format!(
        "#ifndef LIB_RUBY_PARSER_EXTERNAL_C_SHARED_MESSAGES_H
#define LIB_RUBY_PARSER_EXTERNAL_C_SHARED_MESSAGES_H

// This file is autogenerated by {generator}

{structs}

typedef struct LIB_RUBY_PARSER_DiagnosticMessage {{
    enum {{
        {enum_variants}
    }} tag;
    union {{
        {union_members}
    }} as;
}} LIB_RUBY_PARSER_DiagnosticMessage;

{drop_fns}

void LIB_RUBY_PARSER_drop_diagnostic_message(LIB_RUBY_PARSER_DiagnosticMessage *message);

// Diagnostic
typedef struct LIB_RUBY_PARSER_Diagnostic
{{
    LIB_RUBY_PARSER_ErrorLevel level;
    LIB_RUBY_PARSER_DiagnosticMessage message;
    LIB_RUBY_PARSER_Loc loc;
}} LIB_RUBY_PARSER_Diagnostic;
typedef struct LIB_RUBY_PARSER_DiagnosticList
{{
    LIB_RUBY_PARSER_Diagnostic *ptr;
    uint64_t len;
    uint64_t capacity;
}} LIB_RUBY_PARSER_DiagnosticList;
void LIB_RUBY_PARSER_drop_diagnostic(LIB_RUBY_PARSER_Diagnostic *);

#endif // LIB_RUBY_PARSER_EXTERNAL_C_SHARED_MESSAGES_H
",
        generator = file!(),
        structs = messages.map(struct_definition).join("\n\n"),
        enum_variants = messages.map(enum_variant).join(",\n        "),
        union_members = messages.map(union_member).join("\n        "),
        drop_fns = messages.map(drop_fn).join("\n"),
    )
}

pub(crate) fn codegen() {
    std::fs::write("../messages.h", contents()).unwrap();
}

fn struct_definition(message: &lib_ruby_parser_nodes::Message) -> String {
    let fields_declaration = {
        let decls = message.fields.map(|field| {
            let type_name = helpers::messages::fields::field_type(field);
            format!("{t} {name};", t = type_name, name = field_name(field))
        });

        if decls.is_empty() {
            String::from("")
        } else {
            format!("\n    {}", decls.join("\n    "))
        }
    };

    format!(
        "typedef struct LIB_RUBY_PARSER_{struct_name}
{{{fields_declaration}
}} LIB_RUBY_PARSER_{struct_name};",
        struct_name = message.camelcase_name,
        fields_declaration = fields_declaration
    )
}
fn enum_variant(message: &lib_ruby_parser_nodes::Message) -> String {
    format!("LIB_RUBY_PARSER_MESSAGE_{}", message.upper_name())
}
fn union_member(message: &lib_ruby_parser_nodes::Message) -> String {
    format!(
        "LIB_RUBY_PARSER_{struct_name} {variant_name};",
        struct_name = message.camelcase_name,
        variant_name = message.lower_name()
    )
}
fn drop_fn(message: &lib_ruby_parser_nodes::Message) -> String {
    format!(
        "void LIB_RUBY_PARSER_drop_message_{variant}(LIB_RUBY_PARSER_{struct_name}* variant);",
        variant = message.lower_name(),
        struct_name = message.camelcase_name
    )
}
