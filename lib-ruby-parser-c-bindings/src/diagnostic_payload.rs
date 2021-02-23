use crate::StringPtr;

pub struct DiagnosticPayload<T> {
    t: T,
}

pub trait DiagnosticPayloadNewBoxed<T> {
    fn new(t: T) -> Box<Self>;
}

impl DiagnosticPayloadNewBoxed<String> for DiagnosticPayload<String> {
    fn new(t: String) -> Box<Self> {
        Box::new(Self { t })
    }
}

impl DiagnosticPayloadNewBoxed<&'static str> for DiagnosticPayload<String> {
    fn new(t: &'static str) -> Box<Self> {
        Box::new(Self { t: t.to_string() })
    }
}

impl DiagnosticPayloadNewBoxed<u8> for DiagnosticPayload<u8> {
    fn new(t: u8) -> Box<Self> {
        Box::new(Self { t })
    }
}

impl DiagnosticPayloadNewBoxed<i8> for DiagnosticPayload<i8> {
    fn new(t: i8) -> Box<Self> {
        Box::new(Self { t })
    }
}

impl DiagnosticPayloadNewBoxed<*mut i8> for DiagnosticPayload<String> {
    fn new(t: *mut i8) -> Box<Self> {
        Box::new(Self {
            t: unsafe { std::ffi::CStr::from_ptr(t) }
                .to_str()
                .unwrap()
                .to_owned(),
        })
    }
}

pub trait DiagnosticPayloadUnwrap<T> {
    fn unwrap(&self) -> T;
}

impl DiagnosticPayloadUnwrap<i8> for DiagnosticPayload<u8> {
    fn unwrap(&self) -> i8 {
        self.t as i8
    }
}

impl DiagnosticPayloadUnwrap<u8> for DiagnosticPayload<i8> {
    fn unwrap(&self) -> u8 {
        self.t as u8
    }
}

impl DiagnosticPayloadUnwrap<*mut i8> for DiagnosticPayload<String> {
    fn unwrap(&self) -> *mut i8 {
        StringPtr::from(self.t.clone()).unwrap()
    }
}

impl DiagnosticPayloadUnwrap<String> for DiagnosticPayload<String> {
    fn unwrap(&self) -> String {
        self.t.clone()
    }
}
