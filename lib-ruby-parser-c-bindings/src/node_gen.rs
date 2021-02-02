use crate::bindings::*;
use crate::StringPtr;
use crate::ptr_value;

impl From<lib_ruby_parser::Node> for Node {
    fn from(node: lib_ruby_parser::Node) -> Self {
        match node {
            lib_ruby_parser::Node::Alias(inner) => Node::from(inner),
            lib_ruby_parser::Node::AndAsgn(inner) => Node::from(inner),
            lib_ruby_parser::Node::And(inner) => Node::from(inner),
            lib_ruby_parser::Node::Arg(inner) => Node::from(inner),
            lib_ruby_parser::Node::Args(inner) => Node::from(inner),
            lib_ruby_parser::Node::Array(inner) => Node::from(inner),
            lib_ruby_parser::Node::ArrayPattern(inner) => Node::from(inner),
            lib_ruby_parser::Node::ArrayPatternWithTail(inner) => Node::from(inner),
            lib_ruby_parser::Node::BackRef(inner) => Node::from(inner),
            lib_ruby_parser::Node::Begin(inner) => Node::from(inner),
            lib_ruby_parser::Node::Block(inner) => Node::from(inner),
            lib_ruby_parser::Node::BlockPass(inner) => Node::from(inner),
            lib_ruby_parser::Node::Blockarg(inner) => Node::from(inner),
            lib_ruby_parser::Node::Break(inner) => Node::from(inner),
            lib_ruby_parser::Node::Case(inner) => Node::from(inner),
            lib_ruby_parser::Node::CaseMatch(inner) => Node::from(inner),
            lib_ruby_parser::Node::Casgn(inner) => Node::from(inner),
            lib_ruby_parser::Node::Cbase(inner) => Node::from(inner),
            lib_ruby_parser::Node::Class(inner) => Node::from(inner),
            lib_ruby_parser::Node::Complex(inner) => Node::from(inner),
            lib_ruby_parser::Node::Const(inner) => Node::from(inner),
            lib_ruby_parser::Node::ConstPattern(inner) => Node::from(inner),
            lib_ruby_parser::Node::CSend(inner) => Node::from(inner),
            lib_ruby_parser::Node::Cvar(inner) => Node::from(inner),
            lib_ruby_parser::Node::Cvasgn(inner) => Node::from(inner),
            lib_ruby_parser::Node::Def(inner) => Node::from(inner),
            lib_ruby_parser::Node::Defined(inner) => Node::from(inner),
            lib_ruby_parser::Node::Defs(inner) => Node::from(inner),
            lib_ruby_parser::Node::Dstr(inner) => Node::from(inner),
            lib_ruby_parser::Node::Dsym(inner) => Node::from(inner),
            lib_ruby_parser::Node::EFlipFlop(inner) => Node::from(inner),
            lib_ruby_parser::Node::EmptyElse(inner) => Node::from(inner),
            lib_ruby_parser::Node::Encoding(inner) => Node::from(inner),
            lib_ruby_parser::Node::Ensure(inner) => Node::from(inner),
            lib_ruby_parser::Node::Erange(inner) => Node::from(inner),
            lib_ruby_parser::Node::False(inner) => Node::from(inner),
            lib_ruby_parser::Node::File(inner) => Node::from(inner),
            lib_ruby_parser::Node::FindPattern(inner) => Node::from(inner),
            lib_ruby_parser::Node::Float(inner) => Node::from(inner),
            lib_ruby_parser::Node::For(inner) => Node::from(inner),
            lib_ruby_parser::Node::ForwardArg(inner) => Node::from(inner),
            lib_ruby_parser::Node::ForwardedArgs(inner) => Node::from(inner),
            lib_ruby_parser::Node::Gvar(inner) => Node::from(inner),
            lib_ruby_parser::Node::Gvasgn(inner) => Node::from(inner),
            lib_ruby_parser::Node::Hash(inner) => Node::from(inner),
            lib_ruby_parser::Node::Kwargs(inner) => Node::from(inner),
            lib_ruby_parser::Node::HashPattern(inner) => Node::from(inner),
            lib_ruby_parser::Node::Heredoc(inner) => Node::from(inner),
            lib_ruby_parser::Node::If(inner) => Node::from(inner),
            lib_ruby_parser::Node::IfGuard(inner) => Node::from(inner),
            lib_ruby_parser::Node::IfMod(inner) => Node::from(inner),
            lib_ruby_parser::Node::IfTernary(inner) => Node::from(inner),
            lib_ruby_parser::Node::IFlipFlop(inner) => Node::from(inner),
            lib_ruby_parser::Node::MatchPattern(inner) => Node::from(inner),
            lib_ruby_parser::Node::MatchPatternP(inner) => Node::from(inner),
            lib_ruby_parser::Node::InPattern(inner) => Node::from(inner),
            lib_ruby_parser::Node::Index(inner) => Node::from(inner),
            lib_ruby_parser::Node::IndexAsgn(inner) => Node::from(inner),
            lib_ruby_parser::Node::Int(inner) => Node::from(inner),
            lib_ruby_parser::Node::Irange(inner) => Node::from(inner),
            lib_ruby_parser::Node::Ivar(inner) => Node::from(inner),
            lib_ruby_parser::Node::Ivasgn(inner) => Node::from(inner),
            lib_ruby_parser::Node::Kwarg(inner) => Node::from(inner),
            lib_ruby_parser::Node::KwBegin(inner) => Node::from(inner),
            lib_ruby_parser::Node::Kwnilarg(inner) => Node::from(inner),
            lib_ruby_parser::Node::Kwoptarg(inner) => Node::from(inner),
            lib_ruby_parser::Node::Kwrestarg(inner) => Node::from(inner),
            lib_ruby_parser::Node::Kwsplat(inner) => Node::from(inner),
            lib_ruby_parser::Node::Lambda(inner) => Node::from(inner),
            lib_ruby_parser::Node::Line(inner) => Node::from(inner),
            lib_ruby_parser::Node::Lvar(inner) => Node::from(inner),
            lib_ruby_parser::Node::Lvasgn(inner) => Node::from(inner),
            lib_ruby_parser::Node::Masgn(inner) => Node::from(inner),
            lib_ruby_parser::Node::MatchAlt(inner) => Node::from(inner),
            lib_ruby_parser::Node::MatchAs(inner) => Node::from(inner),
            lib_ruby_parser::Node::MatchCurrentLine(inner) => Node::from(inner),
            lib_ruby_parser::Node::MatchNilPattern(inner) => Node::from(inner),
            lib_ruby_parser::Node::MatchRest(inner) => Node::from(inner),
            lib_ruby_parser::Node::MatchVar(inner) => Node::from(inner),
            lib_ruby_parser::Node::MatchWithLvasgn(inner) => Node::from(inner),
            lib_ruby_parser::Node::Mlhs(inner) => Node::from(inner),
            lib_ruby_parser::Node::Module(inner) => Node::from(inner),
            lib_ruby_parser::Node::Next(inner) => Node::from(inner),
            lib_ruby_parser::Node::Nil(inner) => Node::from(inner),
            lib_ruby_parser::Node::NthRef(inner) => Node::from(inner),
            lib_ruby_parser::Node::Numblock(inner) => Node::from(inner),
            lib_ruby_parser::Node::OpAsgn(inner) => Node::from(inner),
            lib_ruby_parser::Node::Optarg(inner) => Node::from(inner),
            lib_ruby_parser::Node::Or(inner) => Node::from(inner),
            lib_ruby_parser::Node::OrAsgn(inner) => Node::from(inner),
            lib_ruby_parser::Node::Pair(inner) => Node::from(inner),
            lib_ruby_parser::Node::Pin(inner) => Node::from(inner),
            lib_ruby_parser::Node::Postexe(inner) => Node::from(inner),
            lib_ruby_parser::Node::Preexe(inner) => Node::from(inner),
            lib_ruby_parser::Node::Procarg0(inner) => Node::from(inner),
            lib_ruby_parser::Node::Rational(inner) => Node::from(inner),
            lib_ruby_parser::Node::Redo(inner) => Node::from(inner),
            lib_ruby_parser::Node::RegOpt(inner) => Node::from(inner),
            lib_ruby_parser::Node::Regexp(inner) => Node::from(inner),
            lib_ruby_parser::Node::Rescue(inner) => Node::from(inner),
            lib_ruby_parser::Node::RescueBody(inner) => Node::from(inner),
            lib_ruby_parser::Node::Restarg(inner) => Node::from(inner),
            lib_ruby_parser::Node::Retry(inner) => Node::from(inner),
            lib_ruby_parser::Node::Return(inner) => Node::from(inner),
            lib_ruby_parser::Node::SClass(inner) => Node::from(inner),
            lib_ruby_parser::Node::Self_(inner) => Node::from(inner),
            lib_ruby_parser::Node::Send(inner) => Node::from(inner),
            lib_ruby_parser::Node::Shadowarg(inner) => Node::from(inner),
            lib_ruby_parser::Node::Splat(inner) => Node::from(inner),
            lib_ruby_parser::Node::Str(inner) => Node::from(inner),
            lib_ruby_parser::Node::Super(inner) => Node::from(inner),
            lib_ruby_parser::Node::Sym(inner) => Node::from(inner),
            lib_ruby_parser::Node::True(inner) => Node::from(inner),
            lib_ruby_parser::Node::Undef(inner) => Node::from(inner),
            lib_ruby_parser::Node::UnlessGuard(inner) => Node::from(inner),
            lib_ruby_parser::Node::Until(inner) => Node::from(inner),
            lib_ruby_parser::Node::UntilPost(inner) => Node::from(inner),
            lib_ruby_parser::Node::When(inner) => Node::from(inner),
            lib_ruby_parser::Node::While(inner) => Node::from(inner),
            lib_ruby_parser::Node::WhilePost(inner) => Node::from(inner),
            lib_ruby_parser::Node::XHeredoc(inner) => Node::from(inner),
            lib_ruby_parser::Node::Xstr(inner) => Node::from(inner),
            lib_ruby_parser::Node::Yield(inner) => Node::from(inner),
            lib_ruby_parser::Node::ZSuper(inner) => Node::from(inner),
        }
    }
}


