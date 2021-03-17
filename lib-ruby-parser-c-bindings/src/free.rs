use crate::bindings;
use crate::ptr_free;

fn array_ptr_free<T>(ptr: *mut T, size: usize) {
    drop(unsafe { Vec::from_raw_parts(ptr, size, size) });
}

#[no_mangle]
pub extern "C" fn input_free(ptr: *mut lib_ruby_parser::source::Input) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_loc_free(ptr: *mut bindings::Loc) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_comments_free(ptr: *mut bindings::Comment, size: u32) { array_ptr_free(ptr, size as usize); }

#[no_mangle]
pub extern "C" fn rust_comment_list_free(ptr: *mut bindings::CommentList) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_diagnostics_free(ptr: *mut bindings::Diagnostic, size: u32) { array_ptr_free(ptr, size as usize); }

#[no_mangle]
pub extern "C" fn rust_diagnostic_list_free(ptr: *mut bindings::DiagnosticList) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_magic_comments_free(ptr: *mut bindings::MagicComment, size: u32) { array_ptr_free(ptr, size as usize); }

#[no_mangle]
pub extern "C" fn rust_magic_comment_list_free(ptr: *mut bindings::MagicCommentList) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_string_free(ptr: *mut i8) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_inner_node_free(ptr: *mut bindings::InnerNode) { ptr_free(ptr); }

// Nodes start
#[no_mangle]
pub extern "C" fn rust_alias_node_free(ptr: *mut bindings::Alias) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_and_asgn_node_free(ptr: *mut bindings::AndAsgn) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_and_node_free(ptr: *mut bindings::And) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_arg_node_free(ptr: *mut bindings::Arg) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_args_node_free(ptr: *mut bindings::Args) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_array_node_free(ptr: *mut bindings::Array) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_array_pattern_node_free(ptr: *mut bindings::ArrayPattern) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_array_pattern_with_tail_node_free(ptr: *mut bindings::ArrayPatternWithTail) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_back_ref_node_free(ptr: *mut bindings::BackRef) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_begin_node_free(ptr: *mut bindings::Begin) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_block_node_free(ptr: *mut bindings::Block) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_block_pass_node_free(ptr: *mut bindings::BlockPass) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_blockarg_node_free(ptr: *mut bindings::Blockarg) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_break__node_free(ptr: *mut bindings::Break) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_case_node_free(ptr: *mut bindings::Case) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_case_match_node_free(ptr: *mut bindings::CaseMatch) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_casgn_node_free(ptr: *mut bindings::Casgn) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_cbase_node_free(ptr: *mut bindings::Cbase) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_class_node_free(ptr: *mut bindings::Class) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_complex_node_free(ptr: *mut bindings::Complex) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_const__node_free(ptr: *mut bindings::Const) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_const_pattern_node_free(ptr: *mut bindings::ConstPattern) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_csend_node_free(ptr: *mut bindings::CSend) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_cvar_node_free(ptr: *mut bindings::Cvar) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_cvasgn_node_free(ptr: *mut bindings::Cvasgn) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_def_node_free(ptr: *mut bindings::Def) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_defined_node_free(ptr: *mut bindings::Defined) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_defs_node_free(ptr: *mut bindings::Defs) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_dstr_node_free(ptr: *mut bindings::Dstr) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_dsym_node_free(ptr: *mut bindings::Dsym) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_eflipflop_node_free(ptr: *mut bindings::EFlipFlop) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_empty_else_node_free(ptr: *mut bindings::EmptyElse) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_encoding__node_free(ptr: *mut bindings::Encoding) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_ensure_node_free(ptr: *mut bindings::Ensure) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_erange_node_free(ptr: *mut bindings::Erange) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_false__node_free(ptr: *mut bindings::False) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_file_node_free(ptr: *mut bindings::File) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_find_pattern_node_free(ptr: *mut bindings::FindPattern) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_float_node_free(ptr: *mut bindings::Float) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_for__node_free(ptr: *mut bindings::For) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_forward_arg_node_free(ptr: *mut bindings::ForwardArg) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_forwarded_args_node_free(ptr: *mut bindings::ForwardedArgs) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_gvar_node_free(ptr: *mut bindings::Gvar) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_gvasgn_node_free(ptr: *mut bindings::Gvasgn) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_hash_node_free(ptr: *mut bindings::Hash) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_kwargs_node_free(ptr: *mut bindings::Kwargs) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_hash_pattern_node_free(ptr: *mut bindings::HashPattern) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_heredoc_node_free(ptr: *mut bindings::Heredoc) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_if__node_free(ptr: *mut bindings::If) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_if_guard_node_free(ptr: *mut bindings::IfGuard) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_if_mod_node_free(ptr: *mut bindings::IfMod) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_if_ternary_node_free(ptr: *mut bindings::IfTernary) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_iflipflop_node_free(ptr: *mut bindings::IFlipFlop) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_match_pattern_node_free(ptr: *mut bindings::MatchPattern) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_match_pattern_p_node_free(ptr: *mut bindings::MatchPatternP) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_in_pattern_node_free(ptr: *mut bindings::InPattern) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_index_node_free(ptr: *mut bindings::Index) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_index_asgn_node_free(ptr: *mut bindings::IndexAsgn) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_int_node_free(ptr: *mut bindings::Int) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_irange_node_free(ptr: *mut bindings::Irange) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_ivar_node_free(ptr: *mut bindings::Ivar) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_ivasgn_node_free(ptr: *mut bindings::Ivasgn) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_kwarg_node_free(ptr: *mut bindings::Kwarg) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_kwbegin_node_free(ptr: *mut bindings::KwBegin) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_kwnilarg_node_free(ptr: *mut bindings::Kwnilarg) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_kwoptarg_node_free(ptr: *mut bindings::Kwoptarg) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_kwrestarg_node_free(ptr: *mut bindings::Kwrestarg) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_kwsplat_node_free(ptr: *mut bindings::Kwsplat) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_lambda_node_free(ptr: *mut bindings::Lambda) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_line_node_free(ptr: *mut bindings::Line) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_lvar_node_free(ptr: *mut bindings::Lvar) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_lvasgn_node_free(ptr: *mut bindings::Lvasgn) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_masgn_node_free(ptr: *mut bindings::Masgn) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_match_alt_node_free(ptr: *mut bindings::MatchAlt) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_match_as_node_free(ptr: *mut bindings::MatchAs) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_match_current_line_node_free(ptr: *mut bindings::MatchCurrentLine) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_match_nil_pattern_node_free(ptr: *mut bindings::MatchNilPattern) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_match_rest_node_free(ptr: *mut bindings::MatchRest) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_match_var_node_free(ptr: *mut bindings::MatchVar) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_match_with_lvasgn_node_free(ptr: *mut bindings::MatchWithLvasgn) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_mlhs_node_free(ptr: *mut bindings::Mlhs) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_module_node_free(ptr: *mut bindings::Module) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_next_node_free(ptr: *mut bindings::Next) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_nil_node_free(ptr: *mut bindings::Nil) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_nth_ref_node_free(ptr: *mut bindings::NthRef) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_numblock_node_free(ptr: *mut bindings::Numblock) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_op_asgn_node_free(ptr: *mut bindings::OpAsgn) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_optarg_node_free(ptr: *mut bindings::Optarg) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_or_node_free(ptr: *mut bindings::Or) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_or_asgn_node_free(ptr: *mut bindings::OrAsgn) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_pair_node_free(ptr: *mut bindings::Pair) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_pin_node_free(ptr: *mut bindings::Pin) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_postexe_node_free(ptr: *mut bindings::Postexe) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_preexe_node_free(ptr: *mut bindings::Preexe) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_procarg0_node_free(ptr: *mut bindings::Procarg0) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_rational_node_free(ptr: *mut bindings::Rational) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_redo_node_free(ptr: *mut bindings::Redo) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_reg_opt_node_free(ptr: *mut bindings::RegOpt) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_regexp_node_free(ptr: *mut bindings::Regexp) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_rescue_node_free(ptr: *mut bindings::Rescue) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_rescue_body_node_free(ptr: *mut bindings::RescueBody) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_restarg_node_free(ptr: *mut bindings::Restarg) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_retry_node_free(ptr: *mut bindings::Retry) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_return__node_free(ptr: *mut bindings::Return) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_sclass_node_free(ptr: *mut bindings::SClass) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_self__node_free(ptr: *mut bindings::Self_) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_send_node_free(ptr: *mut bindings::Send) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_shadowarg_node_free(ptr: *mut bindings::Shadowarg) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_splat_node_free(ptr: *mut bindings::Splat) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_str__node_free(ptr: *mut bindings::Str) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_super__node_free(ptr: *mut bindings::Super) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_sym_node_free(ptr: *mut bindings::Sym) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_true__node_free(ptr: *mut bindings::True) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_undef_node_free(ptr: *mut bindings::Undef) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_unless_guard_node_free(ptr: *mut bindings::UnlessGuard) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_until_node_free(ptr: *mut bindings::Until) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_until_post_node_free(ptr: *mut bindings::UntilPost) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_when_node_free(ptr: *mut bindings::When) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_while__node_free(ptr: *mut bindings::While) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_while_post_node_free(ptr: *mut bindings::WhilePost) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_x_heredoc_node_free(ptr: *mut bindings::XHeredoc) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_xstr_node_free(ptr: *mut bindings::Xstr) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_yield__node_free(ptr: *mut bindings::Yield) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_zsuper_node_free(ptr: *mut bindings::ZSuper) { ptr_free(ptr); }
// Nodes end

