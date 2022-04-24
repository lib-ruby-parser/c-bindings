const HEADERS: &[&str] = &[
    "src/shared_byte_list.h",
    "src/string.h",
    "src/bytes.h",
    "src/source_line.h",
    "src/decoded_input.h",
    "src/loc.h",
    "src/token_ids.h",
    "src/token.h",
    "src/comment.h",
    "src/magic_comment.h",
    "src/nodes.h",
    "src/messages.h",
    "src/diagnostic.h",
    "src/decoder.h",
    "src/token_rewriter.h",
    "src/parser_options.h",
    "src/parser_result.h",
    "src/api.h",
];

fn process_header(header_path: &str, sys_includes: &mut Vec<String>, contents: &mut Vec<String>) {
    println!("Processing {:?}", header_path);

    let header = std::fs::read_to_string(header_path).expect("failed to read header file");
    let mut in_test_section = false;

    for line in header.lines() {
        if in_test_section {
            continue;
        }
        if line.starts_with("#ifdef TEST_ENV") {
            if in_test_section {
                panic!("nested TEST_ENV sections are not supported");
            }
            in_test_section = true;
            continue;
        }
        if line.starts_with("#endif") && in_test_section {
            in_test_section = false;
            continue;
        }

        if line.starts_with("#include <") {
            // sys include
            sys_includes.push(line.to_string());
            continue;
        }
        if line.starts_with("#include \"") {
            // local include, skip
            continue;
        }
        if line.starts_with("#ifndef LIB_RUBY_PARSER_")
            || (line.starts_with("#define LIB_RUBY_PARSER_") && line.ends_with("_H"))
            || line.starts_with("#endif // LIB_RUBY_PARSER_")
        {
            // header guard, skip
            continue;
        }

        if line.is_empty() {
            if let Some(last_line) = contents.last() {
                if last_line.is_empty() {
                    // drop 2 consecutive empty lines
                    continue;
                }
            }
        }
        contents.push(line.to_string())
    }
}

fn main() {
    let mut sys_includes = vec![];
    let mut contents = vec![];

    for header in HEADERS {
        process_header(*header, &mut sys_includes, &mut contents);
    }

    sys_includes.sort();
    sys_includes.dedup();

    let contents = format!(
        "#ifndef LIB_RUBY_PARSER_H
#define LIB_RUBY_PARSER_H

/// @file lib-ruby-parser.h

{sys_includes}
{contents}
#endif // LIB_RUBY_PARSER_H
",
        sys_includes = sys_includes.join("\n"),
        contents = contents.join("\n")
    );

    std::fs::write("src/lib-ruby-parser.h", contents).unwrap();
}
