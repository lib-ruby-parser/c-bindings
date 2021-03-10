# c bindings for `lib-ruby-parser`

You can find some examples in `test/test.c`.

## API

1. `struct ParserResult *parse(struct ParserOptions *options, const char *input, uint32_t length)`

    Parses given input into `ParserResult`

    ```c
    const char *input = "2 + 2";
    struct ParserOptions options = {
        .buffer_name = "test.rb",
        .debug = true,
        .record_tokens = true};
    struct ParserResult *result = parse(&options, input, strlen(input));

    // 1. AST
    struct Node *node = result->ast;

    // 2. Tokens
    struct TokenList *tokens = result->tokens;
    for (uint32_t i = 0; i < tokens->len; i++) {
        struct Token token = tokens->list[i];

        // token_type
        int token_type = token.token_type;
        char *tok_name = token_name(token_type);
        free(tok_name);

        // token_value
        char *token_value = token.token_value;

        // loc
        struct Loc *loc = token.loc;
    }

    // 3. Diagnostics
    struct DiagnosticList *diagnostics = result->diagnostics;
    for (uint32_t i = 0; i < diagnostics->len; i++) {
        struct Token diagnostic = diagnostics->list[i];

        // level
        enum ErrorLevel level = diagnostic.level;

        // message
        struct DiagnosticMessage mesage = diagnostic.message;
        char *only_message = diagnostic_render_message(message);
        char *fully_rendered = diagnostic_render(message, result->input);

        // loc
        struct Loc *loc = diagnostic.loc;
    }

    // 4. Comments
    struct CommentList *comments = result->comments;
    for (uint32_t i = 0; i < comments->len; i++) {
        struct Comment comment = comments->list[i];

        // loc
        struct Loc *loc = comment.loc;
    }

    // 5. Magic comments
    struct MagicCommentList *magic_comments = result->magic_comments;
    for (uint32_t i = 0; i < magic_comments->len; i++) {
        struct MagicComment magic_comment = magic_comments->list[i];

        // kind
        enum MagicCommentKind kind = magic_comment.kind;

        // key location
        struct Loc *key_l = magic_comment.key_l;

        // value location
        struct Loc *value_l = magic_comment.value_l;
    }

    // 6. Decoded input
    char *input = result->input;
    const char *ptr = input_ptr(input);
    uint32_t len = input_len(input);
    ```
2. `void parser_result_free(struct ParserResult *result)`

    Deallocates the memory of the `ParserResult`, recursively `free`s all fields

3. `node->node_type` and `node->inner`

    Generic `Node` struct has only two fields: `node_type` and `inner`.
    `node_type` is an enum that can be used to identify which variant of the `inner` union should be used.

    ```c
    assert(node->node_type == NODE_SEND);
    struct Send *send = node->inner->_send;
    ```

    This way you can "unwrap" generic node and convert it into specific node type.
    Specialized node types fully mirror API of Rust nodes, check [full documentation](https://docs.rs/lib-ruby-parser) to understand what is a specialized `Node`.

5. `uint32_t loc_size(struct Loc *loc)`

    Returns size of the loc (literally `end_pos - begin_pos`)

6. `char *loc_source(struct Loc *loc, Input* input)`

    Returns source of the given loc. `input` can be taken from the `ParserResult` struct.
