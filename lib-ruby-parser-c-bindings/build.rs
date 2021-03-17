#[cfg(feature = "generate-bindings")]
extern crate bindgen;
#[cfg(feature = "generate-bindings")]
extern crate lib_ruby_parser_nodes;

#[cfg(feature = "generate-bindings")]
mod gen;

#[cfg(feature = "generate-bindings")]
fn build_c_files() {
    let nodes = lib_ruby_parser_nodes::nodes();
    let messages = lib_ruby_parser_nodes::messages();

    gen::NodeH::new(&nodes).write();
    gen::NodeC::new(&nodes).write();
    gen::DiagnosticMessageH::new(&messages).write();
    gen::RustFreeH::new(&nodes).write();
    gen::FreeRs::new(&nodes).write();
}

#[cfg(feature = "generate-bindings")]
fn build_rs_files() {
    let nodes = lib_ruby_parser_nodes::nodes();
    let messages = lib_ruby_parser_nodes::messages();

    gen::NodeGenRs::new(&nodes).write();
    gen::DiagnosticMessageRs::new(&messages).write();
}

#[cfg(feature = "generate-bindings")]
fn build_bindings() {
    println!("cargo:rerun-if-changed=../src/types.h");
    println!("cargo:rerun-if-changed=../src/loc.h");
    println!("cargo:rerun-if-changed=../src/token.h");
    println!("cargo:rerun-if-changed=../src/diagnostic.h");
    println!("cargo:rerun-if-changed=../src/comment.h");
    println!("cargo:rerun-if-changed=../src/magic_comment.h");
    println!("cargo:rerun-if-changed=../src/node_list.h");
    println!("cargo:rerun-if-changed=../src/parser_options.h");
    println!("cargo:rerun-if-changed=../src/custom_decoder.h");
    println!("cargo:rerun-if-changed=../src/token_rewriter.h");
    println!("cargo:rerun-if-changed=../src/parser_result.h");

    let bindings = bindgen::Builder::default()
        .header("../src/types.h")
        .whitelist_type("ParserOptions")
        .whitelist_type("ParserResult")
        .whitelist_type("DiagnosticMessage")
        .rustified_enum("LexStateActionKind")
        .rustified_enum("TokenRewriteAction")
        .rustified_enum("DecodingStatus")
        .rustified_enum("MagicCommentKind")
        .rustified_enum("ErrorLevel")
        .rustified_enum("DiagnosticMessageType")
        .layout_tests(false)
        .generate()
        .expect("Unable to generate bindings");

    bindings
        .write_to_file("src/bindings.rs")
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
