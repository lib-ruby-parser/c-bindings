use lib_ruby_parser_nodes::{
    template::TemplateFns, Message, MessageWithField, Node, NodeWithField,
};

pub(crate) mod nodes {
    use super::*;

    pub(crate) fn camelcase_name(node: &Node) -> String {
        node.camelcase_name.to_owned()
    }

    pub(crate) fn comment(node: &Node) -> String {
        node.render_comment("//", 0)
    }

    pub(crate) fn upper_name(node: &Node) -> String {
        node.upper_name()
    }

    pub(crate) fn lower_name(node: &Node) -> String {
        node.lower_name()
    }

    pub(crate) fn enum_variant_name(node: &Node) -> String {
        format!("LIB_RUBY_PARSER_NODE_{}", node.upper_name())
    }

    pub(crate) fn union_member_name(node: &Node) -> String {
        let lower = node.lower_name();
        match &lower[..] {
            "and" | "break" | "case" | "class" | "const" | "false" | "float" | "for" | "if"
            | "int" | "or" | "return" | "true" | "while" => format!("{}_", lower),
            other => other.to_owned(),
        }
    }
}

pub(crate) mod node_fields {
    use super::*;

    pub(crate) fn name(node_with_field: &NodeWithField) -> String {
        lib_ruby_parser_bindings::helpers::nodes::fields::field_name(&node_with_field.field)
    }

    pub(crate) fn pack_fn_name(node_with_field: &NodeWithField) -> String {
        use lib_ruby_parser_nodes::NodeFieldType::*;

        match node_with_field.field.field_type {
            Node => "PACK_Ptr",
            Nodes => "PACK_NodeList",
            MaybeNode { .. } => "PACK_MaybePtr",
            Loc => "PACK_Loc",
            MaybeLoc => "PACK_MaybeLoc",
            Str { .. } => "PACK_StringPtr",
            MaybeStr { .. } => "PACK_MaybeStringPtr",
            StringValue => "PACK_Bytes",
            U8 => "PACK_Byte",
        }
        .to_string()
    }

    pub(crate) fn unpack_fn_name(node_with_field: &NodeWithField) -> String {
        use lib_ruby_parser_nodes::NodeFieldType::*;

        match node_with_field.field.field_type {
            Node => "UNPACK_Ptr",
            Nodes => "UNPACK_NodeList",
            MaybeNode { .. } => "UNPACK_MaybePtr",
            Loc => "UNPACK_Loc",
            MaybeLoc => "UNPACK_MaybeLoc",
            Str { .. } => "UNPACK_StringPtr",
            MaybeStr { .. } => "UNPACK_MaybeStringPtr",
            StringValue => "UNPACK_Bytes",
            U8 => "UNPACK_Byte",
        }
        .to_string()
    }

    pub(crate) fn field_type(node_with_field: &NodeWithField) -> String {
        use lib_ruby_parser_nodes::NodeFieldType::*;
        match node_with_field.field.field_type {
            Node => "LIB_RUBY_PARSER_NodePtr",
            Nodes => "LIB_RUBY_PARSER_NodeList",
            MaybeNode { .. } => "LIB_RUBY_PARSER_MaybeNodePtr",
            Loc => "LIB_RUBY_PARSER_Loc",
            MaybeLoc => "LIB_RUBY_PARSER_MaybeLoc",
            Str { .. } => "LIB_RUBY_PARSER_StringPtr",
            MaybeStr { .. } => "LIB_RUBY_PARSER_MaybeStringPtr",
            StringValue => "LIB_RUBY_PARSER_Bytes",
            U8 => "LIB_RUBY_PARSER_Byte",
        }
        .to_string()
    }

    pub(crate) fn blob_type(node_with_field: &NodeWithField) -> String {
        use lib_ruby_parser_nodes::NodeFieldType::*;

        match node_with_field.field.field_type {
            Node => "LIB_RUBY_PARSER_Ptr_BLOB",
            Nodes => "LIB_RUBY_PARSER_NodeList_BLOB",
            MaybeNode { .. } => "LIB_RUBY_PARSER_MaybePtr_BLOB",
            Loc => "LIB_RUBY_PARSER_Loc_BLOB",
            MaybeLoc => "LIB_RUBY_PARSER_MaybeLoc_BLOB",
            Str { .. } => "LIB_RUBY_PARSER_StringPtr_BLOB",
            MaybeStr { .. } => "LIB_RUBY_PARSER_MaybeStringPtr_BLOB",
            StringValue => "LIB_RUBY_PARSER_Bytes_BLOB",
            U8 => "LIB_RUBY_PARSER_Byte_BLOB",
        }
        .to_string()
    }

    pub(crate) fn drop_fn_name(node_with_field: &NodeWithField) -> String {
        use lib_ruby_parser_nodes::NodeFieldType::*;

        match node_with_field.field.field_type {
            Node => "LIB_RUBY_PARSER_drop_node_ptr",
            Nodes => "LIB_RUBY_PARSER_drop_node_list",
            MaybeNode { .. } => "LIB_RUBY_PARSER_drop_maybe_node_ptr",
            Loc => "LIB_RUBY_PARSER_drop_loc",
            MaybeLoc => "LIB_RUBY_PARSER_drop_maybe_loc",

            Str { .. } => "LIB_RUBY_PARSER_drop_string_ptr",

            MaybeStr { .. } => "LIB_RUBY_PARSER_drop_maybe_string_ptr",
            StringValue => "LIB_RUBY_PARSER_drop_bytes",
            U8 => "LIB_RUBY_PARSER_drop_byte",
        }
        .to_string()
    }

