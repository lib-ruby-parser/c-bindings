#ifndef LIB_RUBY_PARSER_GEN_H
#define LIB_RUBY_PARSER_GEN_H

#include <stddef.h>
#include <stdint.h>
#include "node_list.h"
#include "loc.h"

struct Node;
void node_free(struct Node *node);


// Represents `alias to from` statement.
struct Alias
{
    // Target of the `alias`.
    //
    // `Sym("foo")` node for `alias :foo :bar`
    struct Node *to;
    // Source of the `alias`.
    //
    // `Sym("bar")` node for `alias :foo :bar`
    struct Node *from;
    // Location of the `alias` keyword
    //
    // ```text
    // alias foo bar
    // ~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // alias foo bar
    // ~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void alias_node_free(struct Alias *node);


// Represents `a &&= 1` statement.
struct AndAsgn
{
    // Receiver of the `&&=` operation.
    //
    // `Lvasgn("a")` node for `a &&= 1`
    struct Node *recv;
    // Right hand statement of assignment
    //
    // `Int("1")` node for `a &&= 1`
    struct Node *value;
    // Location of the `&&=` operator
    //
    // ```text
    // a &&= 1
    //   ~~~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // a &&= 1
    // ~~~~~~~
    // ```
    struct Loc *expression_l;
};

void and_asgn_node_free(struct AndAsgn *node);


// Represents `foo && bar` (or `foo and bar`) statement.
struct And
{
    // Left hand statament of the `&&` operation.
    //
    // `Lvar("foo")` node for `foo && bar`
    struct Node *lhs;
    // Right hand statement of the `&&` operation.
    //
    // `Lvar("bar")` node for `foo && bar`
    struct Node *rhs;
    // Location of the `&&` (or `and`) operator
    //
    // ```text
    // a && b
    //   ~~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // a && b
    // ~~~~~~
    // ```
    struct Loc *expression_l;
};

void and_node_free(struct And *node);


// Represents a positional required block/method argument.
//
// `a` in `def m(a); end` or `proc { |a| }`
struct Arg
{
    // Name of the argument
    char *name;
    // Location of the full expression
    //
    // ```text
    // def m(argument); end
    //       ~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void arg_node_free(struct Arg *node);


// Represents an arguments list
//
// `Args(vec![Arg("a"), Optarg("b", Int("1"))])` in `def m(a, b = 1); end`
struct Args
{
    // List of arguments
    struct NodeList *args;
    // Location of the full expression
    //
    // ```text
    // def m(a, b = 1, c:, &blk); end
    //      ~~~~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
    // Location of the open parenthesis
    //
    // ```text
    // def m(a, b = 1, c:, &blk); end
    //      ~
    // ```
    //
    // `None` for code like `def m; end` or `def m arg; end`
    struct Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // def m(a, b = 1, c:, &blk); end
    //                         ~
    // ```
    //
    // `None` for code like `def m; end` or `def m arg; end`
    struct Loc *end_l;
};

void args_node_free(struct Args *node);


// Represents an array literal
struct Array
{
    // A list of elements
    struct NodeList *elements;
    // Location of the open bracket
    //
    // ```text
    // [1, 2, 3]
    // ~
    // ```
    struct Loc *begin_l;
    // Location of the closing bracket
    //
    // ```text
    // [1, 2, 3]
    //         ~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // [1, 2, 3]
    // ~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void array_node_free(struct Array *node);


// Represents an array pattern used in pattern matching
struct ArrayPattern
{
    // A list of elements
    struct NodeList *elements;
    // Location of the open bracket
    //
    // ```text
    // [1, ^a, 3 => foo]
    // ~
    // ```
    //
    // `None` for pattern like `1, 2` without brackets
    struct Loc *begin_l;
    // Location of the closing bracket
    //
    // ```text
    // [1, ^a, 3 => foo]
    //                 ~
    // ```
    //
    // `None` for pattern like `1, 2` without brackets
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // [1, ^a, 3 => foo]
    // ~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void array_pattern_node_free(struct ArrayPattern *node);


// Represents an array pattern *with trailing comma* used in pattern matching
//
// It's slightly different from `ArrayPattern`, trailing comma at the end works as `, *`
struct ArrayPatternWithTail
{
    // A list of elements
    struct NodeList *elements;
    // Location of the open bracket
    //
    // ```text
    // [1, ^a, 3 => foo,]
    // ~
    // ```
    //
    // `None` for pattern like `1, 2,` without brackets
    struct Loc *begin_l;
    // Location of the closing bracket
    //
    // ```text
    // [1, ^a, 3 => foo,]
    //                  ~
    // ```
    //
    // `None` for pattern like `1, 2,` without brackets
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // [1, ^a, 3 => foo,]
    // ~~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void array_pattern_with_tail_node_free(struct ArrayPatternWithTail *node);


// Represents special global variables:
//     1. `` $` ``
//     2. `$&`
//     3. `$'`
//     4. `$+`
struct BackRef
{
    // Name of the variable (`"$+"` for `$+`)
    char *name;
    // Location of the full expression
    //
    // ```text
    // $+
    // ~~
    // ```
    struct Loc *expression_l;
};

void back_ref_node_free(struct BackRef *node);


// Represents compound statement (i.e. a multi-statement)
//
// Basically all blocks of code are wrapped into `Begin` node (e.g. method/block body, rescue/ensure handler etc)
struct Begin
{
    // A list of statements
    struct NodeList *statements;
    // Begin of the block
    //
    // ```text
    // (1; 2)
    // ~
    // ```
    //
    // `None` if the block of code is "implicit", like
    //
    // ```text
    // if true; 1; 2; end
    // ```
    struct Loc *begin_l;
    // End of the block
    //
    // ```text
    // (1; 2)
    //      ~
    // ```
    //
    // `None` if the block of code is "implicit", like
    //
    // ```text
    // if true; 1; 2; end
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // (1; 2)
    // ~~~~~~
    // ```
    struct Loc *expression_l;
};

void begin_node_free(struct Begin *node);


// Represents a Ruby block that is passed to a method (`proc { |foo| bar }`)
struct Block
{
    // Method call that takes a block
    //
    // `Send("foo")` in `foo {}`
    struct Node *call;
    // A list of argument that block takes
    //
    // `vec![ Arg("a"), Optarg("b", Int("1")) ]` for `proc { |a, b = 1| }`
    //
    // `None` if the block takes no arguments
    struct Node *args;
    // Block body, `None` if block has no body.
    struct Node *body;
    // Location of the open brace
    //
    // ```text
    // proc { }
    //      ~
    // ```
    struct Loc *begin_l;
    // Location of the closing brace
    //
    // ```text
    // proc { }
    //        ~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // proc { }
    // ~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void block_node_free(struct Block *node);


// Represents a `&blk` argument of the method call (but not of the method definition, see `BlockArg`)
struct BlockPass
{
    // Value that is converted to a block
    //
    // `Int("1")` in `foo(&1)` (yes, it's possible)
    struct Node *value;
    // Location of the `&` operator
    //
    // ```text
    // foo(&blk)
    //     ~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo(&bar)
    //     ~~~~
    // ```
    struct Loc *expression_l;
};

void block_pass_node_free(struct BlockPass *node);


// Represents a `&blk` argument in the method definition (but not in the method call, see `BlockPass`)
struct Blockarg
{
    // Name of the argument, `String("foo")` for `def m(&foo)`
    char *name;
    // Location of the `&` operator
    //
    // ```text
    // def m(&foo); end
    //       ~
    // ```
    struct Loc *operator_l;
    // Location of the name
    //
    // ```text
    // def m(&foo); end
    //        ~~~
    // ```
    struct Loc *name_l;
    // Location of the full expression
    //
    // ```text
    // def m(&foo); end
    //       ~~~~
    // ```
    struct Loc *expression_l;
};

void blockarg_node_free(struct Blockarg *node);


// Represents a `break` keyword (with optional argument)
struct Break
{
    // A list of arguments
    struct NodeList *args;
    // Location of the `break` keyword
    //
    // ```text
    // break :foo
    // ~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // break(:foo)
    // ~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void break__node_free(struct Break *node);


// Represents a `case` statement (for pattern matching see `CaseMatch` node)
struct Case
{
    // Expression given to `case`, `Int("1")` for `case 1; end`
    // `None` for code like
    //
    // ```text
    // case
    // when pattern
    // end
    // ```
    struct Node *expr;
    // A list of `When` nodes (each has `patterns` and `body`)
    struct NodeList *when_bodies;
    // Body of the `else` branch, `None` if there's no `else` branch
    struct Node *else_body;
    // Location of the `case` keyword
    //
    // ```text
    // case 1; end
    // ~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the `else` keyword
    //
    // ```text
    // case 1; else; end
    //         ~~~~
    // ```
    //
    // `None` if there's no `else` branch
    struct Loc *else_l;
    // Location of the `end` keyword
    //
    // ```text
    // case 1; end
    //         ~~~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // case 1; end
    // ~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void case_node_free(struct Case *node);


// Represents a `case` statement used for pattern matching (for regular `case` see `Case` node)
struct CaseMatch
{
    // Expression given to `case`, `Int("1")` for `case 1; in 1; end`
    // `None` for code like
    //
    // ```text
    // case
    // in pattern
    // end
    // ```
    struct Node *expr;
    // A list of `InPattern` nodes (each has `pattern`, `guard` and `body`)
    struct NodeList *in_bodies;
    // Body of the `else` branch, `None` if there's no `else` branch
    struct Node *else_body;
    // Location of the `case` keyword
    //
    // ```text
    // case 1; in 2; end
    // ~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the `else` keyword
    //
    // ```text
    // case 1; in 2; else; end
    //               ~~~~
    // ```
    //
    // `None` if there's no `else` branch
    struct Loc *else_l;
    // Location of the `end` keyword
    //
    // ```text
    // case 1; in 2; end
    //               ~~~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // case 1; in 2; end
    // ~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void case_match_node_free(struct CaseMatch *node);


// Represents a constant assignment (i.e. `A = 1`)
struct Casgn
{
    // Scope where the constant is defined:
    //     1. `Some(Const("A"))` for `A::B = 1`
    //     2. `None` if it's defined in the current scope (i.e. `A = 1`)
    //     3. `Some(Cbase)` if it's defined in the global scope (i.e. `::A = 1`)
    struct Node *scope;
    // Name of the constant, `String("A")` for `A = 1`
    char *name;
    // Value that is assigned to a constant, `Int("1")` for `A = 1`.
    //
    // **Note**: `None` if constant assignment is a part of the multi-assignment.
    // In such case `value` belongs to `Masgn` node of the multi-assignment.
    struct Node *value;
    // Location of the `::` operator
    //
    // ```text
    // A::B = 1
    //  ~~
    //
    // ::A = 1
    // ~~
    // ```
    //
    // `None` if the constant is defined in the current scope
    struct Loc *double_colon_l;
    // Location of the constant name
    //
    // ```text
    // A::CONST = 1
    //    ~~~~~
    // ```
    struct Loc *name_l;
    // Location of the `=` operator
    //
    // ```text
    // A = 1
    //   ~
    // ```
    //
    // `None` if constant assignment is a part of the multi-assignment.
    // In such case `=` belongs to a `Masgn` node
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // A = 1
    // ~~~~~
    // ```
    struct Loc *expression_l;
};

void casgn_node_free(struct Casgn *node);


// Represents leading `::` part of the constant access/assignment that is used to get/set on a global namespace.
struct Cbase
{
    // Location of the full expression
    //
    // ```text
    // ::A
    // ~~
    // ```
    struct Loc *expression_l;
};

void cbase_node_free(struct Cbase *node);


// Represents a class definition (using a `class` keyword, `Class.new` is just a method call)
struct Class
{
    // Name of the class, `String("Foo")` for `class Foo; end`
    struct Node *name;
    // Superclass. Can be an expression in cases like `class A < (obj.foo + 1); end`
    //
    // `None` if no explicit superclass given (i.e. `class Foo; end`)
    struct Node *superclass;
    // Body of the method, `None` if there's no body.
    struct Node *body;
    // Location of the `class` keyword.
    //
    // ```text
    // class Foo; end
    // ~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the `<` operator
    //
    // ```text
    // class A < B; end
    //         ~
    // ```
    //
    // `None` if there's no explicit superclass given.
    struct Loc *operator_l;
    // Location of the `end` keyword.
    //
    // ```text
    // class Foo; end
    //            ~~~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // class Foo; end
    // ~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void class_node_free(struct Class *node);


// Represents a `Complex` literal (that returns an `Complex` number)
struct Complex
{
    // Value of the complex literal, returned as a `String`, `String("1i")` for `1i`
    char *value;
    // Location of the `-` (but not `+`) operator. `+` is a part of the literal:
    //     1. `+1i` is `String("+1i")` with `operator = None`
    //     2. `-1i` is `String("1i")` with `operator = String("-")`
    //
    // ```text
    // -1i
    // ~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // -1i
    // ~~~
    // ```
    struct Loc *expression_l;
};

void complex_node_free(struct Complex *node);


// Represents constant access (i.e. `Foo::Bar`)
struct Const
{
    // Scope where the constant is taken from:
    //     1. `Some(Const("A"))` for `A::B`
    //     2. `None` if it's taken from the current scope (i.e. `A`)
    //     3. `Some(Cbase)` if it's taken from the global scope (i.e. `::A`)
    struct Node *scope;
    // Name of the constant, `String("Foo")` for `Foo`
    char *name;
    // Location of the `::` operator. `None` if constant is taken from the current scope.
    //
    // ```text
    // A::B
    //  ~~
    // ```
    struct Loc *double_colon_l;
    // Location of the constant name
    //
    // ```text
    // Foo::Bar
    //      ~~~
    // ```
    struct Loc *name_l;
    // Location of the full expression
    //
    // ```text
    // Foo::Bar
    // ~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void const__node_free(struct Const *node);


// Const pattern used in pattern matching (e.g. `in A(1, 2)`)
struct ConstPattern
{
    // Constant that is used, `Const("Foo")` for `in For(42)`
    struct Node *const_;
    // Inner part of the constant pattern
    //
    // `ArrayPattern(vec![ Int("1") ])` for `Foo(1)`
    struct Node *pattern;
    // Location of the open parenthesis
    //
    // ```text
    // case 1; in Foo(42); end
    //               ~
    // ```
    struct Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // case 1; in Foo(42); end
    //                  ~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // case 1; in Foo(42); end
    //            ~~~~~~~
    // ```
    struct Loc *expression_l;
};

void const_pattern_node_free(struct ConstPattern *node);


// Represents conditional method call using `&.` operator
struct CSend
{
    // Receiver of the method call, `Int("1")` for `1&.foo`
    struct Node *recv;
    // Name of the method, `String("foo")` for `1&.foo`
    char *method_name;
    // List of arguments
    //
    // ```text
    // foo&.bar(42)
    // # and also setters like
    // foo&.bar = 42
    // ```
    struct NodeList *args;
    // Location of the `&.` operator
    //
    // ```text
    // foo&.bar
    //    ~~
    // ```
    struct Loc *dot_l;
    // Location of the method name
    //
    // ```text
    // foo&.bar(42)
    //      ~~~
    // ```
    //
    // `None` in a very special case when method call is implicit (i.e. `foo&.()`)
    struct Loc *selector_l;
    // Location of the open parenthesis
    //
    // ```text
    // foo&.bar(42)
    //         ~
    // ```
    //
    // `None` if there are no parentheses
    struct Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // foo&.bar(42)
    //            ~
    // ```
    //
    // `None` if there are no parentheses
    struct Loc *end_l;
    // Location of the operator if `CSend` is a part of assignment like
    //
    // ```text
    // foo&.bar = 1
    //          ~
    // ```
    //
    // `None` for a regular call.
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo&.bar(42)
    // ~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void csend_node_free(struct CSend *node);


// Represents access to class variable (i.e. `@@var`)
struct Cvar
{
    // Name of the class variable, `String("@@foo")` for `@@foo`
    char *name;
    // Location of the full expression
    //
    // ```text
    // @@foo
    // ~~~~~
    // ```
    struct Loc *expression_l;
};

void cvar_node_free(struct Cvar *node);


// Represents class variable assignment (i.e. `@@var = 42`)
struct Cvasgn
{
    // Name of the class variable, `String("@@foo")` for `@@foo = 1`
    char *name;
    // Value that is assigned to class variable, `Int("1")` for `@@foo = 1`
    struct Node *value;
    // Location of the class variable name
    //
    // ```text
    // @@foo = 1
    // ~~~~~
    // ```
    struct Loc *name_l;
    // Location of the `=` operator
    //
    // ```text
    // @@foo = 1
    //       ~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // @@foo = 1
    // ~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void cvasgn_node_free(struct Cvasgn *node);


// Represents method definition using `def` keyword (not on a singleton, see `Defs` node).
struct Def
{
    // Name of the method, `String("foo")` for `def foo; end`
    char *name;
    // Arguments of a method, `None` if there's no arguments.
    //
    // All information about parentheses around arguments is stored in this node.
    struct Node *args;
    // Body of a method, `None` if there's no body.
    struct Node *body;
    // Location of the `def` keyword.
    //
    // ```text
    // def foo; end
    // ~~~
    // ```
    struct Loc *keyword_l;
    // Location of the method name.
    //
    // ```text
    // def foo; end
    //     ~~~
    // ```
    struct Loc *name_l;
    // Location of the `end` keyword.
    //
    // ```text
    // def foo; end
    //          ~~~
    // ```
    //
    // `None` for endless method definition
    struct Loc *end_l;
    // Location of the `=` operator for endless method definition
    //
    // ```text
    // def m() = 1
    //         ~
    // ```
    //
    // `None` for regular method definition
    struct Loc *assignment_l;
    // Location of the full expression
    //
    // ```text
    // def m(a); foo; end
    // ~~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void def_node_free(struct Def *node);


// Represents a `defined?(foo)` expression
struct Defined
{
    // Value given to `defined?`
    struct Node *value;
    // Location of the `defined?` keyword
    //
    // ```text
    // defined?(foo)
    // ~~~~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // defined?(foo)
    //         ~
    // ```
    //
    // `None` if there are no parentheses
    struct Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // defined?(foo)
    //             ~
    // ```
    //
    // `None` if there are no parentheses
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // defined?(foo)
    // ~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void defined_node_free(struct Defined *node);


// Represents a singleton method definition (i.e. `def self.foo; end`)
struct Defs
{
    // Definee of a method definition, `Lvar("x")` for `def x.foo; end
    struct Node *definee;
    // Name of the method, `String("foo")` for `def x.foo; end`
    char *name;
    // Arguments of a method, `None` if there's no arguments.
    //
    // All information about parentheses around arguments is stored in this node.
    struct Node *args;
    // Body of the method, `None` if there's no body.
    struct Node *body;
    // Location of the `def` keyword
    //
    // ```text
    // def self.foo; end
    // ~~~
    // ```
    struct Loc *keyword_l;
    // Location of the `.`
    //
    // ```text
    // def self.foo; end
    //         ~
    // ```
    struct Loc *operator_l;
    // Location of the method name
    //
    // ```text
    // def self.foo; end
    //          ~~~
    // ```
    struct Loc *name_l;
    // Location of the `=` operator for endless method definition
    //
    // ```text
    // def self.foo() = 42
    //                ~
    // ```
    //
    // `None` for regular method definition
    struct Loc *assignment_l;
    // Location of the `end` keyword
    //
    // ```text
    // def self.foo; end
    //               ~~~
    // ```
    //
    // `None` for endless method definition
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // def self.foo; end
    // ~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void defs_node_free(struct Defs *node);


// Represents a string with interpolation (i.e. `"#{foo}"`)
struct Dstr
{
    // A list of string parts (static literals and interpolated expressions)
    struct NodeList *parts;
    // Location of the string begin
    //
    // ```text
    // "#{foo}"
    // ~
    //
    // %Q{#{foo}}
    // ~~~
    // ```
    struct Loc *begin_l;
    // Location of the string end
    //
    // ```text
    // "#{foo}"
    //        ~
    //
    // %Q{#{foo}}
    //          ~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // "#{foo}"
    // ~~~~~~~~
    //
    // %Q{#{foo}}
    // ~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void dstr_node_free(struct Dstr *node);


// Represents a symbol with interpolation (i.e. `:"#{foo}"`)
struct Dsym
{
    // A list of symbol parts (static literals and interpolated expressions)
    struct NodeList *parts;
    // Location of the symbol begin
    //
    // ```text
    // :"#{foo}"
    // ~~
    // ```
    //
    // `None` if `Dsym` is a part of the interpolated symbol array:
    //
    // ```text
    // %I[#{bar}]
    // ```
    struct Loc *begin_l;
    // Location of the symbol begin
    //
    // ```text
    // :"#{foo}"
    //         ~
    // ```
    //
    // `None` if `Dsym` is a part of the interpolated symbol array:
    //
    // ```text
    // %I[#{bar}]
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // :"#{foo}"
    // ~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void dsym_node_free(struct Dsym *node);


// Represents exclusive flip-flop (i.e. in `if foo...bar; end`)
struct EFlipFlop
{
    // Left part of the flip-flop. `None` if based on a range without begin (`...bar`)
    struct Node *left;
    // Right part of the flip-flop. `None` if based on a range without end (`foo...`)
    struct Node *right;
    // Location of the `...` operator
    //
    // ```text
    // if foo...bar; end
    //       ~~~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // if foo...bar; end
    //    ~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void eflipflop_node_free(struct EFlipFlop *node);


// Represents a special empty else that is a part of the pattern matching.
//
// Usually empty else (e.g. part of the `if` statement) doesn't mean anything,
// however in pattern matching it prevents raising a `NoPatternError`.
//
// Throwing away this `else` may affect your code.
struct EmptyElse
{
    // Location of the `else` keyword
    //
    // ```text
    // case foo; in 1; else; end
    //                 ~~~~
    // ```
    struct Loc *expression_l;
};

void empty_else_node_free(struct EmptyElse *node);


// Represents a special `__ENCODING__` keyword
struct Encoding
{
    // Location of the `__ENCODING__` keyword
    //
    // ```text
    // __ENCODING__
    // ~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void encoding__node_free(struct Encoding *node);


// Represents a block of code with `ensure` (i.e. `begin; ensure; end`)
struct Ensure
{
    // Block of code that is wrapped into `ensure`
    // **Note**: that's the body of the `ensure` block
    //
    // `Int("1")` for `begin; 1; ensure; 2; end`
    struct Node *body;
    // Body of the `ensure` block
    //
    // `Int("2")` for `begin; 1; ensure; 2; end`
    struct Node *ensure;
    // Location of the `ensure` keyword
    //
    // ```text
    // begin; ensure; end
    //        ~~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // begin; 1; rescue; 2; else; 3; ensure; 4; end
    //        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    //
    // **Note**: begin/end belong to `KwBegin` node.
    struct Loc *expression_l;
};

void ensure_node_free(struct Ensure *node);


// Represents range literal with excluded `end` (i.e. `1...3`)
struct Erange
{
    // Begin of the range, `None` if range has no begin (i.e `...42`)
    struct Node *left;
    // End of the range, `None` if range has no end (i.e `42...`)
    struct Node *right;
    // Location of the `...` operator
    //
    // ```text
    // 1...3
    //  ~~~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // 1...3
    // ~~~~~
    // ```
    struct Loc *expression_l;
};

void erange_node_free(struct Erange *node);


// Represents a `false` literal
struct False
{
    // Location of the `false` literal
    //
    // ```text
    // false
    // ~~~~~
    // ```
    struct Loc *expression_l;
};

void false__node_free(struct False *node);


// Represents a special `__FILE__` literal
struct File
{
    // Location of the `__FILE__` literal
    //
    // ```text
    // __FILE__
    // ~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void file_node_free(struct File *node);


// Represents a find pattern using in pattern matching (i.e. `in [*x, 1 => a, *y]`)
//
// It's different from `ArrayPattern`/`ConstPattern` because it supports multiple wildcard pattern
struct FindPattern
{
    // Inner part of the find pattern
    struct NodeList *elements;
    // Location of the begin
    //
    // ```text
    // case foo; in [*x, 1 => a, *y]; end
    //              ~
    // ```
    //
    // `None` if there are no brackets/parentheses
    struct Loc *begin_l;
    // Location of the end
    //
    // ```text
    // case foo; in [*x, 1 => a, *y]; end
    //                             ~
    // ```
    //
    // `None` if there are no brackets/parentheses
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in [*x, 1 => a, *y]; end
    //              ~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void find_pattern_node_free(struct FindPattern *node);


// Represents a float literal (i.e. `42.5`)
struct Float
{
    // String value of the literal, `String("42.5")` for `42.5`
    char *value;
    // Location of unary `-` (but not `+`)
    //
    // ```text
    // -42.5
    // ~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // -42.5
    // ~~~~~
    // ```
    struct Loc *expression_l;
};

void float_node_free(struct Float *node);


// Represents a `for` loop
struct For
{
    // Variable that is used in loop, `Lvasgn("a")` in `for a in b; end`
    struct Node *iterator;
    // Collection that is for iteration. `Lvar("b")` in `for a in b; end`
    struct Node *iteratee;
    // Body of the loop. `None` if there's no body
    struct Node *body;
    // Location of the `for` keyword
    //
    // ```text
    // for a in b; end
    // ~~~
    // ```
    struct Loc *keyword_l;
    // Location of the `in` keyword
    //
    // ```text
    // for a in b; end
    //       ~~
    // ```
    struct Loc *operator_l;
    // Location of the `do` keyword
    //
    // ```text
    // for a in b do; end
    //            ~~
    // ```
    //
    // **Note**: this `do` is optional, and so `begin_l` can be `None`.
    struct Loc *begin_l;
    // Location of the `end` keyword
    //
    // ```text
    // for a in b; end
    //             ~~~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // for a in b; end
    // ~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void for__node_free(struct For *node);


// Represents a special `...` argument that forwards positional/keyword/block arguments.
struct ForwardArg
{
    // Location of the `...`
    //
    // ```text
    // def m(...); end
    //       ~~~
    // ```
    struct Loc *expression_l;
};

void forward_arg_node_free(struct ForwardArg *node);


// Represents a `...` operator that contains forwarded argument (see `ForwardArg`)
struct ForwardedArgs
{
    // Location of the `...`
    //
    // ```text
    // def m(...); foo(...); end
    //                 ~~~
    // ```
    struct Loc *expression_l;
};

void forwarded_args_node_free(struct ForwardedArgs *node);


// Represents access to global variable (i.e. `$foo`)
struct Gvar
{
    // Name of the global variable, `String("$foo")` for `$foo`
    char *name;
    // Location of the full expression
    //
    // ```text
    // $foo
    // ~~~~
    // ```
    struct Loc *expression_l;
};

void gvar_node_free(struct Gvar *node);


// Represents global variable assignment (i.e. `$foo = 42`)
struct Gvasgn
{
    // Name of the global variable, `String("$foo")` for `$foo`
    char *name;
    // Value that is assigned to global variable, `Int("42")` for `$foo = 42`
    //
    // `None` if global variable assignment is a part of the multi-assignment.
    // In such case `value` is a part of the `Masgn` node.
    struct Node *value;
    // Location of the global variable name
    //
    // ```text
    // $foo = 42
    // ~~~~
    // ```
    struct Loc *name_l;
    // Location of the `=` operator
    //
    // ```text
    // $foo = 42
    //      ~
    // ```
    //
    // `None` if global variable assignment is a part of the multi-assignment.
    // In such case `=` operator belongs to the `Masgn` node.
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // $foo = 42
    // ~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void gvasgn_node_free(struct Gvasgn *node);


// Represents a hash literal (i.e. `{ foo: 42 }`)
struct Hash
{
    // A list of key-value pairs
    struct NodeList *pairs;
    // Location of the open parenthesis
    //
    // ```text
    // { a: 1 }
    // ~
    // ```
    //
    // `None` if hash literal is implicit, e.g. `foo(key: "value")`
    struct Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // { a: 1 }
    //        ~
    // ```
    //
    // `None` if hash literal is implicit, e.g. `foo(key: "value")`
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // { a: 1 }
    // ~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void hash_node_free(struct Hash *node);


// Represents kwargs that are given to a method call, super or yield (i.e. `foo(bar: 1)`)
struct Kwargs
{
    // A list of key-value pairs
    struct NodeList *pairs;
    // Location of the full expression
    //
    // ```text
    // foo(bar: 1)
    //     ~~~~~~
    // ```
    struct Loc *expression_l;
};

void kwargs_node_free(struct Kwargs *node);


// Represents a hash pattern used in pattern matching (i.e. `in { a: 1 }`)
struct HashPattern
{
    // A list of inner patterns
    struct NodeList *elements;
    // Location of the open parenthesis
    //
    // ```text
    // case foo; in { a: 1 }; end
    //              ~
    // ```
    //
    // `None` if there are no parentheses
    struct Loc *begin_l;
    // Location of the open parenthesis
    //
    // ```text
    // case foo; in { a: 1 }; end
    //                     ~
    // ```
    //
    // `None` if there are no parentheses
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in { a: 1 }; end
    //              ~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void hash_pattern_node_free(struct HashPattern *node);


// Represents a here-document literal (both with and without interpolation)
//
// It's similar to `Dstr` in terms of abstract syntax tree, but has different source maps.
struct Heredoc
{
    // A list of string parts (static literals and interpolated expressions)
    struct NodeList *parts;
    // Location of the here-document body
    //
    // ```text
    // <<-HERE\n  a\n   #{42}\nHERE
    //          ~~~~~~~~~~~~~~~
    // ```
    struct Loc *heredoc_body_l;
    // Location of the here-document end
    //
    // ```text
    // <<-HERE\n  a\n   #{42}\nHERE
    //                         ~~~~
    // ```
    struct Loc *heredoc_end_l;
    // Location of the here-document identifier
    //
    // ```text
    // <<-HERE\n  a\n   #{42}\nHERE
    // ~~~~~~~
    // ```
    //
    // **Note**: This is the only node (with `XHeredoc`) that has `expression_l` smaller that all other sub-locations merged.
    // The reason for that is that it's possible to add more code after here-document ID:
    //
    // ```text
    // <<-HERE + "rest"
    //   content
    // HERE
    // ```
    struct Loc *expression_l;
};

void heredoc_node_free(struct Heredoc *node);


// Represents an `if` statement (i.e. `if foo; bar; else; baz; end`)
struct If
{
    // Condition given to the `if` statement, `Lvar("a")` for `if a; b; else; c; end`
    struct Node *cond;
    // True-branch of the `if` statement, `Lvar("b")` for `if a; b; else; c; end`
    struct Node *if_true;
    // False-branch of the `if` statement, `Lvar("c")` for `if a; b; else; c; end`
    struct Node *if_false;
    // Location of the `if` keyword
    //
    // ```text
    // if foo; end
    // ~~
    // ```
    struct Loc *keyword_l;
    // Location of the `then` keyword
    //
    // ```text
    // if foo then; end
    //        ~~~~
    // ```
    //
    // `None` if `then` keyword is omitted
    struct Loc *begin_l;
    // Location of the `else` keyword
    //
    // ```text
    // if foo; else; end
    //         ~~~~
    // ```
    //
    // `None` if there's no `else` branch
    struct Loc *else_l;
    // Location of the `end` keyword
    //
    // ```text
    // if foo; end
    //         ~~~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // if a then; b; else; c end
    // ~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void if__node_free(struct If *node);


// Represents an `if` guard used in pattern matching (i.e. `case foo; in pattern if guard; end`)
struct IfGuard
{
    // Condition of the guard, `Lvar("foo")` in `in pattern if guard`
    struct Node *cond;
    // Location of the `if` keyword
    //
    // ```text
    // case foo; in pattern if cond; end
    //                      ~~
    // ```
    struct Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in pattern if cond; end
    //                      ~~~~~~~
    // ```
    struct Loc *expression_l;
};

void if_guard_node_free(struct IfGuard *node);


// Represents an `if`/`unless` modifier (i.e. `stmt if cond`)
struct IfMod
{
    // Condition of the modifier
    struct Node *cond;
    // True-branch of the modifier.
    //
    // Always set for `if` modifier.
    // Always `None` for `unless` modifier.
    struct Node *if_true;
    // False-branch of the modifier.
    //
    // Always set for `unless` modifier.
    // Always `None` for `if` modifier.
    struct Node *if_false;
    // Location of the `if`/`unless` keyword
    //
    // ```text
    // stmt if cond
    //      ~~
    //
    // stmt unless cond
    //      ~~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // stmt if cond
    // ~~~~~~~~~~~~
    //
    // stmt unless cond
    // ~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void if_mod_node_free(struct IfMod *node);


// Represents ternary `if` statement (i.e. `cond ? if_true : if_false`)
struct IfTernary
{
    // Condition of the `if` statement
    struct Node *cond;
    // True-branch
    struct Node *if_true;
    // True-branch
    struct Node *if_false;
    // Location of the `?` operator
    //
    // ```text
    // cond ? if_true : if_false
    //      ~
    // ```
    struct Loc *question_l;
    // Location of the `:` operator
    //
    // ```text
    // cond ? if_true : if_false
    //                ~
    // ```
    struct Loc *colon_l;
    // Location of the full expression
    //
    // ```text
    // cond ? if_true : if_false
    // ~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void if_ternary_node_free(struct IfTernary *node);


// Represents inclusive flip-flop (i.e. in `if foo..bar; end`)
struct IFlipFlop
{
    // Left part of the flip-flop. `None` if based on a range without begin (`..bar`)
    struct Node *left;
    // Right part of the flip-flop. `None` if based on a range without end (`foo..`)
    struct Node *right;
    // Location of the `..` operator
    //
    // ```text
    // if foo..bar; end
    //       ~~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // if foo..bar; end
    //    ~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void iflipflop_node_free(struct IFlipFlop *node);


// Represents a one-line pattern matching that can throw an error (i.e. `foo => pattern`)
struct MatchPattern
{
    // Value that is used for matching
    struct Node *value;
    // Pattern that is used for matching
    struct Node *pattern;
    // Location of the `=>` operator
    //
    // ```text
    // foo => pattern
    //     ~~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo => pattern
    // ~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void match_pattern_node_free(struct MatchPattern *node);


// Represents a one-line pattern matching that never throws but returns true/false (i.e. `foo in pattern`)
struct MatchPatternP
{
    // Value that is used for matching
    struct Node *value;
    // Pattern that is used for matching
    struct Node *pattern;
    // Location of the `in` operator
    //
    // ```text
    // foo in pattern
    //     ~~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo in pattern
    // ~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void match_pattern_p_node_free(struct MatchPatternP *node);


// Represents an `in pattern` branch of the pattern matching
struct InPattern
{
    // Value that is used for matching
    struct Node *pattern;
    // Guard that is used for matching
    //
    // Optional, so can be `None`
    struct Node *guard;
    // Body of the branch that is invoked if value matches pattern
    struct Node *body;
    // Location of the `in` keyword
    //
    // ```text
    // case value; in pattern; end
    //             ~~
    // ```
    struct Loc *keyword_l;
    // Location of the `then` keyword
    //
    // ```text
    // case value; in pattern then; end
    //                        ~~~~
    // ```
    struct Loc *begin_l;
    // Location of the full expression
    //
    // ```text
    // case value; in pattern then; 42; end
    //             ~~~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void in_pattern_node_free(struct InPattern *node);


// Represents indexing operation (i.e. `foo[1,2,3]`)
struct Index
{
    // Receiver of indexing
    struct Node *recv;
    // A list of indexes
    struct NodeList *indexes;
    // Location of open bracket
    //
    // ```text
    // foo[1, 2, 3]
    //    ~
    // ```
    struct Loc *begin_l;
    // Location of closing bracket
    //
    // ```text
    // foo[1, 2, 3]
    //            ~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // foo[1, 2, 3]
    // ~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void index_node_free(struct Index *node);


// Represents assignment using indexing operation (i.e. `foo[1, 2, 3] = bar`)
struct IndexAsgn
{
    // Receiver of the indexing
    struct Node *recv;
    // A list of indexes
    struct NodeList *indexes;
    // Value that is assigned
    //
    // `None` if assignment is a part of the multi-assignment.
    // In such case `value` belongs to `Masgn` node.
    struct Node *value;
    // Location of open bracket
    //
    // ```text
    // foo[1, 2, 3] = bar
    //    ~
    // ```
    struct Loc *begin_l;
    // Location of closing bracket
    //
    // ```text
    // foo[1, 2, 3] = bar
    //            ~
    // ```
    struct Loc *end_l;
    // Location of the `=` operator
    //
    // ```text
    // foo[1, 2, 3] = bar
    //              ~
    // ```
    //
    // `None` if assignment is a part of the multi-assignment.
    // In such case operator `=` belongs to `Masgn` node.
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo[1, 2, 3] = bar
    // ~~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void index_asgn_node_free(struct IndexAsgn *node);


// Represents an integer literal (i.e. `42`)
struct Int
{
    // String value of the literal, `String("42")` for `42`
    char *value;
    // Location of unary `-` (but not `+`)
    //
    // ```text
    // -42
    // ~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // -42
    // ~~~
    // ```
    struct Loc *expression_l;
};

void int_node_free(struct Int *node);


// Represents inclusive range (i.e. `2..4`)
struct Irange
{
    // Begin of the range, `None` if range has no `begin` (i.e. `..4`)
    struct Node *left;
    // End of the range, `None` if range has no `end` (i.e. `2..`)
    struct Node *right;
    // Location of the `..` operator
    //
    // ```text
    // 2..4
    //  ~~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // 2..4
    // ~~~~
    // ```
    struct Loc *expression_l;
};

void irange_node_free(struct Irange *node);


// Represents access to instance variable (i.e. `@foo`)
struct Ivar
{
    // Name of the instance variable, `String("@foo")` in `@foo`
    char *name;
    // Location of the full expression
    //
    // ```text
    // @foo
    // ~~~~
    // ```
    struct Loc *expression_l;
};

void ivar_node_free(struct Ivar *node);


// Represents instance variable assignment (i.e `@foo = 42`)
struct Ivasgn
{
    // Name of the instance variable, `String("@foo")` in `@foo = 42`
    char *name;
    // Value that is assigned to instance variable.
    //
    // `None` if instance variable assignment is a part of the multi-assignment.
    // In such case `value` is a part of the `Masgn` node.
    struct Node *value;
    // Location of the instance variable name.
    //
    // ```text
    // @foo = 1
    // ~~~~
    // ```
    struct Loc *name_l;
    // Location of the `=` operator.
    //
    // ```text
    // @foo = 1
    //      ~
    // ```
    //
    // `None` if instance variable assignment is a part of the multi-assignment.
    // In such case `value` is a part of the `Masgn` node.
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // @foo = 42
    // ~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void ivasgn_node_free(struct Ivasgn *node);


// Represents required keyword argument (i.e. `foo` in `def m(foo:); end`)
struct Kwarg
{
    // Name of the keyword argument
    char *name;
    // Location of the name
    //
    // ```text
    // def foo(bar:); end
    //         ~~~
    // ```
    struct Loc *name_l;
    // Location of the full expression
    //
    // ```text
    // def foo(bar:); end
    //         ~~~~
    // ```
    struct Loc *expression_l;
};

void kwarg_node_free(struct Kwarg *node);


// Represents an explicit `begin; end` block.
//
// The reason why it's different is that only
// ```text
// begin; foo; end while cond
// ```
// is a post-while loop (same with post-until loop)
struct KwBegin
{
    // A list of statements
    struct NodeList *statements;
    // Location of the `begin` keyword
    //
    // ```text
    // begin; foo; end
    // ~~~~~
    // ```
    struct Loc *begin_l;
    // Location of the `begin` keyword
    //
    // ```text
    // begin; foo; end
    //             ~~~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // begin; foo; bar
    // ~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void kwbegin_node_free(struct KwBegin *node);


// Represents an special argument that rejects all keyword arguments (i.e. `def m(**nil); end`)
struct Kwnilarg
{
    // Location of the `nil`
    //
    // ```text
    // def m(**nil); end
    //         ~~~
    // ```
    struct Loc *name_l;
    // Location of the `nil`
    //
    // ```text
    // def m(**nil); end
    //       ~~~~~
    // ```
    struct Loc *expression_l;
};

void kwnilarg_node_free(struct Kwnilarg *node);


// Represents an optional keyword argument (i.e. `foo` in `def m(foo: 42); end`)
struct Kwoptarg
{
    // Name of the optional keyword argument
    char *name;
    // Default value of the optional keyword argument
    struct Node *default_;
    // Location of the argument name
    //
    // ```text
    // def m(foo: 1); end
    //       ~~~
    // ```
    struct Loc *name_l;
    // Location of the argument name
    //
    // ```text
    // def m(foo: 1); end
    //       ~~~~~~
    // ```
    struct Loc *expression_l;
};

void kwoptarg_node_free(struct Kwoptarg *node);


// Represents a keyword rest argument (i.e. `foo` in `def m(**foo); end`)
struct Kwrestarg
{
    // Name of the keyword rest argument, `String("foo")` in `def m(**foo); end`.
    //
    // `None` if argument has no name (`def m(**); end`)
    char *name;
    // Location of the `**` operator
    //
    // ```text
    // def m(**foo); end
    //       ~~
    // ```
    struct Loc *operator_l;
    // Location of the argument name
    //
    // ```text
    // def m(**foo); end
    //         ~~~
    // ```
    //
    // `None` if argument has no name (`def m(**); end`)
    struct Loc *name_l;
    // Location of the full expression
    //
    // ```text
    // def m(**foo); end
    //       ~~~~~
    // ```
    struct Loc *expression_l;
};

void kwrestarg_node_free(struct Kwrestarg *node);


// Represents a keyword arguments splat (i.e. `**bar` in a call like `foo(**bar)`)
struct Kwsplat
{
    // Value that is converted into a `Hash` using `**`
    struct Node *value;
    // Location of the `**` operator
    //
    // ```text
    // foo(**bar)
    //     ~~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo(**bar)
    //     ~~~~~
    // ```
    struct Loc *expression_l;
};

void kwsplat_node_free(struct Kwsplat *node);


// Represents a lambda call using `->` (i.e. `-> {}`)
//
// Note that `Lambda` is a part of the `Block`, not other way around.
struct Lambda
{
    // Location of the `->`
    //
    // ```text
    // -> {}
    // ~~
    // ```
    struct Loc *expression_l;
};

void lambda_node_free(struct Lambda *node);


// Represents a special `__LINE__` literal
struct Line
{
    // Location of the `__LINE__` literal
    //
    // ```text
    // __LINE__
    // ~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void line_node_free(struct Line *node);


// Represents access to a local variable (i.e. `foo`)
//
// Parser knows that it's a local variable because:
//     1. there was an assignment to this variable **before** accessing it
//     2. it's an argument of the current method / block
//     3. it's been implicitly declared by `MatchWithLvasgn` node
//
// Otherwise it's a method call (see `Send`)
struct Lvar
{
    // Name of the local variable
    char *name;
    // Location of the local variable
    //
    // ```text
    // foo
    // ~~~
    // ```
    struct Loc *expression_l;
};

void lvar_node_free(struct Lvar *node);


// Represents local variable assignment (i.e. `foo = 42`)
struct Lvasgn
{
    // Name of the local variable
    char *name;
    // Value that is assigned to a local variable
    struct Node *value;
    // Location of the local variable name
    //
    // ```text
    // foo = 42
    // ~~~
    // ```
    struct Loc *name_l;
    // Location of the `=` operator
    //
    // ```text
    // foo = 42
    //     ~
    // ```
    //
    // `None` if local variable assignment is a part of the multi-assignment.
    // In such case `value` is a part of the `Masgn` node.
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo = 42
    // ~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void lvasgn_node_free(struct Lvasgn *node);


// Represents mass-assignment (i.e. `foo, bar = 1, 2`)
struct Masgn
{
    // Left hand statement of the assignment
    struct Node *lhs;
    // Left hand statement of the assignment
    struct Node *rhs;
    // Location of the `=` operator
    //
    // ```text
    // foo, bar = 1, 2
    //          ~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo, bar = 1, 2
    // ~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void masgn_node_free(struct Masgn *node);


// Represents pattern matching using one of the given patterns (i.e. `foo in 1 | 2`)
struct MatchAlt
{
    // Left pattern
    struct Node *lhs;
    // Right pattern
    struct Node *rhs;
    // Location of the `|` operator
    //
    // ```text
    // foo in 1 | 2
    //          ~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo in 1 | 2
    //        ~~~~~
    // ```
    struct Loc *expression_l;
};

void match_alt_node_free(struct MatchAlt *node);


// Represents matching with renaming into specified local variable (i.e. `case 1; in Integer => a; end`)
struct MatchAs
{
    // Pattern that is used for matching
    struct Node *value;
    // Variable that is assigned if matched (see `MatchVar` node)
    struct Node *as_;
    // Location of the `=>` operator
    //
    // ```text
    // case 1; in Integer => a; end
    //                    ~~
    // ```
    struct Loc *operator_l;
    // Location of the `=>` operator
    //
    // ```text
    // case 1; in Integer => a; end
    //            ~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void match_as_node_free(struct MatchAs *node);


// Represents implicit matching using `if /regex/`
//
// ```text
// if /.*/
//   puts 'true'
// else
//   puts 'false'
// end
// ```
// Prints "false".
//
// Under the hood this construction matches regex against `$_`, so the following works:
// ```text
// $_ = 'match_me'
// if /match_me/
//   puts 'true'
// else
//   puts 'false'
// end
// ```
// this code prints "true".
struct MatchCurrentLine
{
    // Given regex
    struct Node *re;
    // Location of the regex
    //
    // ```text
    // if /re/; end
    //    ~~~~
    // ```
    //
    // Technically this location is redundant, but keeping it is the only way to
    // have the same interface for all nodes.
    struct Loc *expression_l;
};

void match_current_line_node_free(struct MatchCurrentLine *node);


// Represents empty hash pattern that is used in pattern matching (i.e. `in **nil`)
struct MatchNilPattern
{
    // Location of the `**` operator
    //
    // ```text
    // in **nil
    //    ~~
    // ```
    struct Loc *operator_l;
    // Location of the name
    //
    // ```text
    // in **nil
    //      ~~~
    // ```
    struct Loc *name_l;
    // Location of the full expression
    //
    // ```text
    // in **nil
    //    ~~~~~
    // ```
    struct Loc *expression_l;
};

void match_nil_pattern_node_free(struct MatchNilPattern *node);


// Represents a wildcard pattern used in pattern matching (i.e. `in *foo`)
struct MatchRest
{
    // Name of the variable name
    //
    // `None` if there's no name (i.e. `in *`)
    struct Node *name;
    // Location of the `*` operator
    //
    // ```text
    // case foo; in *bar; end
    //              ~
    // ```
    struct Loc *operator_l;
    // Location of the `*` operator
    //
    // ```text
    // case foo; in *bar; end
    //              ~~~~
    // ```
    struct Loc *expression_l;
};

void match_rest_node_free(struct MatchRest *node);


// Represents matching with assignment into a local variable (i.e. `pattern => var`)
struct MatchVar
{
    // Name of the variable that is assigned if matching succeeds
    char *name;
    // Location of the name
    //
    // ```text
    // case foo; in pattern => bar; end
    //                         ~~~
    // ```
    //
    // **Note** it can also be produced by a hash pattern
    //
    // ```text
    // case foo; in { a: }; end
    //                ~
    // ```
    struct Loc *name_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in pattern => bar; end
    //                         ~~~
    // ```
    //
    // **Note** it can also be produced by a hash pattern
    //
    // ```text
    // case foo; in { a: }; end
    //                ~~
    // ```
    struct Loc *expression_l;
};

void match_var_node_free(struct MatchVar *node);


// Represents matching a regex that produces local variables (i.e. `/(?<match>bar)/ =~ 'bar'`)
//
// Each named group in regex declares a local variable.
struct MatchWithLvasgn
{
    // Regex that is used for matching
    struct Node *re;
    // Value that is used for matching
    struct Node *value;
    // Location of the `=~` operatir
    //
    // ```text
    // /(?<match>bar)/ =~ 'bar'
    //                 ~~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // /(?<match>bar)/ =~ 'bar'
    // ~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void match_with_lvasgn_node_free(struct MatchWithLvasgn *node);


// Represents left hand statement of the mass-assignment (i.e. `foo, bar` in `foo, bar = 1, 2`)
struct Mlhs
{
    // A list of items that are assigned
    struct NodeList *items;
    // Location of the open parenthesis
    //
    // ```text
    // (a, b) = 1, 2
    // ~
    // ```
    //
    // `None` if there are no parentheses
    struct Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // (a, b) = 1, 2
    //      ~
    // ```
    //
    // `None` if there are no parentheses
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // (a, b) = 1, 2
    // ~~~~~~
    // ```
    struct Loc *expression_l;
};

void mlhs_node_free(struct Mlhs *node);


// Represents module declaration using `module` keyword
struct Module
{
    // Name of the module
    struct Node *name;
    // Body of the module
    //
    // `None` if module has no body
    struct Node *body;
    // Location of the `module` keyword
    //
    // ```text
    // module M; end
    // ~~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the `end` keyword
    //
    // ```text
    // module M; end
    //           ~~~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // module M; end
    // ~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void module_node_free(struct Module *node);


// Represents `next` keyword
struct Next
{
    // Arguments given to `next`
    struct NodeList *args;
    // Location of the `next` keyword
    //
    // ```text
    // next 42
    // ```
    struct Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // next(42)
    // ~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void next_node_free(struct Next *node);


// Represents `nil` literal
struct Nil
{
    // Location of the `nil` keyword
    //
    // ```text
    // nil
    // ~~~
    // ```
    struct Loc *expression_l;
};

void nil_node_free(struct Nil *node);


// Represents numeric global variable (e.g. `$1`)
struct NthRef
{
    // Name of the variable, `String("1")` for `$1`
    char *name;
    // Location of the full expression
    //
    // ```text
    // $1
    // ~~
    // ```
    struct Loc *expression_l;
};

void nth_ref_node_free(struct NthRef *node);


// Represents a block that takes numbered parameters (i.e. `proc { _1 }`)
struct Numblock
{
    // Method call that takes a block
    struct Node *call;
    // Number of parameters that block takes
    uint32_t numargs;
    // Block body
    struct Node *body;
    // Location of the open brace
    //
    // ```text
    // proc { _1 }
    //      ~
    // ```
    struct Loc *begin_l;
    // Location of the closing brace
    //
    // ```text
    // proc { _1 }
    //           ~
    // ```
    struct Loc *end_l;
    // Location of the open brace
    //
    // ```text
    // proc { _1 }
    // ~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void numblock_node_free(struct Numblock *node);


// Represents an operation with assignment (e.g. `a += 1`)
struct OpAsgn
{
    // Left hand statement of the assignment
    struct Node *recv;
    // Operator, can be one of:
    //     1. `+=`
    //     2. `-=`
    //     3. `*=`
    //     4. `/=`
    //     5. `|=`
    //     6. `&=`
    //     7. `>>=`
    //     8. `<<=`
    //     9. `%=`
    //     10. `^=`
    //     11. `**=`
    char *operator;
    // Right hand statement of the assignment
    struct Node *value;
    // Location of the operator
    //
    // ```text
    // a.b <<= c
    //     ~~~
    // ```
    struct Loc *operator_l;
    // Location of the operator
    //
    // ```text
    // a.b <<= c
    // ~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void op_asgn_node_free(struct OpAsgn *node);


// Represents optional positional argument (i.e. `foo` in `m(foo = 1)`)
struct Optarg
{
    // Name of the argument
    char *name;
    // Default value of the argument
    struct Node *default_;
    // Location of the argument name
    //
    // ```text
    // def m(foo = 1); end
    //       ~~~
    // ```
    struct Loc *name_l;
    // Location of the `=` operator
    //
    // ```text
    // def m(foo = 1); end
    //           ~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // def m(foo = 1); end
    //       ~~~~~~~
    // ```
    struct Loc *expression_l;
};

void optarg_node_free(struct Optarg *node);


// Represents `foo || bar` (or `foo or bar`) statement.
struct Or
{
    // Left hand statement
    struct Node *lhs;
    // Right hand statement
    struct Node *rhs;
    // Location of the `||`/`or` operator
    //
    // ```text
    // foo || bar
    //     ~~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo || bar
    // ~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void or_node_free(struct Or *node);


// Represents `lhs ||= rhs` assignment
struct OrAsgn
{
    // Left hand statement
    struct Node *recv;
    // Right hand statement
    struct Node *value;
    // Location of the `||=` operator
    //
    // ```text
    // foo ||= bar
    //     ~~~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo ||= bar
    // ~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void or_asgn_node_free(struct OrAsgn *node);


// Represents a key/value pair (e.g. a part of the `Hash` node)
struct Pair
{
    // Key of the pair
    struct Node *key;
    // Value of the pair
    struct Node *value;
    // Location of the `:` or `=>` operator
    //
    // ```text
    // { foo: bar }
    //      ~
    //
    // { :foo => bar }
    //        ~~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // { foo: bar }
    //   ~~~~~~~~
    //
    // { :foo => bar }
    //   ~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void pair_node_free(struct Pair *node);


// Represents a pattern based on a "pinned" variable (e.g. `^foo`)
struct Pin
{
    // Variable that is pinned
    struct Node *var;
    // Location of the `^` operator
    //
    // ```text
    // case foo; in ^bar; end
    //              ~
    // ```
    struct Loc *selector_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in ^bar; end
    //              ~~~~
    // ```
    struct Loc *expression_l;
};

void pin_node_free(struct Pin *node);


// Represents `END { .. }` statement
struct Postexe
{
    // Body of the block
    struct Node *body;
    // Location of the `END` keyword
    //
    // ```text
    // END { 42 }
    // ~~~
    // ```
    struct Loc *keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // END { 42 }
    //     ~
    // ```
    struct Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // END { 42 }
    //          ~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // END { 42 }
    // ~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void postexe_node_free(struct Postexe *node);


// Represents `BEGIN { ... }` statement
struct Preexe
{
    // Body of the block
    struct Node *body;
    // Location of the `BEGIN` keyword
    //
    // ```text
    // BEGIN { 42 }
    // ~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // BEGIN { 42 }
    //       ~
    // ```
    struct Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // BEGIN { 42 }
    //            ~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // BEGIN { 42 }
    // ~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void preexe_node_free(struct Preexe *node);


// Represents a sole block argument (e.g. `|foo|`)
//
// Block that takes a single array argument automatically expands it.
// Adding trailing comma after block argument disables this behavior (and then the only argument is emitted as `Arg`).
struct Procarg0
{
    // Parts of the sole block argument.
    //
    // `proc { |(a, b)| }` also counts as a sole argument, so this list may contain:
    //     1. A single `Arg` node (for `proc { |a| }` case)
    //     2. Multiple `Arg` nodes  (for `proc { |(a, b, c)| }` case)
    struct NodeList *args;
    // Location of the open parenthesis
    //
    // ```text
    // proc { |(foo, bar)| }
    //         ~
    // ```
    //
    // `None` if there's only one argument
    struct Loc *begin_l;
    // Location of the open parenthesis
    //
    // ```text
    // proc { |(foo, bar)| }
    //                  ~
    // ```
    //
    // `None` if there's only one argument
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // proc { |(foo, bar)| }
    //         ~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void procarg0_node_free(struct Procarg0 *node);


// Represents rational literal (e.g. `1r`)
struct Rational
{
    // String value of the literal, `String("1r")` for `1r`
    char *value;
    // Location of the unary `-` (but not `+`)
    //
    // ```text
    // -1r
    // ~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // -1r
    // ~~~
    // ```
    struct Loc *expression_l;
};

void rational_node_free(struct Rational *node);


// Represents `redo` keyword
struct Redo
{
    // Location of the full expression
    //
    // ```text
    // redo
    // ~~~~
    // ```
    struct Loc *expression_l;
};

void redo_node_free(struct Redo *node);


// Represents flags of the regex literal (i.e. `mix` for `/foo/mix`)
struct RegOpt
{
    // A list of flags
    char *options;
    // Location of the full expression
    //
    // ```text
    // /foo/mix
    //      ~~~
    // ```
    struct Loc *expression_l;
};

void reg_opt_node_free(struct RegOpt *node);


// Represents regex literal (e.g. `/foo/`)
struct Regexp
{
    // A list of static and dynamic regex parts
    struct NodeList *parts;
    // Regex options.
    //
    // `None` if regex has no explicit flags
    struct Node *options;
    // Location of the regex begin
    //
    // ```text
    // /foo/
    // ~
    //
    // %r{foo}
    // ~~
    // ```
    struct Loc *begin_l;
    // Location of the regex end
    //
    // ```text
    // /foo/
    //     ~
    //
    // %r{foo}
    //       ~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // /foo/mix
    // ~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void regexp_node_free(struct Regexp *node);


// Represents a `rescue` block
struct Rescue
{
    // Body of the block that is wrapped into `rescue` (i.e. the part that may throw an error)
    struct Node *body;
    // A list of `rescue` handlers (see `RescueBody` node)
    struct NodeList *rescue_bodies;
    // Else branch.
    //
    // `None` if there's no `else` branch
    struct Node *else_;
    // Location of the `else` keyword
    //
    // ```text
    // begin; 1; rescue StandardError => e; 2; else; 3; end
    //                                         ~~~~
    // ```
    //
    // `None` if there's no `else` branch
    struct Loc *else_l;
    // Location of the full expression
    //
    // ```text
    // begin; 1; rescue StandardError => e; 2; else; 3; end
    //        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    //
    // **Note**: `begin/end` keywords belong to `KwBegin` node
    struct Loc *expression_l;
};

void rescue_node_free(struct Rescue *node);


// Represents a single `rescue` handler (i.e. `rescue E => e ...`)
struct RescueBody
{
    // A list of exception classes
    //
    // `None` if no classes specified (i.e. `rescue => e; ...` or just `rescue; ...`)
    struct Node *exc_list;
    // Variable that captures exception
    //
    // `None` if no variable specified (i.e. `rescue E; ...` or just `rescue; ... `)
    struct Node *exc_var;
    // Body of the handler
    struct Node *body;
    // Location of the `rescue` keyword
    //
    // ```text
    // begin; 1; rescue E => e; 2; end
    //           ~~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the `=>` operator
    //
    // ```text
    // begin; 1; rescue E => e; 2; end
    //                    ~~
    // ```
    //
    // `None` if exception is not captured.
    struct Loc *assoc_l;
    // Location of the `then` keyword
    //
    // ```text
    // begin; 1; rescue E => e then; 2; end
    //                         ~~~~
    // ```
    //
    // `then` is optional, so `begin_l` can be `None`
    struct Loc *begin_l;
    // Location of the full expression
    //
    // ```text
    // begin; 1; rescue E => e then; 2; end
    //           ~~~~~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void rescue_body_node_free(struct RescueBody *node);


// Represents positional rest argument (i.e. `*foo` in `def m(*foo); end`)
struct Restarg
{
    // Name of the argument.
    //
    // `None` if argument has no name (i.e. `def m(*); end`)
    char *name;
    // Location of the `*` operator
    //
    // ```text
    // def m(*foo); end
    //       ~
    // ```
    struct Loc *operator_l;
    // Location of the argument name
    //
    // ```text
    // def m(*foo); end
    //        ~~~
    // ```
    struct Loc *name_l;
    // Location of the full expression
    //
    // ```text
    // def m(*foo); end
    //       ~~~~
    // ```
    struct Loc *expression_l;
};

void restarg_node_free(struct Restarg *node);


// Represents `retry` keyword
struct Retry
{
    // Location of the `retry` keyword
    //
    // ```text
    // retry
    // ~~~~~
    // ```
    struct Loc *expression_l;
};

void retry_node_free(struct Retry *node);


// Represents `return` keyword
struct Return
{
    // A list of values that is returned
    struct NodeList *args;
    // Location of the `return` keyword
    //
    // ```text
    // return 1, 2
    // ~~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // return 1, 2
    // ~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void return__node_free(struct Return *node);


// Represents opening a singleton class (i.e. `class << foo; ... end;`)
struct SClass
{
    // Expression that is used to get a singleton class
    //
    // `Lvar("foo")` for `class << foo; end`
    struct Node *expr;
    // Body of the block
    struct Node *body;
    // Location of the `class` keyword
    //
    // ```text
    // class << foo; end
    // ~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the `<<` operator
    //
    // ```text
    // class << foo; end
    //       ~~
    // ```
    struct Loc *operator_l;
    // Location of the `end` keyword
    //
    // ```text
    // class << foo; end
    //               ~~~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // class << foo; end
    // ~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void sclass_node_free(struct SClass *node);


// Represents `self` keyword
struct Self_
{
    // Location of the `self` keyword
    //
    // ```text
    // self
    // ~~~~
    // ```
    struct Loc *expression_l;
};

void self__node_free(struct Self_ *node);


// Represents a method call (e.g. `foo.bar(42)`)
struct Send
{
    // Receiver of the method call
    //
    // `None` for implicit method call (e.g. `foo(42)`)
    struct Node *recv;
    // Name of the method that is called
    char *method_name;
    // A list of arguments
    struct NodeList *args;
    // Location of the `.` operator
    //
    // ```text
    // foo.bar(42)
    //    ~
    // ```
    //
    // `None` for implicit method call (e.g. `foo(42)`)
    struct Loc *dot_l;
    // Location of the method name
    //
    // ```text
    // foo.bar(42)
    //     ~~~
    // ```
    //
    // `None` in a very special case when method call is implicit (i.e. `foo.(42)`)
    struct Loc *selector_l;
    // Location of open parenthesis
    //
    // ```text
    // foo(42)
    //    ~
    // ```
    //
    // `None` if there are parentheses
    struct Loc *begin_l;
    // Location of closing parenthesis
    //
    // ```text
    // foo(42)
    //       ~
    // ```
    //
    // `None` if there are parentheses
    struct Loc *end_l;
    // Location of the operator if method is a setter
    //
    // ```text
    // foo.bar = 42
    //         ~
    // ```
    //
    // `None` otherwise
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo.bar(42)
    // ~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void send_node_free(struct Send *node);


// Represents a special block argument that "shadows" outer variable (i.e. `|;foo|`)
struct Shadowarg
{
    // Name of the argument
    char *name;
    // Location of the argument
    //
    // ```text
    // proc { |;foo|}
    //          ~~~
    // ```
    struct Loc *expression_l;
};

void shadowarg_node_free(struct Shadowarg *node);


// Represents an arguments splat (i.e. `*bar` in a call like `foo(*bar)`)
struct Splat
{
    // Value that is converted to array
    struct Node *value;
    // Location of the `*` operator
    //
    // ```text
    // foo(*bar)
    //     ~
    // ```
    struct Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo(*bar)
    //     ~~~~
    // ```
    struct Loc *expression_l;
};

void splat_node_free(struct Splat *node);


// Represents a plain non-interpolated string literal (e.g. `"foo"`)
struct Str
{
    // Value of the string literal
    //
    // Note that it's a `StringValue`, not a `String`.
    // The reason is that you can get UTF-8 incompatible strings
    // from a valid UTF-8 source using escape sequences like `"\xFF"`
    //
    // These "\", "x", "F", "F" chars are valid separately, but together
    // they construct a char with code = 255 that is invalid for UTF-8.
    //
    // You can use `to_string_lossy` or `to_string` methods to get a raw string value.
    char *value;
    // Location of the string begin
    //
    // ```text
    // "foo"
    // ~
    // ```
    //
    // `None` if string literal is a part of the words array (like `%w[foo bar baz]`)
    struct Loc *begin_l;
    // Location of the string begin
    //
    // ```text
    // "foo"
    //     ~
    // ```
    //
    // `None` if string literal is a part of the words array (like `%w[foo bar baz]`)
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // "foo"
    // ~~~~~
    // ```
    struct Loc *expression_l;
};

void str__node_free(struct Str *node);


// Represents a `super` keyword
struct Super
{
    // A list of arguments given to `super`
    struct NodeList *args;
    // Location of the `super` keyword
    //
    // ```text
    // super(1, 2)
    // ~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // super(1, 2)
    //      ~
    // ```
    //
    // `None` if there are no parentheses
    struct Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // super(1, 2)
    //           ~
    // ```
    //
    // `None` if there are no parentheses
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // super(1, 2)
    // ~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void super__node_free(struct Super *node);


// Represents a plain symbol literal (i.e. `:foo`)
//
// Note that `:` in `{ foo: bar }` belongs to a `pair` node.
struct Sym
{
    // Value of the symbol literal
    //
    // Note that it's a `StringValue`, not a `String`.
    // The reason is that you can get UTF-8 incompatible strings
    // from a valid UTF-8 source using escape sequences like `"\xFF"`
    //
    // These "\", "x", "F", "F" chars are valid separately, but together
    // they construct a char with code = 255 that is invalid for UTF-8.
    //
    // You can use `to_string_lossy` or `to_string` methods to get a raw symbol value.
    char *name;
    // Location of the symbol begin
    //
    // ```text
    // :foo
    // ~
    // ```
    //
    // `None` if symbol is a label (`{ foo: 1 }`) or a part of the symbols array (`%i[foo bar baz]`)
    struct Loc *begin_l;
    // Location of the symbol end
    //
    // ```text
    // { 'foo': 1 }
    //        ~
    // ```
    //
    // `None` if symbol is **not** a string label (`:foo`) or a part of the symbols array (`%i[foo bar baz]`)
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // :foo
    // ~~~~
    //
    // { foo: 1 }
    //   ~~~~
    //
    // %i[foo]
    //    ~~~
    // ```
    struct Loc *expression_l;
};

void sym_node_free(struct Sym *node);


// Represents a `true` literal
struct True
{
    // Location of the `true` keyword
    //
    // ```text
    // true
    // ~~~~
    // ```
    struct Loc *expression_l;
};

void true__node_free(struct True *node);


// Represents an `undef` keyword (e.g. `undef foo, :bar`)
struct Undef
{
    // A list of names to `undef`
    struct NodeList *names;
    // Location the `undef` keyword
    //
    // ```text
    // undef foo, :bar
    // ~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // undef :foo, bar
    // ~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void undef_node_free(struct Undef *node);


// Represents an `unless` guard used in pattern matching (i.e. `in pattern unless guard`)
struct UnlessGuard
{
    // Condition of the guard, `Lvar("foo")` in `in pattern unless guard`
    struct Node *cond;
    // Location of the `unless` keyword
    //
    // ```text
    // case foo; in pattern unless cond; end
    //                      ~~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in pattern unless cond; end
    //                      ~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void unless_guard_node_free(struct UnlessGuard *node);


// Represents `until` loop
struct Until
{
    // Condition of the loop
    struct Node *cond;
    // Body of the loop.
    //
    // `None` if body is empty
    struct Node *body;
    // Location of the `until` keyword
    //
    // ```text
    // until cond do; foo; end
    // ~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the `do` keyword
    //
    // ```text
    // until cond do; foo; end
    //            ~~
    // ```
    //
    // `do` is optional, and so `begin_l` can be `None`
    struct Loc *begin_l;
    // Location of the `end` keyword
    //
    // ```text
    // until cond do; foo; end
    //                     ~~~
    // ```
    //
    // `None` if loop is a modifier (i.e. `foo until bar`)
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // until cond do; foo; end
    // ~~~~~~~~~~~~~~~~~~~~~~~
    //
    // foo until bar
    // ~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void until_node_free(struct Until *node);


// Represents a post-until loop
//
// ```text
// begin
//   foo
// end until bar
// ```
struct UntilPost
{
    // Condition of the loop
    struct Node *cond;
    // Body of the loop
    struct Node *body;
    // Location of the `until` keyword
    //
    // ```text
    // begin; foo; end until bar
    //                 ~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the `until` keyword
    //
    // ```text
    // begin; foo; end until bar
    // ~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void until_post_node_free(struct UntilPost *node);


// Represents a branch of the `case` statement (i.e. `when foo`)
struct When
{
    // A list of values to compare/match against
    struct NodeList *patterns;
    // Body of the `when` branch
    struct Node *body;
    // Location of the `when` keyword
    //
    // ```text
    // case foo; when bar; end
    //           ~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the `then` keyword
    //
    // ```text
    // case foo; when bar then baz; end
    //                    ~~~~
    // ```
    //
    // `then` is optional, and so `begin_l` can be `None`
    struct Loc *begin_l;
    // Location of the full expression
    //
    // ```text
    // case foo; when bar then baz; end
    //           ~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void when_node_free(struct When *node);


// Represents `while` loop
struct While
{
    // Condition of the loop
    struct Node *cond;
    // Body of the loop.
    //
    // `None` if body is empty
    struct Node *body;
    // Location of the `while` keyword
    //
    // ```text
    // while cond do; foo; end
    // ~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the `do` keyword
    //
    // ```text
    // while cond do; foo; end
    //            ~~
    // ```
    //
    // `do` is optional, and so `begin_l` can be `None`
    struct Loc *begin_l;
    // Location of the `end` keyword
    //
    // ```text
    // while cond do; foo; end
    //                     ~~~
    // ```
    //
    // `None` if loop is a modifier (i.e. `foo while bar`)
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // while cond do; foo; end
    // ~~~~~~~~~~~~~~~~~~~~~~~
    //
    // foo while bar
    // ~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void while__node_free(struct While *node);


// Represents a post-while loop
//
// ```text
// begin
//   foo
// end while bar
// ```
struct WhilePost
{
    // Condition of the loop
    struct Node *cond;
    // Body of the loop
    struct Node *body;
    // Location of the `while` keyword
    //
    // ```text
    // begin; foo; end while bar
    //                 ~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the `while` keyword
    //
    // ```text
    // begin; foo; end while bar
    // ~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void while_post_node_free(struct WhilePost *node);


// Represents a executable here-document literal (both with and without interpolation)
//
// It's similar to `Xstr` in terms of abstract syntax tree, but has different source maps.
struct XHeredoc
{
    // A list of string parts (static literals and interpolated expressions)
    struct NodeList *parts;
    // Location of the executable here-document body
    //
    // ```text
    // <<-`HERE`\n  a\n   #{42}\nHERE
    //          ~~~~~~~~~~~~~~~
    // ```
    struct Loc *heredoc_body_l;
    // Location of the executable here-document end
    //
    // ```text
    // <<-`HERE`\n  a\n   #{42}\nHERE
    //                         ~~~~
    // ```
    struct Loc *heredoc_end_l;
    // Location of the executable here-document identifier
    //
    // ```text
    // <<-`HERE`\n  a\n   #{42}\nHERE
    // ~~~~~~~
    // ```
    //
    // **Note**: This is the only node (with `Heredoc`) that has `expression_l` smaller that all other sub-locations merged.
    // The reason for that is that it's possible to add more code after here-document ID:
    //
    // ```text
    // <<-`HERE` + "rest"
    //   content
    // HERE
    // ```
    struct Loc *expression_l;
};

void x_heredoc_node_free(struct XHeredoc *node);


// Represents an executable string (i.e. `` `sh #{script_name}` ``)
struct Xstr
{
    // A list of string parts (static literals and interpolated expressions)
    struct NodeList *parts;
    // Location of the string begin
    //
    // ```text
    // `#{foo}`
    // ~
    //
    // %X{#{foo}}
    // ~~~
    // ```
    struct Loc *begin_l;
    // Location of the string end
    //
    // ```text
    // `#{foo}`
    //        ~
    //
    // %X{#{foo}}
    //          ~
    // ```
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // `#{foo}`
    // ~~~~~~~~
    //
    // %X{#{foo}}
    // ~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void xstr_node_free(struct Xstr *node);


// Represents an `yield` keyword
struct Yield
{
    // A list of arguments given to `yield`
    struct NodeList *args;
    // Location of the `yield` keyword
    //
    // ```text
    // yield 1, 2
    // ~~~~~
    // ```
    struct Loc *keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // yield(1, 2)
    //      ~
    // ```
    //
    // `None` if there are no parentheses
    struct Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // yield(1, 2)
    //           ~
    // ```
    //
    // `None` if there are no parentheses
    struct Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // yield(1, 2)
    // ~~~~~~~~~~~
    // ```
    struct Loc *expression_l;
};

void yield__node_free(struct Yield *node);


// Represents a `super` call without arguments and parentheses
//
// It's different from `super()` as it implicitly forwards current arguments
struct ZSuper
{
    // Location of the `super` keyword
    //
    // ```text
    // super
    // ~~~~~
    // ```
    struct Loc *expression_l;
};

void zsuper_node_free(struct ZSuper *node);

enum NodeType
{
    NODE_ALIAS,
    NODE_AND_ASGN,
    NODE_AND,
    NODE_ARG,
    NODE_ARGS,
    NODE_ARRAY,
    NODE_ARRAY_PATTERN,
    NODE_ARRAY_PATTERN_WITH_TAIL,
    NODE_BACK_REF,
    NODE_BEGIN,
    NODE_BLOCK,
    NODE_BLOCK_PASS,
    NODE_BLOCKARG,
    NODE_BREAK_,
    NODE_CASE,
    NODE_CASE_MATCH,
    NODE_CASGN,
    NODE_CBASE,
    NODE_CLASS,
    NODE_COMPLEX,
    NODE_CONST_,
    NODE_CONST_PATTERN,
    NODE_CSEND,
    NODE_CVAR,
    NODE_CVASGN,
    NODE_DEF,
    NODE_DEFINED,
    NODE_DEFS,
    NODE_DSTR,
    NODE_DSYM,
    NODE_EFLIPFLOP,
    NODE_EMPTY_ELSE,
    NODE_ENCODING_,
    NODE_ENSURE,
    NODE_ERANGE,
    NODE_FALSE_,
    NODE_FILE,
    NODE_FIND_PATTERN,
    NODE_FLOAT,
    NODE_FOR_,
    NODE_FORWARD_ARG,
    NODE_FORWARDED_ARGS,
    NODE_GVAR,
    NODE_GVASGN,
    NODE_HASH,
    NODE_KWARGS,
    NODE_HASH_PATTERN,
    NODE_HEREDOC,
    NODE_IF_,
    NODE_IF_GUARD,
    NODE_IF_MOD,
    NODE_IF_TERNARY,
    NODE_IFLIPFLOP,
    NODE_MATCH_PATTERN,
    NODE_MATCH_PATTERN_P,
    NODE_IN_PATTERN,
    NODE_INDEX,
    NODE_INDEX_ASGN,
    NODE_INT,
    NODE_IRANGE,
    NODE_IVAR,
    NODE_IVASGN,
    NODE_KWARG,
    NODE_KWBEGIN,
    NODE_KWNILARG,
    NODE_KWOPTARG,
    NODE_KWRESTARG,
    NODE_KWSPLAT,
    NODE_LAMBDA,
    NODE_LINE,
    NODE_LVAR,
    NODE_LVASGN,
    NODE_MASGN,
    NODE_MATCH_ALT,
    NODE_MATCH_AS,
    NODE_MATCH_CURRENT_LINE,
    NODE_MATCH_NIL_PATTERN,
    NODE_MATCH_REST,
    NODE_MATCH_VAR,
    NODE_MATCH_WITH_LVASGN,
    NODE_MLHS,
    NODE_MODULE,
    NODE_NEXT,
    NODE_NIL,
    NODE_NTH_REF,
    NODE_NUMBLOCK,
    NODE_OP_ASGN,
    NODE_OPTARG,
    NODE_OR,
    NODE_OR_ASGN,
    NODE_PAIR,
    NODE_PIN,
    NODE_POSTEXE,
    NODE_PREEXE,
    NODE_PROCARG0,
    NODE_RATIONAL,
    NODE_REDO,
    NODE_REG_OPT,
    NODE_REGEXP,
    NODE_RESCUE,
    NODE_RESCUE_BODY,
    NODE_RESTARG,
    NODE_RETRY,
    NODE_RETURN_,
    NODE_SCLASS,
    NODE_SELF_,
    NODE_SEND,
    NODE_SHADOWARG,
    NODE_SPLAT,
    NODE_STR_,
    NODE_SUPER_,
    NODE_SYM,
    NODE_TRUE_,
    NODE_UNDEF,
    NODE_UNLESS_GUARD,
    NODE_UNTIL,
    NODE_UNTIL_POST,
    NODE_WHEN,
    NODE_WHILE_,
    NODE_WHILE_POST,
    NODE_X_HEREDOC,
    NODE_XSTR,
    NODE_YIELD_,
    NODE_ZSUPER,
};

union InnerNode
{
    struct Alias *_alias;
    struct AndAsgn *_and_asgn;
    struct And *_and;
    struct Arg *_arg;
    struct Args *_args;
    struct Array *_array;
    struct ArrayPattern *_array_pattern;
    struct ArrayPatternWithTail *_array_pattern_with_tail;
    struct BackRef *_back_ref;
    struct Begin *_begin;
    struct Block *_block;
    struct BlockPass *_block_pass;
    struct Blockarg *_blockarg;
    struct Break *_break_;
    struct Case *_case;
    struct CaseMatch *_case_match;
    struct Casgn *_casgn;
    struct Cbase *_cbase;
    struct Class *_class;
    struct Complex *_complex;
    struct Const *_const_;
    struct ConstPattern *_const_pattern;
    struct CSend *_csend;
    struct Cvar *_cvar;
    struct Cvasgn *_cvasgn;
    struct Def *_def;
    struct Defined *_defined;
    struct Defs *_defs;
    struct Dstr *_dstr;
    struct Dsym *_dsym;
    struct EFlipFlop *_eflipflop;
    struct EmptyElse *_empty_else;
    struct Encoding *_encoding_;
    struct Ensure *_ensure;
    struct Erange *_erange;
    struct False *_false_;
    struct File *_file;
    struct FindPattern *_find_pattern;
    struct Float *_float;
    struct For *_for_;
    struct ForwardArg *_forward_arg;
    struct ForwardedArgs *_forwarded_args;
    struct Gvar *_gvar;
    struct Gvasgn *_gvasgn;
    struct Hash *_hash;
    struct Kwargs *_kwargs;
    struct HashPattern *_hash_pattern;
    struct Heredoc *_heredoc;
    struct If *_if_;
    struct IfGuard *_if_guard;
    struct IfMod *_if_mod;
    struct IfTernary *_if_ternary;
    struct IFlipFlop *_iflipflop;
    struct MatchPattern *_match_pattern;
    struct MatchPatternP *_match_pattern_p;
    struct InPattern *_in_pattern;
    struct Index *_index;
    struct IndexAsgn *_index_asgn;
    struct Int *_int;
    struct Irange *_irange;
    struct Ivar *_ivar;
    struct Ivasgn *_ivasgn;
    struct Kwarg *_kwarg;
    struct KwBegin *_kwbegin;
    struct Kwnilarg *_kwnilarg;
    struct Kwoptarg *_kwoptarg;
    struct Kwrestarg *_kwrestarg;
    struct Kwsplat *_kwsplat;
    struct Lambda *_lambda;
    struct Line *_line;
    struct Lvar *_lvar;
    struct Lvasgn *_lvasgn;
    struct Masgn *_masgn;
    struct MatchAlt *_match_alt;
    struct MatchAs *_match_as;
    struct MatchCurrentLine *_match_current_line;
    struct MatchNilPattern *_match_nil_pattern;
    struct MatchRest *_match_rest;
    struct MatchVar *_match_var;
    struct MatchWithLvasgn *_match_with_lvasgn;
    struct Mlhs *_mlhs;
    struct Module *_module;
    struct Next *_next;
    struct Nil *_nil;
    struct NthRef *_nth_ref;
    struct Numblock *_numblock;
    struct OpAsgn *_op_asgn;
    struct Optarg *_optarg;
    struct Or *_or;
    struct OrAsgn *_or_asgn;
    struct Pair *_pair;
    struct Pin *_pin;
    struct Postexe *_postexe;
    struct Preexe *_preexe;
    struct Procarg0 *_procarg0;
    struct Rational *_rational;
    struct Redo *_redo;
    struct RegOpt *_reg_opt;
    struct Regexp *_regexp;
    struct Rescue *_rescue;
    struct RescueBody *_rescue_body;
    struct Restarg *_restarg;
    struct Retry *_retry;
    struct Return *_return_;
    struct SClass *_sclass;
    struct Self_ *_self_;
    struct Send *_send;
    struct Shadowarg *_shadowarg;
    struct Splat *_splat;
    struct Str *_str_;
    struct Super *_super_;
    struct Sym *_sym;
    struct True *_true_;
    struct Undef *_undef;
    struct UnlessGuard *_unless_guard;
    struct Until *_until;
    struct UntilPost *_until_post;
    struct When *_when;
    struct While *_while_;
    struct WhilePost *_while_post;
    struct XHeredoc *_x_heredoc;
    struct Xstr *_xstr;
    struct Yield *_yield_;
    struct ZSuper *_zsuper;
};

struct Node
{
    enum NodeType node_type;
    union InnerNode *inner;
};

void inner_node_free(union InnerNode *inner_node, enum NodeType node_type);
void node_free(struct Node *node);

#endif // LIB_RUBY_PARSER_GEN_H
