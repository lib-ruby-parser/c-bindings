#[cfg(feature = "generate-bindings")]
extern crate bindgen;
#[cfg(feature = "generate-bindings")]
extern crate lib_ruby_parser_nodes;

use std::path::Path;

#[cfg(feature = "generate-bindings")]
mod gen;
#[cfg(feature = "generate-bindings")]
use gen::{CFile, RustFile};

#[allow(dead_code)]
fn relative_path(path: &str) -> String {
    Path::new(file!())
        .parent()
        .unwrap()
        .join(path)
        .to_str()
        .unwrap()
        .to_owned()
}

#[cfg(feature = "generate-bindings")]
fn build_c_files() {
    let nodes = lib_ruby_parser_nodes::nodes().unwrap();
    let c_file = CFile::new(nodes);

    std::fs::write(&relative_path("../src/node.h"), c_file.node_h()).unwrap();
    std::fs::write(&relative_path("../src/node.c"), c_file.node_c()).unwrap();
}

#[cfg(feature = "generate-bindings")]
fn build_rs_files() {
    let output_path = relative_path("src/node_gen.rs");

    let nodes = lib_ruby_parser_nodes::nodes().unwrap();
    let contents = RustFile::new(nodes).code();

    std::fs::write(&output_path, contents).unwrap();
}

#[cfg(feature = "generate-bindings")]
fn build_bindings() {
    println!("cargo:rerun-if-changed=../src/types.h");
    println!("cargo:rerun-if-changed=../src/loc.h");
    println!("cargo:rerun-if-changed=../src/range.h");
    println!("cargo:rerun-if-changed=../src/token.h");
    println!("cargo:rerun-if-changed=../src/diagnostic.h");
    println!("cargo:rerun-if-changed=../src/comment.h");
    println!("cargo:rerun-if-changed=../src/magic_comment.h");
    println!("cargo:rerun-if-changed=../src/node_list.h");
    println!("cargo:rerun-if-changed=../src/parser_options.h");
    println!("cargo:rerun-if-changed=../src/custom_decoder.h");
    println!("cargo:rerun-if-changed=../src/token_rewriter.h");
    println!("cargo:rerun-if-changed=../src/parser_result.h");

    let types_h = relative_path("../src/types.h");

    let bindings = bindgen::Builder::default()
        .header(types_h)
        .whitelist_type("ParserOptions")
        .whitelist_type("ParserResult")
        .layout_tests(false)
        .generate()
        .expect("Unable to generate bindings");

    let out_path = relative_path("src/bindings.rs");
    bindings
        .write_to_file(out_path)
        .expect("Couldn't write bindings!");
}

#[cfg(feature = "generate-bindings")]
fn main() {
    build_c_files();

    build_rs_files();

    build_bindings();
}

#[cfg(not(feature = "generate-bindings"))]
fn main() {
    println!(
        "Running with disabled 'generate-bindings' feature, so bindgen is disabled too. All files are expected to be pre-generated"
    );
}
