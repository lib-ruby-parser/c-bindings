# c bindings for `lib-ruby-parser`

You can find some examples in `main.c` and `test.c`.

## API

1. `struct ParserResult *parse(const char *input, uint32_t length)`

    Parses given input into `ParserResult`

    ```c
    const char *input = "2 + 2";
    struct ParserResult *result = parse(input, strlen(input));
    struct Node *node = result->ast;
    struct TokenList *tokens = result->tokens;
    struct Diagnostics *diagnostics = result->diagnostics;
    struct CommentList *comments = result->comments;
    struct MagicCommentList *magic_comments = result->magic_comments;
    char *input = result->input;
    ```
2. `void parser_result_free(struct ParserResult *result)`

    Deallocates the memory of the `ParserResult`, recursively `free`s all fields

3. `node->node_type` and `node->inner`

    Generic `Node` struct has only two fields: `node_type` and `inner`.
    `node_type` is an enum that can be used to identifier which variant of the `inner` union should be used.

    ```c
    assert(node->node_type == NODE_SEND);
    struct Send *send = node->inner->_send;
    ```

    This way you can "unwrap" generic node and convert it into specific node type.
    Specialized node types fully mirror API of Rust nodes, check [full documentation](https://docs.rs/lib-ruby-parser) to understand what is a specialized `Node`.

5. `uint32_t loc_size(struct Loc *loc)`

    Returns size of the loc (literally `end_pos - begin_pos`)

6. `char *loc_source(struct Loc *loc, char *input)`

    Returns source of the given loc. `input` is a field of the `ParserResult` struct.
