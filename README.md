# c bindings for `lib-ruby-parser`

You can find some examples in `main.c` and `test.c`.

## API

1. `struct ParserResult *parse(const char *input, size_t length)`

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

4. `char *debug_fmt_ast(struct Node *node)`

    Returns a pretty-printed debug representation of the given `node`

    ```c
    const char *code = "2 + 2"
    printf("%s\n", debug_fmt_ast(parse(code, strlen(code))));
    ```

    prints

    ```
    Send {
        recv: Int {
            value: "2",
            operator_l: None,
            expression_l: Range {
                begin_pos: 0,
                end_pos: 1,
            },
        },
        method_name: "+",
        args: [
            Int {
                value: "2",
                operator_l: None,
                expression_l: Range {
                    begin_pos: 4,
                    end_pos: 5,
                },
            },
        ],
        dot_l: None,
        selector_l: Range {
            begin_pos: 2,
            end_pos: 3,
        },
        begin_l: None,
        end_l: None,
        operator_l: None,
        expression_l: Range {
            begin_pos: 0,
            end_pos: 5,
        },
    }
    ```

    It's based on Rust `std::fmt::Debug` trait. Its implementation is fully custom, because it needs to walk through pointers.

    Keep in mind that `char *` that it returns must be `free`-ed manually.

5. `size_t range_size(struct Range *range)`

    Returns size of the range (literally `end_pos - begin_pos`)

6. `char *range_source(struct Range *range, char *input)`

    Returns source of the given range. `input` is a field of the `ParserResult` struct.