#[no_mangle]
pub extern "C" fn rust_node_free(ptr: *mut bindings::Node) { ptr_free(ptr); }
#[no_mangle]
pub extern "C" fn rust_nodes_free(ptr: *mut bindings::Node, size: u32) { array_ptr_free(ptr, size as usize); }

#[no_mangle]
pub extern "C" fn rust_node_list_free(ptr: *mut bindings::NodeList) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_tokens_free(ptr: *mut bindings::Token, size: u32) { array_ptr_free(ptr, size as usize); }

#[no_mangle]
pub extern "C" fn rust_token_list_free(ptr: *mut bindings::TokenList) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn rust_parser_result_free(ptr: *mut bindings::ParserResult) { ptr_free(ptr); }

#[no_mangle]
pub extern "C" fn free_token_name(ptr: *mut i8) { rust_string_free(ptr); }

#[no_mangle]
pub extern "C" fn free_token_value(ptr: *mut i8) { rust_string_free(ptr); }

#[no_mangle]
pub extern "C" fn free_rendered_diagnostic(ptr: *mut i8) { rust_string_free(ptr); }

#[no_mangle]
pub extern "C" fn free_diagnostic_message(ptr: *mut i8) { rust_string_free(ptr); }

#[no_mangle]
pub extern "C" fn free_loc_source(ptr: *mut i8) { rust_string_free(ptr); }
