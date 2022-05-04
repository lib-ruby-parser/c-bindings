use lib_ruby_parser_nodes::LiquidTemplate;

fn render(template_path: &str, output_path: &str) {
    let rendered = LiquidTemplate::new(template_path).render();
    std::fs::write(output_path, rendered).unwrap();
}

pub(crate) fn codegen() {
    render("codegen/messages.h.liquid", "../messages.h");
    render("codegen/messages_test.c.liquid", "../tests/messages_test.c");

    render("codegen/nodes.h.liquid", "../nodes.h");
    render("codegen/nodes_test.c.liquid", "../tests/nodes_test.c");

    render(
        "codegen/messages.rs.liquid",
        "../ruby-parser-c/src/message.rs",
    );
    render("codegen/nodes.rs.liquid", "../ruby-parser-c/src/node.rs");
}
