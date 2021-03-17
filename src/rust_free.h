#ifndef LIB_RUBY_PARSER_RUST_FREE_H
#define LIB_RUBY_PARSER_RUST_FREE_H

struct Loc;
void rust_loc_free(struct Loc*);

struct Comment;
void rust_comments_free(struct Comment*);

struct CommentList;
void rust_comment_list_free(struct CommentList*);

struct Diagnostic;
void rust_diagnostics_free(struct Diagnostic*);

struct DiagnosticList;
void rust_diagnostic_list_free(struct DiagnosticList*);

struct MagicComment;
void rust_magic_comments_free(struct MagicComment*);

struct MagicCommentList;
void rust_magic_comment_list_free(struct MagicCommentList*);

void rust_string_free(char *);

union InnerNode;
void rust_inner_node_free(union InnerNode *);

// Nodes start
struct Alias;
void rust_alias_node_free(struct Alias*);

struct AndAsgn;
void rust_and_asgn_node_free(struct AndAsgn*);

struct And;
void rust_and_node_free(struct And*);

struct Arg;
void rust_arg_node_free(struct Arg*);

struct Args;
void rust_args_node_free(struct Args*);

struct Array;
void rust_array_node_free(struct Array*);

struct ArrayPattern;
void rust_array_pattern_node_free(struct ArrayPattern*);

struct ArrayPatternWithTail;
void rust_array_pattern_with_tail_node_free(struct ArrayPatternWithTail*);

struct BackRef;
void rust_back_ref_node_free(struct BackRef*);

struct Begin;
void rust_begin_node_free(struct Begin*);

struct Block;
void rust_block_node_free(struct Block*);

struct BlockPass;
void rust_block_pass_node_free(struct BlockPass*);

struct Blockarg;
void rust_blockarg_node_free(struct Blockarg*);

struct Break;
void rust_break__node_free(struct Break*);

struct Case;
void rust_case_node_free(struct Case*);

struct CaseMatch;
void rust_case_match_node_free(struct CaseMatch*);

struct Casgn;
void rust_casgn_node_free(struct Casgn*);

struct Cbase;
void rust_cbase_node_free(struct Cbase*);

struct Class;
void rust_class_node_free(struct Class*);

struct Complex;
void rust_complex_node_free(struct Complex*);

struct Const;
void rust_const__node_free(struct Const*);

struct ConstPattern;
void rust_const_pattern_node_free(struct ConstPattern*);

struct CSend;
void rust_csend_node_free(struct CSend*);

struct Cvar;
void rust_cvar_node_free(struct Cvar*);

struct Cvasgn;
void rust_cvasgn_node_free(struct Cvasgn*);

struct Def;
void rust_def_node_free(struct Def*);

struct Defined;
void rust_defined_node_free(struct Defined*);

struct Defs;
void rust_defs_node_free(struct Defs*);

struct Dstr;
void rust_dstr_node_free(struct Dstr*);

struct Dsym;
void rust_dsym_node_free(struct Dsym*);

struct EFlipFlop;
void rust_eflipflop_node_free(struct EFlipFlop*);

struct EmptyElse;
void rust_empty_else_node_free(struct EmptyElse*);

struct Encoding;
void rust_encoding__node_free(struct Encoding*);

struct Ensure;
void rust_ensure_node_free(struct Ensure*);

struct Erange;
void rust_erange_node_free(struct Erange*);

struct False;
void rust_false__node_free(struct False*);

struct File;
void rust_file_node_free(struct File*);

struct FindPattern;
void rust_find_pattern_node_free(struct FindPattern*);

struct Float;
void rust_float_node_free(struct Float*);

struct For;
void rust_for__node_free(struct For*);

struct ForwardArg;
void rust_forward_arg_node_free(struct ForwardArg*);

struct ForwardedArgs;
void rust_forwarded_args_node_free(struct ForwardedArgs*);

struct Gvar;
void rust_gvar_node_free(struct Gvar*);

struct Gvasgn;
void rust_gvasgn_node_free(struct Gvasgn*);

struct Hash;
void rust_hash_node_free(struct Hash*);

struct Kwargs;
void rust_kwargs_node_free(struct Kwargs*);

struct HashPattern;
void rust_hash_pattern_node_free(struct HashPattern*);

struct Heredoc;
void rust_heredoc_node_free(struct Heredoc*);

struct If;
void rust_if__node_free(struct If*);

struct IfGuard;
void rust_if_guard_node_free(struct IfGuard*);

struct IfMod;
void rust_if_mod_node_free(struct IfMod*);

struct IfTernary;
void rust_if_ternary_node_free(struct IfTernary*);

struct IFlipFlop;
void rust_iflipflop_node_free(struct IFlipFlop*);

struct MatchPattern;
void rust_match_pattern_node_free(struct MatchPattern*);

struct MatchPatternP;
void rust_match_pattern_p_node_free(struct MatchPatternP*);

struct InPattern;
void rust_in_pattern_node_free(struct InPattern*);

struct Index;
void rust_index_node_free(struct Index*);

struct IndexAsgn;
void rust_index_asgn_node_free(struct IndexAsgn*);

struct Int;
void rust_int_node_free(struct Int*);

struct Irange;
void rust_irange_node_free(struct Irange*);

