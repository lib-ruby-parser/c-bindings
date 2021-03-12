#ifndef LIB_RUBY_PARSER_GEN_H
#define LIB_RUBY_PARSER_GEN_H

#include <stddef.h>
#include <stdint.h>
#include "node_list.h"
#include "loc.h"

typedef struct Node Node;
typedef struct Loc Loc;
typedef struct NodeList NodeList;
void node_free(Node *node);


// Represents `alias to from` statement.
typedef struct Alias
{
    // Target of the `alias`.
    //
    // `Sym("foo")` node for `alias :foo :bar`
    Node *to;
    // Source of the `alias`.
    //
    // `Sym("bar")` node for `alias :foo :bar`
    Node *from;
    // Location of the `alias` keyword
    //
    // ```text
    // alias foo bar
    // ~~~~~
    // ```
    Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // alias foo bar
    // ~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Alias;

void alias_node_free(Alias *node);


// Represents `a &&= 1` statement.
typedef struct AndAsgn
{
    // Receiver of the `&&=` operation.
    //
    // `Lvasgn("a")` node for `a &&= 1`
    Node *recv;
    // Right hand statement of assignment
    //
    // `Int("1")` node for `a &&= 1`
    Node *value;
    // Location of the `&&=` operator
    //
    // ```text
    // a &&= 1
    //   ~~~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // a &&= 1
    // ~~~~~~~
    // ```
    Loc *expression_l;
} AndAsgn;

void and_asgn_node_free(AndAsgn *node);


// Represents `foo && bar` (or `foo and bar`) statement.
typedef struct And
{
    // Left hand statament of the `&&` operation.
    //
    // `Lvar("foo")` node for `foo && bar`
    Node *lhs;
    // Right hand statement of the `&&` operation.
    //
    // `Lvar("bar")` node for `foo && bar`
    Node *rhs;
    // Location of the `&&` (or `and`) operator
    //
    // ```text
    // a && b
    //   ~~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // a && b
    // ~~~~~~
    // ```
    Loc *expression_l;
} And;

void and_node_free(And *node);


// Represents a positional required block/method argument.
//
// `a` in `def m(a); end` or `proc { |a| }`
typedef struct Arg
{
    // Name of the argument
    char *name;
    // Location of the full expression
    //
    // ```text
    // def m(argument); end
    //       ~~~~~~~~
    // ```
    Loc *expression_l;
} Arg;

void arg_node_free(Arg *node);


// Represents an arguments list
//
// `Args(vec![Arg("a"), Optarg("b", Int("1"))])` in `def m(a, b = 1); end`
typedef struct Args
{
    // List of arguments
    NodeList *args;
    // Location of the full expression
    //
    // ```text
    // def m(a, b = 1, c:, &blk); end
    //      ~~~~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
    // Location of the open parenthesis
    //
    // ```text
    // def m(a, b = 1, c:, &blk); end
    //      ~
    // ```
    //
    // `None` for code like `def m; end` or `def m arg; end`
    Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // def m(a, b = 1, c:, &blk); end
    //                         ~
    // ```
    //
    // `None` for code like `def m; end` or `def m arg; end`
    Loc *end_l;
} Args;

void args_node_free(Args *node);


// Represents an array literal
typedef struct Array
{
    // A list of elements
    NodeList *elements;
    // Location of the open bracket
    //
    // ```text
    // [1, 2, 3]
    // ~
    // ```
    Loc *begin_l;
    // Location of the closing bracket
    //
    // ```text
    // [1, 2, 3]
    //         ~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // [1, 2, 3]
    // ~~~~~~~~~
    // ```
    Loc *expression_l;
} Array;

void array_node_free(Array *node);


// Represents an array pattern used in pattern matching
typedef struct ArrayPattern
{
    // A list of elements
    NodeList *elements;
    // Location of the open bracket
    //
    // ```text
    // [1, ^a, 3 => foo]
    // ~
    // ```
    //
    // `None` for pattern like `1, 2` without brackets
    Loc *begin_l;
    // Location of the closing bracket
    //
    // ```text
    // [1, ^a, 3 => foo]
    //                 ~
    // ```
    //
    // `None` for pattern like `1, 2` without brackets
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // [1, ^a, 3 => foo]
    // ~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} ArrayPattern;

void array_pattern_node_free(ArrayPattern *node);


// Represents an array pattern *with trailing comma* used in pattern matching
//
// It's slightly different from `ArrayPattern`, trailing comma at the end works as `, *`
typedef struct ArrayPatternWithTail
{
    // A list of elements
    NodeList *elements;
    // Location of the open bracket
    //
    // ```text
    // [1, ^a, 3 => foo,]
    // ~
    // ```
    //
    // `None` for pattern like `1, 2,` without brackets
    Loc *begin_l;
    // Location of the closing bracket
    //
    // ```text
    // [1, ^a, 3 => foo,]
    //                  ~
    // ```
    //
    // `None` for pattern like `1, 2,` without brackets
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // [1, ^a, 3 => foo,]
    // ~~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} ArrayPatternWithTail;

void array_pattern_with_tail_node_free(ArrayPatternWithTail *node);


// Represents special global variables:
//     1. `` $` ``
//     2. `$&`
//     3. `$'`
//     4. `$+`
typedef struct BackRef
{
    // Name of the variable (`"$+"` for `$+`)
    char *name;
    // Location of the full expression
    //
    // ```text
    // $+
    // ~~
    // ```
    Loc *expression_l;
} BackRef;

void back_ref_node_free(BackRef *node);


// Represents compound statement (i.e. a multi-statement)
//
// Basically all blocks of code are wrapped into `Begin` node (e.g. method/block body, rescue/ensure handler etc)
typedef struct Begin
{
    // A list of statements
    NodeList *statements;
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
    Loc *begin_l;
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
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // (1; 2)
    // ~~~~~~
    // ```
    Loc *expression_l;
} Begin;

void begin_node_free(Begin *node);


// Represents a Ruby block that is passed to a method (`proc { |foo| bar }`)
typedef struct Block
{
    // Method call that takes a block
    //
    // `Send("foo")` in `foo {}`
    Node *call;
    // A list of argument that block takes
    //
    // `vec![ Arg("a"), Optarg("b", Int("1")) ]` for `proc { |a, b = 1| }`
    //
    // `None` if the block takes no arguments
    Node *args;
    // Block body, `None` if block has no body.
    Node *body;
    // Location of the open brace
    //
    // ```text
    // proc { }
    //      ~
    // ```
    Loc *begin_l;
    // Location of the closing brace
    //
    // ```text
    // proc { }
    //        ~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // proc { }
    // ~~~~~~~~
    // ```
    Loc *expression_l;
} Block;

void block_node_free(Block *node);


// Represents a `&blk` argument of the method call (but not of the method definition, see `BlockArg`)
typedef struct BlockPass
{
    // Value that is converted to a block
    //
    // `Int("1")` in `foo(&1)` (yes, it's possible)
    Node *value;
    // Location of the `&` operator
    //
    // ```text
    // foo(&blk)
    //     ~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo(&bar)
    //     ~~~~
    // ```
    Loc *expression_l;
} BlockPass;

void block_pass_node_free(BlockPass *node);


// Represents a `&blk` argument in the method definition (but not in the method call, see `BlockPass`)
typedef struct Blockarg
{
    // Name of the argument, `String("foo")` for `def m(&foo)`
    char *name;
    // Location of the `&` operator
    //
    // ```text
    // def m(&foo); end
    //       ~
    // ```
    Loc *operator_l;
    // Location of the name
    //
    // ```text
    // def m(&foo); end
    //        ~~~
    // ```
    Loc *name_l;
    // Location of the full expression
    //
    // ```text
    // def m(&foo); end
    //       ~~~~
    // ```
    Loc *expression_l;
} Blockarg;

void blockarg_node_free(Blockarg *node);


// Represents a `break` keyword (with optional argument)
typedef struct Break
{
    // A list of arguments
    NodeList *args;
    // Location of the `break` keyword
    //
    // ```text
    // break :foo
    // ~~~~~
    // ```
    Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // break(:foo)
    // ~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Break;

void break__node_free(Break *node);


// Represents a `case` statement (for pattern matching see `CaseMatch` node)
typedef struct Case
{
    // Expression given to `case`, `Int("1")` for `case 1; end`
    // `None` for code like
    //
    // ```text
    // case
    // when pattern
    // end
    // ```
    Node *expr;
    // A list of `When` nodes (each has `patterns` and `body`)
    NodeList *when_bodies;
    // Body of the `else` branch, `None` if there's no `else` branch
    Node *else_body;
    // Location of the `case` keyword
    //
    // ```text
    // case 1; end
    // ~~~~
    // ```
    Loc *keyword_l;
    // Location of the `else` keyword
    //
    // ```text
    // case 1; else; end
    //         ~~~~
    // ```
    //
    // `None` if there's no `else` branch
    Loc *else_l;
    // Location of the `end` keyword
    //
    // ```text
    // case 1; end
    //         ~~~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // case 1; end
    // ~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Case;

void case_node_free(Case *node);


// Represents a `case` statement used for pattern matching (for regular `case` see `Case` node)
typedef struct CaseMatch
{
    // Expression given to `case`, `Int("1")` for `case 1; in 1; end`
    // `None` for code like
    //
    // ```text
    // case
    // in pattern
    // end
    // ```
    Node *expr;
    // A list of `InPattern` nodes (each has `pattern`, `guard` and `body`)
    NodeList *in_bodies;
    // Body of the `else` branch, `None` if there's no `else` branch
    Node *else_body;
    // Location of the `case` keyword
    //
    // ```text
    // case 1; in 2; end
    // ~~~~
    // ```
    Loc *keyword_l;
    // Location of the `else` keyword
    //
    // ```text
    // case 1; in 2; else; end
    //               ~~~~
    // ```
    //
    // `None` if there's no `else` branch
    Loc *else_l;
    // Location of the `end` keyword
    //
    // ```text
    // case 1; in 2; end
    //               ~~~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // case 1; in 2; end
    // ~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} CaseMatch;

void case_match_node_free(CaseMatch *node);


// Represents a constant assignment (i.e. `A = 1`)
typedef struct Casgn
{
    // Scope where the constant is defined:
    //     1. `Some(Const("A"))` for `A::B = 1`
    //     2. `None` if it's defined in the current scope (i.e. `A = 1`)
    //     3. `Some(Cbase)` if it's defined in the global scope (i.e. `::A = 1`)
    Node *scope;
    // Name of the constant, `String("A")` for `A = 1`
    char *name;
    // Value that is assigned to a constant, `Int("1")` for `A = 1`.
    //
    // **Note**: `None` if constant assignment is a part of the multi-assignment.
    // In such case `value` belongs to `Masgn` node of the multi-assignment.
    Node *value;
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
    Loc *double_colon_l;
    // Location of the constant name
    //
    // ```text
    // A::CONST = 1
    //    ~~~~~
    // ```
    Loc *name_l;
    // Location of the `=` operator
    //
    // ```text
    // A = 1
    //   ~
    // ```
    //
    // `None` if constant assignment is a part of the multi-assignment.
    // In such case `=` belongs to a `Masgn` node
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // A = 1
    // ~~~~~
    // ```
    Loc *expression_l;
} Casgn;

void casgn_node_free(Casgn *node);


// Represents leading `::` part of the constant access/assignment that is used to get/set on a global namespace.
typedef struct Cbase
{
    // Location of the full expression
    //
    // ```text
    // ::A
    // ~~
    // ```
    Loc *expression_l;
} Cbase;

void cbase_node_free(Cbase *node);


// Represents a class definition (using a `class` keyword, `Class.new` is just a method call)
typedef struct Class
{
    // Name of the class, `String("Foo")` for `class Foo; end`
    Node *name;
    // Superclass. Can be an expression in cases like `class A < (obj.foo + 1); end`
    //
    // `None` if no explicit superclass given (i.e. `class Foo; end`)
    Node *superclass;
    // Body of the method, `None` if there's no body.
    Node *body;
    // Location of the `class` keyword.
    //
    // ```text
    // class Foo; end
    // ~~~~~
    // ```
    Loc *keyword_l;
    // Location of the `<` operator
    //
    // ```text
    // class A < B; end
    //         ~
    // ```
    //
    // `None` if there's no explicit superclass given.
    Loc *operator_l;
    // Location of the `end` keyword.
    //
    // ```text
    // class Foo; end
    //            ~~~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // class Foo; end
    // ~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Class;

void class_node_free(Class *node);


// Represents a `Complex` literal (that returns an `Complex` number)
typedef struct Complex
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
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // -1i
    // ~~~
    // ```
    Loc *expression_l;
} Complex;

void complex_node_free(Complex *node);


// Represents constant access (i.e. `Foo::Bar`)
typedef struct Const
{
    // Scope where the constant is taken from:
    //     1. `Some(Const("A"))` for `A::B`
    //     2. `None` if it's taken from the current scope (i.e. `A`)
    //     3. `Some(Cbase)` if it's taken from the global scope (i.e. `::A`)
    Node *scope;
    // Name of the constant, `String("Foo")` for `Foo`
    char *name;
    // Location of the `::` operator. `None` if constant is taken from the current scope.
    //
    // ```text
    // A::B
    //  ~~
    // ```
    Loc *double_colon_l;
    // Location of the constant name
    //
    // ```text
    // Foo::Bar
    //      ~~~
    // ```
    Loc *name_l;
    // Location of the full expression
    //
    // ```text
    // Foo::Bar
    // ~~~~~~~~
    // ```
    Loc *expression_l;
} Const;

void const__node_free(Const *node);


// Const pattern used in pattern matching (e.g. `in A(1, 2)`)
typedef struct ConstPattern
{
    // Constant that is used, `Const("Foo")` for `in For(42)`
    Node *const_;
    // Inner part of the constant pattern
    //
    // `ArrayPattern(vec![ Int("1") ])` for `Foo(1)`
    Node *pattern;
    // Location of the open parenthesis
    //
    // ```text
    // case 1; in Foo(42); end
    //               ~
    // ```
    Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // case 1; in Foo(42); end
    //                  ~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // case 1; in Foo(42); end
    //            ~~~~~~~
    // ```
    Loc *expression_l;
} ConstPattern;

void const_pattern_node_free(ConstPattern *node);


// Represents conditional method call using `&.` operator
typedef struct CSend
{
    // Receiver of the method call, `Int("1")` for `1&.foo`
    Node *recv;
    // Name of the method, `String("foo")` for `1&.foo`
    char *method_name;
    // List of arguments
    //
    // ```text
    // foo&.bar(42)
    // # and also setters like
    // foo&.bar = 42
    // ```
    NodeList *args;
    // Location of the `&.` operator
    //
    // ```text
    // foo&.bar
    //    ~~
    // ```
    Loc *dot_l;
    // Location of the method name
    //
    // ```text
    // foo&.bar(42)
    //      ~~~
    // ```
    //
    // `None` in a very special case when method call is implicit (i.e. `foo&.()`)
    Loc *selector_l;
    // Location of the open parenthesis
    //
    // ```text
    // foo&.bar(42)
    //         ~
    // ```
    //
    // `None` if there are no parentheses
    Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // foo&.bar(42)
    //            ~
    // ```
    //
    // `None` if there are no parentheses
    Loc *end_l;
    // Location of the operator if `CSend` is a part of assignment like
    //
    // ```text
    // foo&.bar = 1
    //          ~
    // ```
    //
    // `None` for a regular call.
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo&.bar(42)
    // ~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} CSend;

void csend_node_free(CSend *node);


// Represents access to class variable (i.e. `@@var`)
typedef struct Cvar
{
    // Name of the class variable, `String("@@foo")` for `@@foo`
    char *name;
    // Location of the full expression
    //
    // ```text
    // @@foo
    // ~~~~~
    // ```
    Loc *expression_l;
} Cvar;

void cvar_node_free(Cvar *node);


// Represents class variable assignment (i.e. `@@var = 42`)
typedef struct Cvasgn
{
    // Name of the class variable, `String("@@foo")` for `@@foo = 1`
    char *name;
    // Value that is assigned to class variable, `Int("1")` for `@@foo = 1`
    Node *value;
    // Location of the class variable name
    //
    // ```text
    // @@foo = 1
    // ~~~~~
    // ```
    Loc *name_l;
    // Location of the `=` operator
    //
    // ```text
    // @@foo = 1
    //       ~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // @@foo = 1
    // ~~~~~~~~~
    // ```
    Loc *expression_l;
} Cvasgn;

void cvasgn_node_free(Cvasgn *node);


// Represents method definition using `def` keyword (not on a singleton, see `Defs` node).
typedef struct Def
{
    // Name of the method, `String("foo")` for `def foo; end`
    char *name;
    // Arguments of a method, `None` if there's no arguments.
    //
    // All information about parentheses around arguments is stored in this node.
    Node *args;
    // Body of a method, `None` if there's no body.
    Node *body;
    // Location of the `def` keyword.
    //
    // ```text
    // def foo; end
    // ~~~
    // ```
    Loc *keyword_l;
    // Location of the method name.
    //
    // ```text
    // def foo; end
    //     ~~~
    // ```
    Loc *name_l;
    // Location of the `end` keyword.
    //
    // ```text
    // def foo; end
    //          ~~~
    // ```
    //
    // `None` for endless method definition
    Loc *end_l;
    // Location of the `=` operator for endless method definition
    //
    // ```text
    // def m() = 1
    //         ~
    // ```
    //
    // `None` for regular method definition
    Loc *assignment_l;
    // Location of the full expression
    //
    // ```text
    // def m(a); foo; end
    // ~~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Def;

void def_node_free(Def *node);


// Represents a `defined?(foo)` expression
typedef struct Defined
{
    // Value given to `defined?`
    Node *value;
    // Location of the `defined?` keyword
    //
    // ```text
    // defined?(foo)
    // ~~~~~~~~
    // ```
    Loc *keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // defined?(foo)
    //         ~
    // ```
    //
    // `None` if there are no parentheses
    Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // defined?(foo)
    //             ~
    // ```
    //
    // `None` if there are no parentheses
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // defined?(foo)
    // ~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Defined;

void defined_node_free(Defined *node);


// Represents a singleton method definition (i.e. `def self.foo; end`)
typedef struct Defs
{
    // Definee of a method definition, `Lvar("x")` for `def x.foo; end
    Node *definee;
    // Name of the method, `String("foo")` for `def x.foo; end`
    char *name;
    // Arguments of a method, `None` if there's no arguments.
    //
    // All information about parentheses around arguments is stored in this node.
    Node *args;
    // Body of the method, `None` if there's no body.
    Node *body;
    // Location of the `def` keyword
    //
    // ```text
    // def self.foo; end
    // ~~~
    // ```
    Loc *keyword_l;
    // Location of the `.`
    //
    // ```text
    // def self.foo; end
    //         ~
    // ```
    Loc *operator_l;
    // Location of the method name
    //
    // ```text
    // def self.foo; end
    //          ~~~
    // ```
    Loc *name_l;
    // Location of the `=` operator for endless method definition
    //
    // ```text
    // def self.foo() = 42
    //                ~
    // ```
    //
    // `None` for regular method definition
    Loc *assignment_l;
    // Location of the `end` keyword
    //
    // ```text
    // def self.foo; end
    //               ~~~
    // ```
    //
    // `None` for endless method definition
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // def self.foo; end
    // ~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Defs;

void defs_node_free(Defs *node);


// Represents a string with interpolation (i.e. `"#{foo}"`)
typedef struct Dstr
{
    // A list of string parts (static literals and interpolated expressions)
    NodeList *parts;
    // Location of the string begin
    //
    // ```text
    // "#{foo}"
    // ~
    //
    // %Q{#{foo}}
    // ~~~
    // ```
    Loc *begin_l;
    // Location of the string end
    //
    // ```text
    // "#{foo}"
    //        ~
    //
    // %Q{#{foo}}
    //          ~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // "#{foo}"
    // ~~~~~~~~
    //
    // %Q{#{foo}}
    // ~~~~~~~~~~
    // ```
    Loc *expression_l;
} Dstr;

void dstr_node_free(Dstr *node);


// Represents a symbol with interpolation (i.e. `:"#{foo}"`)
typedef struct Dsym
{
    // A list of symbol parts (static literals and interpolated expressions)
    NodeList *parts;
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
    Loc *begin_l;
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
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // :"#{foo}"
    // ~~~~~~~~~
    // ```
    Loc *expression_l;
} Dsym;

void dsym_node_free(Dsym *node);


// Represents exclusive flip-flop (i.e. in `if foo...bar; end`)
typedef struct EFlipFlop
{
    // Left part of the flip-flop. `None` if based on a range without begin (`...bar`)
    Node *left;
    // Right part of the flip-flop. `None` if based on a range without end (`foo...`)
    Node *right;
    // Location of the `...` operator
    //
    // ```text
    // if foo...bar; end
    //       ~~~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // if foo...bar; end
    //    ~~~~~~~~~
    // ```
    Loc *expression_l;
} EFlipFlop;

void eflipflop_node_free(EFlipFlop *node);


// Represents a special empty else that is a part of the pattern matching.
//
// Usually empty else (e.g. part of the `if` statement) doesn't mean anything,
// however in pattern matching it prevents raising a `NoPatternError`.
//
// Throwing away this `else` may affect your code.
typedef struct EmptyElse
{
    // Location of the `else` keyword
    //
    // ```text
    // case foo; in 1; else; end
    //                 ~~~~
    // ```
    Loc *expression_l;
} EmptyElse;

void empty_else_node_free(EmptyElse *node);


// Represents a special `__ENCODING__` keyword
typedef struct Encoding
{
    // Location of the `__ENCODING__` keyword
    //
    // ```text
    // __ENCODING__
    // ~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Encoding;

void encoding__node_free(Encoding *node);


// Represents a block of code with `ensure` (i.e. `begin; ensure; end`)
typedef struct Ensure
{
    // Block of code that is wrapped into `ensure`
    // **Note**: that's the body of the `ensure` block
    //
    // `Int("1")` for `begin; 1; ensure; 2; end`
    Node *body;
    // Body of the `ensure` block
    //
    // `Int("2")` for `begin; 1; ensure; 2; end`
    Node *ensure;
    // Location of the `ensure` keyword
    //
    // ```text
    // begin; ensure; end
    //        ~~~~~~
    // ```
    Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // begin; 1; rescue; 2; else; 3; ensure; 4; end
    //        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    //
    // **Note**: begin/end belong to `KwBegin` node.
    Loc *expression_l;
} Ensure;

void ensure_node_free(Ensure *node);


// Represents range literal with excluded `end` (i.e. `1...3`)
typedef struct Erange
{
    // Begin of the range, `None` if range has no begin (i.e `...42`)
    Node *left;
    // End of the range, `None` if range has no end (i.e `42...`)
    Node *right;
    // Location of the `...` operator
    //
    // ```text
    // 1...3
    //  ~~~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // 1...3
    // ~~~~~
    // ```
    Loc *expression_l;
} Erange;

void erange_node_free(Erange *node);


// Represents a `false` literal
typedef struct False
{
    // Location of the `false` literal
    //
    // ```text
    // false
    // ~~~~~
    // ```
    Loc *expression_l;
} False;

void false__node_free(False *node);


// Represents a special `__FILE__` literal
typedef struct File
{
    // Location of the `__FILE__` literal
    //
    // ```text
    // __FILE__
    // ~~~~~~~~
    // ```
    Loc *expression_l;
} File;

void file_node_free(File *node);


// Represents a find pattern using in pattern matching (i.e. `in [*x, 1 => a, *y]`)
//
// It's different from `ArrayPattern`/`ConstPattern` because it supports multiple wildcard pattern
typedef struct FindPattern
{
    // Inner part of the find pattern
    NodeList *elements;
    // Location of the begin
    //
    // ```text
    // case foo; in [*x, 1 => a, *y]; end
    //              ~
    // ```
    //
    // `None` if there are no brackets/parentheses
    Loc *begin_l;
    // Location of the end
    //
    // ```text
    // case foo; in [*x, 1 => a, *y]; end
    //                             ~
    // ```
    //
    // `None` if there are no brackets/parentheses
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in [*x, 1 => a, *y]; end
    //              ~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} FindPattern;

void find_pattern_node_free(FindPattern *node);


// Represents a float literal (i.e. `42.5`)
typedef struct Float
{
    // String value of the literal, `String("42.5")` for `42.5`
    char *value;
    // Location of unary `-` (but not `+`)
    //
    // ```text
    // -42.5
    // ~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // -42.5
    // ~~~~~
    // ```
    Loc *expression_l;
} Float;

void float_node_free(Float *node);


// Represents a `for` loop
typedef struct For
{
    // Variable that is used in loop, `Lvasgn("a")` in `for a in b; end`
    Node *iterator;
    // Collection that is for iteration. `Lvar("b")` in `for a in b; end`
    Node *iteratee;
    // Body of the loop. `None` if there's no body
    Node *body;
    // Location of the `for` keyword
    //
    // ```text
    // for a in b; end
    // ~~~
    // ```
    Loc *keyword_l;
    // Location of the `in` keyword
    //
    // ```text
    // for a in b; end
    //       ~~
    // ```
    Loc *operator_l;
    // Location of the `do` keyword
    //
    // ```text
    // for a in b do; end
    //            ~~
    // ```
    //
    // **Note**: this `do` is optional, and so `begin_l` can be `None`.
    Loc *begin_l;
    // Location of the `end` keyword
    //
    // ```text
    // for a in b; end
    //             ~~~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // for a in b; end
    // ~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} For;

void for__node_free(For *node);


// Represents a special `...` argument that forwards positional/keyword/block arguments.
typedef struct ForwardArg
{
    // Location of the `...`
    //
    // ```text
    // def m(...); end
    //       ~~~
    // ```
    Loc *expression_l;
} ForwardArg;

void forward_arg_node_free(ForwardArg *node);


// Represents a `...` operator that contains forwarded argument (see `ForwardArg`)
typedef struct ForwardedArgs
{
    // Location of the `...`
    //
    // ```text
    // def m(...); foo(...); end
    //                 ~~~
    // ```
    Loc *expression_l;
} ForwardedArgs;

void forwarded_args_node_free(ForwardedArgs *node);


// Represents access to global variable (i.e. `$foo`)
typedef struct Gvar
{
    // Name of the global variable, `String("$foo")` for `$foo`
    char *name;
    // Location of the full expression
    //
    // ```text
    // $foo
    // ~~~~
    // ```
    Loc *expression_l;
} Gvar;

void gvar_node_free(Gvar *node);


// Represents global variable assignment (i.e. `$foo = 42`)
typedef struct Gvasgn
{
    // Name of the global variable, `String("$foo")` for `$foo`
    char *name;
    // Value that is assigned to global variable, `Int("42")` for `$foo = 42`
    //
    // `None` if global variable assignment is a part of the multi-assignment.
    // In such case `value` is a part of the `Masgn` node.
    Node *value;
    // Location of the global variable name
    //
    // ```text
    // $foo = 42
    // ~~~~
    // ```
    Loc *name_l;
    // Location of the `=` operator
    //
    // ```text
    // $foo = 42
    //      ~
    // ```
    //
    // `None` if global variable assignment is a part of the multi-assignment.
    // In such case `=` operator belongs to the `Masgn` node.
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // $foo = 42
    // ~~~~~~~~~
    // ```
    Loc *expression_l;
} Gvasgn;

void gvasgn_node_free(Gvasgn *node);


// Represents a hash literal (i.e. `{ foo: 42 }`)
typedef struct Hash
{
    // A list of key-value pairs
    NodeList *pairs;
    // Location of the open parenthesis
    //
    // ```text
    // { a: 1 }
    // ~
    // ```
    //
    // `None` if hash literal is implicit, e.g. `foo(key: "value")`
    Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // { a: 1 }
    //        ~
    // ```
    //
    // `None` if hash literal is implicit, e.g. `foo(key: "value")`
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // { a: 1 }
    // ~~~~~~~~
    // ```
    Loc *expression_l;
} Hash;

void hash_node_free(Hash *node);


// Represents kwargs that are given to a method call, super or yield (i.e. `foo(bar: 1)`)
typedef struct Kwargs
{
    // A list of key-value pairs
    NodeList *pairs;
    // Location of the full expression
    //
    // ```text
    // foo(bar: 1)
    //     ~~~~~~
    // ```
    Loc *expression_l;
} Kwargs;

void kwargs_node_free(Kwargs *node);


// Represents a hash pattern used in pattern matching (i.e. `in { a: 1 }`)
typedef struct HashPattern
{
    // A list of inner patterns
    NodeList *elements;
    // Location of the open parenthesis
    //
    // ```text
    // case foo; in { a: 1 }; end
    //              ~
    // ```
    //
    // `None` if there are no parentheses
    Loc *begin_l;
    // Location of the open parenthesis
    //
    // ```text
    // case foo; in { a: 1 }; end
    //                     ~
    // ```
    //
    // `None` if there are no parentheses
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in { a: 1 }; end
    //              ~~~~~~~~
    // ```
    Loc *expression_l;
} HashPattern;

void hash_pattern_node_free(HashPattern *node);


// Represents a here-document literal (both with and without interpolation)
//
// It's similar to `Dstr` in terms of abstract syntax tree, but has different source maps.
typedef struct Heredoc
{
    // A list of string parts (static literals and interpolated expressions)
    NodeList *parts;
    // Location of the here-document body
    //
    // ```text
    // <<-HERE\n  a\n   #{42}\nHERE
    //          ~~~~~~~~~~~~~~~
    // ```
    Loc *heredoc_body_l;
    // Location of the here-document end
    //
    // ```text
    // <<-HERE\n  a\n   #{42}\nHERE
    //                         ~~~~
    // ```
    Loc *heredoc_end_l;
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
    Loc *expression_l;
} Heredoc;

void heredoc_node_free(Heredoc *node);


// Represents an `if` statement (i.e. `if foo; bar; else; baz; end`)
typedef struct If
{
    // Condition given to the `if` statement, `Lvar("a")` for `if a; b; else; c; end`
    Node *cond;
    // True-branch of the `if` statement, `Lvar("b")` for `if a; b; else; c; end`
    Node *if_true;
    // False-branch of the `if` statement, `Lvar("c")` for `if a; b; else; c; end`
    Node *if_false;
    // Location of the `if` keyword
    //
    // ```text
    // if foo; end
    // ~~
    // ```
    Loc *keyword_l;
    // Location of the `then` keyword
    //
    // ```text
    // if foo then; end
    //        ~~~~
    // ```
    //
    // `None` if `then` keyword is omitted
    Loc *begin_l;
    // Location of the `else` keyword
    //
    // ```text
    // if foo; else; end
    //         ~~~~
    // ```
    //
    // `None` if there's no `else` branch
    Loc *else_l;
    // Location of the `end` keyword
    //
    // ```text
    // if foo; end
    //         ~~~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // if a then; b; else; c end
    // ~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} If;

void if__node_free(If *node);


// Represents an `if` guard used in pattern matching (i.e. `case foo; in pattern if guard; end`)
typedef struct IfGuard
{
    // Condition of the guard, `Lvar("foo")` in `in pattern if guard`
    Node *cond;
    // Location of the `if` keyword
    //
    // ```text
    // case foo; in pattern if cond; end
    //                      ~~
    // ```
    Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in pattern if cond; end
    //                      ~~~~~~~
    // ```
    Loc *expression_l;
} IfGuard;

void if_guard_node_free(IfGuard *node);


// Represents an `if`/`unless` modifier (i.e. `stmt if cond`)
typedef struct IfMod
{
    // Condition of the modifier
    Node *cond;
    // True-branch of the modifier.
    //
    // Always set for `if` modifier.
    // Always `None` for `unless` modifier.
    Node *if_true;
    // False-branch of the modifier.
    //
    // Always set for `unless` modifier.
    // Always `None` for `if` modifier.
    Node *if_false;
    // Location of the `if`/`unless` keyword
    //
    // ```text
    // stmt if cond
    //      ~~
    //
    // stmt unless cond
    //      ~~~~~~
    // ```
    Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // stmt if cond
    // ~~~~~~~~~~~~
    //
    // stmt unless cond
    // ~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} IfMod;

void if_mod_node_free(IfMod *node);


// Represents ternary `if` statement (i.e. `cond ? if_true : if_false`)
typedef struct IfTernary
{
    // Condition of the `if` statement
    Node *cond;
    // True-branch
    Node *if_true;
    // True-branch
    Node *if_false;
    // Location of the `?` operator
    //
    // ```text
    // cond ? if_true : if_false
    //      ~
    // ```
    Loc *question_l;
    // Location of the `:` operator
    //
    // ```text
    // cond ? if_true : if_false
    //                ~
    // ```
    Loc *colon_l;
    // Location of the full expression
    //
    // ```text
    // cond ? if_true : if_false
    // ~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} IfTernary;

void if_ternary_node_free(IfTernary *node);


// Represents inclusive flip-flop (i.e. in `if foo..bar; end`)
typedef struct IFlipFlop
{
    // Left part of the flip-flop. `None` if based on a range without begin (`..bar`)
    Node *left;
    // Right part of the flip-flop. `None` if based on a range without end (`foo..`)
    Node *right;
    // Location of the `..` operator
    //
    // ```text
    // if foo..bar; end
    //       ~~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // if foo..bar; end
    //    ~~~~~~~~
    // ```
    Loc *expression_l;
} IFlipFlop;

void iflipflop_node_free(IFlipFlop *node);


// Represents a one-line pattern matching that can throw an error (i.e. `foo => pattern`)
typedef struct MatchPattern
{
    // Value that is used for matching
    Node *value;
    // Pattern that is used for matching
    Node *pattern;
    // Location of the `=>` operator
    //
    // ```text
    // foo => pattern
    //     ~~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo => pattern
    // ~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} MatchPattern;

void match_pattern_node_free(MatchPattern *node);


// Represents a one-line pattern matching that never throws but returns true/false (i.e. `foo in pattern`)
typedef struct MatchPatternP
{
    // Value that is used for matching
    Node *value;
    // Pattern that is used for matching
    Node *pattern;
    // Location of the `in` operator
    //
    // ```text
    // foo in pattern
    //     ~~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo in pattern
    // ~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} MatchPatternP;

void match_pattern_p_node_free(MatchPatternP *node);


// Represents an `in pattern` branch of the pattern matching
typedef struct InPattern
{
    // Value that is used for matching
    Node *pattern;
    // Guard that is used for matching
    //
    // Optional, so can be `None`
    Node *guard;
    // Body of the branch that is invoked if value matches pattern
    Node *body;
    // Location of the `in` keyword
    //
    // ```text
    // case value; in pattern; end
    //             ~~
    // ```
    Loc *keyword_l;
    // Location of the `then` keyword
    //
    // ```text
    // case value; in pattern then; end
    //                        ~~~~
    // ```
    Loc *begin_l;
    // Location of the full expression
    //
    // ```text
    // case value; in pattern then; 42; end
    //             ~~~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} InPattern;

void in_pattern_node_free(InPattern *node);


// Represents indexing operation (i.e. `foo[1,2,3]`)
typedef struct Index
{
    // Receiver of indexing
    Node *recv;
    // A list of indexes
    NodeList *indexes;
    // Location of open bracket
    //
    // ```text
    // foo[1, 2, 3]
    //    ~
    // ```
    Loc *begin_l;
    // Location of closing bracket
    //
    // ```text
    // foo[1, 2, 3]
    //            ~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // foo[1, 2, 3]
    // ~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Index;

void index_node_free(Index *node);


// Represents assignment using indexing operation (i.e. `foo[1, 2, 3] = bar`)
typedef struct IndexAsgn
{
    // Receiver of the indexing
    Node *recv;
    // A list of indexes
    NodeList *indexes;
    // Value that is assigned
    //
    // `None` if assignment is a part of the multi-assignment.
    // In such case `value` belongs to `Masgn` node.
    Node *value;
    // Location of open bracket
    //
    // ```text
    // foo[1, 2, 3] = bar
    //    ~
    // ```
    Loc *begin_l;
    // Location of closing bracket
    //
    // ```text
    // foo[1, 2, 3] = bar
    //            ~
    // ```
    Loc *end_l;
    // Location of the `=` operator
    //
    // ```text
    // foo[1, 2, 3] = bar
    //              ~
    // ```
    //
    // `None` if assignment is a part of the multi-assignment.
    // In such case operator `=` belongs to `Masgn` node.
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo[1, 2, 3] = bar
    // ~~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} IndexAsgn;

void index_asgn_node_free(IndexAsgn *node);


// Represents an integer literal (i.e. `42`)
typedef struct Int
{
    // String value of the literal, `String("42")` for `42`
    char *value;
    // Location of unary `-` (but not `+`)
    //
    // ```text
    // -42
    // ~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // -42
    // ~~~
    // ```
    Loc *expression_l;
} Int;

void int_node_free(Int *node);


// Represents inclusive range (i.e. `2..4`)
typedef struct Irange
{
    // Begin of the range, `None` if range has no `begin` (i.e. `..4`)
    Node *left;
    // End of the range, `None` if range has no `end` (i.e. `2..`)
    Node *right;
    // Location of the `..` operator
    //
    // ```text
    // 2..4
    //  ~~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // 2..4
    // ~~~~
    // ```
    Loc *expression_l;
} Irange;

void irange_node_free(Irange *node);


// Represents access to instance variable (i.e. `@foo`)
typedef struct Ivar
{
    // Name of the instance variable, `String("@foo")` in `@foo`
    char *name;
    // Location of the full expression
    //
    // ```text
    // @foo
    // ~~~~
    // ```
    Loc *expression_l;
} Ivar;

void ivar_node_free(Ivar *node);


// Represents instance variable assignment (i.e `@foo = 42`)
typedef struct Ivasgn
{
    // Name of the instance variable, `String("@foo")` in `@foo = 42`
    char *name;
    // Value that is assigned to instance variable.
    //
    // `None` if instance variable assignment is a part of the multi-assignment.
    // In such case `value` is a part of the `Masgn` node.
    Node *value;
    // Location of the instance variable name.
    //
    // ```text
    // @foo = 1
    // ~~~~
    // ```
    Loc *name_l;
    // Location of the `=` operator.
    //
    // ```text
    // @foo = 1
    //      ~
    // ```
    //
    // `None` if instance variable assignment is a part of the multi-assignment.
    // In such case `value` is a part of the `Masgn` node.
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // @foo = 42
    // ~~~~~~~~~
    // ```
    Loc *expression_l;
} Ivasgn;

void ivasgn_node_free(Ivasgn *node);


// Represents required keyword argument (i.e. `foo` in `def m(foo:); end`)
typedef struct Kwarg
{
    // Name of the keyword argument
    char *name;
    // Location of the name
    //
    // ```text
    // def foo(bar:); end
    //         ~~~
    // ```
    Loc *name_l;
    // Location of the full expression
    //
    // ```text
    // def foo(bar:); end
    //         ~~~~
    // ```
    Loc *expression_l;
} Kwarg;

void kwarg_node_free(Kwarg *node);


// Represents an explicit `begin; end` block.
//
// The reason why it's different is that only
// ```text
// begin; foo; end while cond
// ```
// is a post-while loop (same with post-until loop)
typedef struct KwBegin
{
    // A list of statements
    NodeList *statements;
    // Location of the `begin` keyword
    //
    // ```text
    // begin; foo; end
    // ~~~~~
    // ```
    Loc *begin_l;
    // Location of the `begin` keyword
    //
    // ```text
    // begin; foo; end
    //             ~~~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // begin; foo; bar
    // ~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} KwBegin;

void kwbegin_node_free(KwBegin *node);


// Represents an special argument that rejects all keyword arguments (i.e. `def m(**nil); end`)
typedef struct Kwnilarg
{
    // Location of the `nil`
    //
    // ```text
    // def m(**nil); end
    //         ~~~
    // ```
    Loc *name_l;
    // Location of the `nil`
    //
    // ```text
    // def m(**nil); end
    //       ~~~~~
    // ```
    Loc *expression_l;
} Kwnilarg;

void kwnilarg_node_free(Kwnilarg *node);


// Represents an optional keyword argument (i.e. `foo` in `def m(foo: 42); end`)
typedef struct Kwoptarg
{
    // Name of the optional keyword argument
    char *name;
    // Default value of the optional keyword argument
    Node *default_;
    // Location of the argument name
    //
    // ```text
    // def m(foo: 1); end
    //       ~~~
    // ```
    Loc *name_l;
    // Location of the argument name
    //
    // ```text
    // def m(foo: 1); end
    //       ~~~~~~
    // ```
    Loc *expression_l;
} Kwoptarg;

void kwoptarg_node_free(Kwoptarg *node);


// Represents a keyword rest argument (i.e. `foo` in `def m(**foo); end`)
typedef struct Kwrestarg
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
    Loc *operator_l;
    // Location of the argument name
    //
    // ```text
    // def m(**foo); end
    //         ~~~
    // ```
    //
    // `None` if argument has no name (`def m(**); end`)
    Loc *name_l;
    // Location of the full expression
    //
    // ```text
    // def m(**foo); end
    //       ~~~~~
    // ```
    Loc *expression_l;
} Kwrestarg;

void kwrestarg_node_free(Kwrestarg *node);


// Represents a keyword arguments splat (i.e. `**bar` in a call like `foo(**bar)`)
typedef struct Kwsplat
{
    // Value that is converted into a `Hash` using `**`
    Node *value;
    // Location of the `**` operator
    //
    // ```text
    // foo(**bar)
    //     ~~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo(**bar)
    //     ~~~~~
    // ```
    Loc *expression_l;
} Kwsplat;

void kwsplat_node_free(Kwsplat *node);


// Represents a lambda call using `->` (i.e. `-> {}`)
//
// Note that `Lambda` is a part of the `Block`, not other way around.
typedef struct Lambda
{
    // Location of the `->`
    //
    // ```text
    // -> {}
    // ~~
    // ```
    Loc *expression_l;
} Lambda;

void lambda_node_free(Lambda *node);


// Represents a special `__LINE__` literal
typedef struct Line
{
    // Location of the `__LINE__` literal
    //
    // ```text
    // __LINE__
    // ~~~~~~~~
    // ```
    Loc *expression_l;
} Line;

void line_node_free(Line *node);


// Represents access to a local variable (i.e. `foo`)
//
// Parser knows that it's a local variable because:
//     1. there was an assignment to this variable **before** accessing it
//     2. it's an argument of the current method / block
//     3. it's been implicitly declared by `MatchWithLvasgn` node
//
// Otherwise it's a method call (see `Send`)
typedef struct Lvar
{
    // Name of the local variable
    char *name;
    // Location of the local variable
    //
    // ```text
    // foo
    // ~~~
    // ```
    Loc *expression_l;
} Lvar;

void lvar_node_free(Lvar *node);


// Represents local variable assignment (i.e. `foo = 42`)
typedef struct Lvasgn
{
    // Name of the local variable
    char *name;
    // Value that is assigned to a local variable
    Node *value;
    // Location of the local variable name
    //
    // ```text
    // foo = 42
    // ~~~
    // ```
    Loc *name_l;
    // Location of the `=` operator
    //
    // ```text
    // foo = 42
    //     ~
    // ```
    //
    // `None` if local variable assignment is a part of the multi-assignment.
    // In such case `value` is a part of the `Masgn` node.
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo = 42
    // ~~~~~~~~
    // ```
    Loc *expression_l;
} Lvasgn;

void lvasgn_node_free(Lvasgn *node);


// Represents mass-assignment (i.e. `foo, bar = 1, 2`)
typedef struct Masgn
{
    // Left hand statement of the assignment
    Node *lhs;
    // Left hand statement of the assignment
    Node *rhs;
    // Location of the `=` operator
    //
    // ```text
    // foo, bar = 1, 2
    //          ~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo, bar = 1, 2
    // ~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Masgn;

void masgn_node_free(Masgn *node);


// Represents pattern matching using one of the given patterns (i.e. `foo in 1 | 2`)
typedef struct MatchAlt
{
    // Left pattern
    Node *lhs;
    // Right pattern
    Node *rhs;
    // Location of the `|` operator
    //
    // ```text
    // foo in 1 | 2
    //          ~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo in 1 | 2
    //        ~~~~~
    // ```
    Loc *expression_l;
} MatchAlt;

void match_alt_node_free(MatchAlt *node);


// Represents matching with renaming into specified local variable (i.e. `case 1; in Integer => a; end`)
typedef struct MatchAs
{
    // Pattern that is used for matching
    Node *value;
    // Variable that is assigned if matched (see `MatchVar` node)
    Node *as_;
    // Location of the `=>` operator
    //
    // ```text
    // case 1; in Integer => a; end
    //                    ~~
    // ```
    Loc *operator_l;
    // Location of the `=>` operator
    //
    // ```text
    // case 1; in Integer => a; end
    //            ~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} MatchAs;

void match_as_node_free(MatchAs *node);


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
typedef struct MatchCurrentLine
{
    // Given regex
    Node *re;
    // Location of the regex
    //
    // ```text
    // if /re/; end
    //    ~~~~
    // ```
    //
    // Technically this location is redundant, but keeping it is the only way to
    // have the same interface for all nodes.
    Loc *expression_l;
} MatchCurrentLine;

void match_current_line_node_free(MatchCurrentLine *node);


// Represents empty hash pattern that is used in pattern matching (i.e. `in **nil`)
typedef struct MatchNilPattern
{
    // Location of the `**` operator
    //
    // ```text
    // in **nil
    //    ~~
    // ```
    Loc *operator_l;
    // Location of the name
    //
    // ```text
    // in **nil
    //      ~~~
    // ```
    Loc *name_l;
    // Location of the full expression
    //
    // ```text
    // in **nil
    //    ~~~~~
    // ```
    Loc *expression_l;
} MatchNilPattern;

void match_nil_pattern_node_free(MatchNilPattern *node);


// Represents a wildcard pattern used in pattern matching (i.e. `in *foo`)
typedef struct MatchRest
{
    // Name of the variable name
    //
    // `None` if there's no name (i.e. `in *`)
    Node *name;
    // Location of the `*` operator
    //
    // ```text
    // case foo; in *bar; end
    //              ~
    // ```
    Loc *operator_l;
    // Location of the `*` operator
    //
    // ```text
    // case foo; in *bar; end
    //              ~~~~
    // ```
    Loc *expression_l;
} MatchRest;

void match_rest_node_free(MatchRest *node);


// Represents matching with assignment into a local variable (i.e. `pattern => var`)
typedef struct MatchVar
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
    Loc *name_l;
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
    Loc *expression_l;
} MatchVar;

void match_var_node_free(MatchVar *node);


// Represents matching a regex that produces local variables (i.e. `/(?<match>bar)/ =~ 'bar'`)
//
// Each named group in regex declares a local variable.
typedef struct MatchWithLvasgn
{
    // Regex that is used for matching
    Node *re;
    // Value that is used for matching
    Node *value;
    // Location of the `=~` operatir
    //
    // ```text
    // /(?<match>bar)/ =~ 'bar'
    //                 ~~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // /(?<match>bar)/ =~ 'bar'
    // ~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} MatchWithLvasgn;

void match_with_lvasgn_node_free(MatchWithLvasgn *node);


// Represents left hand statement of the mass-assignment (i.e. `foo, bar` in `foo, bar = 1, 2`)
typedef struct Mlhs
{
    // A list of items that are assigned
    NodeList *items;
    // Location of the open parenthesis
    //
    // ```text
    // (a, b) = 1, 2
    // ~
    // ```
    //
    // `None` if there are no parentheses
    Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // (a, b) = 1, 2
    //      ~
    // ```
    //
    // `None` if there are no parentheses
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // (a, b) = 1, 2
    // ~~~~~~
    // ```
    Loc *expression_l;
} Mlhs;

void mlhs_node_free(Mlhs *node);


// Represents module declaration using `module` keyword
typedef struct Module
{
    // Name of the module
    Node *name;
    // Body of the module
    //
    // `None` if module has no body
    Node *body;
    // Location of the `module` keyword
    //
    // ```text
    // module M; end
    // ~~~~~~
    // ```
    Loc *keyword_l;
    // Location of the `end` keyword
    //
    // ```text
    // module M; end
    //           ~~~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // module M; end
    // ~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Module;

void module_node_free(Module *node);


// Represents `next` keyword
typedef struct Next
{
    // Arguments given to `next`
    NodeList *args;
    // Location of the `next` keyword
    //
    // ```text
    // next 42
    // ```
    Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // next(42)
    // ~~~~~~~~
    // ```
    Loc *expression_l;
} Next;

void next_node_free(Next *node);


// Represents `nil` literal
typedef struct Nil
{
    // Location of the `nil` keyword
    //
    // ```text
    // nil
    // ~~~
    // ```
    Loc *expression_l;
} Nil;

void nil_node_free(Nil *node);


// Represents numeric global variable (e.g. `$1`)
typedef struct NthRef
{
    // Name of the variable, `String("1")` for `$1`
    char *name;
    // Location of the full expression
    //
    // ```text
    // $1
    // ~~
    // ```
    Loc *expression_l;
} NthRef;

void nth_ref_node_free(NthRef *node);


// Represents a block that takes numbered parameters (i.e. `proc { _1 }`)
typedef struct Numblock
{
    // Method call that takes a block
    Node *call;
    // Number of parameters that block takes
    uint32_t numargs;
    // Block body
    Node *body;
    // Location of the open brace
    //
    // ```text
    // proc { _1 }
    //      ~
    // ```
    Loc *begin_l;
    // Location of the closing brace
    //
    // ```text
    // proc { _1 }
    //           ~
    // ```
    Loc *end_l;
    // Location of the open brace
    //
    // ```text
    // proc { _1 }
    // ~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Numblock;

void numblock_node_free(Numblock *node);


// Represents an operation with assignment (e.g. `a += 1`)
typedef struct OpAsgn
{
    // Left hand statement of the assignment
    Node *recv;
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
    Node *value;
    // Location of the operator
    //
    // ```text
    // a.b <<= c
    //     ~~~
    // ```
    Loc *operator_l;
    // Location of the operator
    //
    // ```text
    // a.b <<= c
    // ~~~~~~~~~
    // ```
    Loc *expression_l;
} OpAsgn;

void op_asgn_node_free(OpAsgn *node);


// Represents optional positional argument (i.e. `foo` in `m(foo = 1)`)
typedef struct Optarg
{
    // Name of the argument
    char *name;
    // Default value of the argument
    Node *default_;
    // Location of the argument name
    //
    // ```text
    // def m(foo = 1); end
    //       ~~~
    // ```
    Loc *name_l;
    // Location of the `=` operator
    //
    // ```text
    // def m(foo = 1); end
    //           ~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // def m(foo = 1); end
    //       ~~~~~~~
    // ```
    Loc *expression_l;
} Optarg;

void optarg_node_free(Optarg *node);


// Represents `foo || bar` (or `foo or bar`) statement.
typedef struct Or
{
    // Left hand statement
    Node *lhs;
    // Right hand statement
    Node *rhs;
    // Location of the `||`/`or` operator
    //
    // ```text
    // foo || bar
    //     ~~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo || bar
    // ~~~~~~~~~~
    // ```
    Loc *expression_l;
} Or;

void or_node_free(Or *node);


// Represents `lhs ||= rhs` assignment
typedef struct OrAsgn
{
    // Left hand statement
    Node *recv;
    // Right hand statement
    Node *value;
    // Location of the `||=` operator
    //
    // ```text
    // foo ||= bar
    //     ~~~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo ||= bar
    // ~~~~~~~~~~~
    // ```
    Loc *expression_l;
} OrAsgn;

void or_asgn_node_free(OrAsgn *node);


// Represents a key/value pair (e.g. a part of the `Hash` node)
typedef struct Pair
{
    // Key of the pair
    Node *key;
    // Value of the pair
    Node *value;
    // Location of the `:` or `=>` operator
    //
    // ```text
    // { foo: bar }
    //      ~
    //
    // { :foo => bar }
    //        ~~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // { foo: bar }
    //   ~~~~~~~~
    //
    // { :foo => bar }
    //   ~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Pair;

void pair_node_free(Pair *node);


// Represents a pattern based on a "pinned" variable (e.g. `^foo`)
typedef struct Pin
{
    // Variable that is pinned
    Node *var;
    // Location of the `^` operator
    //
    // ```text
    // case foo; in ^bar; end
    //              ~
    // ```
    Loc *selector_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in ^bar; end
    //              ~~~~
    // ```
    Loc *expression_l;
} Pin;

void pin_node_free(Pin *node);


// Represents `END { .. }` statement
typedef struct Postexe
{
    // Body of the block
    Node *body;
    // Location of the `END` keyword
    //
    // ```text
    // END { 42 }
    // ~~~
    // ```
    Loc *keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // END { 42 }
    //     ~
    // ```
    Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // END { 42 }
    //          ~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // END { 42 }
    // ~~~~~~~~~~
    // ```
    Loc *expression_l;
} Postexe;

void postexe_node_free(Postexe *node);


// Represents `BEGIN { ... }` statement
typedef struct Preexe
{
    // Body of the block
    Node *body;
    // Location of the `BEGIN` keyword
    //
    // ```text
    // BEGIN { 42 }
    // ~~~~~
    // ```
    Loc *keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // BEGIN { 42 }
    //       ~
    // ```
    Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // BEGIN { 42 }
    //            ~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // BEGIN { 42 }
    // ~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Preexe;

void preexe_node_free(Preexe *node);


// Represents a sole block argument (e.g. `|foo|`)
//
// Block that takes a single array argument automatically expands it.
// Adding trailing comma after block argument disables this behavior (and then the only argument is emitted as `Arg`).
typedef struct Procarg0
{
    // Parts of the sole block argument.
    //
    // `proc { |(a, b)| }` also counts as a sole argument, so this list may contain:
    //     1. A single `Arg` node (for `proc { |a| }` case)
    //     2. Multiple `Arg` nodes  (for `proc { |(a, b, c)| }` case)
    NodeList *args;
    // Location of the open parenthesis
    //
    // ```text
    // proc { |(foo, bar)| }
    //         ~
    // ```
    //
    // `None` if there's only one argument
    Loc *begin_l;
    // Location of the open parenthesis
    //
    // ```text
    // proc { |(foo, bar)| }
    //                  ~
    // ```
    //
    // `None` if there's only one argument
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // proc { |(foo, bar)| }
    //         ~~~~~~~~~~
    // ```
    Loc *expression_l;
} Procarg0;

void procarg0_node_free(Procarg0 *node);


// Represents rational literal (e.g. `1r`)
typedef struct Rational
{
    // String value of the literal, `String("1r")` for `1r`
    char *value;
    // Location of the unary `-` (but not `+`)
    //
    // ```text
    // -1r
    // ~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // -1r
    // ~~~
    // ```
    Loc *expression_l;
} Rational;

void rational_node_free(Rational *node);


// Represents `redo` keyword
typedef struct Redo
{
    // Location of the full expression
    //
    // ```text
    // redo
    // ~~~~
    // ```
    Loc *expression_l;
} Redo;

void redo_node_free(Redo *node);


// Represents flags of the regex literal (i.e. `mix` for `/foo/mix`)
typedef struct RegOpt
{
    // A list of flags
    char *options;
    // Location of the full expression
    //
    // ```text
    // /foo/mix
    //      ~~~
    // ```
    Loc *expression_l;
} RegOpt;

void reg_opt_node_free(RegOpt *node);


// Represents regex literal (e.g. `/foo/`)
typedef struct Regexp
{
    // A list of static and dynamic regex parts
    NodeList *parts;
    // Regex options.
    //
    // `None` if regex has no explicit flags
    Node *options;
    // Location of the regex begin
    //
    // ```text
    // /foo/
    // ~
    //
    // %r{foo}
    // ~~
    // ```
    Loc *begin_l;
    // Location of the regex end
    //
    // ```text
    // /foo/
    //     ~
    //
    // %r{foo}
    //       ~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // /foo/mix
    // ~~~~~~~~
    // ```
    Loc *expression_l;
} Regexp;

void regexp_node_free(Regexp *node);


// Represents a `rescue` block
typedef struct Rescue
{
    // Body of the block that is wrapped into `rescue` (i.e. the part that may throw an error)
    Node *body;
    // A list of `rescue` handlers (see `RescueBody` node)
    NodeList *rescue_bodies;
    // Else branch.
    //
    // `None` if there's no `else` branch
    Node *else_;
    // Location of the `else` keyword
    //
    // ```text
    // begin; 1; rescue StandardError => e; 2; else; 3; end
    //                                         ~~~~
    // ```
    //
    // `None` if there's no `else` branch
    Loc *else_l;
    // Location of the full expression
    //
    // ```text
    // begin; 1; rescue StandardError => e; 2; else; 3; end
    //        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    //
    // **Note**: `begin/end` keywords belong to `KwBegin` node
    Loc *expression_l;
} Rescue;

void rescue_node_free(Rescue *node);


// Represents a single `rescue` handler (i.e. `rescue E => e ...`)
typedef struct RescueBody
{
    // A list of exception classes
    //
    // `None` if no classes specified (i.e. `rescue => e; ...` or just `rescue; ...`)
    Node *exc_list;
    // Variable that captures exception
    //
    // `None` if no variable specified (i.e. `rescue E; ...` or just `rescue; ... `)
    Node *exc_var;
    // Body of the handler
    Node *body;
    // Location of the `rescue` keyword
    //
    // ```text
    // begin; 1; rescue E => e; 2; end
    //           ~~~~~~
    // ```
    Loc *keyword_l;
    // Location of the `=>` operator
    //
    // ```text
    // begin; 1; rescue E => e; 2; end
    //                    ~~
    // ```
    //
    // `None` if exception is not captured.
    Loc *assoc_l;
    // Location of the `then` keyword
    //
    // ```text
    // begin; 1; rescue E => e then; 2; end
    //                         ~~~~
    // ```
    //
    // `then` is optional, so `begin_l` can be `None`
    Loc *begin_l;
    // Location of the full expression
    //
    // ```text
    // begin; 1; rescue E => e then; 2; end
    //           ~~~~~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} RescueBody;

void rescue_body_node_free(RescueBody *node);


// Represents positional rest argument (i.e. `*foo` in `def m(*foo); end`)
typedef struct Restarg
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
    Loc *operator_l;
    // Location of the argument name
    //
    // ```text
    // def m(*foo); end
    //        ~~~
    // ```
    Loc *name_l;
    // Location of the full expression
    //
    // ```text
    // def m(*foo); end
    //       ~~~~
    // ```
    Loc *expression_l;
} Restarg;

void restarg_node_free(Restarg *node);


// Represents `retry` keyword
typedef struct Retry
{
    // Location of the `retry` keyword
    //
    // ```text
    // retry
    // ~~~~~
    // ```
    Loc *expression_l;
} Retry;

void retry_node_free(Retry *node);


// Represents `return` keyword
typedef struct Return
{
    // A list of values that is returned
    NodeList *args;
    // Location of the `return` keyword
    //
    // ```text
    // return 1, 2
    // ~~~~~~
    // ```
    Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // return 1, 2
    // ~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Return;

void return__node_free(Return *node);


// Represents opening a singleton class (i.e. `class << foo; ... end;`)
typedef struct SClass
{
    // Expression that is used to get a singleton class
    //
    // `Lvar("foo")` for `class << foo; end`
    Node *expr;
    // Body of the block
    Node *body;
    // Location of the `class` keyword
    //
    // ```text
    // class << foo; end
    // ~~~~~
    // ```
    Loc *keyword_l;
    // Location of the `<<` operator
    //
    // ```text
    // class << foo; end
    //       ~~
    // ```
    Loc *operator_l;
    // Location of the `end` keyword
    //
    // ```text
    // class << foo; end
    //               ~~~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // class << foo; end
    // ~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} SClass;

void sclass_node_free(SClass *node);


// Represents `self` keyword
typedef struct Self_
{
    // Location of the `self` keyword
    //
    // ```text
    // self
    // ~~~~
    // ```
    Loc *expression_l;
} Self_;

void self__node_free(Self_ *node);


// Represents a method call (e.g. `foo.bar(42)`)
typedef struct Send
{
    // Receiver of the method call
    //
    // `None` for implicit method call (e.g. `foo(42)`)
    Node *recv;
    // Name of the method that is called
    char *method_name;
    // A list of arguments
    NodeList *args;
    // Location of the `.` operator
    //
    // ```text
    // foo.bar(42)
    //    ~
    // ```
    //
    // `None` for implicit method call (e.g. `foo(42)`)
    Loc *dot_l;
    // Location of the method name
    //
    // ```text
    // foo.bar(42)
    //     ~~~
    // ```
    //
    // `None` in a very special case when method call is implicit (i.e. `foo.(42)`)
    Loc *selector_l;
    // Location of open parenthesis
    //
    // ```text
    // foo(42)
    //    ~
    // ```
    //
    // `None` if there are parentheses
    Loc *begin_l;
    // Location of closing parenthesis
    //
    // ```text
    // foo(42)
    //       ~
    // ```
    //
    // `None` if there are parentheses
    Loc *end_l;
    // Location of the operator if method is a setter
    //
    // ```text
    // foo.bar = 42
    //         ~
    // ```
    //
    // `None` otherwise
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo.bar(42)
    // ~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Send;

void send_node_free(Send *node);


// Represents a special block argument that "shadows" outer variable (i.e. `|;foo|`)
typedef struct Shadowarg
{
    // Name of the argument
    char *name;
    // Location of the argument
    //
    // ```text
    // proc { |;foo|}
    //          ~~~
    // ```
    Loc *expression_l;
} Shadowarg;

void shadowarg_node_free(Shadowarg *node);


// Represents an arguments splat (i.e. `*bar` in a call like `foo(*bar)`)
typedef struct Splat
{
    // Value that is converted to array
    Node *value;
    // Location of the `*` operator
    //
    // ```text
    // foo(*bar)
    //     ~
    // ```
    Loc *operator_l;
    // Location of the full expression
    //
    // ```text
    // foo(*bar)
    //     ~~~~
    // ```
    Loc *expression_l;
} Splat;

void splat_node_free(Splat *node);


// Represents a plain non-interpolated string literal (e.g. `"foo"`)
typedef struct Str
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
    Loc *begin_l;
    // Location of the string begin
    //
    // ```text
    // "foo"
    //     ~
    // ```
    //
    // `None` if string literal is a part of the words array (like `%w[foo bar baz]`)
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // "foo"
    // ~~~~~
    // ```
    Loc *expression_l;
} Str;

void str__node_free(Str *node);


// Represents a `super` keyword
typedef struct Super
{
    // A list of arguments given to `super`
    NodeList *args;
    // Location of the `super` keyword
    //
    // ```text
    // super(1, 2)
    // ~~~~~
    // ```
    Loc *keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // super(1, 2)
    //      ~
    // ```
    //
    // `None` if there are no parentheses
    Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // super(1, 2)
    //           ~
    // ```
    //
    // `None` if there are no parentheses
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // super(1, 2)
    // ~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Super;

void super__node_free(Super *node);


// Represents a plain symbol literal (i.e. `:foo`)
//
// Note that `:` in `{ foo: bar }` belongs to a `pair` node.
typedef struct Sym
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
    Loc *begin_l;
    // Location of the symbol end
    //
    // ```text
    // { 'foo': 1 }
    //        ~
    // ```
    //
    // `None` if symbol is **not** a string label (`:foo`) or a part of the symbols array (`%i[foo bar baz]`)
    Loc *end_l;
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
    Loc *expression_l;
} Sym;

void sym_node_free(Sym *node);


// Represents a `true` literal
typedef struct True
{
    // Location of the `true` keyword
    //
    // ```text
    // true
    // ~~~~
    // ```
    Loc *expression_l;
} True;

void true__node_free(True *node);


// Represents an `undef` keyword (e.g. `undef foo, :bar`)
typedef struct Undef
{
    // A list of names to `undef`
    NodeList *names;
    // Location the `undef` keyword
    //
    // ```text
    // undef foo, :bar
    // ~~~~~
    // ```
    Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // undef :foo, bar
    // ~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Undef;

void undef_node_free(Undef *node);


// Represents an `unless` guard used in pattern matching (i.e. `in pattern unless guard`)
typedef struct UnlessGuard
{
    // Condition of the guard, `Lvar("foo")` in `in pattern unless guard`
    Node *cond;
    // Location of the `unless` keyword
    //
    // ```text
    // case foo; in pattern unless cond; end
    //                      ~~~~~~
    // ```
    Loc *keyword_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in pattern unless cond; end
    //                      ~~~~~~~~~~~
    // ```
    Loc *expression_l;
} UnlessGuard;

void unless_guard_node_free(UnlessGuard *node);


// Represents `until` loop
typedef struct Until
{
    // Condition of the loop
    Node *cond;
    // Body of the loop.
    //
    // `None` if body is empty
    Node *body;
    // Location of the `until` keyword
    //
    // ```text
    // until cond do; foo; end
    // ~~~~~
    // ```
    Loc *keyword_l;
    // Location of the `do` keyword
    //
    // ```text
    // until cond do; foo; end
    //            ~~
    // ```
    //
    // `do` is optional, and so `begin_l` can be `None`
    Loc *begin_l;
    // Location of the `end` keyword
    //
    // ```text
    // until cond do; foo; end
    //                     ~~~
    // ```
    //
    // `None` if loop is a modifier (i.e. `foo until bar`)
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // until cond do; foo; end
    // ~~~~~~~~~~~~~~~~~~~~~~~
    //
    // foo until bar
    // ~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Until;

void until_node_free(Until *node);


// Represents a post-until loop
//
// ```text
// begin
//   foo
// end until bar
// ```
typedef struct UntilPost
{
    // Condition of the loop
    Node *cond;
    // Body of the loop
    Node *body;
    // Location of the `until` keyword
    //
    // ```text
    // begin; foo; end until bar
    //                 ~~~~~
    // ```
    Loc *keyword_l;
    // Location of the `until` keyword
    //
    // ```text
    // begin; foo; end until bar
    // ~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} UntilPost;

void until_post_node_free(UntilPost *node);


// Represents a branch of the `case` statement (i.e. `when foo`)
typedef struct When
{
    // A list of values to compare/match against
    NodeList *patterns;
    // Body of the `when` branch
    Node *body;
    // Location of the `when` keyword
    //
    // ```text
    // case foo; when bar; end
    //           ~~~~
    // ```
    Loc *keyword_l;
    // Location of the `then` keyword
    //
    // ```text
    // case foo; when bar then baz; end
    //                    ~~~~
    // ```
    //
    // `then` is optional, and so `begin_l` can be `None`
    Loc *begin_l;
    // Location of the full expression
    //
    // ```text
    // case foo; when bar then baz; end
    //           ~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} When;

void when_node_free(When *node);


// Represents `while` loop
typedef struct While
{
    // Condition of the loop
    Node *cond;
    // Body of the loop.
    //
    // `None` if body is empty
    Node *body;
    // Location of the `while` keyword
    //
    // ```text
    // while cond do; foo; end
    // ~~~~~
    // ```
    Loc *keyword_l;
    // Location of the `do` keyword
    //
    // ```text
    // while cond do; foo; end
    //            ~~
    // ```
    //
    // `do` is optional, and so `begin_l` can be `None`
    Loc *begin_l;
    // Location of the `end` keyword
    //
    // ```text
    // while cond do; foo; end
    //                     ~~~
    // ```
    //
    // `None` if loop is a modifier (i.e. `foo while bar`)
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // while cond do; foo; end
    // ~~~~~~~~~~~~~~~~~~~~~~~
    //
    // foo while bar
    // ~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} While;

void while__node_free(While *node);


// Represents a post-while loop
//
// ```text
// begin
//   foo
// end while bar
// ```
typedef struct WhilePost
{
    // Condition of the loop
    Node *cond;
    // Body of the loop
    Node *body;
    // Location of the `while` keyword
    //
    // ```text
    // begin; foo; end while bar
    //                 ~~~~~
    // ```
    Loc *keyword_l;
    // Location of the `while` keyword
    //
    // ```text
    // begin; foo; end while bar
    // ~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    Loc *expression_l;
} WhilePost;

void while_post_node_free(WhilePost *node);


// Represents a executable here-document literal (both with and without interpolation)
//
// It's similar to `Xstr` in terms of abstract syntax tree, but has different source maps.
typedef struct XHeredoc
{
    // A list of string parts (static literals and interpolated expressions)
    NodeList *parts;
    // Location of the executable here-document body
    //
    // ```text
    // <<-`HERE`\n  a\n   #{42}\nHERE
    //          ~~~~~~~~~~~~~~~
    // ```
    Loc *heredoc_body_l;
    // Location of the executable here-document end
    //
    // ```text
    // <<-`HERE`\n  a\n   #{42}\nHERE
    //                         ~~~~
    // ```
    Loc *heredoc_end_l;
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
    Loc *expression_l;
} XHeredoc;

void x_heredoc_node_free(XHeredoc *node);


// Represents an executable string (i.e. `` `sh #{script_name}` ``)
typedef struct Xstr
{
    // A list of string parts (static literals and interpolated expressions)
    NodeList *parts;
    // Location of the string begin
    //
    // ```text
    // `#{foo}`
    // ~
    //
    // %X{#{foo}}
    // ~~~
    // ```
    Loc *begin_l;
    // Location of the string end
    //
    // ```text
    // `#{foo}`
    //        ~
    //
    // %X{#{foo}}
    //          ~
    // ```
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // `#{foo}`
    // ~~~~~~~~
    //
    // %X{#{foo}}
    // ~~~~~~~~~~
    // ```
    Loc *expression_l;
} Xstr;

void xstr_node_free(Xstr *node);


// Represents an `yield` keyword
typedef struct Yield
{
    // A list of arguments given to `yield`
    NodeList *args;
    // Location of the `yield` keyword
    //
    // ```text
    // yield 1, 2
    // ~~~~~
    // ```
    Loc *keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // yield(1, 2)
    //      ~
    // ```
    //
    // `None` if there are no parentheses
    Loc *begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // yield(1, 2)
    //           ~
    // ```
    //
    // `None` if there are no parentheses
    Loc *end_l;
    // Location of the full expression
    //
    // ```text
    // yield(1, 2)
    // ~~~~~~~~~~~
    // ```
    Loc *expression_l;
} Yield;

void yield__node_free(Yield *node);


// Represents a `super` call without arguments and parentheses
//
// It's different from `super()` as it implicitly forwards current arguments
typedef struct ZSuper
{
    // Location of the `super` keyword
    //
    // ```text
    // super
    // ~~~~~
    // ```
    Loc *expression_l;
} ZSuper;

void zsuper_node_free(ZSuper *node);

typedef enum NodeType
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
} NodeType;

typedef union InnerNode
{
    Alias *_alias;
    AndAsgn *_and_asgn;
    And *_and;
    Arg *_arg;
    Args *_args;
    Array *_array;
    ArrayPattern *_array_pattern;
    ArrayPatternWithTail *_array_pattern_with_tail;
    BackRef *_back_ref;
    Begin *_begin;
    Block *_block;
    BlockPass *_block_pass;
    Blockarg *_blockarg;
    Break *_break_;
    Case *_case;
    CaseMatch *_case_match;
    Casgn *_casgn;
    Cbase *_cbase;
    Class *_class;
    Complex *_complex;
    Const *_const_;
    ConstPattern *_const_pattern;
    CSend *_csend;
    Cvar *_cvar;
    Cvasgn *_cvasgn;
    Def *_def;
    Defined *_defined;
    Defs *_defs;
    Dstr *_dstr;
    Dsym *_dsym;
    EFlipFlop *_eflipflop;
    EmptyElse *_empty_else;
    Encoding *_encoding_;
    Ensure *_ensure;
    Erange *_erange;
    False *_false_;
    File *_file;
    FindPattern *_find_pattern;
    Float *_float;
    For *_for_;
    ForwardArg *_forward_arg;
    ForwardedArgs *_forwarded_args;
    Gvar *_gvar;
    Gvasgn *_gvasgn;
    Hash *_hash;
    Kwargs *_kwargs;
    HashPattern *_hash_pattern;
    Heredoc *_heredoc;
    If *_if_;
    IfGuard *_if_guard;
    IfMod *_if_mod;
    IfTernary *_if_ternary;
    IFlipFlop *_iflipflop;
    MatchPattern *_match_pattern;
    MatchPatternP *_match_pattern_p;
    InPattern *_in_pattern;
    Index *_index;
    IndexAsgn *_index_asgn;
    Int *_int;
    Irange *_irange;
    Ivar *_ivar;
    Ivasgn *_ivasgn;
    Kwarg *_kwarg;
    KwBegin *_kwbegin;
    Kwnilarg *_kwnilarg;
    Kwoptarg *_kwoptarg;
    Kwrestarg *_kwrestarg;
    Kwsplat *_kwsplat;
    Lambda *_lambda;
    Line *_line;
    Lvar *_lvar;
    Lvasgn *_lvasgn;
    Masgn *_masgn;
    MatchAlt *_match_alt;
    MatchAs *_match_as;
    MatchCurrentLine *_match_current_line;
    MatchNilPattern *_match_nil_pattern;
    MatchRest *_match_rest;
    MatchVar *_match_var;
    MatchWithLvasgn *_match_with_lvasgn;
    Mlhs *_mlhs;
    Module *_module;
    Next *_next;
    Nil *_nil;
    NthRef *_nth_ref;
    Numblock *_numblock;
    OpAsgn *_op_asgn;
    Optarg *_optarg;
    Or *_or;
    OrAsgn *_or_asgn;
    Pair *_pair;
    Pin *_pin;
    Postexe *_postexe;
    Preexe *_preexe;
    Procarg0 *_procarg0;
    Rational *_rational;
    Redo *_redo;
    RegOpt *_reg_opt;
    Regexp *_regexp;
    Rescue *_rescue;
    RescueBody *_rescue_body;
    Restarg *_restarg;
    Retry *_retry;
    Return *_return_;
    SClass *_sclass;
    Self_ *_self_;
    Send *_send;
    Shadowarg *_shadowarg;
    Splat *_splat;
    Str *_str_;
    Super *_super_;
    Sym *_sym;
    True *_true_;
    Undef *_undef;
    UnlessGuard *_unless_guard;
    Until *_until;
    UntilPost *_until_post;
    When *_when;
    While *_while_;
    WhilePost *_while_post;
    XHeredoc *_x_heredoc;
    Xstr *_xstr;
    Yield *_yield_;
    ZSuper *_zsuper;
} InnerNode;

typedef struct Node
{
    NodeType node_type;
    InnerNode *inner;
} Node;

void inner_node_free(InnerNode *inner_node, NodeType node_type);
void node_free(Node *node);

#endif // LIB_RUBY_PARSER_GEN_H
