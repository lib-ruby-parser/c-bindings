use lib_ruby_parser_nodes::template::*;

const TEMPLATE: &str = "#ifndef LIB_RUBY_PARSER_MESSAGES_H
#define LIB_RUBY_PARSER_MESSAGES_H

// This file is autogenerated by {{ helper generated-by }}

#include <stdint.h>
#include \"string.h\"

{{ each message }}<dnl>
{{ helper message-comment }}
typedef struct LIB_RUBY_PARSER_{{ helper message-camelcase-name }}
{
{{ if message-has-no-fields }}<dnl>
    // dummy byte (zero-sized structs are no allowed in C)
    uint8_t dummy;
{{ else }}<dnl>
{{ end }}<dnl>
<dnl>
{{ each message-field }}<dnl>
{{ helper message-field-comment }}
    {{ helper message-field-c-field-type }} {{ helper message-field-c-name }};
{{ end }}<dnl>
} LIB_RUBY_PARSER_{{ helper message-camelcase-name }};

{{ end }}<dnl>

typedef struct LIB_RUBY_PARSER_DiagnosticMessage {
    enum {
{{ each message }}<dnl>
        LIB_RUBY_PARSER_MESSAGE_{{ helper message-upper-name }},
{{ end }}<dnl>
    } tag;

    union {
{{ each message }}<dnl>
        LIB_RUBY_PARSER_{{ helper message-camelcase-name }} {{ helper message-lower-name }};
{{ end }}<dnl>
    } as;
} LIB_RUBY_PARSER_DiagnosticMessage;

{{ each message }}<dnl>
void LIB_RUBY_PARSER_drop_message_{{ helper message-lower-name }}(LIB_RUBY_PARSER_{{ helper message-camelcase-name }}* variant);
{{ end }}<dnl>

void LIB_RUBY_PARSER_drop_diagnostic_message(LIB_RUBY_PARSER_DiagnosticMessage *message);

#endif // LIB_RUBY_PARSER_MESSAGES_H
";

pub(crate) fn codegen() {
    let template = TemplateRoot::new(TEMPLATE).unwrap();
    let fns = crate::codegen::fns::default_fns!();

    let contents = template.render(ALL_DATA, &fns);
    std::fs::write("../messages.h", contents).unwrap();
}
