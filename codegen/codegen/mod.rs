use lib_ruby_parser_nodes::LiquidTemplate;

fn render(template_path: &str, output_path: &str) {
    let rendered = LiquidTemplate::new(template_path).render();
    std::fs::write(output_path, rendered).unwrap();
}

pub(crate) fn codegen() {
    render("codegen/messages.h.liquid", "../messages.h");
    render("codegen/messages.c.liquid", "../messages.c");

    render("codegen/nodes.h.liquid", "../nodes.h");
    render("codegen/nodes.c.liquid", "../nodes.c");

    render(
        "codegen/messages.rs.liquid",
        "../ruby-parser-c/src/message.rs",
    );
    render("codegen/nodes.rs.liquid", "../ruby-parser-c/src/node.rs");
}