struct Ivar;
void rust_ivar_node_free(struct Ivar*);

struct Ivasgn;
void rust_ivasgn_node_free(struct Ivasgn*);

struct Kwarg;
void rust_kwarg_node_free(struct Kwarg*);

struct KwBegin;
void rust_kwbegin_node_free(struct KwBegin*);

struct Kwnilarg;
void rust_kwnilarg_node_free(struct Kwnilarg*);

struct Kwoptarg;
void rust_kwoptarg_node_free(struct Kwoptarg*);

struct Kwrestarg;
void rust_kwrestarg_node_free(struct Kwrestarg*);

struct Kwsplat;
void rust_kwsplat_node_free(struct Kwsplat*);

struct Lambda;
void rust_lambda_node_free(struct Lambda*);

struct Line;
void rust_line_node_free(struct Line*);

struct Lvar;
void rust_lvar_node_free(struct Lvar*);

struct Lvasgn;
void rust_lvasgn_node_free(struct Lvasgn*);

struct Masgn;
void rust_masgn_node_free(struct Masgn*);

struct MatchAlt;
void rust_match_alt_node_free(struct MatchAlt*);

struct MatchAs;
void rust_match_as_node_free(struct MatchAs*);

struct MatchCurrentLine;
void rust_match_current_line_node_free(struct MatchCurrentLine*);

struct MatchNilPattern;
void rust_match_nil_pattern_node_free(struct MatchNilPattern*);

struct MatchRest;
void rust_match_rest_node_free(struct MatchRest*);

struct MatchVar;
void rust_match_var_node_free(struct MatchVar*);

struct MatchWithLvasgn;
void rust_match_with_lvasgn_node_free(struct MatchWithLvasgn*);

struct Mlhs;
void rust_mlhs_node_free(struct Mlhs*);

struct Module;
void rust_module_node_free(struct Module*);

struct Next;
void rust_next_node_free(struct Next*);

struct Nil;
void rust_nil_node_free(struct Nil*);

struct NthRef;
void rust_nth_ref_node_free(struct NthRef*);

struct Numblock;
void rust_numblock_node_free(struct Numblock*);

struct OpAsgn;
void rust_op_asgn_node_free(struct OpAsgn*);

struct Optarg;
void rust_optarg_node_free(struct Optarg*);

struct Or;
void rust_or_node_free(struct Or*);

struct OrAsgn;
void rust_or_asgn_node_free(struct OrAsgn*);

struct Pair;
void rust_pair_node_free(struct Pair*);

struct Pin;
void rust_pin_node_free(struct Pin*);

struct Postexe;
void rust_postexe_node_free(struct Postexe*);

struct Preexe;
void rust_preexe_node_free(struct Preexe*);

struct Procarg0;
void rust_procarg0_node_free(struct Procarg0*);

struct Rational;
void rust_rational_node_free(struct Rational*);

struct Redo;
void rust_redo_node_free(struct Redo*);

struct RegOpt;
void rust_reg_opt_node_free(struct RegOpt*);

struct Regexp;
void rust_regexp_node_free(struct Regexp*);

struct Rescue;
void rust_rescue_node_free(struct Rescue*);

struct RescueBody;
void rust_rescue_body_node_free(struct RescueBody*);

struct Restarg;
void rust_restarg_node_free(struct Restarg*);

struct Retry;
void rust_retry_node_free(struct Retry*);

struct Return;
void rust_return__node_free(struct Return*);

struct SClass;
void rust_sclass_node_free(struct SClass*);

struct Self_;
void rust_self__node_free(struct Self_*);

struct Send;
void rust_send_node_free(struct Send*);

struct Shadowarg;
void rust_shadowarg_node_free(struct Shadowarg*);

struct Splat;
void rust_splat_node_free(struct Splat*);

struct Str;
void rust_str__node_free(struct Str*);

struct Super;
void rust_super__node_free(struct Super*);

struct Sym;
void rust_sym_node_free(struct Sym*);

struct True;
void rust_true__node_free(struct True*);

struct Undef;
void rust_undef_node_free(struct Undef*);

struct UnlessGuard;
void rust_unless_guard_node_free(struct UnlessGuard*);

struct Until;
void rust_until_node_free(struct Until*);

struct UntilPost;
void rust_until_post_node_free(struct UntilPost*);

struct When;
void rust_when_node_free(struct When*);

struct While;
void rust_while__node_free(struct While*);

struct WhilePost;
void rust_while_post_node_free(struct WhilePost*);

struct XHeredoc;
void rust_x_heredoc_node_free(struct XHeredoc*);

struct Xstr;
void rust_xstr_node_free(struct Xstr*);

struct Yield;
void rust_yield__node_free(struct Yield*);

struct ZSuper;
void rust_zsuper_node_free(struct ZSuper*);
// Nodes end

struct Node;
void rust_node_free(struct Node*);
void rust_nodes_free(struct Node*);

struct NodeList;
void rust_node_list_free(struct NodeList*);

struct Token;
void rust_tokens_free(struct Token*);

struct TokenList;
void rust_token_list_free(struct TokenList*);

struct ParserResult;
void rust_parser_result_free(struct ParserResult*);

#endif // LIB_RUBY_PARSER_RUST_FREE_H
