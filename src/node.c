#include <stdlib.h>
#include "node.h"
#include "rust_free.h"

void maybe_node_free(Node *node)
{
    if (node != NULL) {
        node_free(node);
    }
}

void maybe_node_list_free(NodeList *list)
{
    if (list != NULL) {
        node_list_free(list);
    }
}

void maybe_loc_free(Loc *loc)
{
    if (loc != NULL) {
        loc_free(loc);
    }
}


void alias_node_free(Alias *node)
{
    maybe_node_free(node->to);
    maybe_node_free(node->from);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    rust_alias_node_free(node);
}

void and_asgn_node_free(AndAsgn *node)
{
    maybe_node_free(node->recv);
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_and_asgn_node_free(node);
}

void and_node_free(And *node)
{
    maybe_node_free(node->lhs);
    maybe_node_free(node->rhs);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_and_node_free(node);
}

void arg_node_free(Arg *node)
{
    rust_string_free(node->name);
    maybe_loc_free(node->expression_l);
    rust_arg_node_free(node);
}

void args_node_free(Args *node)
{
    maybe_node_list_free(node->args);
    maybe_loc_free(node->expression_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    rust_args_node_free(node);
}

void array_node_free(Array *node)
{
    maybe_node_list_free(node->elements);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_array_node_free(node);
}

void array_pattern_node_free(ArrayPattern *node)
{
    maybe_node_list_free(node->elements);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_array_pattern_node_free(node);
}

void array_pattern_with_tail_node_free(ArrayPatternWithTail *node)
{
    maybe_node_list_free(node->elements);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_array_pattern_with_tail_node_free(node);
}

void back_ref_node_free(BackRef *node)
{
    rust_string_free(node->name);
    maybe_loc_free(node->expression_l);
    rust_back_ref_node_free(node);
}

void begin_node_free(Begin *node)
{
    maybe_node_list_free(node->statements);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_begin_node_free(node);
}

void block_node_free(Block *node)
{
    maybe_node_free(node->call);
    maybe_node_free(node->args);
    maybe_node_free(node->body);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_block_node_free(node);
}

void block_pass_node_free(BlockPass *node)
{
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_block_pass_node_free(node);
}

void blockarg_node_free(Blockarg *node)
{
    rust_string_free(node->name);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    rust_blockarg_node_free(node);
}

void break__node_free(Break *node)
{
    maybe_node_list_free(node->args);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    rust_break__node_free(node);
}

void case_node_free(Case *node)
{
    maybe_node_free(node->expr);
    maybe_node_list_free(node->when_bodies);
    maybe_node_free(node->else_body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->else_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_case_node_free(node);
}

void case_match_node_free(CaseMatch *node)
{
    maybe_node_free(node->expr);
    maybe_node_list_free(node->in_bodies);
    maybe_node_free(node->else_body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->else_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_case_match_node_free(node);
}

void casgn_node_free(Casgn *node)
{
    maybe_node_free(node->scope);
    rust_string_free(node->name);
    maybe_node_free(node->value);
    maybe_loc_free(node->double_colon_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_casgn_node_free(node);
}

void cbase_node_free(Cbase *node)
{
    maybe_loc_free(node->expression_l);
    rust_cbase_node_free(node);
}

void class_node_free(Class *node)
{
    maybe_node_free(node->name);
    maybe_node_free(node->superclass);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_class_node_free(node);
}

void complex_node_free(Complex *node)
{
    rust_string_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_complex_node_free(node);
}

void const__node_free(Const *node)
{
    maybe_node_free(node->scope);
    rust_string_free(node->name);
    maybe_loc_free(node->double_colon_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    rust_const__node_free(node);
}

void const_pattern_node_free(ConstPattern *node)
{
    maybe_node_free(node->const_);
    maybe_node_free(node->pattern);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_const_pattern_node_free(node);
}

void csend_node_free(CSend *node)
{
    maybe_node_free(node->recv);
    rust_string_free(node->method_name);
    maybe_node_list_free(node->args);
    maybe_loc_free(node->dot_l);
    maybe_loc_free(node->selector_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_csend_node_free(node);
}

void cvar_node_free(Cvar *node)
{
    rust_string_free(node->name);
    maybe_loc_free(node->expression_l);
    rust_cvar_node_free(node);
}

void cvasgn_node_free(Cvasgn *node)
{
    rust_string_free(node->name);
    maybe_node_free(node->value);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_cvasgn_node_free(node);
}

void def_node_free(Def *node)
{
    rust_string_free(node->name);
    maybe_node_free(node->args);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->assignment_l);
    maybe_loc_free(node->expression_l);
    rust_def_node_free(node);
}

void defined_node_free(Defined *node)
{
    maybe_node_free(node->value);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_defined_node_free(node);
}

void defs_node_free(Defs *node)
{
    maybe_node_free(node->definee);
    rust_string_free(node->name);
    maybe_node_free(node->args);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->assignment_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_defs_node_free(node);
}

void dstr_node_free(Dstr *node)
{
    maybe_node_list_free(node->parts);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_dstr_node_free(node);
}

void dsym_node_free(Dsym *node)
{
    maybe_node_list_free(node->parts);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_dsym_node_free(node);
}

void eflipflop_node_free(EFlipFlop *node)
{
    maybe_node_free(node->left);
    maybe_node_free(node->right);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_eflipflop_node_free(node);
}

void empty_else_node_free(EmptyElse *node)
{
    maybe_loc_free(node->expression_l);
    rust_empty_else_node_free(node);
}

void encoding__node_free(Encoding *node)
{
    maybe_loc_free(node->expression_l);
    rust_encoding__node_free(node);
}

void ensure_node_free(Ensure *node)
{
    maybe_node_free(node->body);
    maybe_node_free(node->ensure);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    rust_ensure_node_free(node);
}

void erange_node_free(Erange *node)
{
    maybe_node_free(node->left);
    maybe_node_free(node->right);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_erange_node_free(node);
}

void false__node_free(False *node)
{
    maybe_loc_free(node->expression_l);
    rust_false__node_free(node);
}

void file_node_free(File *node)
{
    maybe_loc_free(node->expression_l);
    rust_file_node_free(node);
}

void find_pattern_node_free(FindPattern *node)
{
    maybe_node_list_free(node->elements);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_find_pattern_node_free(node);
}

void float_node_free(Float *node)
{
    rust_string_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_float_node_free(node);
}

void for__node_free(For *node)
{
    maybe_node_free(node->iterator);
    maybe_node_free(node->iteratee);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_for__node_free(node);
}

void forward_arg_node_free(ForwardArg *node)
{
    maybe_loc_free(node->expression_l);
    rust_forward_arg_node_free(node);
}

void forwarded_args_node_free(ForwardedArgs *node)
{
    maybe_loc_free(node->expression_l);
    rust_forwarded_args_node_free(node);
}

void gvar_node_free(Gvar *node)
{
    rust_string_free(node->name);
    maybe_loc_free(node->expression_l);
    rust_gvar_node_free(node);
}

void gvasgn_node_free(Gvasgn *node)
{
    rust_string_free(node->name);
    maybe_node_free(node->value);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_gvasgn_node_free(node);
}

void hash_node_free(Hash *node)
{
    maybe_node_list_free(node->pairs);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_hash_node_free(node);
}

void kwargs_node_free(Kwargs *node)
{
    maybe_node_list_free(node->pairs);
    maybe_loc_free(node->expression_l);
    rust_kwargs_node_free(node);
}

void hash_pattern_node_free(HashPattern *node)
{
    maybe_node_list_free(node->elements);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_hash_pattern_node_free(node);
}

void heredoc_node_free(Heredoc *node)
{
    maybe_node_list_free(node->parts);
    maybe_loc_free(node->heredoc_body_l);
    maybe_loc_free(node->heredoc_end_l);
    maybe_loc_free(node->expression_l);
    rust_heredoc_node_free(node);
}

void if__node_free(If *node)
{
    maybe_node_free(node->cond);
    maybe_node_free(node->if_true);
    maybe_node_free(node->if_false);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->else_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_if__node_free(node);
}

void if_guard_node_free(IfGuard *node)
{
    maybe_node_free(node->cond);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    rust_if_guard_node_free(node);
}

void if_mod_node_free(IfMod *node)
{
    maybe_node_free(node->cond);
    maybe_node_free(node->if_true);
    maybe_node_free(node->if_false);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    rust_if_mod_node_free(node);
}

void if_ternary_node_free(IfTernary *node)
{
    maybe_node_free(node->cond);
    maybe_node_free(node->if_true);
    maybe_node_free(node->if_false);
    maybe_loc_free(node->question_l);
    maybe_loc_free(node->colon_l);
    maybe_loc_free(node->expression_l);
    rust_if_ternary_node_free(node);
}

void iflipflop_node_free(IFlipFlop *node)
{
    maybe_node_free(node->left);
    maybe_node_free(node->right);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_iflipflop_node_free(node);
}

void match_pattern_node_free(MatchPattern *node)
{
    maybe_node_free(node->value);
    maybe_node_free(node->pattern);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_match_pattern_node_free(node);
}

void match_pattern_p_node_free(MatchPatternP *node)
{
    maybe_node_free(node->value);
    maybe_node_free(node->pattern);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_match_pattern_p_node_free(node);
}

void in_pattern_node_free(InPattern *node)
{
    maybe_node_free(node->pattern);
    maybe_node_free(node->guard);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->expression_l);
    rust_in_pattern_node_free(node);
}

void index_node_free(Index *node)
{
    maybe_node_free(node->recv);
    maybe_node_list_free(node->indexes);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_index_node_free(node);
}

void index_asgn_node_free(IndexAsgn *node)
{
    maybe_node_free(node->recv);
    maybe_node_list_free(node->indexes);
    maybe_node_free(node->value);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_index_asgn_node_free(node);
}

void int_node_free(Int *node)
{
    rust_string_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_int_node_free(node);
}

void irange_node_free(Irange *node)
{
    maybe_node_free(node->left);
    maybe_node_free(node->right);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_irange_node_free(node);
}

void ivar_node_free(Ivar *node)
{
    rust_string_free(node->name);
    maybe_loc_free(node->expression_l);
    rust_ivar_node_free(node);
}

void ivasgn_node_free(Ivasgn *node)
{
    rust_string_free(node->name);
    maybe_node_free(node->value);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_ivasgn_node_free(node);
}

void kwarg_node_free(Kwarg *node)
{
    rust_string_free(node->name);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    rust_kwarg_node_free(node);
}

void kwbegin_node_free(KwBegin *node)
{
    maybe_node_list_free(node->statements);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_kwbegin_node_free(node);
}

void kwnilarg_node_free(Kwnilarg *node)
{
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    rust_kwnilarg_node_free(node);
}

void kwoptarg_node_free(Kwoptarg *node)
{
    rust_string_free(node->name);
    maybe_node_free(node->default_);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    rust_kwoptarg_node_free(node);
}

void kwrestarg_node_free(Kwrestarg *node)
{
    rust_string_free(node->name);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    rust_kwrestarg_node_free(node);
}

void kwsplat_node_free(Kwsplat *node)
{
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_kwsplat_node_free(node);
}

void lambda_node_free(Lambda *node)
{
    maybe_loc_free(node->expression_l);
    rust_lambda_node_free(node);
}

void line_node_free(Line *node)
{
    maybe_loc_free(node->expression_l);
    rust_line_node_free(node);
}

void lvar_node_free(Lvar *node)
{
    rust_string_free(node->name);
    maybe_loc_free(node->expression_l);
    rust_lvar_node_free(node);
}

void lvasgn_node_free(Lvasgn *node)
{
    rust_string_free(node->name);
    maybe_node_free(node->value);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_lvasgn_node_free(node);
}

void masgn_node_free(Masgn *node)
{
    maybe_node_free(node->lhs);
    maybe_node_free(node->rhs);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_masgn_node_free(node);
}

void match_alt_node_free(MatchAlt *node)
{
    maybe_node_free(node->lhs);
    maybe_node_free(node->rhs);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_match_alt_node_free(node);
}

void match_as_node_free(MatchAs *node)
{
    maybe_node_free(node->value);
    maybe_node_free(node->as_);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_match_as_node_free(node);
}

void match_current_line_node_free(MatchCurrentLine *node)
{
    maybe_node_free(node->re);
    maybe_loc_free(node->expression_l);
    rust_match_current_line_node_free(node);
}

void match_nil_pattern_node_free(MatchNilPattern *node)
{
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    rust_match_nil_pattern_node_free(node);
}

void match_rest_node_free(MatchRest *node)
{
    maybe_node_free(node->name);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_match_rest_node_free(node);
}

void match_var_node_free(MatchVar *node)
{
    rust_string_free(node->name);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    rust_match_var_node_free(node);
}

void match_with_lvasgn_node_free(MatchWithLvasgn *node)
{
    maybe_node_free(node->re);
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_match_with_lvasgn_node_free(node);
}

void mlhs_node_free(Mlhs *node)
{
    maybe_node_list_free(node->items);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_mlhs_node_free(node);
}

void module_node_free(Module *node)
{
    maybe_node_free(node->name);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_module_node_free(node);
}

void next_node_free(Next *node)
{
    maybe_node_list_free(node->args);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    rust_next_node_free(node);
}

void nil_node_free(Nil *node)
{
    maybe_loc_free(node->expression_l);
    rust_nil_node_free(node);
}

void nth_ref_node_free(NthRef *node)
{
    rust_string_free(node->name);
    maybe_loc_free(node->expression_l);
    rust_nth_ref_node_free(node);
}

void numblock_node_free(Numblock *node)
{
    maybe_node_free(node->call);
    maybe_node_free(node->body);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_numblock_node_free(node);
}

void op_asgn_node_free(OpAsgn *node)
{
    maybe_node_free(node->recv);
    rust_string_free(node->operator);
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_op_asgn_node_free(node);
}

void optarg_node_free(Optarg *node)
{
    rust_string_free(node->name);
    maybe_node_free(node->default_);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_optarg_node_free(node);
}

void or_node_free(Or *node)
{
    maybe_node_free(node->lhs);
    maybe_node_free(node->rhs);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_or_node_free(node);
}

void or_asgn_node_free(OrAsgn *node)
{
    maybe_node_free(node->recv);
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_or_asgn_node_free(node);
}

void pair_node_free(Pair *node)
{
    maybe_node_free(node->key);
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_pair_node_free(node);
}

void pin_node_free(Pin *node)
{
    maybe_node_free(node->var);
    maybe_loc_free(node->selector_l);
    maybe_loc_free(node->expression_l);
    rust_pin_node_free(node);
}

void postexe_node_free(Postexe *node)
{
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_postexe_node_free(node);
}

void preexe_node_free(Preexe *node)
{
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_preexe_node_free(node);
}

void procarg0_node_free(Procarg0 *node)
{
    maybe_node_list_free(node->args);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_procarg0_node_free(node);
}

void rational_node_free(Rational *node)
{
    rust_string_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_rational_node_free(node);
}

void redo_node_free(Redo *node)
{
    maybe_loc_free(node->expression_l);
    rust_redo_node_free(node);
}

void reg_opt_node_free(RegOpt *node)
{
    rust_string_free(node->options);
    maybe_loc_free(node->expression_l);
    rust_reg_opt_node_free(node);
}

void regexp_node_free(Regexp *node)
{
    maybe_node_list_free(node->parts);
    maybe_node_free(node->options);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_regexp_node_free(node);
}

void rescue_node_free(Rescue *node)
{
    maybe_node_free(node->body);
    maybe_node_list_free(node->rescue_bodies);
    maybe_node_free(node->else_);
    maybe_loc_free(node->else_l);
    maybe_loc_free(node->expression_l);
    rust_rescue_node_free(node);
}

void rescue_body_node_free(RescueBody *node)
{
    maybe_node_free(node->exc_list);
    maybe_node_free(node->exc_var);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->assoc_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->expression_l);
    rust_rescue_body_node_free(node);
}

void restarg_node_free(Restarg *node)
{
    rust_string_free(node->name);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->name_l);
    maybe_loc_free(node->expression_l);
    rust_restarg_node_free(node);
}

void retry_node_free(Retry *node)
{
    maybe_loc_free(node->expression_l);
    rust_retry_node_free(node);
}

void return__node_free(Return *node)
{
    maybe_node_list_free(node->args);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    rust_return__node_free(node);
}

void sclass_node_free(SClass *node)
{
    maybe_node_free(node->expr);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_sclass_node_free(node);
}

void self__node_free(Self_ *node)
{
    maybe_loc_free(node->expression_l);
    rust_self__node_free(node);
}

void send_node_free(Send *node)
{
    maybe_node_free(node->recv);
    rust_string_free(node->method_name);
    maybe_node_list_free(node->args);
    maybe_loc_free(node->dot_l);
    maybe_loc_free(node->selector_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_send_node_free(node);
}

void shadowarg_node_free(Shadowarg *node)
{
    rust_string_free(node->name);
    maybe_loc_free(node->expression_l);
    rust_shadowarg_node_free(node);
}

void splat_node_free(Splat *node)
{
    maybe_node_free(node->value);
    maybe_loc_free(node->operator_l);
    maybe_loc_free(node->expression_l);
    rust_splat_node_free(node);
}

void str__node_free(Str *node)
{
    rust_string_free(node->value);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_str__node_free(node);
}

void super__node_free(Super *node)
{
    maybe_node_list_free(node->args);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_super__node_free(node);
}

void sym_node_free(Sym *node)
{
    rust_string_free(node->name);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_sym_node_free(node);
}

void true__node_free(True *node)
{
    maybe_loc_free(node->expression_l);
    rust_true__node_free(node);
}

void undef_node_free(Undef *node)
{
    maybe_node_list_free(node->names);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    rust_undef_node_free(node);
}

void unless_guard_node_free(UnlessGuard *node)
{
    maybe_node_free(node->cond);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    rust_unless_guard_node_free(node);
}

void until_node_free(Until *node)
{
    maybe_node_free(node->cond);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_until_node_free(node);
}

void until_post_node_free(UntilPost *node)
{
    maybe_node_free(node->cond);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    rust_until_post_node_free(node);
}

void when_node_free(When *node)
{
    maybe_node_list_free(node->patterns);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->expression_l);
    rust_when_node_free(node);
}

void while__node_free(While *node)
{
    maybe_node_free(node->cond);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_while__node_free(node);
}

void while_post_node_free(WhilePost *node)
{
    maybe_node_free(node->cond);
    maybe_node_free(node->body);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->expression_l);
    rust_while_post_node_free(node);
}

void x_heredoc_node_free(XHeredoc *node)
{
    maybe_node_list_free(node->parts);
    maybe_loc_free(node->heredoc_body_l);
    maybe_loc_free(node->heredoc_end_l);
    maybe_loc_free(node->expression_l);
    rust_x_heredoc_node_free(node);
}

void xstr_node_free(Xstr *node)
{
    maybe_node_list_free(node->parts);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_xstr_node_free(node);
}

void yield__node_free(Yield *node)
{
    maybe_node_list_free(node->args);
    maybe_loc_free(node->keyword_l);
    maybe_loc_free(node->begin_l);
    maybe_loc_free(node->end_l);
    maybe_loc_free(node->expression_l);
    rust_yield__node_free(node);
}

void zsuper_node_free(ZSuper *node)
{
    maybe_loc_free(node->expression_l);
    rust_zsuper_node_free(node);
}

void inner_node_free(InnerNode *inner_node, NodeType node_type)
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
    rust_inner_node_free(inner_node);
}

void node_free(Node *node)
{
    inner_node_free(node->inner, node->node_type);
    rust_node_free(node);
}
