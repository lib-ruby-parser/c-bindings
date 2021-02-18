#include <stdlib.h>
#include "node.h"

void maybe_node_free(struct Node *node)
{
    if (node != NULL) {
        node_free(node);
    }
}

void maybe_node_list_free(struct NodeList *list)
{
    if (list != NULL) {
        node_list_free(list);
    }
}

void maybe_loc_free(struct Loc *loc)
{
    if (loc != NULL) {
        loc_free(loc);
    }
}


void alias_node_free(struct Alias *node)
{
    maybe_node_free(node->to);
    maybe_node_free(node->from);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void and_asgn_node_free(struct AndAsgn *node)
{
    maybe_node_free(node->recv);
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void and_node_free(struct And *node)
{
    maybe_node_free(node->lhs);
    maybe_node_free(node->rhs);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void arg_node_free(struct Arg *node)
{
    free(node->name);
    maybe_loc_free(node->expression_l);
    free(node);
}

void args_node_free(struct Args *node)
{
    maybe_node_list_free(node->args);
    maybe_loc_free(node->expression_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    free(node);
}

void array_node_free(struct Array *node)
{
    maybe_node_list_free(node->elements);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void array_pattern_node_free(struct ArrayPattern *node)
{
    maybe_node_list_free(node->elements);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void array_pattern_with_tail_node_free(struct ArrayPatternWithTail *node)
{
    maybe_node_list_free(node->elements);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void back_ref_node_free(struct BackRef *node)
{
    free(node->name);
    maybe_loc_free(node->expression_l);
    free(node);
}

void begin_node_free(struct Begin *node)
{
    maybe_node_list_free(node->statements);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void block_node_free(struct Block *node)
{
    maybe_node_free(node->call);
    maybe_node_free(node->args);
    maybe_node_free(node->body);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void block_pass_node_free(struct BlockPass *node)
{
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void blockarg_node_free(struct Blockarg *node)
{
    free(node->name);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void break__node_free(struct Break *node)
{
    maybe_node_list_free(node->args);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void case_node_free(struct Case *node)
{
    maybe_node_free(node->expr);
    maybe_node_list_free(node->when_bodies);
    maybe_node_free(node->else_body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->else_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void case_match_node_free(struct CaseMatch *node)
{
    maybe_node_free(node->expr);
    maybe_node_list_free(node->in_bodies);
    maybe_node_free(node->else_body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->else_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void casgn_node_free(struct Casgn *node)
{
    maybe_node_free(node->scope);
    free(node->name);
    maybe_node_free(node->value);
    maybe_loc_free(node->double_colon_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void cbase_node_free(struct Cbase *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void class_node_free(struct Class *node)
{
    maybe_node_free(node->name);
    maybe_node_free(node->superclass);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void complex_node_free(struct Complex *node)
{
    free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void const__node_free(struct Const *node)
{
    maybe_node_free(node->scope);
    free(node->name);
    maybe_loc_free(node->double_colon_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void const_pattern_node_free(struct ConstPattern *node)
{
    maybe_node_free(node->const_);
    maybe_node_free(node->pattern);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void csend_node_free(struct CSend *node)
{
    maybe_node_free(node->recv);
    free(node->method_name);
    maybe_node_list_free(node->args);
    maybe_loc_free(node->dot_l);
    maybe_loc_free(node->selector_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void cvar_node_free(struct Cvar *node)
{
    free(node->name);
    maybe_loc_free(node->expression_l);
    free(node);
}

void cvasgn_node_free(struct Cvasgn *node)
{
    free(node->name);
    maybe_node_free(node->value);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void def_node_free(struct Def *node)
{
    free(node->name);
    maybe_node_free(node->args);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->assignment_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void defined_node_free(struct Defined *node)
{
    maybe_node_free(node->value);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void defs_node_free(struct Defs *node)
{
    maybe_node_free(node->definee);
    free(node->name);
    maybe_node_free(node->args);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->assignment_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void dstr_node_free(struct Dstr *node)
{
    maybe_node_list_free(node->parts);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void dsym_node_free(struct Dsym *node)
{
    maybe_node_list_free(node->parts);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void eflipflop_node_free(struct EFlipFlop *node)
{
    maybe_node_free(node->left);
    maybe_node_free(node->right);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void empty_else_node_free(struct EmptyElse *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void encoding__node_free(struct Encoding *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void ensure_node_free(struct Ensure *node)
{
    maybe_node_free(node->body);
    maybe_node_free(node->ensure);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void erange_node_free(struct Erange *node)
{
    maybe_node_free(node->left);
    maybe_node_free(node->right);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void false__node_free(struct False *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void file_node_free(struct File *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void find_pattern_node_free(struct FindPattern *node)
{
    maybe_node_list_free(node->elements);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void float_node_free(struct Float *node)
{
    free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void for__node_free(struct For *node)
{
    maybe_node_free(node->iterator);
    maybe_node_free(node->iteratee);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void forward_arg_node_free(struct ForwardArg *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void forwarded_args_node_free(struct ForwardedArgs *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void gvar_node_free(struct Gvar *node)
{
    free(node->name);
    maybe_loc_free(node->expression_l);
    free(node);
}

void gvasgn_node_free(struct Gvasgn *node)
{
    free(node->name);
    maybe_node_free(node->value);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void hash_node_free(struct Hash *node)
{
    maybe_node_list_free(node->pairs);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void kwargs_node_free(struct Kwargs *node)
{
    maybe_node_list_free(node->pairs);
    maybe_loc_free(node->expression_l);
    free(node);
}

void hash_pattern_node_free(struct HashPattern *node)
{
    maybe_node_list_free(node->elements);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void heredoc_node_free(struct Heredoc *node)
{
    maybe_node_list_free(node->parts);
    maybe_loc_free(node->heredoc_body_l);
    maybe_loc_free(node->heredoc_end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void if__node_free(struct If *node)
{
    maybe_node_free(node->cond);
    maybe_node_free(node->if_true);
    maybe_node_free(node->if_false);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->else_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void if_guard_node_free(struct IfGuard *node)
{
    maybe_node_free(node->cond);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void if_mod_node_free(struct IfMod *node)
{
    maybe_node_free(node->cond);
    maybe_node_free(node->if_true);
    maybe_node_free(node->if_false);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void if_ternary_node_free(struct IfTernary *node)
{
    maybe_node_free(node->cond);
    maybe_node_free(node->if_true);
    maybe_node_free(node->if_false);
    maybe_loc_free(node->question_l);
    maybe_loc_free(node->colon_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void iflipflop_node_free(struct IFlipFlop *node)
{
    maybe_node_free(node->left);
    maybe_node_free(node->right);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void match_pattern_node_free(struct MatchPattern *node)
{
    maybe_node_free(node->value);
    maybe_node_free(node->pattern);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void match_pattern_p_node_free(struct MatchPatternP *node)
{
    maybe_node_free(node->value);
    maybe_node_free(node->pattern);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void in_pattern_node_free(struct InPattern *node)
{
    maybe_node_free(node->pattern);
    maybe_node_free(node->guard);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void index_node_free(struct Index *node)
{
    maybe_node_free(node->recv);
    maybe_node_list_free(node->indexes);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void index_asgn_node_free(struct IndexAsgn *node)
{
    maybe_node_free(node->recv);
    maybe_node_list_free(node->indexes);
    maybe_node_free(node->value);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void int_node_free(struct Int *node)
{
    free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void irange_node_free(struct Irange *node)
{
    maybe_node_free(node->left);
    maybe_node_free(node->right);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void ivar_node_free(struct Ivar *node)
{
    free(node->name);
    maybe_loc_free(node->expression_l);
    free(node);
}

void ivasgn_node_free(struct Ivasgn *node)
{
    free(node->name);
    maybe_node_free(node->value);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void kwarg_node_free(struct Kwarg *node)
{
    free(node->name);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void kwbegin_node_free(struct KwBegin *node)
{
    maybe_node_list_free(node->statements);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void kwnilarg_node_free(struct Kwnilarg *node)
{
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void kwoptarg_node_free(struct Kwoptarg *node)
{
    free(node->name);
    maybe_node_free(node->default_);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void kwrestarg_node_free(struct Kwrestarg *node)
{
    free(node->name);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void kwsplat_node_free(struct Kwsplat *node)
{
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void lambda_node_free(struct Lambda *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void line_node_free(struct Line *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void lvar_node_free(struct Lvar *node)
{
    free(node->name);
    maybe_loc_free(node->expression_l);
    free(node);
}

void lvasgn_node_free(struct Lvasgn *node)
{
    free(node->name);
    maybe_node_free(node->value);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void masgn_node_free(struct Masgn *node)
{
    maybe_node_free(node->lhs);
    maybe_node_free(node->rhs);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void match_alt_node_free(struct MatchAlt *node)
{
    maybe_node_free(node->lhs);
    maybe_node_free(node->rhs);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void match_as_node_free(struct MatchAs *node)
{
    maybe_node_free(node->value);
    maybe_node_free(node->as_);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void match_current_line_node_free(struct MatchCurrentLine *node)
{
    maybe_node_free(node->re);
    maybe_loc_free(node->expression_l);
    free(node);
}

void match_nil_pattern_node_free(struct MatchNilPattern *node)
{
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void match_rest_node_free(struct MatchRest *node)
{
    maybe_node_free(node->name);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void match_var_node_free(struct MatchVar *node)
{
    free(node->name);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void match_with_lvasgn_node_free(struct MatchWithLvasgn *node)
{
    maybe_node_free(node->re);
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void mlhs_node_free(struct Mlhs *node)
{
    maybe_node_list_free(node->items);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void module_node_free(struct Module *node)
{
    maybe_node_free(node->name);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void next_node_free(struct Next *node)
{
    maybe_node_list_free(node->args);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void nil_node_free(struct Nil *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void nth_ref_node_free(struct NthRef *node)
{
    free(node->name);
    maybe_loc_free(node->expression_l);
    free(node);
}

void numblock_node_free(struct Numblock *node)
{
    maybe_node_free(node->call);
    maybe_node_free(node->body);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void op_asgn_node_free(struct OpAsgn *node)
{
    maybe_node_free(node->recv);
    free(node->operator);
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void optarg_node_free(struct Optarg *node)
{
    free(node->name);
    maybe_node_free(node->default_);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void or_node_free(struct Or *node)
{
    maybe_node_free(node->lhs);
    maybe_node_free(node->rhs);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void or_asgn_node_free(struct OrAsgn *node)
{
    maybe_node_free(node->recv);
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void pair_node_free(struct Pair *node)
{
    maybe_node_free(node->key);
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void pin_node_free(struct Pin *node)
{
    maybe_node_free(node->var);
    maybe_loc_free(node->selector_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void postexe_node_free(struct Postexe *node)
{
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void preexe_node_free(struct Preexe *node)
{
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void procarg0_node_free(struct Procarg0 *node)
{
    maybe_node_list_free(node->args);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void rational_node_free(struct Rational *node)
{
    free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void redo_node_free(struct Redo *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void reg_opt_node_free(struct RegOpt *node)
{
    free(node->options);
    maybe_loc_free(node->expression_l);
    free(node);
}

void regexp_node_free(struct Regexp *node)
{
    maybe_node_list_free(node->parts);
    maybe_node_free(node->options);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void rescue_node_free(struct Rescue *node)
{
    maybe_node_free(node->body);
    maybe_node_list_free(node->rescue_bodies);
    maybe_node_free(node->else_);
    maybe_loc_free(node->else_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void rescue_body_node_free(struct RescueBody *node)
{
    maybe_node_free(node->exc_list);
    maybe_node_free(node->exc_var);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->assoc_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void restarg_node_free(struct Restarg *node)
{
    free(node->name);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void retry_node_free(struct Retry *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void return__node_free(struct Return *node)
{
    maybe_node_list_free(node->args);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void sclass_node_free(struct SClass *node)
{
    maybe_node_free(node->expr);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void self__node_free(struct Self_ *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void send_node_free(struct Send *node)
{
    maybe_node_free(node->recv);
    free(node->method_name);
    maybe_node_list_free(node->args);
    maybe_loc_free(node->dot_l);
    maybe_loc_free(node->selector_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void shadowarg_node_free(struct Shadowarg *node)
{
    free(node->name);
    maybe_loc_free(node->expression_l);
    free(node);
}

void splat_node_free(struct Splat *node)
{
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void str__node_free(struct Str *node)
{
    free(node->value);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void super__node_free(struct Super *node)
{
    maybe_node_list_free(node->args);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void sym_node_free(struct Sym *node)
{
    free(node->name);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void true__node_free(struct True *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void undef_node_free(struct Undef *node)
{
    maybe_node_list_free(node->names);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void unless_guard_node_free(struct UnlessGuard *node)
{
    maybe_node_free(node->cond);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void until_node_free(struct Until *node)
{
    maybe_node_free(node->cond);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void until_post_node_free(struct UntilPost *node)
{
    maybe_node_free(node->cond);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void when_node_free(struct When *node)
{
    maybe_node_list_free(node->patterns);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void while__node_free(struct While *node)
{
    maybe_node_free(node->cond);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void while_post_node_free(struct WhilePost *node)
{
    maybe_node_free(node->cond);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void x_heredoc_node_free(struct XHeredoc *node)
{
    maybe_node_list_free(node->parts);
    maybe_loc_free(node->heredoc_body_l);
    maybe_loc_free(node->heredoc_end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void xstr_node_free(struct Xstr *node)
{
    maybe_node_list_free(node->parts);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void yield__node_free(struct Yield *node)
{
    maybe_node_list_free(node->args);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    free(node);
}

void zsuper_node_free(struct ZSuper *node)
{
    maybe_loc_free(node->expression_l);
    free(node);
}

void inner_node_free(union InnerNode *inner_node, enum NodeType node_type)
{
    switch (node_type)
    {
    case NODE_ALIAS:
        alias_node_free(inner_node->_alias);
        break;
    case NODE_AND_ASGN:
        and_asgn_node_free(inner_node->_and_asgn);
        break;
    case NODE_AND:
        and_node_free(inner_node->_and);
        break;
    case NODE_ARG:
        arg_node_free(inner_node->_arg);
        break;
    case NODE_ARGS:
        args_node_free(inner_node->_args);
        break;
    case NODE_ARRAY:
        array_node_free(inner_node->_array);
        break;
    case NODE_ARRAY_PATTERN:
        array_pattern_node_free(inner_node->_array_pattern);
        break;
    case NODE_ARRAY_PATTERN_WITH_TAIL:
        array_pattern_with_tail_node_free(inner_node->_array_pattern_with_tail);
        break;
    case NODE_BACK_REF:
        back_ref_node_free(inner_node->_back_ref);
        break;
    case NODE_BEGIN:
        begin_node_free(inner_node->_begin);
        break;
    case NODE_BLOCK:
        block_node_free(inner_node->_block);
        break;
    case NODE_BLOCK_PASS:
        block_pass_node_free(inner_node->_block_pass);
        break;
    case NODE_BLOCKARG:
        blockarg_node_free(inner_node->_blockarg);
        break;
    case NODE_BREAK_:
        break__node_free(inner_node->_break_);
        break;
    case NODE_CASE:
        case_node_free(inner_node->_case);
        break;
    case NODE_CASE_MATCH:
        case_match_node_free(inner_node->_case_match);
        break;
    case NODE_CASGN:
        casgn_node_free(inner_node->_casgn);
        break;
    case NODE_CBASE:
        cbase_node_free(inner_node->_cbase);
        break;
    case NODE_CLASS:
        class_node_free(inner_node->_class);
        break;
    case NODE_COMPLEX:
        complex_node_free(inner_node->_complex);
        break;
    case NODE_CONST_:
        const__node_free(inner_node->_const_);
        break;
    case NODE_CONST_PATTERN:
        const_pattern_node_free(inner_node->_const_pattern);
        break;
    case NODE_CSEND:
        csend_node_free(inner_node->_csend);
        break;
    case NODE_CVAR:
        cvar_node_free(inner_node->_cvar);
        break;
    case NODE_CVASGN:
        cvasgn_node_free(inner_node->_cvasgn);
        break;
    case NODE_DEF:
        def_node_free(inner_node->_def);
        break;
    case NODE_DEFINED:
        defined_node_free(inner_node->_defined);
        break;
    case NODE_DEFS:
        defs_node_free(inner_node->_defs);
        break;
    case NODE_DSTR:
        dstr_node_free(inner_node->_dstr);
        break;
    case NODE_DSYM:
        dsym_node_free(inner_node->_dsym);
        break;
    case NODE_EFLIPFLOP:
        eflipflop_node_free(inner_node->_eflipflop);
        break;
    case NODE_EMPTY_ELSE:
        empty_else_node_free(inner_node->_empty_else);
        break;
    case NODE_ENCODING_:
        encoding__node_free(inner_node->_encoding_);
        break;
    case NODE_ENSURE:
        ensure_node_free(inner_node->_ensure);
        break;
    case NODE_ERANGE:
        erange_node_free(inner_node->_erange);
        break;
    case NODE_FALSE_:
        false__node_free(inner_node->_false_);
        break;
    case NODE_FILE:
        file_node_free(inner_node->_file);
        break;
    case NODE_FIND_PATTERN:
        find_pattern_node_free(inner_node->_find_pattern);
        break;
    case NODE_FLOAT:
        float_node_free(inner_node->_float);
        break;
    case NODE_FOR_:
        for__node_free(inner_node->_for_);
        break;
    case NODE_FORWARD_ARG:
        forward_arg_node_free(inner_node->_forward_arg);
        break;
    case NODE_FORWARDED_ARGS:
        forwarded_args_node_free(inner_node->_forwarded_args);
        break;
    case NODE_GVAR:
        gvar_node_free(inner_node->_gvar);
        break;
    case NODE_GVASGN:
        gvasgn_node_free(inner_node->_gvasgn);
        break;
    case NODE_HASH:
        hash_node_free(inner_node->_hash);
        break;
    case NODE_KWARGS:
        kwargs_node_free(inner_node->_kwargs);
        break;
    case NODE_HASH_PATTERN:
        hash_pattern_node_free(inner_node->_hash_pattern);
        break;
    case NODE_HEREDOC:
        heredoc_node_free(inner_node->_heredoc);
        break;
    case NODE_IF_:
        if__node_free(inner_node->_if_);
        break;
    case NODE_IF_GUARD:
        if_guard_node_free(inner_node->_if_guard);
        break;
    case NODE_IF_MOD:
        if_mod_node_free(inner_node->_if_mod);
        break;
    case NODE_IF_TERNARY:
        if_ternary_node_free(inner_node->_if_ternary);
        break;
    case NODE_IFLIPFLOP:
        iflipflop_node_free(inner_node->_iflipflop);
        break;
    case NODE_MATCH_PATTERN:
        match_pattern_node_free(inner_node->_match_pattern);
        break;
    case NODE_MATCH_PATTERN_P:
        match_pattern_p_node_free(inner_node->_match_pattern_p);
        break;
    case NODE_IN_PATTERN:
        in_pattern_node_free(inner_node->_in_pattern);
        break;
    case NODE_INDEX:
        index_node_free(inner_node->_index);
        break;
    case NODE_INDEX_ASGN:
        index_asgn_node_free(inner_node->_index_asgn);
        break;
    case NODE_INT:
        int_node_free(inner_node->_int);
        break;
    case NODE_IRANGE:
        irange_node_free(inner_node->_irange);
        break;
    case NODE_IVAR:
        ivar_node_free(inner_node->_ivar);
        break;
    case NODE_IVASGN:
        ivasgn_node_free(inner_node->_ivasgn);
        break;
    case NODE_KWARG:
        kwarg_node_free(inner_node->_kwarg);
        break;
    case NODE_KWBEGIN:
        kwbegin_node_free(inner_node->_kwbegin);
        break;
    case NODE_KWNILARG:
        kwnilarg_node_free(inner_node->_kwnilarg);
        break;
    case NODE_KWOPTARG:
        kwoptarg_node_free(inner_node->_kwoptarg);
        break;
    case NODE_KWRESTARG:
        kwrestarg_node_free(inner_node->_kwrestarg);
        break;
    case NODE_KWSPLAT:
        kwsplat_node_free(inner_node->_kwsplat);
        break;
    case NODE_LAMBDA:
        lambda_node_free(inner_node->_lambda);
        break;
    case NODE_LINE:
        line_node_free(inner_node->_line);
        break;
    case NODE_LVAR:
        lvar_node_free(inner_node->_lvar);
        break;
    case NODE_LVASGN:
        lvasgn_node_free(inner_node->_lvasgn);
        break;
    case NODE_MASGN:
        masgn_node_free(inner_node->_masgn);
        break;
    case NODE_MATCH_ALT:
        match_alt_node_free(inner_node->_match_alt);
        break;
    case NODE_MATCH_AS:
        match_as_node_free(inner_node->_match_as);
        break;
    case NODE_MATCH_CURRENT_LINE:
        match_current_line_node_free(inner_node->_match_current_line);
        break;
    case NODE_MATCH_NIL_PATTERN:
        match_nil_pattern_node_free(inner_node->_match_nil_pattern);
        break;
    case NODE_MATCH_REST:
        match_rest_node_free(inner_node->_match_rest);
        break;
    case NODE_MATCH_VAR:
        match_var_node_free(inner_node->_match_var);
        break;
    case NODE_MATCH_WITH_LVASGN:
        match_with_lvasgn_node_free(inner_node->_match_with_lvasgn);
        break;
    case NODE_MLHS:
        mlhs_node_free(inner_node->_mlhs);
        break;
    case NODE_MODULE:
        module_node_free(inner_node->_module);
        break;
    case NODE_NEXT:
        next_node_free(inner_node->_next);
        break;
    case NODE_NIL:
        nil_node_free(inner_node->_nil);
        break;
    case NODE_NTH_REF:
        nth_ref_node_free(inner_node->_nth_ref);
        break;
    case NODE_NUMBLOCK:
        numblock_node_free(inner_node->_numblock);
        break;
    case NODE_OP_ASGN:
        op_asgn_node_free(inner_node->_op_asgn);
        break;
    case NODE_OPTARG:
        optarg_node_free(inner_node->_optarg);
        break;
    case NODE_OR:
        or_node_free(inner_node->_or);
        break;
    case NODE_OR_ASGN:
        or_asgn_node_free(inner_node->_or_asgn);
        break;
    case NODE_PAIR:
        pair_node_free(inner_node->_pair);
        break;
    case NODE_PIN:
        pin_node_free(inner_node->_pin);
        break;
    case NODE_POSTEXE:
        postexe_node_free(inner_node->_postexe);
        break;
    case NODE_PREEXE:
        preexe_node_free(inner_node->_preexe);
        break;
    case NODE_PROCARG0:
        procarg0_node_free(inner_node->_procarg0);
        break;
    case NODE_RATIONAL:
        rational_node_free(inner_node->_rational);
        break;
    case NODE_REDO:
        redo_node_free(inner_node->_redo);
        break;
    case NODE_REG_OPT:
        reg_opt_node_free(inner_node->_reg_opt);
        break;
    case NODE_REGEXP:
        regexp_node_free(inner_node->_regexp);
        break;
    case NODE_RESCUE:
        rescue_node_free(inner_node->_rescue);
        break;
    case NODE_RESCUE_BODY:
        rescue_body_node_free(inner_node->_rescue_body);
        break;
    case NODE_RESTARG:
        restarg_node_free(inner_node->_restarg);
        break;
    case NODE_RETRY:
        retry_node_free(inner_node->_retry);
        break;
    case NODE_RETURN_:
        return__node_free(inner_node->_return_);
        break;
    case NODE_SCLASS:
        sclass_node_free(inner_node->_sclass);
        break;
    case NODE_SELF_:
        self__node_free(inner_node->_self_);
        break;
    case NODE_SEND:
        send_node_free(inner_node->_send);
        break;
    case NODE_SHADOWARG:
        shadowarg_node_free(inner_node->_shadowarg);
        break;
    case NODE_SPLAT:
        splat_node_free(inner_node->_splat);
        break;
    case NODE_STR_:
        str__node_free(inner_node->_str_);
        break;
    case NODE_SUPER_:
        super__node_free(inner_node->_super_);
        break;
    case NODE_SYM:
        sym_node_free(inner_node->_sym);
        break;
    case NODE_TRUE_:
        true__node_free(inner_node->_true_);
        break;
    case NODE_UNDEF:
        undef_node_free(inner_node->_undef);
        break;
    case NODE_UNLESS_GUARD:
        unless_guard_node_free(inner_node->_unless_guard);
        break;
    case NODE_UNTIL:
        until_node_free(inner_node->_until);
        break;
    case NODE_UNTIL_POST:
        until_post_node_free(inner_node->_until_post);
        break;
    case NODE_WHEN:
        when_node_free(inner_node->_when);
        break;
    case NODE_WHILE_:
        while__node_free(inner_node->_while_);
        break;
    case NODE_WHILE_POST:
        while_post_node_free(inner_node->_while_post);
        break;
    case NODE_X_HEREDOC:
        x_heredoc_node_free(inner_node->_x_heredoc);
        break;
    case NODE_XSTR:
        xstr_node_free(inner_node->_xstr);
        break;
    case NODE_YIELD_:
        yield__node_free(inner_node->_yield_);
        break;
    case NODE_ZSUPER:
        zsuper_node_free(inner_node->_zsuper);
        break;
    }
    free(inner_node);
}

void node_free(struct Node *node)
{
    inner_node_free(node->inner, node->node_type);
    free(node);
}
