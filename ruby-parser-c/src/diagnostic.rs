use crate::blob_type;
#[allow(unused_imports)]
use crate::message::DiagnosticMessageBlob;
#[allow(unused_imports)]
use lib_ruby_parser::{Diagnostic, DiagnosticMessage, ErrorLevel, Loc};

blob_type!(BlobDiagnostic, Diagnostic);
blob_type!(BlobDiagnosticList, Vec<Diagnostic>);

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_diagnostic(
    level: ErrorLevel,
    message: DiagnosticMessageBlob,
    loc: Loc,
) -> BlobDiagnostic {
    BlobDiagnostic::from(Diagnostic {
        level,
        message: DiagnosticMessage::from(message),
        loc,
    })
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_diagnostic(diagnostic: *mut Diagnostic) {
    unsafe { std::ptr::drop_in_place(diagnostic) }
}

#[cfg(feature = "tests")]
#[no_mangle]
pub extern "C" fn lib_ruby_parser__test__make_diagnostic_list(
    diagnostic: BlobDiagnostic,
) -> BlobDiagnosticList {
    BlobDiagnosticList::from(vec![Diagnostic::from(diagnostic)])
}

#[no_mangle]
pub extern "C" fn LIB_RUBY_PARSER_drop_diagnostic_list(diagnostic_list: *mut Vec<Diagnostic>) {
    unsafe { std::ptr::drop_in_place(diagnostic_list) }
}
