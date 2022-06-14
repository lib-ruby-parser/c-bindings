use crate::blob_type;
#[allow(unused_imports)]
use crate::message::DiagnosticMessageBlob;
use lib_ruby_parser::source::DecodedInput;
#[allow(unused_imports)]
use lib_ruby_parser::{Diagnostic, DiagnosticMessage, ErrorLevel, Loc};

blob_type!(DiagnosticBlob, Diagnostic);
blob_type!(DiagnosticListBlob, Vec<Diagnostic>);

#[cfg(test)]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_diagnostic(
    level: ErrorLevel,
    message: DiagnosticMessageBlob,
    loc: Loc,
) -> DiagnosticBlob {
    DiagnosticBlob::from(Diagnostic {
        level,
        message: DiagnosticMessage::from(message),
        loc,
    })
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_diagnostic(diagnostic: *mut Diagnostic) {
    unsafe { std::ptr::drop_in_place(diagnostic) }
}

#[cfg(test)]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_diagnostic_list(
    diagnostic: DiagnosticBlob,
) -> DiagnosticListBlob {
    let mut v = vec![Diagnostic::from(diagnostic)];
    v.reserve(10);
    DiagnosticListBlob::from(v)
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_diagnostic_list(diagnostic_list: *mut Vec<Diagnostic>) {
    unsafe { std::ptr::drop_in_place(diagnostic_list) }
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_render_diagnostic(
    diagnostic: *const Diagnostic,
    input: *const DecodedInput,
) -> *mut i8 {
    let diagnostic = unsafe { diagnostic.as_ref().unwrap() };
    let input = unsafe { input.as_ref().unwrap() };
    let rendered = diagnostic.render(input).unwrap();
    std::ffi::CString::new(rendered).unwrap().into_raw()
}
