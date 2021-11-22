extern crate cbindgen;
extern crate lib_ruby_parser_nodes;

mod codegen;

fn main() {
    codegen::codegen();

    tokend_ids::codegen();
}

mod tokend_ids {
    const TOKEN_IDS: &str = "../token_ids.h";

    pub(crate) fn codegen() {
        cbindgen::Builder::new()
            .with_crate("../ruby-parser-c")
            .with_parse_deps(true)
            .with_parse_extra_bindings(&["lib-ruby-parser"])
            .with_no_includes()
            .include_item("Lexer")
            .generate()
            .expect("Unable to generate bindings")
            .write_to_file(TOKEN_IDS);

        let contents = std::fs::read_to_string(TOKEN_IDS).unwrap();
        let mut token_ids = vec![];
        for line in contents.lines() {
            if line.starts_with("/// Token") {
                // token comment line
                token_ids.push(line.to_string());
            } else if line.contains("const int32_t Lexer_") {
                let line = line
                    .replace("static ", "")
                    .replace("Lexer_", "LIB_RUBY_PARSER_TOKEN_");
                token_ids.push(line);
                token_ids.push(String::from(""))
            }
        }

        let contents = format!(
            "#ifndef LIB_RUBY_PARSER_TOKEN_IDS_H
#define LIB_RUBY_PARSER_TOKEN_IDS_H

#include <stdint.h>

{token_ids}
#endif // LIB_RUBY_PARSER_TOKEN_IDS_H",
            token_ids = token_ids.join("\n")
        );

        std::fs::write(TOKEN_IDS, contents).unwrap();
    }
}
