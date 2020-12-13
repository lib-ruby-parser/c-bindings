extern crate bindgen;
extern crate lib_ruby_parser_nodes;

use std::path::Path;

mod gen;
use gen::{CFile, RustFile};

fn relative_path(path: &str) -> String {
    Path::new(file!())
        .parent()
        .unwrap()
        .join(path)
        .to_str()
        .unwrap()
        .to_owned()
}

fn build_c_files() {
    let output_path = relative_path("../includes/gen.h");

    let nodes = lib_ruby_parser_nodes::nodes().unwrap();
    let contents = CFile::new(nodes).code();

    std::fs::write(&output_path, contents).unwrap();
}

fn build_rs_files() {
    let output_path = relative_path("src/node_gen.rs");

    let nodes = lib_ruby_parser_nodes::nodes().unwrap();
    let contents = RustFile::new(nodes).code();

    std::fs::write(&output_path, contents).unwrap();
}

fn build_bindings() {
    println!("cargo:rerun-if-changed=../includes/types.h");

    let types_h = relative_path("../includes/types.h");

    let bindings = bindgen::Builder::default()
        .header(types_h)
        .whitelist_type("ParserOptions")
        .whitelist_type("ParserResult")
        .generate()
        .expect("Unable to generate bindings");

    let out_path = relative_path("src/bindings.rs");
    bindings
        .write_to_file(out_path)
        .expect("Couldn't write bindings!");
}

fn main() {
    build_c_files();

    build_rs_files();

    build_bindings();
}
