#ifndef LIB_RUBY_PARSER_GEN_H
#define LIB_RUBY_PARSER_GEN_H

#include <stddef.h>
#include <stdint.h>
#include "node_list.h"
#include "range.h"

struct Node;
void node_free(struct Node *node);


struct Alias
{
    struct Node *to;
    struct Node *from;
    struct Range *keyword_l;
    struct Range *expression_l;
};

void alias_node_free(struct Alias *node);


struct AndAsgn
{
    struct Node *recv;
    struct Node *value;
    struct Range *operator_l;
    struct Range *expression_l;
};

void and_asgn_node_free(struct AndAsgn *node);


struct And
{
    struct Node *lhs;
    struct Node *rhs;
    struct Range *operator_l;
    struct Range *expression_l;
};

void and_node_free(struct And *node);


struct Arg
{
    char *name;
    struct Range *expression_l;
};

void arg_node_free(struct Arg *node);


struct Args
{
    struct NodeList *args;
    struct Range *expression_l;
    struct Range *begin_l;
    struct Range *end_l;
};

void args_node_free(struct Args *node);


struct Array
{
    struct NodeList *elements;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void array_node_free(struct Array *node);


struct ArrayPattern
{
    struct NodeList *elements;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void array_pattern_node_free(struct ArrayPattern *node);


struct ArrayPatternWithTail
{
    struct NodeList *elements;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void array_pattern_with_tail_node_free(struct ArrayPatternWithTail *node);


struct BackRef
{
    char *name;
    struct Range *expression_l;
};

void back_ref_node_free(struct BackRef *node);


struct Begin
{
    struct NodeList *statements;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void begin_node_free(struct Begin *node);


struct Block
{
    struct Node *call;
    struct Node *args;
    struct Node *body;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void block_node_free(struct Block *node);


struct BlockPass
{
    struct Node *value;
    struct Range *operator_l;
    struct Range *expression_l;
};

void block_pass_node_free(struct BlockPass *node);


struct Blockarg
{
    char *name;
    struct Range *operator_l;
    struct Range *name_l;
    struct Range *expression_l;
};

void blockarg_node_free(struct Blockarg *node);


struct Break
{
    struct NodeList *args;
    struct Range *keyword_l;
    struct Range *expression_l;
};

void break__node_free(struct Break *node);


struct Case
{
    struct Node *expr;
    struct NodeList *when_bodies;
    struct Node *else_body;
    struct Range *keyword_l;
    struct Range *else_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void case_node_free(struct Case *node);


struct CaseMatch
{
    struct Node *expr;
    struct NodeList *in_bodies;
    struct Node *else_body;
    struct Range *keyword_l;
    struct Range *else_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void case_match_node_free(struct CaseMatch *node);


struct Casgn
{
    struct Node *scope;
    char *name;
    struct Node *value;
    struct Range *double_colon_l;
    struct Range *name_l;
    struct Range *operator_l;
    struct Range *expression_l;
};

void casgn_node_free(struct Casgn *node);


struct Cbase
{
    struct Range *expression_l;
};

void cbase_node_free(struct Cbase *node);


struct Class
{
    struct Node *name;
    struct Node *superclass;
    struct Node *body;
    struct Range *keyword_l;
    struct Range *operator_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void class_node_free(struct Class *node);


struct Complex
{
    char *value;
    struct Range *operator_l;
    struct Range *expression_l;
};

void complex_node_free(struct Complex *node);


struct Const
{
    struct Node *scope;
    char *name;
    struct Range *double_colon_l;
    struct Range *name_l;
    struct Range *expression_l;
};

void const__node_free(struct Const *node);


struct ConstPattern
{
    struct Node *const_;
    struct Node *pattern;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void const_pattern_node_free(struct ConstPattern *node);


struct CSend
{
    struct Node *recv;
    char *method_name;
    struct NodeList *args;
    struct Range *dot_l;
    struct Range *selector_l;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *operator_l;
    struct Range *expression_l;
};

void csend_node_free(struct CSend *node);


struct Cvar
{
    char *name;
    struct Range *expression_l;
};

void cvar_node_free(struct Cvar *node);


struct Cvasgn
{
    char *name;
    struct Node *value;
    struct Range *name_l;
    struct Range *operator_l;
    struct Range *expression_l;
};

void cvasgn_node_free(struct Cvasgn *node);


struct Def
{
    char *name;
    struct Node *args;
    struct Node *body;
    struct Range *keyword_l;
    struct Range *name_l;
    struct Range *end_l;
    struct Range *assignment_l;
    struct Range *expression_l;
};

void def_node_free(struct Def *node);


struct Defined
{
    struct Node *value;
    struct Range *keyword_l;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void defined_node_free(struct Defined *node);


struct Defs
{
    struct Node *definee;
    char *name;
    struct Node *args;
    struct Node *body;
    struct Range *keyword_l;
    struct Range *operator_l;
    struct Range *name_l;
    struct Range *assignment_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void defs_node_free(struct Defs *node);


struct Dstr
{
    struct NodeList *parts;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void dstr_node_free(struct Dstr *node);


struct Dsym
{
    struct NodeList *parts;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void dsym_node_free(struct Dsym *node);


struct EFlipFlop
{
    struct Node *left;
    struct Node *right;
    struct Range *operator_l;
    struct Range *expression_l;
};

void eflipflop_node_free(struct EFlipFlop *node);


struct EmptyElse
{
    struct Range *expression_l;
};

void empty_else_node_free(struct EmptyElse *node);


struct Encoding
{
    struct Range *expression_l;
};

void encoding__node_free(struct Encoding *node);


struct Ensure
{
    struct Node *body;
    struct Node *ensure;
    struct Range *keyword_l;
    struct Range *expression_l;
};

void ensure_node_free(struct Ensure *node);


struct Erange
{
    struct Node *left;
    struct Node *right;
    struct Range *operator_l;
    struct Range *expression_l;
};

void erange_node_free(struct Erange *node);


struct False
{
    struct Range *expression_l;
};

void false__node_free(struct False *node);


struct File
{
    struct Range *expression_l;
};

void file_node_free(struct File *node);


struct FindPattern
{
    struct NodeList *elements;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void find_pattern_node_free(struct FindPattern *node);


struct Float
{
    char *value;
    struct Range *operator_l;
    struct Range *expression_l;
};

void float_node_free(struct Float *node);


struct For
{
    struct Node *iterator;
    struct Node *iteratee;
    struct Node *body;
    struct Range *keyword_l;
    struct Range *operator_l;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void for__node_free(struct For *node);


struct ForwardArg
{
    struct Range *expression_l;
};

void forward_arg_node_free(struct ForwardArg *node);


struct ForwardedArgs
{
    struct Range *expression_l;
};

void forwarded_args_node_free(struct ForwardedArgs *node);


struct Gvar
{
    char *name;
    struct Range *expression_l;
};

void gvar_node_free(struct Gvar *node);


struct Gvasgn
{
    char *name;
    struct Node *value;
    struct Range *name_l;
    struct Range *operator_l;
    struct Range *expression_l;
};

void gvasgn_node_free(struct Gvasgn *node);


struct Hash
{
    struct NodeList *pairs;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void hash_node_free(struct Hash *node);


struct Kwargs
{
    struct NodeList *pairs;
    struct Range *expression_l;
};

void kwargs_node_free(struct Kwargs *node);


struct HashPattern
{
    struct NodeList *elements;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void hash_pattern_node_free(struct HashPattern *node);


struct Heredoc
{
    struct NodeList *parts;
    struct Range *heredoc_body_l;
    struct Range *heredoc_end_l;
    struct Range *expression_l;
};

void heredoc_node_free(struct Heredoc *node);


struct If
{
    struct Node *cond;
    struct Node *if_true;
    struct Node *if_false;
    struct Range *keyword_l;
    struct Range *begin_l;
    struct Range *else_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void if__node_free(struct If *node);


struct IfGuard
{
    struct Node *cond;
    struct Range *keyword_l;
    struct Range *expression_l;
};

void if_guard_node_free(struct IfGuard *node);


struct IfMod
{
    struct Node *cond;
    struct Node *if_true;
    struct Node *if_false;
    struct Range *keyword_l;
    struct Range *expression_l;
};

void if_mod_node_free(struct IfMod *node);


struct IfTernary
{
    struct Node *cond;
    struct Node *if_true;
    struct Node *if_false;
    struct Range *question_l;
    struct Range *colon_l;
    struct Range *expression_l;
};

void if_ternary_node_free(struct IfTernary *node);


struct IFlipFlop
{
    struct Node *left;
    struct Node *right;
    struct Range *operator_l;
    struct Range *expression_l;
};

void iflipflop_node_free(struct IFlipFlop *node);


struct MatchPattern
{
    struct Node *value;
    struct Node *pattern;
    struct Range *operator_l;
    struct Range *expression_l;
};

void match_pattern_node_free(struct MatchPattern *node);


struct MatchPatternP
{
    struct Node *value;
    struct Node *pattern;
    struct Range *operator_l;
    struct Range *expression_l;
};

void match_pattern_p_node_free(struct MatchPatternP *node);


struct InPattern
{
    struct Node *pattern;
    struct Node *guard;
    struct Node *body;
    struct Range *keyword_l;
    struct Range *begin_l;
    struct Range *expression_l;
};

void in_pattern_node_free(struct InPattern *node);


struct Index
{
    struct Node *recv;
    struct NodeList *indexes;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void index_node_free(struct Index *node);


struct IndexAsgn
{
    struct Node *recv;
    struct NodeList *indexes;
    struct Node *value;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *operator_l;
    struct Range *expression_l;
};

void index_asgn_node_free(struct IndexAsgn *node);


struct Int
{
    char *value;
    struct Range *operator_l;
    struct Range *expression_l;
};

void int_node_free(struct Int *node);


struct Irange
{
    struct Node *left;
    struct Node *right;
    struct Range *operator_l;
    struct Range *expression_l;
};

void irange_node_free(struct Irange *node);


struct Ivar
{
    char *name;
    struct Range *expression_l;
};

void ivar_node_free(struct Ivar *node);


struct Ivasgn
{
    char *name;
    struct Node *value;
    struct Range *name_l;
    struct Range *operator_l;
    struct Range *expression_l;
};

void ivasgn_node_free(struct Ivasgn *node);


struct Kwarg
{
    char *name;
    struct Range *name_l;
    struct Range *expression_l;
};

void kwarg_node_free(struct Kwarg *node);


struct KwBegin
{
    struct NodeList *statements;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void kwbegin_node_free(struct KwBegin *node);


struct Kwnilarg
{
    struct Range *name_l;
    struct Range *expression_l;
};

void kwnilarg_node_free(struct Kwnilarg *node);


struct Kwoptarg
{
    char *name;
    struct Node *default_;
    struct Range *name_l;
    struct Range *expression_l;
};

void kwoptarg_node_free(struct Kwoptarg *node);


struct Kwrestarg
{
    char *name;
    struct Range *operator_l;
    struct Range *name_l;
    struct Range *expression_l;
};

void kwrestarg_node_free(struct Kwrestarg *node);


struct Kwsplat
{
    struct Node *value;
    struct Range *operator_l;
    struct Range *expression_l;
};

void kwsplat_node_free(struct Kwsplat *node);


struct Lambda
{
    struct Range *expression_l;
};

void lambda_node_free(struct Lambda *node);


struct Line
{
    struct Range *expression_l;
};

void line_node_free(struct Line *node);


struct Lvar
{
    char *name;
    struct Range *expression_l;
};

void lvar_node_free(struct Lvar *node);


struct Lvasgn
{
    char *name;
    struct Node *value;
    struct Range *name_l;
    struct Range *operator_l;
    struct Range *expression_l;
};

void lvasgn_node_free(struct Lvasgn *node);


struct Masgn
{
    struct Node *lhs;
    struct Node *rhs;
    struct Range *operator_l;
    struct Range *expression_l;
};

void masgn_node_free(struct Masgn *node);


struct MatchAlt
{
    struct Node *lhs;
    struct Node *rhs;
    struct Range *operator_l;
    struct Range *expression_l;
};

void match_alt_node_free(struct MatchAlt *node);


struct MatchAs
{
    struct Node *value;
    struct Node *as_;
    struct Range *operator_l;
    struct Range *expression_l;
};

void match_as_node_free(struct MatchAs *node);


struct MatchCurrentLine
{
    struct Node *re;
    struct Range *expression_l;
};

void match_current_line_node_free(struct MatchCurrentLine *node);


struct MatchNilPattern
{
    struct Range *operator_l;
    struct Range *name_l;
    struct Range *expression_l;
};

void match_nil_pattern_node_free(struct MatchNilPattern *node);


struct MatchRest
{
    struct Node *name;
    struct Range *operator_l;
    struct Range *expression_l;
};

void match_rest_node_free(struct MatchRest *node);


struct MatchVar
{
    char *name;
    struct Range *name_l;
    struct Range *expression_l;
};

void match_var_node_free(struct MatchVar *node);


struct MatchWithLvasgn
{
    struct Node *re;
    struct Node *value;
    struct Range *operator_l;
    struct Range *expression_l;
};

void match_with_lvasgn_node_free(struct MatchWithLvasgn *node);


struct Mlhs
{
    struct NodeList *items;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void mlhs_node_free(struct Mlhs *node);


struct Module
{
    struct Node *name;
    struct Node *body;
    struct Range *keyword_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void module_node_free(struct Module *node);


struct Next
{
    struct NodeList *args;
    struct Range *keyword_l;
    struct Range *expression_l;
};

void next_node_free(struct Next *node);


struct Nil
{
    struct Range *expression_l;
};

void nil_node_free(struct Nil *node);


struct NthRef
{
    char *name;
    struct Range *expression_l;
};

void nth_ref_node_free(struct NthRef *node);


struct Numblock
{
    struct Node *call;
    uint32_t numargs;
    struct Node *body;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void numblock_node_free(struct Numblock *node);


struct OpAsgn
{
    struct Node *recv;
    char *operator;
    struct Node *value;
    struct Range *operator_l;
    struct Range *expression_l;
};

void op_asgn_node_free(struct OpAsgn *node);


struct Optarg
{
    char *name;
    struct Node *default_;
    struct Range *name_l;
    struct Range *operator_l;
    struct Range *expression_l;
};

void optarg_node_free(struct Optarg *node);


struct Or
{
    struct Node *lhs;
    struct Node *rhs;
    struct Range *operator_l;
    struct Range *expression_l;
};

void or_node_free(struct Or *node);


struct OrAsgn
{
    struct Node *recv;
    struct Node *value;
    struct Range *operator_l;
    struct Range *expression_l;
};

void or_asgn_node_free(struct OrAsgn *node);


struct Pair
{
    struct Node *key;
    struct Node *value;
    struct Range *operator_l;
    struct Range *expression_l;
};

void pair_node_free(struct Pair *node);


struct Pin
{
    struct Node *var;
    struct Range *selector_l;
    struct Range *expression_l;
};

void pin_node_free(struct Pin *node);


struct Postexe
{
    struct Node *body;
    struct Range *keyword_l;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void postexe_node_free(struct Postexe *node);


struct Preexe
{
    struct Node *body;
    struct Range *keyword_l;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void preexe_node_free(struct Preexe *node);


struct Procarg0
{
    struct NodeList *args;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void procarg0_node_free(struct Procarg0 *node);


struct Rational
{
    char *value;
    struct Range *operator_l;
    struct Range *expression_l;
};

void rational_node_free(struct Rational *node);


struct Redo
{
    struct Range *expression_l;
};

void redo_node_free(struct Redo *node);


struct RegOpt
{
    char *options;
    struct Range *expression_l;
};

void reg_opt_node_free(struct RegOpt *node);


struct Regexp
{
    struct NodeList *parts;
    struct Node *options;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void regexp_node_free(struct Regexp *node);


struct Rescue
{
    struct Node *body;
    struct NodeList *rescue_bodies;
    struct Node *else_;
    struct Range *else_l;
    struct Range *expression_l;
};

void rescue_node_free(struct Rescue *node);


struct RescueBody
{
    struct Node *exc_list;
    struct Node *exc_var;
    struct Node *body;
    struct Range *keyword_l;
    struct Range *assoc_l;
    struct Range *begin_l;
    struct Range *expression_l;
};

void rescue_body_node_free(struct RescueBody *node);


struct Restarg
{
    char *name;
    struct Range *operator_l;
    struct Range *name_l;
    struct Range *expression_l;
};

void restarg_node_free(struct Restarg *node);


struct Retry
{
    struct Range *expression_l;
};

void retry_node_free(struct Retry *node);


struct Return
{
    struct NodeList *args;
    struct Range *keyword_l;
    struct Range *expression_l;
};

void return__node_free(struct Return *node);


struct SClass
{
    struct Node *expr;
    struct Node *body;
    struct Range *keyword_l;
    struct Range *operator_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void sclass_node_free(struct SClass *node);


struct Self_
{
    struct Range *expression_l;
};

void self__node_free(struct Self_ *node);


struct Send
{
    struct Node *recv;
    char *method_name;
    struct NodeList *args;
    struct Range *dot_l;
    struct Range *selector_l;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *operator_l;
    struct Range *expression_l;
};

void send_node_free(struct Send *node);


struct Shadowarg
{
    char *name;
    struct Range *expression_l;
};

void shadowarg_node_free(struct Shadowarg *node);


struct Splat
{
    struct Node *value;
    struct Range *operator_l;
    struct Range *expression_l;
};

void splat_node_free(struct Splat *node);


struct Str
{
    char *value;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void str__node_free(struct Str *node);


struct Super
{
    struct NodeList *args;
    struct Range *keyword_l;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void super__node_free(struct Super *node);


struct Sym
{
    char *name;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void sym_node_free(struct Sym *node);


struct True
{
    struct Range *expression_l;
};

void true__node_free(struct True *node);


struct Undef
{
    struct NodeList *names;
    struct Range *keyword_l;
    struct Range *expression_l;
};

void undef_node_free(struct Undef *node);


struct UnlessGuard
{
    struct Node *cond;
    struct Range *keyword_l;
    struct Range *expression_l;
};

void unless_guard_node_free(struct UnlessGuard *node);


struct Until
{
    struct Node *cond;
    struct Node *body;
    struct Range *keyword_l;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void until_node_free(struct Until *node);


struct UntilPost
{
    struct Node *cond;
    struct Node *body;
    struct Range *keyword_l;
    struct Range *expression_l;
};

void until_post_node_free(struct UntilPost *node);


struct When
{
    struct NodeList *patterns;
    struct Node *body;
    struct Range *keyword_l;
    struct Range *begin_l;
    struct Range *expression_l;
};

void when_node_free(struct When *node);


struct While
{
    struct Node *cond;
    struct Node *body;
    struct Range *keyword_l;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void while__node_free(struct While *node);


struct WhilePost
{
    struct Node *cond;
    struct Node *body;
    struct Range *keyword_l;
    struct Range *expression_l;
};

void while_post_node_free(struct WhilePost *node);


struct XHeredoc
{
    struct NodeList *parts;
    struct Range *heredoc_body_l;
    struct Range *heredoc_end_l;
    struct Range *expression_l;
};

void x_heredoc_node_free(struct XHeredoc *node);


struct Xstr
{
    struct NodeList *parts;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void xstr_node_free(struct Xstr *node);


struct Yield
{
    struct NodeList *args;
    struct Range *keyword_l;
    struct Range *begin_l;
    struct Range *end_l;
    struct Range *expression_l;
};

void yield__node_free(struct Yield *node);


struct ZSuper
{
    struct Range *expression_l;
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
