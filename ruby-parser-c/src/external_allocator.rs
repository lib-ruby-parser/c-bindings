struct UsingExternalAllocator;

use std::alloc::{GlobalAlloc, Layout};

struct ExternalAllocator;

extern "C" {
    fn lib_ruby_parser__external__alloc(size: usize) -> *mut u8;
    fn lib_ruby_parser__external__free(ptr: *mut u8);
}

unsafe impl GlobalAlloc for ExternalAllocator {
    unsafe fn alloc(&self, layout: Layout) -> *mut u8 {
        lib_ruby_parser__external__alloc(layout.size())
    }

    unsafe fn dealloc(&self, ptr: *mut u8, _layout: Layout) {
        lib_ruby_parser__external__free(ptr)
    }
}

#[global_allocator]
static GLOBAL: ExternalAllocator = ExternalAllocator;