    pub(crate) fn comment(node_with_field: &NodeWithField) -> String {
        node_with_field.field.render_comment("//", 4)
    }
}

pub(crate) mod messages {
    use super::*;

    pub(crate) fn camelcase_name(message: &Message) -> String {
        message.camelcase_name.to_owned()
    }

    pub(crate) fn upper_name(message: &Message) -> String {
        message.upper_name()
    }

    pub(crate) fn lower_name(message: &Message) -> String {
        message.lower_name()
    }

    pub(crate) fn has_no_fields(message: &Message) -> bool {
        message.fields.0.is_empty()
    }

    pub(crate) fn comment(message: &Message) -> String {
        message.render_comment("//", 0)
    }
}

pub(crate) mod message_fields {
    use super::*;

    pub(crate) fn name(message_with_field: &MessageWithField) -> String {
        lib_ruby_parser_bindings::helpers::messages::fields::field_name(&message_with_field.field)
            .to_string()
    }

    pub(crate) fn field_type(message_with_field: &MessageWithField) -> String {
        use lib_ruby_parser_nodes::MessageFieldType::*;
        match message_with_field.field.field_type {
            Str => "LIB_RUBY_PARSER_StringPtr",
            Byte => "LIB_RUBY_PARSER_Byte",
        }
        .to_string()
    }

    pub(crate) fn blob_type(message_with_field: &MessageWithField) -> String {
        format!("{}_BLOB", field_type(message_with_field))
    }

    pub(crate) fn pack_fn_name(message_with_field: &MessageWithField) -> String {
        use lib_ruby_parser_nodes::MessageFieldType::*;
        match message_with_field.field.field_type {
            Str => "PACK_StringPtr",
            Byte => "PACK_Byte",
        }
        .to_string()
    }
    pub(crate) fn unpack_fn_name(message_with_field: &MessageWithField) -> String {
        use lib_ruby_parser_nodes::MessageFieldType::*;
        match message_with_field.field.field_type {
            Str => "UNPACK_StringPtr",
            Byte => "UNPACK_Byte",
        }
        .to_string()
    }

    pub(crate) fn drop_fn_name(message_with_field: &MessageWithField) -> String {
        use lib_ruby_parser_nodes::MessageFieldType::*;
        match message_with_field.field.field_type {
            Str => "LIB_RUBY_PARSER_drop_string_ptr",
            Byte => "LIB_RUBY_PARSER_drop_byte",
        }
        .to_string()
    }

    pub(crate) fn comment(message_with_field: &MessageWithField) -> String {
        message_with_field.field.render_comment("//", 4)
    }
}

pub(crate) fn build() -> TemplateFns {
    let mut fns = TemplateFns::new();

    fns.register_helper("node-camelcase-name", nodes::camelcase_name);
    fns.register_helper("node-comment", nodes::comment);
    fns.register_helper("node-upper-name", nodes::upper_name);
    fns.register_helper("node-lower-name", nodes::lower_name);
    fns.register_helper("node-c-enum-variant-name", nodes::enum_variant_name);
    fns.register_helper("node-c-union-member-name", nodes::union_member_name);

    fns.register_helper("node-field-name", node_fields::name);
    fns.register_helper("node-field-comment", node_fields::comment);
    fns.register_helper("node-field-type", node_fields::field_type);
    fns.register_helper("node-field-blob-type", node_fields::blob_type);
    fns.register_helper("node-field-pack-fn-name", node_fields::pack_fn_name);
    fns.register_helper("node-field-unpack-fn-name", node_fields::unpack_fn_name);
    fns.register_helper("node-field-drop-fn-name", node_fields::drop_fn_name);

    fns.register_helper("message-camelcase-name", messages::camelcase_name);
    fns.register_helper("message-upper-name", messages::upper_name);
    fns.register_helper("message-lower-name", messages::lower_name);
    fns.register_helper("message-comment", messages::comment);
    fns.register_predicate("message-has-no-fields", messages::has_no_fields);

    fns.register_helper("message-field-comment", message_fields::comment);
    fns.register_helper("message-field-name", message_fields::name);
    fns.register_helper("message-field-type", message_fields::field_type);
    fns.register_helper("message-field-blob-type", message_fields::blob_type);
    fns.register_helper("message-field-pack-fn-name", message_fields::pack_fn_name);
    fns.register_helper(
        "message-field-unpack-fn-name",
        message_fields::unpack_fn_name,
    );
    fns.register_helper("message-field-drop-fn-name", message_fields::drop_fn_name);

    fns
}

macro_rules! default_fns {
    () => {{
        fn generated_by(_: &lib_ruby_parser_nodes::template::GlobalContext) -> String {
            file!().to_string()
        }
        fn generated_by_for_node(_: &lib_ruby_parser_nodes::Node) -> String {
            file!().to_string()
        }
        let mut fns = $crate::codegen::fns::build();
        fns.register_helper("generated-by", generated_by);
        fns.register_helper("generated-by", generated_by_for_node);
        fns
    }};
}
pub(crate) use default_fns;
