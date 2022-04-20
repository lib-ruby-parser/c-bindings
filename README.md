# c bindings for `lib-ruby-parser`

All structs, enums and functions are prefixed with `LIB_RUBY_PARSER_`. API mostly mirrors Rust version.

[Documentation](https://lib-ruby-parser.github.io/c-bindings/)

Pre-compiled library and header file are available on [Releases](https://github.com/lib-ruby-parser/c-bindings/releases), supported platforms:

+ `x86_64-apple-darwin`
+ `x86_64-unknown-linux-gnu`
+ `x86_64-pc-windows-msvc`
+ `x86_64-pc-windows-gnu`

## API

```c
char *input = "2 + 2";
LIB_RUBY_PARSER_ByteList input = LIB_RUBY_PARSER_new_bytes_from_cstr(
    input,
    strlen(input));

LIB_RUBY_PARSER_ParserOptions options = {
    .buffer_name = LIB_RUBY_PARSER_new_string_from_cstr("(eval)"),
    .decoder = {.decoder = {.f = NULL}},
    .record_tokens = false,
    .token_rewriter = {.token_rewriter = {.f = NULL}}};

LIB_RUBY_PARSER_ParserResult result = LIB_RUBY_PARSER_parse(input, options);
```

Parser input:
+ `LIB_RUBY_PARSER_ByteList input` - source code you want to parse
+ `LIB_RUBY_PARSER_ParserOptions options` - options of parsing:
    + `buffer_name` - name of your source code
    + `decoder` - decoder that is used if there's a magic comment with non-UTF-8 encoding
    + `record_token` specifies whether tokens should be recorded during parsing
    + `token_rewriter` - token rewriter, optional, called for each token **after** lexing but before shifting.

Parser output:
+ `LIB_RUBY_PARSER_ParserResult result` - all data that parser can output:
    + `LIB_RUBY_PARSER_Node *ast` - pointer to AST where
        + node is represented as `LIB_RUBY_PARSER_Node` that is a tagged union with `tag` and `as` fields
        + every node type is represented by its own struct like `LIB_RUBY_PARSER_Class`
    + `LIB_RUBY_PARSER_TokenList tokens` - a list of tokens (`ptr` + `len`) where
        + token is represented as `LIB_RUBY_PARSER_Token` with
            + `int32_t token_type` - type of the token (e.g. `LIB_RUBY_PARSER_tDEF`)
            + `LIB_RUBY_PARSER_Bytes token_value` - value of the token
            + `LIB_RUBY_PARSER_Loc loc` - location of the token
            + `int32_t lex_state_before` - state before token was lex-ed (useless unless you have a custom token rewriter)
            + `int32_t lex_state_after` - state after token was lex-ed (useless unless you have a custom token rewriter)
    + `LIB_RUBY_PARSER_DiagnosticList diagnostics` - a list of diagnostics (`ptr` + `len`) where
        + diagnostic is represented as `LIB_RUBY_PARSER_Diagnostic` with fields
            + `LIB_RUBY_PARSER_ErrorLevel level` - level of the diagnostic (error or warning)
            + `LIB_RUBY_PARSER_DiagnosticMessage message` - message that is a tagged union with `tag` and `as` fields, every message type is represented by its own struct like `LIB_RUBY_PARSER_UnterminatedList`
            + `LIB_RUBY_PARSER_Loc loc` - location of the diagnostic
    + `LIB_RUBY_PARSER_CommentList comments` - a list of comments (`ptr` + `len`) where
        + comment is represented as `LIB_RUBY_PARSER_Comment` with fields
            + `LIB_RUBY_PARSER_Loc location` - location of the comment
            + `LIB_RUBY_PARSER_CommentType kind` - kind of the comment (inline/document/unknown)
    + `LIB_RUBY_PARSER_MagicCommentList magic_comments` - a list of magic comments (`ptr` + `len`) where
        + magic comment is represented as `LIB_RUBY_PARSER_MagicComment` with fields
            + `LIB_RUBY_PARSER_MagicCommentKind kind`
            + `LIB_RUBY_PARSER_Loc key_l`
            + `LIB_RUBY_PARSER_Loc value_l`
    + `LIB_RUBY_PARSER_DecodedInput input` - decoded input, is different from initial input if it has encoding different from utf-8, with fields:
        + `LIB_RUBY_PARSER_String name` - initial name of the source code
        + `LIB_RUBY_PARSER_SourceLineList lines` - parsed source lines
        + `LIB_RUBY_PARSER_ByteList bytes` - (maybe re-encoded) initial input

# Development

+ Clone the repo
+ Set environment variables:
    + `TARGET` (e.g. `export TARGET=x86_64-apple-darwin`, no default value)
    + `CC` (e.g. `gcc`)
    + `BUILD_ENV` (`debug` or `release`, `debug` is the default value)
+ run `make tests/run` to run tests
+ run `make libruby_parser_c.a` (or `make libruby_parser_c.lib` for MSVC) to get a static library
+ run `make lib-ruby-parser.h` to get a header file

# Structure

+ Each directory has its own `build.mk` file that is included my the main `Makefile`
+ Rust parser with basic C bindings is located under `ruby-parser-c`.
+ Actual C bindings are located in `*.{h, c}` files in the root directory
+ `scripts` directory contains per-triplet additional configurations for `make`
+ `codegen` directory is a Rust micro-library that does code generation
+ `benchmark` directory contains a set of scripts to compare performance of Rust vs C vs Ripper
