extern crate bindgen;
extern crate lib_ruby_parser_nodes;

use lib_ruby_parser_nodes::FieldType;
use std::collections::HashSet;
use std::path::Path;

fn sorted_set<T: std::cmp::Ord>(set: HashSet<T>) -> Vec<T> {
    let mut vec = set.into_iter().collect::<Vec<_>>();
    vec.sort();
    vec
}

fn build_c_files() {
    let nodes = lib_ruby_parser_nodes::nodes().unwrap();

    let mut node_methods = HashSet::new();
    let mut node_list_methods = HashSet::new();
    let mut range_methods = HashSet::new();
    let mut string_methods = HashSet::new();
    let mut usize_methods = HashSet::new();

    let mut structs = "".to_owned();

    for node in nodes.iter() {
        structs.push_str(&format!("struct {}\n{{\n}};\n", node.struct_name));

        for node in node.fields.iter() {
            let field_name = node.field_name.to_owned();
            match node.field_type {
                FieldType::Node | FieldType::MaybeNode => {
                    node_methods.insert(field_name.to_owned());
                }
                FieldType::Nodes => {
                    node_list_methods.insert(field_name.to_owned());
                }
                FieldType::Range | FieldType::MaybeRange => {
                    range_methods.insert(field_name.to_owned());
                }
                FieldType::Str
                | FieldType::MaybeStr
                | FieldType::Chars
                | FieldType::StringValue
                | FieldType::RawString
                | FieldType::RegexOptions => {
                    string_methods.insert(field_name.to_owned());
                }
                FieldType::U8 | FieldType::Usize => {
                    usize_methods.insert(field_name.to_owned());
                }
            }
        }
    }

    let mut fns = "".to_owned();
    for mid in sorted_set(node_methods).iter() {
        fns.push_str(&format!(
            "extern struct Node *get_{}_node(struct Node *node);\n",
            mid
        ));
    }
    for mid in sorted_set(node_list_methods).iter() {
        fns.push_str(&format!(
            "extern struct Node *get_{}_list(struct Node *node);\n",
            mid
        ));

        fns.push_str(&format!(
            "extern size_t get_{}_length(struct Node *node);\n",
            mid
        ));
    }
    for mid in sorted_set(range_methods).iter() {
        fns.push_str(&format!(
            "extern struct Range *get_{}(struct Node *node);\n",
            mid
        ));
    }
    for mid in sorted_set(string_methods).iter() {
        fns.push_str(&format!("extern char *get_{}(struct Node *node);\n", mid));
    }

    for mid in sorted_set(usize_methods).iter() {
        fns.push_str(&format!("extern size_t *get_{}(struct Node *node);\n", mid));
    }

    let target_file = Path::new(file!())
        .parent()
        .unwrap()
        .join("../includes/gen.h")
        .to_str()
        .unwrap()
        .to_owned();

    let contents = format!(
        "#ifndef LIB_RUBY_PARSER_GEN_H
#define LIB_RUBY_PARSER_GEN_H

#include <stddef.h>

{structs}
{fns}
#endif // LIB_RUBY_PARSER_GEN_H
",
        structs = structs,
        fns = fns
    );

    std::fs::write(&target_file, contents).unwrap();
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
    build_c_files();

    build_bindings();
}
