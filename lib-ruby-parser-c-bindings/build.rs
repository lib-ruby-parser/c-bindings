extern crate bindgen;
extern crate lib_ruby_parser_nodes;

use lib_ruby_parser_nodes::{FieldType, Node};
use std::path::Path;

fn fields(node: &Node) -> String {
    let mut result = "".to_owned();

    for field in node.fields.iter() {
        let field_name = match &field.field_name[..] {
            "default" => "default_",
            other => other,
        };

        let field_declaration = match field.field_type {
            FieldType::Node => format!("struct Node *{}", field_name),
            FieldType::Nodes => format!("struct NodeList *{}", field_name),
            FieldType::MaybeNode => format!("struct Node *{}", field_name),
            FieldType::Range => format!("struct Range *{}", field_name),
            FieldType::MaybeRange => format!("struct Range *{}", field_name),
            FieldType::Str => format!("struct StringValue *{}", field_name),
            FieldType::MaybeStr => format!("struct StringValue *{}", field_name),
            FieldType::Chars => format!("struct StringValue *{}", field_name),
            FieldType::StringValue => format!("struct StringValue *{}", field_name),
            FieldType::U8 => format!("unsigned char {}", field_name),
            FieldType::Usize => format!("size_t {}", field_name),
            FieldType::RawString => format!("struct StringValue *{}", field_name),
            FieldType::RegexOptions => format!("struct StringValue *{}", field_name),
        };

        result.push_str(&format!("    {};\n", field_declaration));
    }

    result
}

fn build_c_files() {
    let nodes = &lib_ruby_parser_nodes::nodes().unwrap();
    let target_dir = Path::new(file!())
        .parent()
        .unwrap()
        .join("../includes/gen")
        .to_str()
        .unwrap()
        .to_owned();

    std::fs::create_dir_all(&target_dir).unwrap();

    let mut includes = "".to_owned();
    let mut enum_code = "".to_owned();
    let mut union_code = "".to_owned();

    for node in nodes.iter() {
        let mut contents = "".to_owned();
        let guard = format!("NODE_{}_H", node.filename.to_uppercase());

        contents.push_str(&format!(
            "#ifndef {guard}\n#define {guard}\n\n",
            guard = guard
        ));
        contents.push_str(
            "#include \"node.h\"
#include \"../range.h\"
#include <stddef.h>

",
        );
        contents.push_str(&format!("struct {}\n", node.struct_name));
        contents.push_str("{\n");
        contents.push_str(&fields(node));
        contents.push_str("};\n\n");
        contents.push_str(&format!("#endif // {}\n", guard));

        std::fs::write(&format!("{}/{}.h", target_dir, node.filename), contents).unwrap();

        includes.push_str(&format!("#include \"{}.h\"\n", node.filename));
        enum_code.push_str(&format!("    {},\n", node.filename.to_uppercase()));
        union_code.push_str(&format!(
            "    struct {name} *{name};\n",
            name = node.struct_name
        ));
    }

    let root = format!(
        "#ifndef NODE_NODE_H
#define NODE_NODE_H

{includes}
enum NodeKind
{{
{enum_code}}};

union InnerNode
{{
{union_code}}};

struct Node
{{
    enum NodeKind kind;
    union InnerNode inner;
}};

#endif // NODE_NODE_H
",
        includes = includes,
        enum_code = enum_code,
        union_code = union_code
    );

    std::fs::write(&format!("{}/node.h", target_dir), root).unwrap();
}

fn build_bindings() {
    println!("cargo:rerun-if-changed=../includes/types.h");

    let types_h = Path::new(file!())
        .parent()
        .unwrap()
        .join("../includes/types.h")
        .to_str()
        .unwrap()
        .to_owned();

    let bindings = bindgen::Builder::default()
        .header(types_h)
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .impl_debug(false)
        .generate()
        .expect("Unable to generate bindings");

    let out_path = Path::new(file!()).parent().unwrap().join("src/bindings.rs");
    bindings
        .write_to_file(out_path)
        .expect("Couldn't write bindings!");
}

fn main() {
    // build_c_files();

    build_bindings();
}
