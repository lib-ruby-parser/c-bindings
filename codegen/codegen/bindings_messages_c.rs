use lib_ruby_parser_nodes::{template::*, Message, MessageField};

const TEMPLATE: &str = "// This file is autogenerated by {{ helper generated-by }}

#include \"bindings.h\"

// constructors
{{ each message }}<dnl>
{{ helper constructor-sig }}
{
    LIB_RUBY_PARSER_DiagnosticMessage message = {
        .tag = LIB_RUBY_PARSER_MESSAGE_{{ helper message-upper-name }},
        .as = {
            .{{ helper message-lower-name }} = {
{{ each message-field }}<dnl>
                .{{ helper message-field-c-name }} = {{ helper message-field-c-unpack-fn-name }}({{ helper message-field-c-name }}_blob),
{{ end }}<dnl>
{{ if message-has-no-fields }}<dnl>
                .dummy = 0
{{ else }}<dnl>
{{ end }}<dnl>
            }
        }
    };
    return PACK_DiagnosticMessage(message);
}
{{ end }}<dnl>

// variant getters
{{ each message }}<dnl>
{{ helper variant-getter-sig }}
{
    const LIB_RUBY_PARSER_DiagnosticMessage *self = (const LIB_RUBY_PARSER_DiagnosticMessage *)self_blob;
    if (self->tag == LIB_RUBY_PARSER_MESSAGE_{{ helper message-upper-name }}) {
        return (const LIB_RUBY_PARSER_{{ helper message-camelcase-name }}_BLOB*)(&(self->as.{{ helper message-lower-name }}));
    } else {
        return NULL;
    }
}
{{ end }}<dnl>

// field getters
{{ each message }}<dnl>
{{ each message-field }}<dnl>
{{ helper field-getter-sig }}
{
    const LIB_RUBY_PARSER_{{ helper message-camelcase-name }} *self = (const LIB_RUBY_PARSER_{{ helper message-camelcase-name }} *)self_blob;
    return (const {{ helper message-field-c-blob-type }} *)(&(self->{{ helper message-field-c-name }}));
}
{{ end }}<dnl>
{{ end }}<dnl>

// variant predicates
{{ each message }}<dnl>
{{ helper variant-predicate-sig }}
{
    return ((const LIB_RUBY_PARSER_DiagnosticMessage *)self_blob)->tag == LIB_RUBY_PARSER_MESSAGE_{{ helper message-upper-name }};
}
{{ end }}<dnl>

void lib_ruby_parser__external__diagnostic_message__drop(LIB_RUBY_PARSER_DiagnosticMessage_BLOB *self_blob)
{
    LIB_RUBY_PARSER_DiagnosticMessage *self = (LIB_RUBY_PARSER_DiagnosticMessage *)self_blob;
    LIB_RUBY_PARSER_drop_diagnostic_message(self);
}
";

pub(crate) fn codegen() {
    let template = TemplateRoot::new(TEMPLATE).unwrap();
    let mut fns = crate::codegen::fns::default_fns!();

    fns.register::<Message, F::Helper>(
        "constructor-sig",
        lib_ruby_parser_bindings::helpers::messages::constructor::sig,
    );
    fns.register::<Message, F::Helper>(
        "variant-getter-sig",
        lib_ruby_parser_bindings::helpers::messages::variant_getter::sig,
    );
    fns.register::<MessageField, F::Helper>(
        "field-getter-sig",
        lib_ruby_parser_bindings::helpers::messages::field_getter::sig,
    );
    fns.register::<Message, F::Helper>(
        "variant-predicate-sig",
        lib_ruby_parser_bindings::helpers::messages::variant_predicate::sig,
    );

    let contents = template.render(ALL_DATA, &fns);
    std::fs::write("../bindings_messages.c", contents).unwrap();
}
