use lib_ruby_parser_nodes::FieldType;

pub enum CFieldType {
    NodePtr,
    NodeList,
    RangePtr,
    CharPtr,
    SizeT,
}

impl CFieldType {
    pub fn new(rust_field_type: &FieldType) -> Self {
        match rust_field_type {
            FieldType::Node => Self::NodePtr,
            FieldType::MaybeNode => Self::NodePtr,
            FieldType::Nodes => Self::NodeList,
            FieldType::Range => Self::RangePtr,
            FieldType::MaybeRange => Self::RangePtr,
            FieldType::Str => Self::CharPtr,
            FieldType::MaybeStr => Self::CharPtr,
            FieldType::Chars => Self::CharPtr,
            FieldType::StringValue => Self::CharPtr,
            FieldType::RawString => Self::CharPtr,
            FieldType::RegexOptions => Self::NodePtr,
            FieldType::U8 => Self::SizeT,
            FieldType::Usize => Self::SizeT,
        }
    }

    pub fn declaration_code(&self) -> String {
        match &self {
            Self::NodePtr => "struct Node *",
            Self::NodeList => "struct NodeList *",
            Self::RangePtr => "struct Range *",
            Self::CharPtr => "char *",
            Self::SizeT => "size_t ",
        }
        .to_owned()
    }

    pub fn free_fn_name(&self) -> Option<&'static str> {
        match &self {
            Self::NodePtr => Some("node_free"),
            Self::NodeList => Some("node_list_free"),
            Self::RangePtr => Some("range_free"),
            Self::CharPtr => Some("char_ptr_free"),
            Self::SizeT => None,
        }
    }
}
