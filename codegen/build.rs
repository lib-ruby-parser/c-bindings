extern crate lib_ruby_parser_bindings;
extern crate lib_ruby_parser_nodes;

mod codegen;

fn main() {
    codegen::codegen()
}
