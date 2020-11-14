# c bindings for `lib-ruby-parser`

You can find some examples in `main.c` and `test.c`.

## API

+ `struct ParserResult *parse(const char *input, size_t length)`

        parses given input into `ParserResult` (a wrapper around Rust struct)

+ `void parser_result_free(struct ParserResult *parser_result)`

        deallocates the memory of the `ParserResult`

+ `struct Node *extract_ast(struct ParserResult *parser_result)`

        extracts `ast` field from the `ParserResult` and return `Node` (a wrapper around Rust struct)

+ `void node_free(struct Node *node)`

        deallocates the memory of the `Node`, must be used only on `Node` that is extracted from the `ParserResult`

+ `struct Tokens *extract_tokens(struct ParserResult *parser_result)`

        extracts `tokens` field from the `ParserResult` and returns `Tokens` struct (a wrapper around `Vec<Token>`)

+ `void tokens_free(struct Tokens *tokens)`

        deallocates the memory of the `Tokens`, must be used only on `Tokens` that is extracted from the `ParserResult`

+ `struct Diagnostics *extract_diagnostics(struct ParserResult *parser_result)`

        extracts `diagnostics` field from the `ParserResult` and returns `Diagnostis` struct (a wrapper around `Vec<Diagnostic>`)

+ `void diagnostics_free(struct Diagnostics *diagnostics)`

        deallocates the memory of the `Diagnostics`, must be used only on `Diagnostics` that is extracted from the `ParserResult`

+ `struct Comments *extract_comments(struct ParserResult *parser_result)`

        extracts `comments` field from the `ParserResult` and returns `Comments` struct (a wrapper around `Vec<Comment>`)

+ `void comments_free(struct Comments *comments)`

        deallocates the memory of the `Comments`, must be used only on `Comments` that is extracted from the `ParserResult`

+ `struct MagicComments *extract_magic_comments(struct ParserResult *parser_result)`

        extracts `magic_comments` field from the `ParserResult` and returns `MagicComments` struct (a wrapper around `Vec<MagicComment>`)

+ `void magic_comments_free(struct MagicComments *magic_comments)`

        deallocates the memory of the `MagicComments`, must be used only on `MagicComments` that is extracted from the `ParserResult`


+ `char *inspect_node(struct Node *node)`

        returns a string representation of the `Node` in the format of `whitequark/parser`

+ `enum NodeType node_kind(struct Node *node)`

        returns kind of the node

+ `struct Node *get_<NAME>_node(struct Node *node)`

        returns a `Node` property  of the given `node` called `NAME`
        e.g. for `Def` node (if you know that it's a `def` node) you can call `get_body_node` to get a `body` property.
        This method should be used with `Box<Node>` and `Option<Box<Node>>` properties, check [documentation of `lib-ruby-parser`](https://docs.rs/lib-ruby-parser)

+ `struct NodeList *get_<NAME>_list(struct Node *node)`

        returns a `NodeList` property  of the given `node` called `NAME`
        e.g. for `Hash` node (if you know that it's a `hash` node) you can call `get_pairs_list` to get a `pairs` property.
        This method should be used with `Vec<Node>` properties, check [documentation of `lib-ruby-parser`](https://docs.rs/lib-ruby-parser)

+ `struct Range *get_<NAME>_l(struct Node *node)`

        returns a `Range` property  of the given `node` called `NAME`
        e.g. for `Send` node (if you know that it's a `send` node) you can call `get_dot_l` to get a `dot_l` property.
        This method should be used with `Range` or `Option<Range>` properties, check [documentation of `lib-ruby-parser`](https://docs.rs/lib-ruby-parser)

+ `char *get_<NAME>_str(struct Node *node)`

        returns a `char *` property  of the given `node` called `NAME`
        e.g. for `Lvar` node (if you know that it's a `lvar` node) you can call `get_name_str` to get a `name` property.
        This method should be used with `String`, `Option<String>`, `Vec<char>` or `StringValue` properties, check [documentation of `lib-ruby-parser`](https://docs.rs/lib-ruby-parser)

+ `struct Node *get_list_item(struct NodeList *list, size_t at)`

        returns a `at`th item of the given `list`