impl From<lib_ruby_parser::nodes::Alias> for Node {
    fn from(node: lib_ruby_parser::nodes::Alias) -> Self {
        let node_type = NodeType_NODE_ALIAS;
        let to = ptr_value(Node::from(node.to));
        let from = ptr_value(Node::from(node.from));
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Alias { to, from, keyword_l, expression_l };
        let inner = ptr_value(InnerNode { _alias: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::AndAsgn> for Node {
    fn from(node: lib_ruby_parser::nodes::AndAsgn) -> Self {
        let node_type = NodeType_NODE_AND_ASGN;
        let recv = ptr_value(Node::from(node.recv));
        let value = ptr_value(Node::from(node.value));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = AndAsgn { recv, value, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _and_asgn: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::And> for Node {
    fn from(node: lib_ruby_parser::nodes::And) -> Self {
        let node_type = NodeType_NODE_AND;
        let lhs = ptr_value(Node::from(node.lhs));
        let rhs = ptr_value(Node::from(node.rhs));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = And { lhs, rhs, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _and: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Arg> for Node {
    fn from(node: lib_ruby_parser::nodes::Arg) -> Self {
        let node_type = NodeType_NODE_ARG;
        let name = StringPtr::from(node.name).unwrap();
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Arg { name, expression_l };
        let inner = ptr_value(InnerNode { _arg: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Args> for Node {
    fn from(node: lib_ruby_parser::nodes::Args) -> Self {
        let node_type = NodeType_NODE_ARGS;
        let args = ptr_value(NodeList::from(node.args));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let typed_node = Args { args, expression_l, begin_l, end_l };
        let inner = ptr_value(InnerNode { _args: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Array> for Node {
    fn from(node: lib_ruby_parser::nodes::Array) -> Self {
        let node_type = NodeType_NODE_ARRAY;
        let elements = ptr_value(NodeList::from(node.elements));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Array { elements, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _array: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::ArrayPattern> for Node {
    fn from(node: lib_ruby_parser::nodes::ArrayPattern) -> Self {
        let node_type = NodeType_NODE_ARRAY_PATTERN;
        let elements = ptr_value(NodeList::from(node.elements));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = ArrayPattern { elements, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _array_pattern: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::ArrayPatternWithTail> for Node {
    fn from(node: lib_ruby_parser::nodes::ArrayPatternWithTail) -> Self {
        let node_type = NodeType_NODE_ARRAY_PATTERN_WITH_TAIL;
        let elements = ptr_value(NodeList::from(node.elements));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = ArrayPatternWithTail { elements, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _array_pattern_with_tail: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::BackRef> for Node {
    fn from(node: lib_ruby_parser::nodes::BackRef) -> Self {
        let node_type = NodeType_NODE_BACK_REF;
        let name = StringPtr::from(node.name).unwrap();
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = BackRef { name, expression_l };
        let inner = ptr_value(InnerNode { _back_ref: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Begin> for Node {
    fn from(node: lib_ruby_parser::nodes::Begin) -> Self {
        let node_type = NodeType_NODE_BEGIN;
        let statements = ptr_value(NodeList::from(node.statements));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Begin { statements, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _begin: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Block> for Node {
    fn from(node: lib_ruby_parser::nodes::Block) -> Self {
        let node_type = NodeType_NODE_BLOCK;
        let call = ptr_value(Node::from(node.call));
        let args = if let Some(v) = node.args { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let begin_l = ptr_value(Range::from(node.begin_l));
        let end_l = ptr_value(Range::from(node.end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Block { call, args, body, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _block: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::BlockPass> for Node {
    fn from(node: lib_ruby_parser::nodes::BlockPass) -> Self {
        let node_type = NodeType_NODE_BLOCK_PASS;
        let value = ptr_value(Node::from(node.value));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = BlockPass { value, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _block_pass: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Blockarg> for Node {
    fn from(node: lib_ruby_parser::nodes::Blockarg) -> Self {
        let node_type = NodeType_NODE_BLOCKARG;
        let name = StringPtr::from(node.name).unwrap();
        let operator_l = ptr_value(Range::from(node.operator_l));
        let name_l = ptr_value(Range::from(node.name_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Blockarg { name, operator_l, name_l, expression_l };
        let inner = ptr_value(InnerNode { _blockarg: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Break> for Node {
    fn from(node: lib_ruby_parser::nodes::Break) -> Self {
        let node_type = NodeType_NODE_BREAK_;
        let args = ptr_value(NodeList::from(node.args));
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Break { args, keyword_l, expression_l };
        let inner = ptr_value(InnerNode { _break_: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Case> for Node {
    fn from(node: lib_ruby_parser::nodes::Case) -> Self {
        let node_type = NodeType_NODE_CASE;
        let expr = if let Some(v) = node.expr { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let when_bodies = ptr_value(NodeList::from(node.when_bodies));
        let else_body = if let Some(v) = node.else_body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let else_l = if let Some(v) = node.else_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = ptr_value(Range::from(node.end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Case { expr, when_bodies, else_body, keyword_l, else_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _case: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::CaseMatch> for Node {
    fn from(node: lib_ruby_parser::nodes::CaseMatch) -> Self {
        let node_type = NodeType_NODE_CASE_MATCH;
        let expr = ptr_value(Node::from(node.expr));
        let in_bodies = ptr_value(NodeList::from(node.in_bodies));
        let else_body = if let Some(v) = node.else_body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let else_l = if let Some(v) = node.else_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = ptr_value(Range::from(node.end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = CaseMatch { expr, in_bodies, else_body, keyword_l, else_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _case_match: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Casgn> for Node {
    fn from(node: lib_ruby_parser::nodes::Casgn) -> Self {
        let node_type = NodeType_NODE_CASGN;
        let scope = if let Some(v) = node.scope { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let name = StringPtr::from(node.name).unwrap();
        let value = if let Some(v) = node.value { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let double_colon_l = if let Some(v) = node.double_colon_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let name_l = ptr_value(Range::from(node.name_l));
        let operator_l = if let Some(v) = node.operator_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Casgn { scope, name, value, double_colon_l, name_l, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _casgn: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Cbase> for Node {
    fn from(node: lib_ruby_parser::nodes::Cbase) -> Self {
        let node_type = NodeType_NODE_CBASE;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Cbase { expression_l };
        let inner = ptr_value(InnerNode { _cbase: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Class> for Node {
    fn from(node: lib_ruby_parser::nodes::Class) -> Self {
        let node_type = NodeType_NODE_CLASS;
        let name = ptr_value(Node::from(node.name));
        let superclass = if let Some(v) = node.superclass { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let operator_l = if let Some(v) = node.operator_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = ptr_value(Range::from(node.end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Class { name, superclass, body, keyword_l, operator_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _class: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Complex> for Node {
    fn from(node: lib_ruby_parser::nodes::Complex) -> Self {
        let node_type = NodeType_NODE_COMPLEX;
        let value = StringPtr::from(node.value).unwrap();
        let operator_l = if let Some(v) = node.operator_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Complex { value, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _complex: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Const> for Node {
    fn from(node: lib_ruby_parser::nodes::Const) -> Self {
        let node_type = NodeType_NODE_CONST_;
        let scope = if let Some(v) = node.scope { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let name = StringPtr::from(node.name).unwrap();
        let double_colon_l = if let Some(v) = node.double_colon_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let name_l = ptr_value(Range::from(node.name_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Const { scope, name, double_colon_l, name_l, expression_l };
        let inner = ptr_value(InnerNode { _const_: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::ConstPattern> for Node {
    fn from(node: lib_ruby_parser::nodes::ConstPattern) -> Self {
        let node_type = NodeType_NODE_CONST_PATTERN;
        let const_ = ptr_value(Node::from(node.const_));
        let pattern = ptr_value(Node::from(node.pattern));
        let begin_l = ptr_value(Range::from(node.begin_l));
        let end_l = ptr_value(Range::from(node.end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = ConstPattern { const_, pattern, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _const_pattern: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::CSend> for Node {
    fn from(node: lib_ruby_parser::nodes::CSend) -> Self {
        let node_type = NodeType_NODE_CSEND;
        let recv = ptr_value(Node::from(node.recv));
        let method_name = StringPtr::from(node.method_name).unwrap();
        let args = ptr_value(NodeList::from(node.args));
        let dot_l = ptr_value(Range::from(node.dot_l));
        let selector_l = ptr_value(Range::from(node.selector_l));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let operator_l = if let Some(v) = node.operator_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = CSend { recv, method_name, args, dot_l, selector_l, begin_l, end_l, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _csend: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Cvar> for Node {
    fn from(node: lib_ruby_parser::nodes::Cvar) -> Self {
        let node_type = NodeType_NODE_CVAR;
        let name = StringPtr::from(node.name).unwrap();
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Cvar { name, expression_l };
        let inner = ptr_value(InnerNode { _cvar: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Cvasgn> for Node {
    fn from(node: lib_ruby_parser::nodes::Cvasgn) -> Self {
        let node_type = NodeType_NODE_CVASGN;
        let name = StringPtr::from(node.name).unwrap();
        let value = if let Some(v) = node.value { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let name_l = ptr_value(Range::from(node.name_l));
        let operator_l = if let Some(v) = node.operator_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Cvasgn { name, value, name_l, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _cvasgn: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Def> for Node {
    fn from(node: lib_ruby_parser::nodes::Def) -> Self {
        let node_type = NodeType_NODE_DEF;
        let name = StringPtr::from(node.name).unwrap();
        let args = if let Some(v) = node.args { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let name_l = ptr_value(Range::from(node.name_l));
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let assignment_l = if let Some(v) = node.assignment_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Def { name, args, body, keyword_l, name_l, end_l, assignment_l, expression_l };
        let inner = ptr_value(InnerNode { _def: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Defined> for Node {
    fn from(node: lib_ruby_parser::nodes::Defined) -> Self {
        let node_type = NodeType_NODE_DEFINED;
        let value = ptr_value(Node::from(node.value));
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Defined { value, keyword_l, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _defined: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Defs> for Node {
    fn from(node: lib_ruby_parser::nodes::Defs) -> Self {
        let node_type = NodeType_NODE_DEFS;
        let definee = ptr_value(Node::from(node.definee));
        let name = StringPtr::from(node.name).unwrap();
        let args = if let Some(v) = node.args { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let name_l = ptr_value(Range::from(node.name_l));
        let assignment_l = if let Some(v) = node.assignment_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Defs { definee, name, args, body, keyword_l, operator_l, name_l, assignment_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _defs: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Dstr> for Node {
    fn from(node: lib_ruby_parser::nodes::Dstr) -> Self {
        let node_type = NodeType_NODE_DSTR;
        let parts = ptr_value(NodeList::from(node.parts));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Dstr { parts, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _dstr: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Dsym> for Node {
    fn from(node: lib_ruby_parser::nodes::Dsym) -> Self {
        let node_type = NodeType_NODE_DSYM;
        let parts = ptr_value(NodeList::from(node.parts));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Dsym { parts, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _dsym: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::EFlipFlop> for Node {
    fn from(node: lib_ruby_parser::nodes::EFlipFlop) -> Self {
        let node_type = NodeType_NODE_EFLIPFLOP;
        let left = if let Some(v) = node.left { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let right = if let Some(v) = node.right { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = EFlipFlop { left, right, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _eflipflop: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::EmptyElse> for Node {
    fn from(node: lib_ruby_parser::nodes::EmptyElse) -> Self {
        let node_type = NodeType_NODE_EMPTY_ELSE;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = EmptyElse { expression_l };
        let inner = ptr_value(InnerNode { _empty_else: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Encoding> for Node {
    fn from(node: lib_ruby_parser::nodes::Encoding) -> Self {
        let node_type = NodeType_NODE_ENCODING_;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Encoding { expression_l };
        let inner = ptr_value(InnerNode { _encoding_: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Ensure> for Node {
    fn from(node: lib_ruby_parser::nodes::Ensure) -> Self {
        let node_type = NodeType_NODE_ENSURE;
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let ensure = if let Some(v) = node.ensure { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Ensure { body, ensure, keyword_l, expression_l };
        let inner = ptr_value(InnerNode { _ensure: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Erange> for Node {
    fn from(node: lib_ruby_parser::nodes::Erange) -> Self {
        let node_type = NodeType_NODE_ERANGE;
        let left = if let Some(v) = node.left { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let right = if let Some(v) = node.right { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Erange { left, right, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _erange: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::False> for Node {
    fn from(node: lib_ruby_parser::nodes::False) -> Self {
        let node_type = NodeType_NODE_FALSE_;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = False { expression_l };
        let inner = ptr_value(InnerNode { _false_: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::File> for Node {
    fn from(node: lib_ruby_parser::nodes::File) -> Self {
        let node_type = NodeType_NODE_FILE;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = File { expression_l };
        let inner = ptr_value(InnerNode { _file: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::FindPattern> for Node {
    fn from(node: lib_ruby_parser::nodes::FindPattern) -> Self {
        let node_type = NodeType_NODE_FIND_PATTERN;
        let elements = ptr_value(NodeList::from(node.elements));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = FindPattern { elements, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _find_pattern: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Float> for Node {
    fn from(node: lib_ruby_parser::nodes::Float) -> Self {
        let node_type = NodeType_NODE_FLOAT;
        let value = StringPtr::from(node.value).unwrap();
        let operator_l = if let Some(v) = node.operator_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Float { value, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _float: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::For> for Node {
    fn from(node: lib_ruby_parser::nodes::For) -> Self {
        let node_type = NodeType_NODE_FOR_;
        let iterator = ptr_value(Node::from(node.iterator));
        let iteratee = ptr_value(Node::from(node.iteratee));
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let begin_l = ptr_value(Range::from(node.begin_l));
        let end_l = ptr_value(Range::from(node.end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = For { iterator, iteratee, body, keyword_l, operator_l, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _for_: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::ForwardArg> for Node {
    fn from(node: lib_ruby_parser::nodes::ForwardArg) -> Self {
        let node_type = NodeType_NODE_FORWARD_ARG;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = ForwardArg { expression_l };
        let inner = ptr_value(InnerNode { _forward_arg: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::ForwardedArgs> for Node {
    fn from(node: lib_ruby_parser::nodes::ForwardedArgs) -> Self {
        let node_type = NodeType_NODE_FORWARDED_ARGS;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = ForwardedArgs { expression_l };
        let inner = ptr_value(InnerNode { _forwarded_args: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Gvar> for Node {
    fn from(node: lib_ruby_parser::nodes::Gvar) -> Self {
        let node_type = NodeType_NODE_GVAR;
        let name = StringPtr::from(node.name).unwrap();
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Gvar { name, expression_l };
        let inner = ptr_value(InnerNode { _gvar: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Gvasgn> for Node {
    fn from(node: lib_ruby_parser::nodes::Gvasgn) -> Self {
        let node_type = NodeType_NODE_GVASGN;
        let name = StringPtr::from(node.name).unwrap();
        let value = if let Some(v) = node.value { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let name_l = ptr_value(Range::from(node.name_l));
        let operator_l = if let Some(v) = node.operator_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Gvasgn { name, value, name_l, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _gvasgn: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Hash> for Node {
    fn from(node: lib_ruby_parser::nodes::Hash) -> Self {
        let node_type = NodeType_NODE_HASH;
        let pairs = ptr_value(NodeList::from(node.pairs));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Hash { pairs, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _hash: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Kwargs> for Node {
    fn from(node: lib_ruby_parser::nodes::Kwargs) -> Self {
        let node_type = NodeType_NODE_KWARGS;
        let pairs = ptr_value(NodeList::from(node.pairs));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Kwargs { pairs, expression_l };
        let inner = ptr_value(InnerNode { _kwargs: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::HashPattern> for Node {
    fn from(node: lib_ruby_parser::nodes::HashPattern) -> Self {
        let node_type = NodeType_NODE_HASH_PATTERN;
        let elements = ptr_value(NodeList::from(node.elements));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = HashPattern { elements, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _hash_pattern: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Heredoc> for Node {
    fn from(node: lib_ruby_parser::nodes::Heredoc) -> Self {
        let node_type = NodeType_NODE_HEREDOC;
        let parts = ptr_value(NodeList::from(node.parts));
        let heredoc_body_l = ptr_value(Range::from(node.heredoc_body_l));
        let heredoc_end_l = ptr_value(Range::from(node.heredoc_end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Heredoc { parts, heredoc_body_l, heredoc_end_l, expression_l };
        let inner = ptr_value(InnerNode { _heredoc: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::If> for Node {
    fn from(node: lib_ruby_parser::nodes::If) -> Self {
        let node_type = NodeType_NODE_IF_;
        let cond = ptr_value(Node::from(node.cond));
        let if_true = if let Some(v) = node.if_true { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let if_false = if let Some(v) = node.if_false { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let begin_l = ptr_value(Range::from(node.begin_l));
        let else_l = if let Some(v) = node.else_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = If { cond, if_true, if_false, keyword_l, begin_l, else_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _if_: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::IfGuard> for Node {
    fn from(node: lib_ruby_parser::nodes::IfGuard) -> Self {
        let node_type = NodeType_NODE_IF_GUARD;
        let cond = ptr_value(Node::from(node.cond));
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = IfGuard { cond, keyword_l, expression_l };
        let inner = ptr_value(InnerNode { _if_guard: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::IfMod> for Node {
    fn from(node: lib_ruby_parser::nodes::IfMod) -> Self {
        let node_type = NodeType_NODE_IF_MOD;
        let cond = ptr_value(Node::from(node.cond));
        let if_true = if let Some(v) = node.if_true { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let if_false = if let Some(v) = node.if_false { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = IfMod { cond, if_true, if_false, keyword_l, expression_l };
        let inner = ptr_value(InnerNode { _if_mod: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::IfTernary> for Node {
    fn from(node: lib_ruby_parser::nodes::IfTernary) -> Self {
        let node_type = NodeType_NODE_IF_TERNARY;
        let cond = ptr_value(Node::from(node.cond));
        let if_true = ptr_value(Node::from(node.if_true));
        let if_false = ptr_value(Node::from(node.if_false));
        let question_l = ptr_value(Range::from(node.question_l));
        let colon_l = ptr_value(Range::from(node.colon_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = IfTernary { cond, if_true, if_false, question_l, colon_l, expression_l };
        let inner = ptr_value(InnerNode { _if_ternary: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::IFlipFlop> for Node {
    fn from(node: lib_ruby_parser::nodes::IFlipFlop) -> Self {
        let node_type = NodeType_NODE_IFLIPFLOP;
        let left = if let Some(v) = node.left { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let right = if let Some(v) = node.right { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = IFlipFlop { left, right, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _iflipflop: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::MatchPattern> for Node {
    fn from(node: lib_ruby_parser::nodes::MatchPattern) -> Self {
        let node_type = NodeType_NODE_MATCH_PATTERN;
        let value = ptr_value(Node::from(node.value));
        let pattern = ptr_value(Node::from(node.pattern));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = MatchPattern { value, pattern, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _match_pattern: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::MatchPatternP> for Node {
    fn from(node: lib_ruby_parser::nodes::MatchPatternP) -> Self {
        let node_type = NodeType_NODE_MATCH_PATTERN_P;
        let value = ptr_value(Node::from(node.value));
        let pattern = ptr_value(Node::from(node.pattern));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = MatchPatternP { value, pattern, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _match_pattern_p: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::InPattern> for Node {
    fn from(node: lib_ruby_parser::nodes::InPattern) -> Self {
        let node_type = NodeType_NODE_IN_PATTERN;
        let pattern = ptr_value(Node::from(node.pattern));
        let guard = if let Some(v) = node.guard { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let begin_l = ptr_value(Range::from(node.begin_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = InPattern { pattern, guard, body, keyword_l, begin_l, expression_l };
        let inner = ptr_value(InnerNode { _in_pattern: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Index> for Node {
    fn from(node: lib_ruby_parser::nodes::Index) -> Self {
        let node_type = NodeType_NODE_INDEX;
        let recv = ptr_value(Node::from(node.recv));
        let indexes = ptr_value(NodeList::from(node.indexes));
        let begin_l = ptr_value(Range::from(node.begin_l));
        let end_l = ptr_value(Range::from(node.end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Index { recv, indexes, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _index: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::IndexAsgn> for Node {
    fn from(node: lib_ruby_parser::nodes::IndexAsgn) -> Self {
        let node_type = NodeType_NODE_INDEX_ASGN;
        let recv = ptr_value(Node::from(node.recv));
        let indexes = ptr_value(NodeList::from(node.indexes));
        let value = if let Some(v) = node.value { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let begin_l = ptr_value(Range::from(node.begin_l));
        let end_l = ptr_value(Range::from(node.end_l));
        let operator_l = if let Some(v) = node.operator_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = IndexAsgn { recv, indexes, value, begin_l, end_l, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _index_asgn: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Int> for Node {
    fn from(node: lib_ruby_parser::nodes::Int) -> Self {
        let node_type = NodeType_NODE_INT;
        let value = StringPtr::from(node.value).unwrap();
        let operator_l = if let Some(v) = node.operator_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Int { value, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _int: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Irange> for Node {
    fn from(node: lib_ruby_parser::nodes::Irange) -> Self {
        let node_type = NodeType_NODE_IRANGE;
        let left = if let Some(v) = node.left { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let right = if let Some(v) = node.right { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Irange { left, right, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _irange: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Ivar> for Node {
    fn from(node: lib_ruby_parser::nodes::Ivar) -> Self {
        let node_type = NodeType_NODE_IVAR;
        let name = StringPtr::from(node.name).unwrap();
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Ivar { name, expression_l };
        let inner = ptr_value(InnerNode { _ivar: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Ivasgn> for Node {
    fn from(node: lib_ruby_parser::nodes::Ivasgn) -> Self {
        let node_type = NodeType_NODE_IVASGN;
        let name = StringPtr::from(node.name).unwrap();
        let value = if let Some(v) = node.value { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let name_l = ptr_value(Range::from(node.name_l));
        let operator_l = if let Some(v) = node.operator_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Ivasgn { name, value, name_l, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _ivasgn: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Kwarg> for Node {
    fn from(node: lib_ruby_parser::nodes::Kwarg) -> Self {
        let node_type = NodeType_NODE_KWARG;
        let name = StringPtr::from(node.name).unwrap();
        let name_l = ptr_value(Range::from(node.name_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Kwarg { name, name_l, expression_l };
        let inner = ptr_value(InnerNode { _kwarg: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::KwBegin> for Node {
    fn from(node: lib_ruby_parser::nodes::KwBegin) -> Self {
        let node_type = NodeType_NODE_KWBEGIN;
        let statements = ptr_value(NodeList::from(node.statements));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = KwBegin { statements, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _kwbegin: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Kwnilarg> for Node {
    fn from(node: lib_ruby_parser::nodes::Kwnilarg) -> Self {
        let node_type = NodeType_NODE_KWNILARG;
        let name_l = ptr_value(Range::from(node.name_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Kwnilarg { name_l, expression_l };
        let inner = ptr_value(InnerNode { _kwnilarg: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Kwoptarg> for Node {
    fn from(node: lib_ruby_parser::nodes::Kwoptarg) -> Self {
        let node_type = NodeType_NODE_KWOPTARG;
        let name = StringPtr::from(node.name).unwrap();
        let default_ = ptr_value(Node::from(node.default));
        let name_l = ptr_value(Range::from(node.name_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Kwoptarg { name, default_, name_l, expression_l };
        let inner = ptr_value(InnerNode { _kwoptarg: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Kwrestarg> for Node {
    fn from(node: lib_ruby_parser::nodes::Kwrestarg) -> Self {
        let node_type = NodeType_NODE_KWRESTARG;
        let name = StringPtr::from(node.name).unwrap();
        let operator_l = ptr_value(Range::from(node.operator_l));
        let name_l = if let Some(v) = node.name_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Kwrestarg { name, operator_l, name_l, expression_l };
        let inner = ptr_value(InnerNode { _kwrestarg: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Kwsplat> for Node {
    fn from(node: lib_ruby_parser::nodes::Kwsplat) -> Self {
        let node_type = NodeType_NODE_KWSPLAT;
        let value = ptr_value(Node::from(node.value));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Kwsplat { value, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _kwsplat: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Lambda> for Node {
    fn from(node: lib_ruby_parser::nodes::Lambda) -> Self {
        let node_type = NodeType_NODE_LAMBDA;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Lambda { expression_l };
        let inner = ptr_value(InnerNode { _lambda: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Line> for Node {
    fn from(node: lib_ruby_parser::nodes::Line) -> Self {
        let node_type = NodeType_NODE_LINE;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Line { expression_l };
        let inner = ptr_value(InnerNode { _line: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Lvar> for Node {
    fn from(node: lib_ruby_parser::nodes::Lvar) -> Self {
        let node_type = NodeType_NODE_LVAR;
        let name = StringPtr::from(node.name).unwrap();
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Lvar { name, expression_l };
        let inner = ptr_value(InnerNode { _lvar: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Lvasgn> for Node {
    fn from(node: lib_ruby_parser::nodes::Lvasgn) -> Self {
        let node_type = NodeType_NODE_LVASGN;
        let name = StringPtr::from(node.name).unwrap();
        let value = if let Some(v) = node.value { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let name_l = ptr_value(Range::from(node.name_l));
        let operator_l = if let Some(v) = node.operator_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Lvasgn { name, value, name_l, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _lvasgn: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Masgn> for Node {
    fn from(node: lib_ruby_parser::nodes::Masgn) -> Self {
        let node_type = NodeType_NODE_MASGN;
        let lhs = ptr_value(Node::from(node.lhs));
        let rhs = ptr_value(Node::from(node.rhs));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Masgn { lhs, rhs, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _masgn: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::MatchAlt> for Node {
    fn from(node: lib_ruby_parser::nodes::MatchAlt) -> Self {
        let node_type = NodeType_NODE_MATCH_ALT;
        let lhs = ptr_value(Node::from(node.lhs));
        let rhs = ptr_value(Node::from(node.rhs));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = MatchAlt { lhs, rhs, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _match_alt: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::MatchAs> for Node {
    fn from(node: lib_ruby_parser::nodes::MatchAs) -> Self {
        let node_type = NodeType_NODE_MATCH_AS;
        let value = ptr_value(Node::from(node.value));
        let as_ = ptr_value(Node::from(node.as_));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = MatchAs { value, as_, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _match_as: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::MatchCurrentLine> for Node {
    fn from(node: lib_ruby_parser::nodes::MatchCurrentLine) -> Self {
        let node_type = NodeType_NODE_MATCH_CURRENT_LINE;
        let re = ptr_value(Node::from(node.re));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = MatchCurrentLine { re, expression_l };
        let inner = ptr_value(InnerNode { _match_current_line: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::MatchNilPattern> for Node {
    fn from(node: lib_ruby_parser::nodes::MatchNilPattern) -> Self {
        let node_type = NodeType_NODE_MATCH_NIL_PATTERN;
        let operator_l = ptr_value(Range::from(node.operator_l));
        let name_l = ptr_value(Range::from(node.name_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = MatchNilPattern { operator_l, name_l, expression_l };
        let inner = ptr_value(InnerNode { _match_nil_pattern: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::MatchRest> for Node {
    fn from(node: lib_ruby_parser::nodes::MatchRest) -> Self {
        let node_type = NodeType_NODE_MATCH_REST;
        let name = if let Some(v) = node.name { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = MatchRest { name, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _match_rest: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::MatchVar> for Node {
    fn from(node: lib_ruby_parser::nodes::MatchVar) -> Self {
        let node_type = NodeType_NODE_MATCH_VAR;
        let name = StringPtr::from(node.name).unwrap();
        let name_l = ptr_value(Range::from(node.name_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = MatchVar { name, name_l, expression_l };
        let inner = ptr_value(InnerNode { _match_var: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::MatchWithLvasgn> for Node {
    fn from(node: lib_ruby_parser::nodes::MatchWithLvasgn) -> Self {
        let node_type = NodeType_NODE_MATCH_WITH_LVASGN;
        let re = ptr_value(Node::from(node.re));
        let value = ptr_value(Node::from(node.value));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = MatchWithLvasgn { re, value, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _match_with_lvasgn: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Mlhs> for Node {
    fn from(node: lib_ruby_parser::nodes::Mlhs) -> Self {
        let node_type = NodeType_NODE_MLHS;
        let items = ptr_value(NodeList::from(node.items));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Mlhs { items, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _mlhs: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Module> for Node {
    fn from(node: lib_ruby_parser::nodes::Module) -> Self {
        let node_type = NodeType_NODE_MODULE;
        let name = ptr_value(Node::from(node.name));
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let end_l = ptr_value(Range::from(node.end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Module { name, body, keyword_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _module: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Next> for Node {
    fn from(node: lib_ruby_parser::nodes::Next) -> Self {
        let node_type = NodeType_NODE_NEXT;
        let args = ptr_value(NodeList::from(node.args));
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Next { args, keyword_l, expression_l };
        let inner = ptr_value(InnerNode { _next: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Nil> for Node {
    fn from(node: lib_ruby_parser::nodes::Nil) -> Self {
        let node_type = NodeType_NODE_NIL;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Nil { expression_l };
        let inner = ptr_value(InnerNode { _nil: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::NthRef> for Node {
    fn from(node: lib_ruby_parser::nodes::NthRef) -> Self {
        let node_type = NodeType_NODE_NTH_REF;
        let name = StringPtr::from(node.name).unwrap();
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = NthRef { name, expression_l };
        let inner = ptr_value(InnerNode { _nth_ref: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Numblock> for Node {
    fn from(node: lib_ruby_parser::nodes::Numblock) -> Self {
        let node_type = NodeType_NODE_NUMBLOCK;
        let call = ptr_value(Node::from(node.call));
        let numargs = node.numargs as u32;
        let body = ptr_value(Node::from(node.body));
        let begin_l = ptr_value(Range::from(node.begin_l));
        let end_l = ptr_value(Range::from(node.end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Numblock { call, numargs, body, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _numblock: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::OpAsgn> for Node {
    fn from(node: lib_ruby_parser::nodes::OpAsgn) -> Self {
        let node_type = NodeType_NODE_OP_ASGN;
        let recv = ptr_value(Node::from(node.recv));
        let operator = StringPtr::from(node.operator).unwrap();
        let value = ptr_value(Node::from(node.value));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = OpAsgn { recv, operator, value, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _op_asgn: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Optarg> for Node {
    fn from(node: lib_ruby_parser::nodes::Optarg) -> Self {
        let node_type = NodeType_NODE_OPTARG;
        let name = StringPtr::from(node.name).unwrap();
        let default_ = ptr_value(Node::from(node.default));
        let name_l = ptr_value(Range::from(node.name_l));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Optarg { name, default_, name_l, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _optarg: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Or> for Node {
    fn from(node: lib_ruby_parser::nodes::Or) -> Self {
        let node_type = NodeType_NODE_OR;
        let lhs = ptr_value(Node::from(node.lhs));
        let rhs = ptr_value(Node::from(node.rhs));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Or { lhs, rhs, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _or: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::OrAsgn> for Node {
    fn from(node: lib_ruby_parser::nodes::OrAsgn) -> Self {
        let node_type = NodeType_NODE_OR_ASGN;
        let recv = ptr_value(Node::from(node.recv));
        let value = ptr_value(Node::from(node.value));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = OrAsgn { recv, value, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _or_asgn: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Pair> for Node {
    fn from(node: lib_ruby_parser::nodes::Pair) -> Self {
        let node_type = NodeType_NODE_PAIR;
        let key = ptr_value(Node::from(node.key));
        let value = ptr_value(Node::from(node.value));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Pair { key, value, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _pair: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Pin> for Node {
    fn from(node: lib_ruby_parser::nodes::Pin) -> Self {
        let node_type = NodeType_NODE_PIN;
        let var = ptr_value(Node::from(node.var));
        let selector_l = ptr_value(Range::from(node.selector_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Pin { var, selector_l, expression_l };
        let inner = ptr_value(InnerNode { _pin: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Postexe> for Node {
    fn from(node: lib_ruby_parser::nodes::Postexe) -> Self {
        let node_type = NodeType_NODE_POSTEXE;
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let begin_l = ptr_value(Range::from(node.begin_l));
        let end_l = ptr_value(Range::from(node.end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Postexe { body, keyword_l, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _postexe: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Preexe> for Node {
    fn from(node: lib_ruby_parser::nodes::Preexe) -> Self {
        let node_type = NodeType_NODE_PREEXE;
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let begin_l = ptr_value(Range::from(node.begin_l));
        let end_l = ptr_value(Range::from(node.end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Preexe { body, keyword_l, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _preexe: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Procarg0> for Node {
    fn from(node: lib_ruby_parser::nodes::Procarg0) -> Self {
        let node_type = NodeType_NODE_PROCARG0;
        let args = ptr_value(NodeList::from(node.args));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Procarg0 { args, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _procarg0: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Rational> for Node {
    fn from(node: lib_ruby_parser::nodes::Rational) -> Self {
        let node_type = NodeType_NODE_RATIONAL;
        let value = StringPtr::from(node.value).unwrap();
        let operator_l = if let Some(v) = node.operator_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Rational { value, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _rational: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Redo> for Node {
    fn from(node: lib_ruby_parser::nodes::Redo) -> Self {
        let node_type = NodeType_NODE_REDO;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Redo { expression_l };
        let inner = ptr_value(InnerNode { _redo: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::RegOpt> for Node {
    fn from(node: lib_ruby_parser::nodes::RegOpt) -> Self {
        let node_type = NodeType_NODE_REG_OPT;
        let options = StringPtr::from(node.options).unwrap();
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = RegOpt { options, expression_l };
        let inner = ptr_value(InnerNode { _reg_opt: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Regexp> for Node {
    fn from(node: lib_ruby_parser::nodes::Regexp) -> Self {
        let node_type = NodeType_NODE_REGEXP;
        let parts = ptr_value(NodeList::from(node.parts));
        let options = if let Some(v) = node.options { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let begin_l = ptr_value(Range::from(node.begin_l));
        let end_l = ptr_value(Range::from(node.end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Regexp { parts, options, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _regexp: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Rescue> for Node {
    fn from(node: lib_ruby_parser::nodes::Rescue) -> Self {
        let node_type = NodeType_NODE_RESCUE;
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let rescue_bodies = ptr_value(NodeList::from(node.rescue_bodies));
        let else_ = if let Some(v) = node.else_ { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let else_l = if let Some(v) = node.else_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Rescue { body, rescue_bodies, else_, else_l, expression_l };
        let inner = ptr_value(InnerNode { _rescue: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::RescueBody> for Node {
    fn from(node: lib_ruby_parser::nodes::RescueBody) -> Self {
        let node_type = NodeType_NODE_RESCUE_BODY;
        let exc_list = if let Some(v) = node.exc_list { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let exc_var = if let Some(v) = node.exc_var { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let assoc_l = if let Some(v) = node.assoc_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = RescueBody { exc_list, exc_var, body, keyword_l, assoc_l, begin_l, expression_l };
        let inner = ptr_value(InnerNode { _rescue_body: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Restarg> for Node {
    fn from(node: lib_ruby_parser::nodes::Restarg) -> Self {
        let node_type = NodeType_NODE_RESTARG;
        let name = StringPtr::from(node.name).unwrap();
        let operator_l = ptr_value(Range::from(node.operator_l));
        let name_l = if let Some(v) = node.name_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Restarg { name, operator_l, name_l, expression_l };
        let inner = ptr_value(InnerNode { _restarg: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Retry> for Node {
    fn from(node: lib_ruby_parser::nodes::Retry) -> Self {
        let node_type = NodeType_NODE_RETRY;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Retry { expression_l };
        let inner = ptr_value(InnerNode { _retry: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Return> for Node {
    fn from(node: lib_ruby_parser::nodes::Return) -> Self {
        let node_type = NodeType_NODE_RETURN_;
        let args = ptr_value(NodeList::from(node.args));
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Return { args, keyword_l, expression_l };
        let inner = ptr_value(InnerNode { _return_: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::SClass> for Node {
    fn from(node: lib_ruby_parser::nodes::SClass) -> Self {
        let node_type = NodeType_NODE_SCLASS;
        let expr = ptr_value(Node::from(node.expr));
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let operator_l = ptr_value(Range::from(node.operator_l));
        let end_l = ptr_value(Range::from(node.end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = SClass { expr, body, keyword_l, operator_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _sclass: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Self_> for Node {
    fn from(node: lib_ruby_parser::nodes::Self_) -> Self {
        let node_type = NodeType_NODE_SELF_;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Self_ { expression_l };
        let inner = ptr_value(InnerNode { _self_: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Send> for Node {
    fn from(node: lib_ruby_parser::nodes::Send) -> Self {
        let node_type = NodeType_NODE_SEND;
        let recv = if let Some(v) = node.recv { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let method_name = StringPtr::from(node.method_name).unwrap();
        let args = ptr_value(NodeList::from(node.args));
        let dot_l = if let Some(v) = node.dot_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let selector_l = if let Some(v) = node.selector_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let operator_l = if let Some(v) = node.operator_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Send { recv, method_name, args, dot_l, selector_l, begin_l, end_l, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _send: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Shadowarg> for Node {
    fn from(node: lib_ruby_parser::nodes::Shadowarg) -> Self {
        let node_type = NodeType_NODE_SHADOWARG;
        let name = StringPtr::from(node.name).unwrap();
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Shadowarg { name, expression_l };
        let inner = ptr_value(InnerNode { _shadowarg: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Splat> for Node {
    fn from(node: lib_ruby_parser::nodes::Splat) -> Self {
        let node_type = NodeType_NODE_SPLAT;
        let value = if let Some(v) = node.value { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let operator_l = ptr_value(Range::from(node.operator_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Splat { value, operator_l, expression_l };
        let inner = ptr_value(InnerNode { _splat: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Str> for Node {
    fn from(node: lib_ruby_parser::nodes::Str) -> Self {
        let node_type = NodeType_NODE_STR_;
        let value = StringPtr::from(node.value).unwrap();
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Str { value, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _str_: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Super> for Node {
    fn from(node: lib_ruby_parser::nodes::Super) -> Self {
        let node_type = NodeType_NODE_SUPER_;
        let args = ptr_value(NodeList::from(node.args));
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Super { args, keyword_l, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _super_: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Sym> for Node {
    fn from(node: lib_ruby_parser::nodes::Sym) -> Self {
        let node_type = NodeType_NODE_SYM;
        let name = StringPtr::from(node.name).unwrap();
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Sym { name, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _sym: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::True> for Node {
    fn from(node: lib_ruby_parser::nodes::True) -> Self {
        let node_type = NodeType_NODE_TRUE_;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = True { expression_l };
        let inner = ptr_value(InnerNode { _true_: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Undef> for Node {
    fn from(node: lib_ruby_parser::nodes::Undef) -> Self {
        let node_type = NodeType_NODE_UNDEF;
        let names = ptr_value(NodeList::from(node.names));
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Undef { names, keyword_l, expression_l };
        let inner = ptr_value(InnerNode { _undef: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::UnlessGuard> for Node {
    fn from(node: lib_ruby_parser::nodes::UnlessGuard) -> Self {
        let node_type = NodeType_NODE_UNLESS_GUARD;
        let cond = ptr_value(Node::from(node.cond));
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = UnlessGuard { cond, keyword_l, expression_l };
        let inner = ptr_value(InnerNode { _unless_guard: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Until> for Node {
    fn from(node: lib_ruby_parser::nodes::Until) -> Self {
        let node_type = NodeType_NODE_UNTIL;
        let cond = ptr_value(Node::from(node.cond));
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Until { cond, body, keyword_l, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _until: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::UntilPost> for Node {
    fn from(node: lib_ruby_parser::nodes::UntilPost) -> Self {
        let node_type = NodeType_NODE_UNTIL_POST;
        let cond = ptr_value(Node::from(node.cond));
        let body = ptr_value(Node::from(node.body));
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = UntilPost { cond, body, keyword_l, expression_l };
        let inner = ptr_value(InnerNode { _until_post: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::When> for Node {
    fn from(node: lib_ruby_parser::nodes::When) -> Self {
        let node_type = NodeType_NODE_WHEN;
        let patterns = ptr_value(NodeList::from(node.patterns));
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let begin_l = ptr_value(Range::from(node.begin_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = When { patterns, body, keyword_l, begin_l, expression_l };
        let inner = ptr_value(InnerNode { _when: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::While> for Node {
    fn from(node: lib_ruby_parser::nodes::While) -> Self {
        let node_type = NodeType_NODE_WHILE_;
        let cond = ptr_value(Node::from(node.cond));
        let body = if let Some(v) = node.body { ptr_value(Node::from(v)) } else { std::ptr::null_mut() };
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = While { cond, body, keyword_l, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _while_: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::WhilePost> for Node {
    fn from(node: lib_ruby_parser::nodes::WhilePost) -> Self {
        let node_type = NodeType_NODE_WHILE_POST;
        let cond = ptr_value(Node::from(node.cond));
        let body = ptr_value(Node::from(node.body));
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = WhilePost { cond, body, keyword_l, expression_l };
        let inner = ptr_value(InnerNode { _while_post: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::XHeredoc> for Node {
    fn from(node: lib_ruby_parser::nodes::XHeredoc) -> Self {
        let node_type = NodeType_NODE_X_HEREDOC;
        let parts = ptr_value(NodeList::from(node.parts));
        let heredoc_body_l = ptr_value(Range::from(node.heredoc_body_l));
        let heredoc_end_l = ptr_value(Range::from(node.heredoc_end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = XHeredoc { parts, heredoc_body_l, heredoc_end_l, expression_l };
        let inner = ptr_value(InnerNode { _x_heredoc: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Xstr> for Node {
    fn from(node: lib_ruby_parser::nodes::Xstr) -> Self {
        let node_type = NodeType_NODE_XSTR;
        let parts = ptr_value(NodeList::from(node.parts));
        let begin_l = ptr_value(Range::from(node.begin_l));
        let end_l = ptr_value(Range::from(node.end_l));
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Xstr { parts, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _xstr: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::Yield> for Node {
    fn from(node: lib_ruby_parser::nodes::Yield) -> Self {
        let node_type = NodeType_NODE_YIELD_;
        let args = ptr_value(NodeList::from(node.args));
        let keyword_l = ptr_value(Range::from(node.keyword_l));
        let begin_l = if let Some(v) = node.begin_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let end_l = if let Some(v) = node.end_l { ptr_value(Range::from(v)) } else { std::ptr::null_mut() };
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = Yield { args, keyword_l, begin_l, end_l, expression_l };
        let inner = ptr_value(InnerNode { _yield_: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl From<lib_ruby_parser::nodes::ZSuper> for Node {
    fn from(node: lib_ruby_parser::nodes::ZSuper) -> Self {
        let node_type = NodeType_NODE_ZSUPER;
        let expression_l = ptr_value(Range::from(node.expression_l));
        let typed_node = ZSuper { expression_l };
        let inner = ptr_value(InnerNode { _zsuper: ptr_value(typed_node) });
        Node { node_type, inner }
    }
}


impl InnerNode {
    pub fn to_debug_string(&self, node_type: u32) -> String {
        match node_type {
            NodeType_NODE_ALIAS => format!("{:#?}",  unsafe { *self._alias }),
            NodeType_NODE_AND_ASGN => format!("{:#?}",  unsafe { *self._and_asgn }),
            NodeType_NODE_AND => format!("{:#?}",  unsafe { *self._and }),
            NodeType_NODE_ARG => format!("{:#?}",  unsafe { *self._arg }),
            NodeType_NODE_ARGS => format!("{:#?}",  unsafe { *self._args }),
            NodeType_NODE_ARRAY => format!("{:#?}",  unsafe { *self._array }),
            NodeType_NODE_ARRAY_PATTERN => format!("{:#?}",  unsafe { *self._array_pattern }),
            NodeType_NODE_ARRAY_PATTERN_WITH_TAIL => format!("{:#?}",  unsafe { *self._array_pattern_with_tail }),
            NodeType_NODE_BACK_REF => format!("{:#?}",  unsafe { *self._back_ref }),
            NodeType_NODE_BEGIN => format!("{:#?}",  unsafe { *self._begin }),
            NodeType_NODE_BLOCK => format!("{:#?}",  unsafe { *self._block }),
            NodeType_NODE_BLOCK_PASS => format!("{:#?}",  unsafe { *self._block_pass }),
            NodeType_NODE_BLOCKARG => format!("{:#?}",  unsafe { *self._blockarg }),
            NodeType_NODE_BREAK_ => format!("{:#?}",  unsafe { *self._break_ }),
            NodeType_NODE_CASE => format!("{:#?}",  unsafe { *self._case }),
            NodeType_NODE_CASE_MATCH => format!("{:#?}",  unsafe { *self._case_match }),
            NodeType_NODE_CASGN => format!("{:#?}",  unsafe { *self._casgn }),
            NodeType_NODE_CBASE => format!("{:#?}",  unsafe { *self._cbase }),
            NodeType_NODE_CLASS => format!("{:#?}",  unsafe { *self._class }),
            NodeType_NODE_COMPLEX => format!("{:#?}",  unsafe { *self._complex }),
            NodeType_NODE_CONST_ => format!("{:#?}",  unsafe { *self._const_ }),
            NodeType_NODE_CONST_PATTERN => format!("{:#?}",  unsafe { *self._const_pattern }),
            NodeType_NODE_CSEND => format!("{:#?}",  unsafe { *self._csend }),
            NodeType_NODE_CVAR => format!("{:#?}",  unsafe { *self._cvar }),
            NodeType_NODE_CVASGN => format!("{:#?}",  unsafe { *self._cvasgn }),
            NodeType_NODE_DEF => format!("{:#?}",  unsafe { *self._def }),
            NodeType_NODE_DEFINED => format!("{:#?}",  unsafe { *self._defined }),
            NodeType_NODE_DEFS => format!("{:#?}",  unsafe { *self._defs }),
            NodeType_NODE_DSTR => format!("{:#?}",  unsafe { *self._dstr }),
            NodeType_NODE_DSYM => format!("{:#?}",  unsafe { *self._dsym }),
            NodeType_NODE_EFLIPFLOP => format!("{:#?}",  unsafe { *self._eflipflop }),
            NodeType_NODE_EMPTY_ELSE => format!("{:#?}",  unsafe { *self._empty_else }),
            NodeType_NODE_ENCODING_ => format!("{:#?}",  unsafe { *self._encoding_ }),
            NodeType_NODE_ENSURE => format!("{:#?}",  unsafe { *self._ensure }),
            NodeType_NODE_ERANGE => format!("{:#?}",  unsafe { *self._erange }),
            NodeType_NODE_FALSE_ => format!("{:#?}",  unsafe { *self._false_ }),
            NodeType_NODE_FILE => format!("{:#?}",  unsafe { *self._file }),
            NodeType_NODE_FIND_PATTERN => format!("{:#?}",  unsafe { *self._find_pattern }),
            NodeType_NODE_FLOAT => format!("{:#?}",  unsafe { *self._float }),
            NodeType_NODE_FOR_ => format!("{:#?}",  unsafe { *self._for_ }),
            NodeType_NODE_FORWARD_ARG => format!("{:#?}",  unsafe { *self._forward_arg }),
            NodeType_NODE_FORWARDED_ARGS => format!("{:#?}",  unsafe { *self._forwarded_args }),
            NodeType_NODE_GVAR => format!("{:#?}",  unsafe { *self._gvar }),
            NodeType_NODE_GVASGN => format!("{:#?}",  unsafe { *self._gvasgn }),
            NodeType_NODE_HASH => format!("{:#?}",  unsafe { *self._hash }),
            NodeType_NODE_KWARGS => format!("{:#?}",  unsafe { *self._kwargs }),
            NodeType_NODE_HASH_PATTERN => format!("{:#?}",  unsafe { *self._hash_pattern }),
            NodeType_NODE_HEREDOC => format!("{:#?}",  unsafe { *self._heredoc }),
            NodeType_NODE_IF_ => format!("{:#?}",  unsafe { *self._if_ }),
            NodeType_NODE_IF_GUARD => format!("{:#?}",  unsafe { *self._if_guard }),
            NodeType_NODE_IF_MOD => format!("{:#?}",  unsafe { *self._if_mod }),
            NodeType_NODE_IF_TERNARY => format!("{:#?}",  unsafe { *self._if_ternary }),
            NodeType_NODE_IFLIPFLOP => format!("{:#?}",  unsafe { *self._iflipflop }),
            NodeType_NODE_MATCH_PATTERN => format!("{:#?}",  unsafe { *self._match_pattern }),
            NodeType_NODE_MATCH_PATTERN_P => format!("{:#?}",  unsafe { *self._match_pattern_p }),
            NodeType_NODE_IN_PATTERN => format!("{:#?}",  unsafe { *self._in_pattern }),
            NodeType_NODE_INDEX => format!("{:#?}",  unsafe { *self._index }),
            NodeType_NODE_INDEX_ASGN => format!("{:#?}",  unsafe { *self._index_asgn }),
            NodeType_NODE_INT => format!("{:#?}",  unsafe { *self._int }),
            NodeType_NODE_IRANGE => format!("{:#?}",  unsafe { *self._irange }),
            NodeType_NODE_IVAR => format!("{:#?}",  unsafe { *self._ivar }),
            NodeType_NODE_IVASGN => format!("{:#?}",  unsafe { *self._ivasgn }),
            NodeType_NODE_KWARG => format!("{:#?}",  unsafe { *self._kwarg }),
            NodeType_NODE_KWBEGIN => format!("{:#?}",  unsafe { *self._kwbegin }),
            NodeType_NODE_KWNILARG => format!("{:#?}",  unsafe { *self._kwnilarg }),
            NodeType_NODE_KWOPTARG => format!("{:#?}",  unsafe { *self._kwoptarg }),
            NodeType_NODE_KWRESTARG => format!("{:#?}",  unsafe { *self._kwrestarg }),
            NodeType_NODE_KWSPLAT => format!("{:#?}",  unsafe { *self._kwsplat }),
            NodeType_NODE_LAMBDA => format!("{:#?}",  unsafe { *self._lambda }),
            NodeType_NODE_LINE => format!("{:#?}",  unsafe { *self._line }),
            NodeType_NODE_LVAR => format!("{:#?}",  unsafe { *self._lvar }),
            NodeType_NODE_LVASGN => format!("{:#?}",  unsafe { *self._lvasgn }),
            NodeType_NODE_MASGN => format!("{:#?}",  unsafe { *self._masgn }),
            NodeType_NODE_MATCH_ALT => format!("{:#?}",  unsafe { *self._match_alt }),
            NodeType_NODE_MATCH_AS => format!("{:#?}",  unsafe { *self._match_as }),
            NodeType_NODE_MATCH_CURRENT_LINE => format!("{:#?}",  unsafe { *self._match_current_line }),
            NodeType_NODE_MATCH_NIL_PATTERN => format!("{:#?}",  unsafe { *self._match_nil_pattern }),
            NodeType_NODE_MATCH_REST => format!("{:#?}",  unsafe { *self._match_rest }),
            NodeType_NODE_MATCH_VAR => format!("{:#?}",  unsafe { *self._match_var }),
            NodeType_NODE_MATCH_WITH_LVASGN => format!("{:#?}",  unsafe { *self._match_with_lvasgn }),
            NodeType_NODE_MLHS => format!("{:#?}",  unsafe { *self._mlhs }),
            NodeType_NODE_MODULE => format!("{:#?}",  unsafe { *self._module }),
            NodeType_NODE_NEXT => format!("{:#?}",  unsafe { *self._next }),
            NodeType_NODE_NIL => format!("{:#?}",  unsafe { *self._nil }),
            NodeType_NODE_NTH_REF => format!("{:#?}",  unsafe { *self._nth_ref }),
            NodeType_NODE_NUMBLOCK => format!("{:#?}",  unsafe { *self._numblock }),
            NodeType_NODE_OP_ASGN => format!("{:#?}",  unsafe { *self._op_asgn }),
            NodeType_NODE_OPTARG => format!("{:#?}",  unsafe { *self._optarg }),
            NodeType_NODE_OR => format!("{:#?}",  unsafe { *self._or }),
            NodeType_NODE_OR_ASGN => format!("{:#?}",  unsafe { *self._or_asgn }),
            NodeType_NODE_PAIR => format!("{:#?}",  unsafe { *self._pair }),
            NodeType_NODE_PIN => format!("{:#?}",  unsafe { *self._pin }),
            NodeType_NODE_POSTEXE => format!("{:#?}",  unsafe { *self._postexe }),
            NodeType_NODE_PREEXE => format!("{:#?}",  unsafe { *self._preexe }),
            NodeType_NODE_PROCARG0 => format!("{:#?}",  unsafe { *self._procarg0 }),
            NodeType_NODE_RATIONAL => format!("{:#?}",  unsafe { *self._rational }),
            NodeType_NODE_REDO => format!("{:#?}",  unsafe { *self._redo }),
            NodeType_NODE_REG_OPT => format!("{:#?}",  unsafe { *self._reg_opt }),
            NodeType_NODE_REGEXP => format!("{:#?}",  unsafe { *self._regexp }),
            NodeType_NODE_RESCUE => format!("{:#?}",  unsafe { *self._rescue }),
            NodeType_NODE_RESCUE_BODY => format!("{:#?}",  unsafe { *self._rescue_body }),
            NodeType_NODE_RESTARG => format!("{:#?}",  unsafe { *self._restarg }),
            NodeType_NODE_RETRY => format!("{:#?}",  unsafe { *self._retry }),
            NodeType_NODE_RETURN_ => format!("{:#?}",  unsafe { *self._return_ }),
            NodeType_NODE_SCLASS => format!("{:#?}",  unsafe { *self._sclass }),
            NodeType_NODE_SELF_ => format!("{:#?}",  unsafe { *self._self_ }),
            NodeType_NODE_SEND => format!("{:#?}",  unsafe { *self._send }),
            NodeType_NODE_SHADOWARG => format!("{:#?}",  unsafe { *self._shadowarg }),
            NodeType_NODE_SPLAT => format!("{:#?}",  unsafe { *self._splat }),
            NodeType_NODE_STR_ => format!("{:#?}",  unsafe { *self._str_ }),
            NodeType_NODE_SUPER_ => format!("{:#?}",  unsafe { *self._super_ }),
            NodeType_NODE_SYM => format!("{:#?}",  unsafe { *self._sym }),
            NodeType_NODE_TRUE_ => format!("{:#?}",  unsafe { *self._true_ }),
            NodeType_NODE_UNDEF => format!("{:#?}",  unsafe { *self._undef }),
            NodeType_NODE_UNLESS_GUARD => format!("{:#?}",  unsafe { *self._unless_guard }),
            NodeType_NODE_UNTIL => format!("{:#?}",  unsafe { *self._until }),
            NodeType_NODE_UNTIL_POST => format!("{:#?}",  unsafe { *self._until_post }),
            NodeType_NODE_WHEN => format!("{:#?}",  unsafe { *self._when }),
            NodeType_NODE_WHILE_ => format!("{:#?}",  unsafe { *self._while_ }),
            NodeType_NODE_WHILE_POST => format!("{:#?}",  unsafe { *self._while_post }),
            NodeType_NODE_X_HEREDOC => format!("{:#?}",  unsafe { *self._x_heredoc }),
            NodeType_NODE_XSTR => format!("{:#?}",  unsafe { *self._xstr }),
            NodeType_NODE_YIELD_ => format!("{:#?}",  unsafe { *self._yield_ }),
            NodeType_NODE_ZSUPER => format!("{:#?}",  unsafe { *self._zsuper }),
            _ => panic!("unsupported node type {}", node_type)
        }
    }
}


