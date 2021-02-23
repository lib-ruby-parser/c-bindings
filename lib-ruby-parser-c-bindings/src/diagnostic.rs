use crate::bindings;
use crate::ptr_value;

impl From<lib_ruby_parser::Diagnostic> for bindings::Diagnostic {
    fn from(diagnostic: lib_ruby_parser::Diagnostic) -> Self {
        Self {
            level: diagnostic.level.into(),
            message: diagnostic.message.into(),
            loc: ptr_value(diagnostic.loc.into()),
        }
    }
}

impl From<bindings::Diagnostic> for lib_ruby_parser::Diagnostic {
    fn from(diagnostic: bindings::Diagnostic) -> Self {
        Self {
            level: diagnostic.level.into(),
            message: diagnostic.message.into(),
            loc: unsafe { *diagnostic.loc }.into(),
        }
    }
}

impl From<lib_ruby_parser::ErrorLevel> for bindings::ErrorLevel {
    fn from(level: lib_ruby_parser::ErrorLevel) -> Self {
        match level {
            lib_ruby_parser::ErrorLevel::Warning => bindings::ErrorLevel::ERROR_LEVEL_WARNING,
            lib_ruby_parser::ErrorLevel::Error => bindings::ErrorLevel::ERROR_LEVEL_ERROR,
        }
    }
}

impl From<bindings::ErrorLevel> for lib_ruby_parser::ErrorLevel {
    fn from(level: bindings::ErrorLevel) -> Self {
        match level {
            bindings::ErrorLevel::ERROR_LEVEL_WARNING => lib_ruby_parser::ErrorLevel::Warning,
            bindings::ErrorLevel::ERROR_LEVEL_ERROR => lib_ruby_parser::ErrorLevel::Error,
        }
    }
}
