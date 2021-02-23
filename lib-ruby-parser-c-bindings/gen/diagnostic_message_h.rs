use super::Message;

pub struct DiagnosticMessageH {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl DiagnosticMessageH {
    pub fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        let messages = registry
            .sections
            .iter()
            .flat_map(|s| s.messages.clone())
            .collect();

        Self { messages }
    }

    pub fn write(&self) {
        std::fs::write("../src/diagnostic_message.h", self.contents()).unwrap();
    }

    fn contents(&self) -> String {
        format!(
            "#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_MESSAGE_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_MESSAGE_H

#include <stdint.h>

enum DiagnosticMessageType {{
    {enum_values}
}};

{structs}

union DiagnosticMessageData {{
    {union_variants}
    uint32_t other;
}};

struct DiagnosticMessage {{
    enum DiagnosticMessageType type;
    union DiagnosticMessageData data;
}};

void diagnostic_message_free(struct DiagnosticMessage);

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_MESSAGE_H",
            enum_values = self.enum_values().join(",\n    "),
            structs = self.structs().join("\n\n"),
            union_variants = self.union_variants().join("\n    ")
        )
    }

    fn enum_values(&self) -> Vec<String> {
        self.messages
            .iter()
            .map(|m| Message::new(m).enum_value())
            .collect()
    }

    fn structs(&self) -> Vec<String> {
        self.messages
            .iter()
            .filter(|m| !m.fields.is_empty())
            .map(|m| Message::new(m).struct_definition())
            .collect()
    }

    fn union_variants(&self) -> Vec<String> {
        self.messages
            .iter()
            .filter(|m| !m.fields.is_empty())
            .map(|m| Message::new(m).union_definition())
            .collect()
    }
}
