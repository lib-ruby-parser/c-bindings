use crate::bindings::*;
use crate::node::helpers::*;

#[no_mangle]
pub extern "C" fn get_args_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Block(lib_ruby_parser::nodes::Block { args, .. }) =>
                maybe_boxed_node_to_ptr(args),
        lib_ruby_parser::Node::Def(lib_ruby_parser::nodes::Def { args, .. }) =>
                maybe_boxed_node_to_ptr(args),
        lib_ruby_parser::Node::Defs(lib_ruby_parser::nodes::Defs { args, .. }) =>
                maybe_boxed_node_to_ptr(args),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_as__node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::MatchAs(lib_ruby_parser::nodes::MatchAs { as_, .. }) =>
                boxed_node_to_ptr(as_),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_body_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Block(lib_ruby_parser::nodes::Block { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::Class(lib_ruby_parser::nodes::Class { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::Def(lib_ruby_parser::nodes::Def { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::Defs(lib_ruby_parser::nodes::Defs { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::Ensure(lib_ruby_parser::nodes::Ensure { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::For(lib_ruby_parser::nodes::For { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::InPattern(lib_ruby_parser::nodes::InPattern { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::Module(lib_ruby_parser::nodes::Module { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::Numblock(lib_ruby_parser::nodes::Numblock { body, .. }) =>
                boxed_node_to_ptr(body),
        lib_ruby_parser::Node::Postexe(lib_ruby_parser::nodes::Postexe { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::Preexe(lib_ruby_parser::nodes::Preexe { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::Rescue(lib_ruby_parser::nodes::Rescue { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::RescueBody(lib_ruby_parser::nodes::RescueBody { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::SClass(lib_ruby_parser::nodes::SClass { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::Until(lib_ruby_parser::nodes::Until { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::UntilPost(lib_ruby_parser::nodes::UntilPost { body, .. }) =>
                boxed_node_to_ptr(body),
        lib_ruby_parser::Node::When(lib_ruby_parser::nodes::When { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::While(lib_ruby_parser::nodes::While { body, .. }) =>
                maybe_boxed_node_to_ptr(body),
        lib_ruby_parser::Node::WhilePost(lib_ruby_parser::nodes::WhilePost { body, .. }) =>
                boxed_node_to_ptr(body),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_call_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Block(lib_ruby_parser::nodes::Block { call, .. }) =>
                boxed_node_to_ptr(call),
        lib_ruby_parser::Node::Numblock(lib_ruby_parser::nodes::Numblock { call, .. }) =>
                boxed_node_to_ptr(call),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_cond_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::If(lib_ruby_parser::nodes::If { cond, .. }) =>
                boxed_node_to_ptr(cond),
        lib_ruby_parser::Node::IfGuard(lib_ruby_parser::nodes::IfGuard { cond, .. }) =>
                boxed_node_to_ptr(cond),
        lib_ruby_parser::Node::IfMod(lib_ruby_parser::nodes::IfMod { cond, .. }) =>
                boxed_node_to_ptr(cond),
        lib_ruby_parser::Node::IfTernary(lib_ruby_parser::nodes::IfTernary { cond, .. }) =>
                boxed_node_to_ptr(cond),
        lib_ruby_parser::Node::UnlessGuard(lib_ruby_parser::nodes::UnlessGuard { cond, .. }) =>
                boxed_node_to_ptr(cond),
        lib_ruby_parser::Node::Until(lib_ruby_parser::nodes::Until { cond, .. }) =>
                boxed_node_to_ptr(cond),
        lib_ruby_parser::Node::UntilPost(lib_ruby_parser::nodes::UntilPost { cond, .. }) =>
                boxed_node_to_ptr(cond),
        lib_ruby_parser::Node::While(lib_ruby_parser::nodes::While { cond, .. }) =>
                boxed_node_to_ptr(cond),
        lib_ruby_parser::Node::WhilePost(lib_ruby_parser::nodes::WhilePost { cond, .. }) =>
                boxed_node_to_ptr(cond),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_const__node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::ConstPattern(lib_ruby_parser::nodes::ConstPattern { const_, .. }) =>
                boxed_node_to_ptr(const_),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_default_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Kwoptarg(lib_ruby_parser::nodes::Kwoptarg { default, .. }) =>
                boxed_node_to_ptr(default),
        lib_ruby_parser::Node::Optarg(lib_ruby_parser::nodes::Optarg { default, .. }) =>
                boxed_node_to_ptr(default),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_definee_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Defs(lib_ruby_parser::nodes::Defs { definee, .. }) =>
                boxed_node_to_ptr(definee),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_else__node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Rescue(lib_ruby_parser::nodes::Rescue { else_, .. }) =>
                maybe_boxed_node_to_ptr(else_),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_else_body_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Case(lib_ruby_parser::nodes::Case { else_body, .. }) =>
                maybe_boxed_node_to_ptr(else_body),
        lib_ruby_parser::Node::CaseMatch(lib_ruby_parser::nodes::CaseMatch { else_body, .. }) =>
                maybe_boxed_node_to_ptr(else_body),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_ensure_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Ensure(lib_ruby_parser::nodes::Ensure { ensure, .. }) =>
                maybe_boxed_node_to_ptr(ensure),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_exc_list_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::RescueBody(lib_ruby_parser::nodes::RescueBody { exc_list, .. }) =>
                maybe_boxed_node_to_ptr(exc_list),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_exc_var_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::RescueBody(lib_ruby_parser::nodes::RescueBody { exc_var, .. }) =>
                maybe_boxed_node_to_ptr(exc_var),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_expr_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Case(lib_ruby_parser::nodes::Case { expr, .. }) =>
                maybe_boxed_node_to_ptr(expr),
        lib_ruby_parser::Node::CaseMatch(lib_ruby_parser::nodes::CaseMatch { expr, .. }) =>
                boxed_node_to_ptr(expr),
        lib_ruby_parser::Node::SClass(lib_ruby_parser::nodes::SClass { expr, .. }) =>
                boxed_node_to_ptr(expr),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_from_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Alias(lib_ruby_parser::nodes::Alias { from, .. }) =>
                boxed_node_to_ptr(from),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_guard_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::InPattern(lib_ruby_parser::nodes::InPattern { guard, .. }) =>
                maybe_boxed_node_to_ptr(guard),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_if_false_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::If(lib_ruby_parser::nodes::If { if_false, .. }) =>
                maybe_boxed_node_to_ptr(if_false),
        lib_ruby_parser::Node::IfMod(lib_ruby_parser::nodes::IfMod { if_false, .. }) =>
                maybe_boxed_node_to_ptr(if_false),
        lib_ruby_parser::Node::IfTernary(lib_ruby_parser::nodes::IfTernary { if_false, .. }) =>
                boxed_node_to_ptr(if_false),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_if_true_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::If(lib_ruby_parser::nodes::If { if_true, .. }) =>
                maybe_boxed_node_to_ptr(if_true),
        lib_ruby_parser::Node::IfMod(lib_ruby_parser::nodes::IfMod { if_true, .. }) =>
                maybe_boxed_node_to_ptr(if_true),
        lib_ruby_parser::Node::IfTernary(lib_ruby_parser::nodes::IfTernary { if_true, .. }) =>
                boxed_node_to_ptr(if_true),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_iteratee_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::For(lib_ruby_parser::nodes::For { iteratee, .. }) =>
                boxed_node_to_ptr(iteratee),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_iterator_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::For(lib_ruby_parser::nodes::For { iterator, .. }) =>
                boxed_node_to_ptr(iterator),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_key_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Pair(lib_ruby_parser::nodes::Pair { key, .. }) =>
                boxed_node_to_ptr(key),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_left_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::EFlipFlop(lib_ruby_parser::nodes::EFlipFlop { left, .. }) =>
                maybe_boxed_node_to_ptr(left),
        lib_ruby_parser::Node::Erange(lib_ruby_parser::nodes::Erange { left, .. }) =>
                maybe_boxed_node_to_ptr(left),
        lib_ruby_parser::Node::IFlipFlop(lib_ruby_parser::nodes::IFlipFlop { left, .. }) =>
                maybe_boxed_node_to_ptr(left),
        lib_ruby_parser::Node::Irange(lib_ruby_parser::nodes::Irange { left, .. }) =>
                maybe_boxed_node_to_ptr(left),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_lhs_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::And(lib_ruby_parser::nodes::And { lhs, .. }) =>
                boxed_node_to_ptr(lhs),
        lib_ruby_parser::Node::Masgn(lib_ruby_parser::nodes::Masgn { lhs, .. }) =>
                boxed_node_to_ptr(lhs),
        lib_ruby_parser::Node::MatchAlt(lib_ruby_parser::nodes::MatchAlt { lhs, .. }) =>
                boxed_node_to_ptr(lhs),
        lib_ruby_parser::Node::Or(lib_ruby_parser::nodes::Or { lhs, .. }) =>
                boxed_node_to_ptr(lhs),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_name_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Class(lib_ruby_parser::nodes::Class { name, .. }) =>
                boxed_node_to_ptr(name),
        lib_ruby_parser::Node::MatchRest(lib_ruby_parser::nodes::MatchRest { name, .. }) =>
                maybe_boxed_node_to_ptr(name),
        lib_ruby_parser::Node::Module(lib_ruby_parser::nodes::Module { name, .. }) =>
                boxed_node_to_ptr(name),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_options_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Regexp(lib_ruby_parser::nodes::Regexp { options, .. }) =>
                maybe_boxed_node_to_ptr(options),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_pattern_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::ConstPattern(lib_ruby_parser::nodes::ConstPattern { pattern, .. }) =>
                boxed_node_to_ptr(pattern),
        lib_ruby_parser::Node::InMatch(lib_ruby_parser::nodes::InMatch { pattern, .. }) =>
                boxed_node_to_ptr(pattern),
        lib_ruby_parser::Node::InPattern(lib_ruby_parser::nodes::InPattern { pattern, .. }) =>
                boxed_node_to_ptr(pattern),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_re_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::MatchCurrentLine(lib_ruby_parser::nodes::MatchCurrentLine { re, .. }) =>
                boxed_node_to_ptr(re),
        lib_ruby_parser::Node::MatchWithLvasgn(lib_ruby_parser::nodes::MatchWithLvasgn { re, .. }) =>
                boxed_node_to_ptr(re),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_recv_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::AndAsgn(lib_ruby_parser::nodes::AndAsgn { recv, .. }) =>
                boxed_node_to_ptr(recv),
        lib_ruby_parser::Node::CSend(lib_ruby_parser::nodes::CSend { recv, .. }) =>
                boxed_node_to_ptr(recv),
        lib_ruby_parser::Node::Index(lib_ruby_parser::nodes::Index { recv, .. }) =>
                boxed_node_to_ptr(recv),
        lib_ruby_parser::Node::IndexAsgn(lib_ruby_parser::nodes::IndexAsgn { recv, .. }) =>
                boxed_node_to_ptr(recv),
        lib_ruby_parser::Node::OpAsgn(lib_ruby_parser::nodes::OpAsgn { recv, .. }) =>
                boxed_node_to_ptr(recv),
        lib_ruby_parser::Node::OrAsgn(lib_ruby_parser::nodes::OrAsgn { recv, .. }) =>
                boxed_node_to_ptr(recv),
        lib_ruby_parser::Node::Send(lib_ruby_parser::nodes::Send { recv, .. }) =>
                maybe_boxed_node_to_ptr(recv),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_rhs_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::And(lib_ruby_parser::nodes::And { rhs, .. }) =>
                boxed_node_to_ptr(rhs),
        lib_ruby_parser::Node::Masgn(lib_ruby_parser::nodes::Masgn { rhs, .. }) =>
                boxed_node_to_ptr(rhs),
        lib_ruby_parser::Node::MatchAlt(lib_ruby_parser::nodes::MatchAlt { rhs, .. }) =>
                boxed_node_to_ptr(rhs),
        lib_ruby_parser::Node::Or(lib_ruby_parser::nodes::Or { rhs, .. }) =>
                boxed_node_to_ptr(rhs),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_right_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::EFlipFlop(lib_ruby_parser::nodes::EFlipFlop { right, .. }) =>
                maybe_boxed_node_to_ptr(right),
        lib_ruby_parser::Node::Erange(lib_ruby_parser::nodes::Erange { right, .. }) =>
                maybe_boxed_node_to_ptr(right),
        lib_ruby_parser::Node::IFlipFlop(lib_ruby_parser::nodes::IFlipFlop { right, .. }) =>
                maybe_boxed_node_to_ptr(right),
        lib_ruby_parser::Node::Irange(lib_ruby_parser::nodes::Irange { right, .. }) =>
                maybe_boxed_node_to_ptr(right),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_scope_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Casgn(lib_ruby_parser::nodes::Casgn { scope, .. }) =>
                maybe_boxed_node_to_ptr(scope),
        lib_ruby_parser::Node::Const(lib_ruby_parser::nodes::Const { scope, .. }) =>
                maybe_boxed_node_to_ptr(scope),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_superclass_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Class(lib_ruby_parser::nodes::Class { superclass, .. }) =>
                maybe_boxed_node_to_ptr(superclass),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_to_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Alias(lib_ruby_parser::nodes::Alias { to, .. }) =>
                boxed_node_to_ptr(to),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_value_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::AndAsgn(lib_ruby_parser::nodes::AndAsgn { value, .. }) =>
                boxed_node_to_ptr(value),
        lib_ruby_parser::Node::BlockPass(lib_ruby_parser::nodes::BlockPass { value, .. }) =>
                boxed_node_to_ptr(value),
        lib_ruby_parser::Node::Casgn(lib_ruby_parser::nodes::Casgn { value, .. }) =>
                maybe_boxed_node_to_ptr(value),
        lib_ruby_parser::Node::Cvasgn(lib_ruby_parser::nodes::Cvasgn { value, .. }) =>
                maybe_boxed_node_to_ptr(value),
        lib_ruby_parser::Node::Defined(lib_ruby_parser::nodes::Defined { value, .. }) =>
                boxed_node_to_ptr(value),
        lib_ruby_parser::Node::Gvasgn(lib_ruby_parser::nodes::Gvasgn { value, .. }) =>
                maybe_boxed_node_to_ptr(value),
        lib_ruby_parser::Node::InMatch(lib_ruby_parser::nodes::InMatch { value, .. }) =>
                boxed_node_to_ptr(value),
        lib_ruby_parser::Node::IndexAsgn(lib_ruby_parser::nodes::IndexAsgn { value, .. }) =>
                maybe_boxed_node_to_ptr(value),
        lib_ruby_parser::Node::Ivasgn(lib_ruby_parser::nodes::Ivasgn { value, .. }) =>
                maybe_boxed_node_to_ptr(value),
        lib_ruby_parser::Node::Kwsplat(lib_ruby_parser::nodes::Kwsplat { value, .. }) =>
                boxed_node_to_ptr(value),
        lib_ruby_parser::Node::Lvasgn(lib_ruby_parser::nodes::Lvasgn { value, .. }) =>
                maybe_boxed_node_to_ptr(value),
        lib_ruby_parser::Node::MatchAs(lib_ruby_parser::nodes::MatchAs { value, .. }) =>
                boxed_node_to_ptr(value),
        lib_ruby_parser::Node::MatchWithLvasgn(lib_ruby_parser::nodes::MatchWithLvasgn { value, .. }) =>
                boxed_node_to_ptr(value),
        lib_ruby_parser::Node::OpAsgn(lib_ruby_parser::nodes::OpAsgn { value, .. }) =>
                boxed_node_to_ptr(value),
        lib_ruby_parser::Node::OrAsgn(lib_ruby_parser::nodes::OrAsgn { value, .. }) =>
                boxed_node_to_ptr(value),
        lib_ruby_parser::Node::Pair(lib_ruby_parser::nodes::Pair { value, .. }) =>
                boxed_node_to_ptr(value),
        lib_ruby_parser::Node::Splat(lib_ruby_parser::nodes::Splat { value, .. }) =>
                maybe_boxed_node_to_ptr(value),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_var_node(node: *mut Node) -> *mut Node {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Pin(lib_ruby_parser::nodes::Pin { var, .. }) =>
                boxed_node_to_ptr(var),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_args_list(node: *mut Node) -> *mut NodeList {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Args(lib_ruby_parser::nodes::Args { args, .. }) =>
                nodes_vec_to_ptr(args),
        lib_ruby_parser::Node::Break(lib_ruby_parser::nodes::Break { args, .. }) =>
                nodes_vec_to_ptr(args),
        lib_ruby_parser::Node::CSend(lib_ruby_parser::nodes::CSend { args, .. }) =>
                nodes_vec_to_ptr(args),
        lib_ruby_parser::Node::Next(lib_ruby_parser::nodes::Next { args, .. }) =>
                nodes_vec_to_ptr(args),
        lib_ruby_parser::Node::Procarg0(lib_ruby_parser::nodes::Procarg0 { args, .. }) =>
                nodes_vec_to_ptr(args),
        lib_ruby_parser::Node::Return(lib_ruby_parser::nodes::Return { args, .. }) =>
                nodes_vec_to_ptr(args),
        lib_ruby_parser::Node::Send(lib_ruby_parser::nodes::Send { args, .. }) =>
                nodes_vec_to_ptr(args),
        lib_ruby_parser::Node::Super(lib_ruby_parser::nodes::Super { args, .. }) =>
                nodes_vec_to_ptr(args),
        lib_ruby_parser::Node::Yield(lib_ruby_parser::nodes::Yield { args, .. }) =>
                nodes_vec_to_ptr(args),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_elements_list(node: *mut Node) -> *mut NodeList {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Array(lib_ruby_parser::nodes::Array { elements, .. }) =>
                nodes_vec_to_ptr(elements),
        lib_ruby_parser::Node::ArrayPattern(lib_ruby_parser::nodes::ArrayPattern { elements, .. }) =>
                nodes_vec_to_ptr(elements),
        lib_ruby_parser::Node::ArrayPatternWithTail(lib_ruby_parser::nodes::ArrayPatternWithTail { elements, .. }) =>
                nodes_vec_to_ptr(elements),
        lib_ruby_parser::Node::FindPattern(lib_ruby_parser::nodes::FindPattern { elements, .. }) =>
                nodes_vec_to_ptr(elements),
        lib_ruby_parser::Node::HashPattern(lib_ruby_parser::nodes::HashPattern { elements, .. }) =>
                nodes_vec_to_ptr(elements),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_in_bodies_list(node: *mut Node) -> *mut NodeList {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::CaseMatch(lib_ruby_parser::nodes::CaseMatch { in_bodies, .. }) =>
                nodes_vec_to_ptr(in_bodies),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_indexes_list(node: *mut Node) -> *mut NodeList {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Index(lib_ruby_parser::nodes::Index { indexes, .. }) =>
                nodes_vec_to_ptr(indexes),
        lib_ruby_parser::Node::IndexAsgn(lib_ruby_parser::nodes::IndexAsgn { indexes, .. }) =>
                nodes_vec_to_ptr(indexes),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_items_list(node: *mut Node) -> *mut NodeList {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Mlhs(lib_ruby_parser::nodes::Mlhs { items, .. }) =>
                nodes_vec_to_ptr(items),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_names_list(node: *mut Node) -> *mut NodeList {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Undef(lib_ruby_parser::nodes::Undef { names, .. }) =>
                nodes_vec_to_ptr(names),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_pairs_list(node: *mut Node) -> *mut NodeList {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Hash(lib_ruby_parser::nodes::Hash { pairs, .. }) =>
                nodes_vec_to_ptr(pairs),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_parts_list(node: *mut Node) -> *mut NodeList {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Dstr(lib_ruby_parser::nodes::Dstr { parts, .. }) =>
                nodes_vec_to_ptr(parts),
        lib_ruby_parser::Node::Dsym(lib_ruby_parser::nodes::Dsym { parts, .. }) =>
                nodes_vec_to_ptr(parts),
        lib_ruby_parser::Node::Heredoc(lib_ruby_parser::nodes::Heredoc { parts, .. }) =>
                nodes_vec_to_ptr(parts),
        lib_ruby_parser::Node::Regexp(lib_ruby_parser::nodes::Regexp { parts, .. }) =>
                nodes_vec_to_ptr(parts),
        lib_ruby_parser::Node::XHeredoc(lib_ruby_parser::nodes::XHeredoc { parts, .. }) =>
                nodes_vec_to_ptr(parts),
        lib_ruby_parser::Node::Xstr(lib_ruby_parser::nodes::Xstr { parts, .. }) =>
                nodes_vec_to_ptr(parts),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_patterns_list(node: *mut Node) -> *mut NodeList {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::When(lib_ruby_parser::nodes::When { patterns, .. }) =>
                nodes_vec_to_ptr(patterns),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_rescue_bodies_list(node: *mut Node) -> *mut NodeList {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Rescue(lib_ruby_parser::nodes::Rescue { rescue_bodies, .. }) =>
                nodes_vec_to_ptr(rescue_bodies),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_statements_list(node: *mut Node) -> *mut NodeList {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Begin(lib_ruby_parser::nodes::Begin { statements, .. }) =>
                nodes_vec_to_ptr(statements),
        lib_ruby_parser::Node::KwBegin(lib_ruby_parser::nodes::KwBegin { statements, .. }) =>
                nodes_vec_to_ptr(statements),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_when_bodies_list(node: *mut Node) -> *mut NodeList {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Case(lib_ruby_parser::nodes::Case { when_bodies, .. }) =>
                nodes_vec_to_ptr(when_bodies),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_assignment_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Def(lib_ruby_parser::nodes::Def { assignment_l, .. }) =>
                maybe_range_to_ptr(assignment_l),
        lib_ruby_parser::Node::Defs(lib_ruby_parser::nodes::Defs { assignment_l, .. }) =>
                maybe_range_to_ptr(assignment_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_assoc_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::RescueBody(lib_ruby_parser::nodes::RescueBody { assoc_l, .. }) =>
                maybe_range_to_ptr(assoc_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_begin_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Args(lib_ruby_parser::nodes::Args { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Array(lib_ruby_parser::nodes::Array { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::ArrayPattern(lib_ruby_parser::nodes::ArrayPattern { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::ArrayPatternWithTail(lib_ruby_parser::nodes::ArrayPatternWithTail { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Begin(lib_ruby_parser::nodes::Begin { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Block(lib_ruby_parser::nodes::Block { begin_l, .. }) =>
                range_to_ptr(begin_l),
        lib_ruby_parser::Node::Break(lib_ruby_parser::nodes::Break { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::CSend(lib_ruby_parser::nodes::CSend { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::ConstPattern(lib_ruby_parser::nodes::ConstPattern { begin_l, .. }) =>
                range_to_ptr(begin_l),
        lib_ruby_parser::Node::Defined(lib_ruby_parser::nodes::Defined { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Dstr(lib_ruby_parser::nodes::Dstr { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Dsym(lib_ruby_parser::nodes::Dsym { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::FindPattern(lib_ruby_parser::nodes::FindPattern { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::For(lib_ruby_parser::nodes::For { begin_l, .. }) =>
                range_to_ptr(begin_l),
        lib_ruby_parser::Node::Hash(lib_ruby_parser::nodes::Hash { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::HashPattern(lib_ruby_parser::nodes::HashPattern { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::If(lib_ruby_parser::nodes::If { begin_l, .. }) =>
                range_to_ptr(begin_l),
        lib_ruby_parser::Node::InPattern(lib_ruby_parser::nodes::InPattern { begin_l, .. }) =>
                range_to_ptr(begin_l),
        lib_ruby_parser::Node::Index(lib_ruby_parser::nodes::Index { begin_l, .. }) =>
                range_to_ptr(begin_l),
        lib_ruby_parser::Node::IndexAsgn(lib_ruby_parser::nodes::IndexAsgn { begin_l, .. }) =>
                range_to_ptr(begin_l),
        lib_ruby_parser::Node::KwBegin(lib_ruby_parser::nodes::KwBegin { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Mlhs(lib_ruby_parser::nodes::Mlhs { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Next(lib_ruby_parser::nodes::Next { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Numblock(lib_ruby_parser::nodes::Numblock { begin_l, .. }) =>
                range_to_ptr(begin_l),
        lib_ruby_parser::Node::Postexe(lib_ruby_parser::nodes::Postexe { begin_l, .. }) =>
                range_to_ptr(begin_l),
        lib_ruby_parser::Node::Preexe(lib_ruby_parser::nodes::Preexe { begin_l, .. }) =>
                range_to_ptr(begin_l),
        lib_ruby_parser::Node::Procarg0(lib_ruby_parser::nodes::Procarg0 { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Regexp(lib_ruby_parser::nodes::Regexp { begin_l, .. }) =>
                range_to_ptr(begin_l),
        lib_ruby_parser::Node::RescueBody(lib_ruby_parser::nodes::RescueBody { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Send(lib_ruby_parser::nodes::Send { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Str(lib_ruby_parser::nodes::Str { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Super(lib_ruby_parser::nodes::Super { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Sym(lib_ruby_parser::nodes::Sym { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Until(lib_ruby_parser::nodes::Until { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::When(lib_ruby_parser::nodes::When { begin_l, .. }) =>
                range_to_ptr(begin_l),
        lib_ruby_parser::Node::While(lib_ruby_parser::nodes::While { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        lib_ruby_parser::Node::Xstr(lib_ruby_parser::nodes::Xstr { begin_l, .. }) =>
                range_to_ptr(begin_l),
        lib_ruby_parser::Node::Yield(lib_ruby_parser::nodes::Yield { begin_l, .. }) =>
                maybe_range_to_ptr(begin_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_colon_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::IfTernary(lib_ruby_parser::nodes::IfTernary { colon_l, .. }) =>
                range_to_ptr(colon_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_dot_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::CSend(lib_ruby_parser::nodes::CSend { dot_l, .. }) =>
                range_to_ptr(dot_l),
        lib_ruby_parser::Node::Send(lib_ruby_parser::nodes::Send { dot_l, .. }) =>
                maybe_range_to_ptr(dot_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_double_colon_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Casgn(lib_ruby_parser::nodes::Casgn { double_colon_l, .. }) =>
                maybe_range_to_ptr(double_colon_l),
        lib_ruby_parser::Node::Const(lib_ruby_parser::nodes::Const { double_colon_l, .. }) =>
                maybe_range_to_ptr(double_colon_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_else_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Case(lib_ruby_parser::nodes::Case { else_l, .. }) =>
                maybe_range_to_ptr(else_l),
        lib_ruby_parser::Node::CaseMatch(lib_ruby_parser::nodes::CaseMatch { else_l, .. }) =>
                maybe_range_to_ptr(else_l),
        lib_ruby_parser::Node::If(lib_ruby_parser::nodes::If { else_l, .. }) =>
                maybe_range_to_ptr(else_l),
        lib_ruby_parser::Node::Rescue(lib_ruby_parser::nodes::Rescue { else_l, .. }) =>
                maybe_range_to_ptr(else_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_end_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Args(lib_ruby_parser::nodes::Args { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Array(lib_ruby_parser::nodes::Array { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::ArrayPattern(lib_ruby_parser::nodes::ArrayPattern { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::ArrayPatternWithTail(lib_ruby_parser::nodes::ArrayPatternWithTail { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Begin(lib_ruby_parser::nodes::Begin { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Block(lib_ruby_parser::nodes::Block { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::Break(lib_ruby_parser::nodes::Break { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::CSend(lib_ruby_parser::nodes::CSend { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Case(lib_ruby_parser::nodes::Case { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::CaseMatch(lib_ruby_parser::nodes::CaseMatch { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::Class(lib_ruby_parser::nodes::Class { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::ConstPattern(lib_ruby_parser::nodes::ConstPattern { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::Def(lib_ruby_parser::nodes::Def { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Defined(lib_ruby_parser::nodes::Defined { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Defs(lib_ruby_parser::nodes::Defs { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Dstr(lib_ruby_parser::nodes::Dstr { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Dsym(lib_ruby_parser::nodes::Dsym { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::FindPattern(lib_ruby_parser::nodes::FindPattern { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::For(lib_ruby_parser::nodes::For { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::Hash(lib_ruby_parser::nodes::Hash { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::HashPattern(lib_ruby_parser::nodes::HashPattern { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::If(lib_ruby_parser::nodes::If { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Index(lib_ruby_parser::nodes::Index { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::IndexAsgn(lib_ruby_parser::nodes::IndexAsgn { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::KwBegin(lib_ruby_parser::nodes::KwBegin { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Mlhs(lib_ruby_parser::nodes::Mlhs { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Module(lib_ruby_parser::nodes::Module { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::Next(lib_ruby_parser::nodes::Next { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Numblock(lib_ruby_parser::nodes::Numblock { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::Postexe(lib_ruby_parser::nodes::Postexe { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::Preexe(lib_ruby_parser::nodes::Preexe { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::Procarg0(lib_ruby_parser::nodes::Procarg0 { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Regexp(lib_ruby_parser::nodes::Regexp { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::SClass(lib_ruby_parser::nodes::SClass { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::Send(lib_ruby_parser::nodes::Send { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Str(lib_ruby_parser::nodes::Str { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Super(lib_ruby_parser::nodes::Super { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Sym(lib_ruby_parser::nodes::Sym { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Until(lib_ruby_parser::nodes::Until { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::While(lib_ruby_parser::nodes::While { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        lib_ruby_parser::Node::Xstr(lib_ruby_parser::nodes::Xstr { end_l, .. }) =>
                range_to_ptr(end_l),
        lib_ruby_parser::Node::Yield(lib_ruby_parser::nodes::Yield { end_l, .. }) =>
                maybe_range_to_ptr(end_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_expression_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Alias(lib_ruby_parser::nodes::Alias { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::And(lib_ruby_parser::nodes::And { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::AndAsgn(lib_ruby_parser::nodes::AndAsgn { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Arg(lib_ruby_parser::nodes::Arg { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Args(lib_ruby_parser::nodes::Args { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Array(lib_ruby_parser::nodes::Array { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::ArrayPattern(lib_ruby_parser::nodes::ArrayPattern { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::ArrayPatternWithTail(lib_ruby_parser::nodes::ArrayPatternWithTail { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::BackRef(lib_ruby_parser::nodes::BackRef { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Begin(lib_ruby_parser::nodes::Begin { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Block(lib_ruby_parser::nodes::Block { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::BlockPass(lib_ruby_parser::nodes::BlockPass { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Blockarg(lib_ruby_parser::nodes::Blockarg { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Break(lib_ruby_parser::nodes::Break { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::CSend(lib_ruby_parser::nodes::CSend { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Case(lib_ruby_parser::nodes::Case { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::CaseMatch(lib_ruby_parser::nodes::CaseMatch { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Casgn(lib_ruby_parser::nodes::Casgn { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Cbase(lib_ruby_parser::nodes::Cbase { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Class(lib_ruby_parser::nodes::Class { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Complex(lib_ruby_parser::nodes::Complex { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Const(lib_ruby_parser::nodes::Const { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::ConstPattern(lib_ruby_parser::nodes::ConstPattern { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Cvar(lib_ruby_parser::nodes::Cvar { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Cvasgn(lib_ruby_parser::nodes::Cvasgn { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Def(lib_ruby_parser::nodes::Def { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Defined(lib_ruby_parser::nodes::Defined { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Defs(lib_ruby_parser::nodes::Defs { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Dstr(lib_ruby_parser::nodes::Dstr { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Dsym(lib_ruby_parser::nodes::Dsym { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::EFlipFlop(lib_ruby_parser::nodes::EFlipFlop { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::EmptyElse(lib_ruby_parser::nodes::EmptyElse { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Encoding(lib_ruby_parser::nodes::Encoding { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Ensure(lib_ruby_parser::nodes::Ensure { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Erange(lib_ruby_parser::nodes::Erange { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::False(lib_ruby_parser::nodes::False { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::File(lib_ruby_parser::nodes::File { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::FindPattern(lib_ruby_parser::nodes::FindPattern { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Float(lib_ruby_parser::nodes::Float { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::For(lib_ruby_parser::nodes::For { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::ForwardArg(lib_ruby_parser::nodes::ForwardArg { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::ForwardedArgs(lib_ruby_parser::nodes::ForwardedArgs { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Gvar(lib_ruby_parser::nodes::Gvar { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Gvasgn(lib_ruby_parser::nodes::Gvasgn { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Hash(lib_ruby_parser::nodes::Hash { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::HashPattern(lib_ruby_parser::nodes::HashPattern { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Heredoc(lib_ruby_parser::nodes::Heredoc { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::IFlipFlop(lib_ruby_parser::nodes::IFlipFlop { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::If(lib_ruby_parser::nodes::If { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::IfGuard(lib_ruby_parser::nodes::IfGuard { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::IfMod(lib_ruby_parser::nodes::IfMod { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::IfTernary(lib_ruby_parser::nodes::IfTernary { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::InMatch(lib_ruby_parser::nodes::InMatch { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::InPattern(lib_ruby_parser::nodes::InPattern { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Index(lib_ruby_parser::nodes::Index { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::IndexAsgn(lib_ruby_parser::nodes::IndexAsgn { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Int(lib_ruby_parser::nodes::Int { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Irange(lib_ruby_parser::nodes::Irange { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Ivar(lib_ruby_parser::nodes::Ivar { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Ivasgn(lib_ruby_parser::nodes::Ivasgn { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::KwBegin(lib_ruby_parser::nodes::KwBegin { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Kwarg(lib_ruby_parser::nodes::Kwarg { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Kwnilarg(lib_ruby_parser::nodes::Kwnilarg { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Kwoptarg(lib_ruby_parser::nodes::Kwoptarg { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Kwrestarg(lib_ruby_parser::nodes::Kwrestarg { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Kwsplat(lib_ruby_parser::nodes::Kwsplat { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Lambda(lib_ruby_parser::nodes::Lambda { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Line(lib_ruby_parser::nodes::Line { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Lvar(lib_ruby_parser::nodes::Lvar { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Lvasgn(lib_ruby_parser::nodes::Lvasgn { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Masgn(lib_ruby_parser::nodes::Masgn { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::MatchAlt(lib_ruby_parser::nodes::MatchAlt { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::MatchAs(lib_ruby_parser::nodes::MatchAs { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::MatchCurrentLine(lib_ruby_parser::nodes::MatchCurrentLine { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::MatchNilPattern(lib_ruby_parser::nodes::MatchNilPattern { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::MatchRest(lib_ruby_parser::nodes::MatchRest { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::MatchVar(lib_ruby_parser::nodes::MatchVar { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::MatchWithLvasgn(lib_ruby_parser::nodes::MatchWithLvasgn { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Mlhs(lib_ruby_parser::nodes::Mlhs { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Module(lib_ruby_parser::nodes::Module { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Next(lib_ruby_parser::nodes::Next { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Nil(lib_ruby_parser::nodes::Nil { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::NthRef(lib_ruby_parser::nodes::NthRef { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Numblock(lib_ruby_parser::nodes::Numblock { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::OpAsgn(lib_ruby_parser::nodes::OpAsgn { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Optarg(lib_ruby_parser::nodes::Optarg { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Or(lib_ruby_parser::nodes::Or { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::OrAsgn(lib_ruby_parser::nodes::OrAsgn { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Pair(lib_ruby_parser::nodes::Pair { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Pin(lib_ruby_parser::nodes::Pin { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Postexe(lib_ruby_parser::nodes::Postexe { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Preexe(lib_ruby_parser::nodes::Preexe { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Procarg0(lib_ruby_parser::nodes::Procarg0 { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Rational(lib_ruby_parser::nodes::Rational { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Redo(lib_ruby_parser::nodes::Redo { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::RegOpt(lib_ruby_parser::nodes::RegOpt { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Regexp(lib_ruby_parser::nodes::Regexp { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Rescue(lib_ruby_parser::nodes::Rescue { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::RescueBody(lib_ruby_parser::nodes::RescueBody { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Restarg(lib_ruby_parser::nodes::Restarg { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Retry(lib_ruby_parser::nodes::Retry { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Return(lib_ruby_parser::nodes::Return { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::SClass(lib_ruby_parser::nodes::SClass { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Self_(lib_ruby_parser::nodes::Self_ { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Send(lib_ruby_parser::nodes::Send { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Shadowarg(lib_ruby_parser::nodes::Shadowarg { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Splat(lib_ruby_parser::nodes::Splat { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Str(lib_ruby_parser::nodes::Str { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Super(lib_ruby_parser::nodes::Super { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Sym(lib_ruby_parser::nodes::Sym { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::True(lib_ruby_parser::nodes::True { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Undef(lib_ruby_parser::nodes::Undef { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::UnlessGuard(lib_ruby_parser::nodes::UnlessGuard { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Until(lib_ruby_parser::nodes::Until { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::UntilPost(lib_ruby_parser::nodes::UntilPost { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::When(lib_ruby_parser::nodes::When { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::While(lib_ruby_parser::nodes::While { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::WhilePost(lib_ruby_parser::nodes::WhilePost { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::XHeredoc(lib_ruby_parser::nodes::XHeredoc { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Xstr(lib_ruby_parser::nodes::Xstr { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::Yield(lib_ruby_parser::nodes::Yield { expression_l, .. }) =>
                range_to_ptr(expression_l),
        lib_ruby_parser::Node::ZSuper(lib_ruby_parser::nodes::ZSuper { expression_l, .. }) =>
                range_to_ptr(expression_l),

    }
}
#[no_mangle]
pub extern "C" fn get_heredoc_body_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Heredoc(lib_ruby_parser::nodes::Heredoc { heredoc_body_l, .. }) =>
                range_to_ptr(heredoc_body_l),
        lib_ruby_parser::Node::XHeredoc(lib_ruby_parser::nodes::XHeredoc { heredoc_body_l, .. }) =>
                range_to_ptr(heredoc_body_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_heredoc_end_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Heredoc(lib_ruby_parser::nodes::Heredoc { heredoc_end_l, .. }) =>
                range_to_ptr(heredoc_end_l),
        lib_ruby_parser::Node::XHeredoc(lib_ruby_parser::nodes::XHeredoc { heredoc_end_l, .. }) =>
                range_to_ptr(heredoc_end_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_keyword_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Alias(lib_ruby_parser::nodes::Alias { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Break(lib_ruby_parser::nodes::Break { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Case(lib_ruby_parser::nodes::Case { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::CaseMatch(lib_ruby_parser::nodes::CaseMatch { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Class(lib_ruby_parser::nodes::Class { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Def(lib_ruby_parser::nodes::Def { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Defined(lib_ruby_parser::nodes::Defined { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Defs(lib_ruby_parser::nodes::Defs { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Ensure(lib_ruby_parser::nodes::Ensure { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::For(lib_ruby_parser::nodes::For { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::If(lib_ruby_parser::nodes::If { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::IfGuard(lib_ruby_parser::nodes::IfGuard { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::IfMod(lib_ruby_parser::nodes::IfMod { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::InPattern(lib_ruby_parser::nodes::InPattern { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Module(lib_ruby_parser::nodes::Module { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Next(lib_ruby_parser::nodes::Next { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Postexe(lib_ruby_parser::nodes::Postexe { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Preexe(lib_ruby_parser::nodes::Preexe { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::RescueBody(lib_ruby_parser::nodes::RescueBody { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Return(lib_ruby_parser::nodes::Return { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::SClass(lib_ruby_parser::nodes::SClass { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Super(lib_ruby_parser::nodes::Super { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Undef(lib_ruby_parser::nodes::Undef { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::UnlessGuard(lib_ruby_parser::nodes::UnlessGuard { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Until(lib_ruby_parser::nodes::Until { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::UntilPost(lib_ruby_parser::nodes::UntilPost { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::When(lib_ruby_parser::nodes::When { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::While(lib_ruby_parser::nodes::While { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::WhilePost(lib_ruby_parser::nodes::WhilePost { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        lib_ruby_parser::Node::Yield(lib_ruby_parser::nodes::Yield { keyword_l, .. }) =>
                range_to_ptr(keyword_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_name_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Blockarg(lib_ruby_parser::nodes::Blockarg { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::Casgn(lib_ruby_parser::nodes::Casgn { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::Const(lib_ruby_parser::nodes::Const { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::Cvasgn(lib_ruby_parser::nodes::Cvasgn { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::Def(lib_ruby_parser::nodes::Def { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::Defs(lib_ruby_parser::nodes::Defs { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::Gvasgn(lib_ruby_parser::nodes::Gvasgn { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::Ivasgn(lib_ruby_parser::nodes::Ivasgn { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::Kwarg(lib_ruby_parser::nodes::Kwarg { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::Kwnilarg(lib_ruby_parser::nodes::Kwnilarg { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::Kwoptarg(lib_ruby_parser::nodes::Kwoptarg { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::Kwrestarg(lib_ruby_parser::nodes::Kwrestarg { name_l, .. }) =>
                maybe_range_to_ptr(name_l),
        lib_ruby_parser::Node::Lvasgn(lib_ruby_parser::nodes::Lvasgn { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::MatchNilPattern(lib_ruby_parser::nodes::MatchNilPattern { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::MatchVar(lib_ruby_parser::nodes::MatchVar { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::Optarg(lib_ruby_parser::nodes::Optarg { name_l, .. }) =>
                range_to_ptr(name_l),
        lib_ruby_parser::Node::Restarg(lib_ruby_parser::nodes::Restarg { name_l, .. }) =>
                maybe_range_to_ptr(name_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_operator_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::And(lib_ruby_parser::nodes::And { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::AndAsgn(lib_ruby_parser::nodes::AndAsgn { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::BlockPass(lib_ruby_parser::nodes::BlockPass { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::Blockarg(lib_ruby_parser::nodes::Blockarg { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::CSend(lib_ruby_parser::nodes::CSend { operator_l, .. }) =>
                maybe_range_to_ptr(operator_l),
        lib_ruby_parser::Node::Casgn(lib_ruby_parser::nodes::Casgn { operator_l, .. }) =>
                maybe_range_to_ptr(operator_l),
        lib_ruby_parser::Node::Class(lib_ruby_parser::nodes::Class { operator_l, .. }) =>
                maybe_range_to_ptr(operator_l),
        lib_ruby_parser::Node::Complex(lib_ruby_parser::nodes::Complex { operator_l, .. }) =>
                maybe_range_to_ptr(operator_l),
        lib_ruby_parser::Node::Cvasgn(lib_ruby_parser::nodes::Cvasgn { operator_l, .. }) =>
                maybe_range_to_ptr(operator_l),
        lib_ruby_parser::Node::Defs(lib_ruby_parser::nodes::Defs { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::EFlipFlop(lib_ruby_parser::nodes::EFlipFlop { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::Erange(lib_ruby_parser::nodes::Erange { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::Float(lib_ruby_parser::nodes::Float { operator_l, .. }) =>
                maybe_range_to_ptr(operator_l),
        lib_ruby_parser::Node::For(lib_ruby_parser::nodes::For { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::Gvasgn(lib_ruby_parser::nodes::Gvasgn { operator_l, .. }) =>
                maybe_range_to_ptr(operator_l),
        lib_ruby_parser::Node::IFlipFlop(lib_ruby_parser::nodes::IFlipFlop { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::InMatch(lib_ruby_parser::nodes::InMatch { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::IndexAsgn(lib_ruby_parser::nodes::IndexAsgn { operator_l, .. }) =>
                maybe_range_to_ptr(operator_l),
        lib_ruby_parser::Node::Int(lib_ruby_parser::nodes::Int { operator_l, .. }) =>
                maybe_range_to_ptr(operator_l),
        lib_ruby_parser::Node::Irange(lib_ruby_parser::nodes::Irange { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::Ivasgn(lib_ruby_parser::nodes::Ivasgn { operator_l, .. }) =>
                maybe_range_to_ptr(operator_l),
        lib_ruby_parser::Node::Kwrestarg(lib_ruby_parser::nodes::Kwrestarg { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::Kwsplat(lib_ruby_parser::nodes::Kwsplat { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::Lvasgn(lib_ruby_parser::nodes::Lvasgn { operator_l, .. }) =>
                maybe_range_to_ptr(operator_l),
        lib_ruby_parser::Node::Masgn(lib_ruby_parser::nodes::Masgn { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::MatchAlt(lib_ruby_parser::nodes::MatchAlt { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::MatchAs(lib_ruby_parser::nodes::MatchAs { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::MatchNilPattern(lib_ruby_parser::nodes::MatchNilPattern { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::MatchRest(lib_ruby_parser::nodes::MatchRest { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::MatchWithLvasgn(lib_ruby_parser::nodes::MatchWithLvasgn { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::OpAsgn(lib_ruby_parser::nodes::OpAsgn { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::Optarg(lib_ruby_parser::nodes::Optarg { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::Or(lib_ruby_parser::nodes::Or { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::OrAsgn(lib_ruby_parser::nodes::OrAsgn { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::Pair(lib_ruby_parser::nodes::Pair { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::Rational(lib_ruby_parser::nodes::Rational { operator_l, .. }) =>
                maybe_range_to_ptr(operator_l),
        lib_ruby_parser::Node::Restarg(lib_ruby_parser::nodes::Restarg { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::SClass(lib_ruby_parser::nodes::SClass { operator_l, .. }) =>
                range_to_ptr(operator_l),
        lib_ruby_parser::Node::Send(lib_ruby_parser::nodes::Send { operator_l, .. }) =>
                maybe_range_to_ptr(operator_l),
        lib_ruby_parser::Node::Splat(lib_ruby_parser::nodes::Splat { operator_l, .. }) =>
                range_to_ptr(operator_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_question_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::IfTernary(lib_ruby_parser::nodes::IfTernary { question_l, .. }) =>
                range_to_ptr(question_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_selector_l(node: *mut Node) -> *mut Range {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::CSend(lib_ruby_parser::nodes::CSend { selector_l, .. }) =>
                range_to_ptr(selector_l),
        lib_ruby_parser::Node::Pin(lib_ruby_parser::nodes::Pin { selector_l, .. }) =>
                range_to_ptr(selector_l),
        lib_ruby_parser::Node::Send(lib_ruby_parser::nodes::Send { selector_l, .. }) =>
                maybe_range_to_ptr(selector_l),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_method_name_str(node: *mut Node) -> *mut u8 {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::CSend(lib_ruby_parser::nodes::CSend { method_name, .. }) =>
                str_to_ptr(method_name),
        lib_ruby_parser::Node::Send(lib_ruby_parser::nodes::Send { method_name, .. }) =>
                str_to_ptr(method_name),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_name_str(node: *mut Node) -> *mut u8 {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Arg(lib_ruby_parser::nodes::Arg { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::BackRef(lib_ruby_parser::nodes::BackRef { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Blockarg(lib_ruby_parser::nodes::Blockarg { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Casgn(lib_ruby_parser::nodes::Casgn { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Const(lib_ruby_parser::nodes::Const { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Cvar(lib_ruby_parser::nodes::Cvar { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Cvasgn(lib_ruby_parser::nodes::Cvasgn { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Def(lib_ruby_parser::nodes::Def { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Defs(lib_ruby_parser::nodes::Defs { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Gvar(lib_ruby_parser::nodes::Gvar { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Gvasgn(lib_ruby_parser::nodes::Gvasgn { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Ivar(lib_ruby_parser::nodes::Ivar { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Ivasgn(lib_ruby_parser::nodes::Ivasgn { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Kwarg(lib_ruby_parser::nodes::Kwarg { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Kwoptarg(lib_ruby_parser::nodes::Kwoptarg { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Kwrestarg(lib_ruby_parser::nodes::Kwrestarg { name, .. }) =>
                maybe_str_to_ptr(name),
        lib_ruby_parser::Node::Lvar(lib_ruby_parser::nodes::Lvar { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Lvasgn(lib_ruby_parser::nodes::Lvasgn { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::MatchVar(lib_ruby_parser::nodes::MatchVar { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::NthRef(lib_ruby_parser::nodes::NthRef { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Optarg(lib_ruby_parser::nodes::Optarg { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Restarg(lib_ruby_parser::nodes::Restarg { name, .. }) =>
                maybe_str_to_ptr(name),
        lib_ruby_parser::Node::Shadowarg(lib_ruby_parser::nodes::Shadowarg { name, .. }) =>
                str_to_ptr(name),
        lib_ruby_parser::Node::Sym(lib_ruby_parser::nodes::Sym { name, .. }) =>
                string_value_to_ptr(name),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_operator_str(node: *mut Node) -> *mut u8 {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::OpAsgn(lib_ruby_parser::nodes::OpAsgn { operator, .. }) =>
                str_to_ptr(operator),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_options_str(node: *mut Node) -> *mut u8 {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::RegOpt(lib_ruby_parser::nodes::RegOpt { options, .. }) =>
                chars_to_ptr(options),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_value_str(node: *mut Node) -> *mut u8 {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Complex(lib_ruby_parser::nodes::Complex { value, .. }) =>
                str_to_ptr(value),
        lib_ruby_parser::Node::Float(lib_ruby_parser::nodes::Float { value, .. }) =>
                str_to_ptr(value),
        lib_ruby_parser::Node::Int(lib_ruby_parser::nodes::Int { value, .. }) =>
                str_to_ptr(value),
        lib_ruby_parser::Node::Rational(lib_ruby_parser::nodes::Rational { value, .. }) =>
                str_to_ptr(value),
        lib_ruby_parser::Node::Str(lib_ruby_parser::nodes::Str { value, .. }) =>
                string_value_to_ptr(value),
        _ => std::ptr::null_mut(),
    }
}
#[no_mangle]
pub extern "C" fn get_numargs_num(node: *mut Node) -> size_t {
    match node_ptr_to_node_ref(node) {
        lib_ruby_parser::Node::Numblock(lib_ruby_parser::nodes::Numblock { numargs, .. }) =>
                u8_to_size_t(numargs),
        _ => 0 as size_t,
    }
}

#[no_mangle]
pub extern "C" fn node_kind(node: *mut Node) -> u32 {
    let node = node_ptr_to_node_ref(node);
    match node {
        lib_ruby_parser::Node::Alias(_) => NodeType_NODE_ALIAS,
        lib_ruby_parser::Node::AndAsgn(_) => NodeType_NODE_AND_ASGN,
        lib_ruby_parser::Node::And(_) => NodeType_NODE_AND,
        lib_ruby_parser::Node::Arg(_) => NodeType_NODE_ARG,
        lib_ruby_parser::Node::Args(_) => NodeType_NODE_ARGS,
        lib_ruby_parser::Node::Array(_) => NodeType_NODE_ARRAY,
        lib_ruby_parser::Node::ArrayPattern(_) => NodeType_NODE_ARRAY_PATTERN,
        lib_ruby_parser::Node::ArrayPatternWithTail(_) => NodeType_NODE_ARRAY_PATTERN_WITH_TAIL,
        lib_ruby_parser::Node::BackRef(_) => NodeType_NODE_BACK_REF,
        lib_ruby_parser::Node::Begin(_) => NodeType_NODE_BEGIN,
        lib_ruby_parser::Node::Block(_) => NodeType_NODE_BLOCK,
        lib_ruby_parser::Node::BlockPass(_) => NodeType_NODE_BLOCK_PASS,
        lib_ruby_parser::Node::Blockarg(_) => NodeType_NODE_BLOCKARG,
        lib_ruby_parser::Node::Break(_) => NodeType_NODE_BREAK_,
        lib_ruby_parser::Node::Case(_) => NodeType_NODE_CASE,
        lib_ruby_parser::Node::CaseMatch(_) => NodeType_NODE_CASE_MATCH,
        lib_ruby_parser::Node::Casgn(_) => NodeType_NODE_CASGN,
        lib_ruby_parser::Node::Cbase(_) => NodeType_NODE_CBASE,
        lib_ruby_parser::Node::Class(_) => NodeType_NODE_CLASS,
        lib_ruby_parser::Node::Complex(_) => NodeType_NODE_COMPLEX,
        lib_ruby_parser::Node::Const(_) => NodeType_NODE_CONST_,
        lib_ruby_parser::Node::ConstPattern(_) => NodeType_NODE_CONST_PATTERN,
        lib_ruby_parser::Node::CSend(_) => NodeType_NODE_CSEND,
        lib_ruby_parser::Node::Cvar(_) => NodeType_NODE_CVAR,
        lib_ruby_parser::Node::Cvasgn(_) => NodeType_NODE_CVASGN,
        lib_ruby_parser::Node::Def(_) => NodeType_NODE_DEF,
        lib_ruby_parser::Node::Defined(_) => NodeType_NODE_DEFINED,
        lib_ruby_parser::Node::Defs(_) => NodeType_NODE_DEFS,
        lib_ruby_parser::Node::Dstr(_) => NodeType_NODE_DSTR,
        lib_ruby_parser::Node::Dsym(_) => NodeType_NODE_DSYM,
        lib_ruby_parser::Node::EFlipFlop(_) => NodeType_NODE_EFLIPFLOP,
        lib_ruby_parser::Node::EmptyElse(_) => NodeType_NODE_EMPTY_ELSE,
        lib_ruby_parser::Node::Encoding(_) => NodeType_NODE_ENCODING_,
        lib_ruby_parser::Node::Ensure(_) => NodeType_NODE_ENSURE,
        lib_ruby_parser::Node::Erange(_) => NodeType_NODE_ERANGE,
        lib_ruby_parser::Node::False(_) => NodeType_NODE_FALSE_,
        lib_ruby_parser::Node::File(_) => NodeType_NODE_FILE,
        lib_ruby_parser::Node::FindPattern(_) => NodeType_NODE_FIND_PATTERN,
        lib_ruby_parser::Node::Float(_) => NodeType_NODE_FLOAT,
        lib_ruby_parser::Node::For(_) => NodeType_NODE_FOR_,
        lib_ruby_parser::Node::ForwardArg(_) => NodeType_NODE_FORWARD_ARG,
        lib_ruby_parser::Node::ForwardedArgs(_) => NodeType_NODE_FORWARDED_ARGS,
        lib_ruby_parser::Node::Gvar(_) => NodeType_NODE_GVAR,
        lib_ruby_parser::Node::Gvasgn(_) => NodeType_NODE_GVASGN,
        lib_ruby_parser::Node::Hash(_) => NodeType_NODE_HASH,
        lib_ruby_parser::Node::HashPattern(_) => NodeType_NODE_HASH_PATTERN,
        lib_ruby_parser::Node::Heredoc(_) => NodeType_NODE_HEREDOC,
        lib_ruby_parser::Node::If(_) => NodeType_NODE_IF_,
        lib_ruby_parser::Node::IfGuard(_) => NodeType_NODE_IF_GUARD,
        lib_ruby_parser::Node::IfMod(_) => NodeType_NODE_IF_MOD,
        lib_ruby_parser::Node::IfTernary(_) => NodeType_NODE_IF_TERNARY,
        lib_ruby_parser::Node::IFlipFlop(_) => NodeType_NODE_IFLIPFLOP,
        lib_ruby_parser::Node::InMatch(_) => NodeType_NODE_IN_MATCH,
        lib_ruby_parser::Node::InPattern(_) => NodeType_NODE_IN_PATTERN,
        lib_ruby_parser::Node::Index(_) => NodeType_NODE_INDEX,
        lib_ruby_parser::Node::IndexAsgn(_) => NodeType_NODE_INDEX_ASGN,
        lib_ruby_parser::Node::Int(_) => NodeType_NODE_INT,
        lib_ruby_parser::Node::Irange(_) => NodeType_NODE_IRANGE,
        lib_ruby_parser::Node::Ivar(_) => NodeType_NODE_IVAR,
        lib_ruby_parser::Node::Ivasgn(_) => NodeType_NODE_IVASGN,
        lib_ruby_parser::Node::Kwarg(_) => NodeType_NODE_KWARG,
        lib_ruby_parser::Node::KwBegin(_) => NodeType_NODE_KWBEGIN,
        lib_ruby_parser::Node::Kwnilarg(_) => NodeType_NODE_KWNILARG,
        lib_ruby_parser::Node::Kwoptarg(_) => NodeType_NODE_KWOPTARG,
        lib_ruby_parser::Node::Kwrestarg(_) => NodeType_NODE_KWRESTARG,
        lib_ruby_parser::Node::Kwsplat(_) => NodeType_NODE_KWSPLAT,
        lib_ruby_parser::Node::Lambda(_) => NodeType_NODE_LAMBDA,
        lib_ruby_parser::Node::Line(_) => NodeType_NODE_LINE,
        lib_ruby_parser::Node::Lvar(_) => NodeType_NODE_LVAR,
        lib_ruby_parser::Node::Lvasgn(_) => NodeType_NODE_LVASGN,
        lib_ruby_parser::Node::Masgn(_) => NodeType_NODE_MASGN,
        lib_ruby_parser::Node::MatchAlt(_) => NodeType_NODE_MATCH_ALT,
        lib_ruby_parser::Node::MatchAs(_) => NodeType_NODE_MATCH_AS,
        lib_ruby_parser::Node::MatchCurrentLine(_) => NodeType_NODE_MATCH_CURRENT_LINE,
        lib_ruby_parser::Node::MatchNilPattern(_) => NodeType_NODE_MATCH_NIL_PATTERN,
        lib_ruby_parser::Node::MatchRest(_) => NodeType_NODE_MATCH_REST,
        lib_ruby_parser::Node::MatchVar(_) => NodeType_NODE_MATCH_VAR,
        lib_ruby_parser::Node::MatchWithLvasgn(_) => NodeType_NODE_MATCH_WITH_LVASGN,
        lib_ruby_parser::Node::Mlhs(_) => NodeType_NODE_MLHS,
        lib_ruby_parser::Node::Module(_) => NodeType_NODE_MODULE,
        lib_ruby_parser::Node::Next(_) => NodeType_NODE_NEXT,
        lib_ruby_parser::Node::Nil(_) => NodeType_NODE_NIL,
        lib_ruby_parser::Node::NthRef(_) => NodeType_NODE_NTH_REF,
        lib_ruby_parser::Node::Numblock(_) => NodeType_NODE_NUMBLOCK,
        lib_ruby_parser::Node::OpAsgn(_) => NodeType_NODE_OP_ASGN,
        lib_ruby_parser::Node::Optarg(_) => NodeType_NODE_OPTARG,
        lib_ruby_parser::Node::Or(_) => NodeType_NODE_OR,
        lib_ruby_parser::Node::OrAsgn(_) => NodeType_NODE_OR_ASGN,
        lib_ruby_parser::Node::Pair(_) => NodeType_NODE_PAIR,
        lib_ruby_parser::Node::Pin(_) => NodeType_NODE_PIN,
        lib_ruby_parser::Node::Postexe(_) => NodeType_NODE_POSTEXE,
        lib_ruby_parser::Node::Preexe(_) => NodeType_NODE_PREEXE,
        lib_ruby_parser::Node::Procarg0(_) => NodeType_NODE_PROCARG0,
        lib_ruby_parser::Node::Rational(_) => NodeType_NODE_RATIONAL,
        lib_ruby_parser::Node::Redo(_) => NodeType_NODE_REDO,
        lib_ruby_parser::Node::RegOpt(_) => NodeType_NODE_REG_OPT,
        lib_ruby_parser::Node::Regexp(_) => NodeType_NODE_REGEXP,
        lib_ruby_parser::Node::Rescue(_) => NodeType_NODE_RESCUE,
        lib_ruby_parser::Node::RescueBody(_) => NodeType_NODE_RESCUE_BODY,
        lib_ruby_parser::Node::Restarg(_) => NodeType_NODE_RESTARG,
        lib_ruby_parser::Node::Retry(_) => NodeType_NODE_RETRY,
        lib_ruby_parser::Node::Return(_) => NodeType_NODE_RETURN_,
        lib_ruby_parser::Node::SClass(_) => NodeType_NODE_SCLASS,
        lib_ruby_parser::Node::Self_(_) => NodeType_NODE_SELF_,
        lib_ruby_parser::Node::Send(_) => NodeType_NODE_SEND,
        lib_ruby_parser::Node::Shadowarg(_) => NodeType_NODE_SHADOWARG,
        lib_ruby_parser::Node::Splat(_) => NodeType_NODE_SPLAT,
        lib_ruby_parser::Node::Str(_) => NodeType_NODE_STR_,
        lib_ruby_parser::Node::Super(_) => NodeType_NODE_SUPER_,
        lib_ruby_parser::Node::Sym(_) => NodeType_NODE_SYM,
        lib_ruby_parser::Node::True(_) => NodeType_NODE_TRUE_,
        lib_ruby_parser::Node::Undef(_) => NodeType_NODE_UNDEF,
        lib_ruby_parser::Node::UnlessGuard(_) => NodeType_NODE_UNLESS_GUARD,
        lib_ruby_parser::Node::Until(_) => NodeType_NODE_UNTIL,
        lib_ruby_parser::Node::UntilPost(_) => NodeType_NODE_UNTIL_POST,
        lib_ruby_parser::Node::When(_) => NodeType_NODE_WHEN,
        lib_ruby_parser::Node::While(_) => NodeType_NODE_WHILE_,
        lib_ruby_parser::Node::WhilePost(_) => NodeType_NODE_WHILE_POST,
        lib_ruby_parser::Node::XHeredoc(_) => NodeType_NODE_X_HEREDOC,
        lib_ruby_parser::Node::Xstr(_) => NodeType_NODE_XSTR,
        lib_ruby_parser::Node::Yield(_) => NodeType_NODE_YIELD_,
        lib_ruby_parser::Node::ZSuper(_) => NodeType_NODE_ZSUPER,
    }
}

