use crate::bindings;
use crate::ptr_value;
use crate::StringPtr;

impl From<lib_ruby_parser::Diagnostic> for bindings::Diagnostic {
    fn from(diagnostic: lib_ruby_parser::Diagnostic) -> Self {
        let level = match diagnostic.level {
            lib_ruby_parser::ErrorLevel::Warning => bindings::ErrorLevel::ERROR_LEVEL_WARNING,
            lib_ruby_parser::ErrorLevel::Error => bindings::ErrorLevel::ERROR_LEVEL_ERROR,
        };
        let message = StringPtr::from(diagnostic.render_message()).unwrap();
        Self {
            level,
            message,
            loc: ptr_value(bindings::Loc::from(diagnostic.loc)),
        }
    }
}
