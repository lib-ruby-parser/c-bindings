extern "C" {
    fn lib_ruby_parser_allocate(size: u32) -> *mut u8;
    fn lib_ruby_parser_free(ptr: *mut u8);
}

struct LibRubyParserAllocator;

use std::alloc::{GlobalAlloc, Layout};
unsafe impl GlobalAlloc for LibRubyParserAllocator {
    unsafe fn alloc(&self, layout: Layout) -> *mut u8 {
        lib_ruby_parser_allocate(layout.size() as u32)
    }

    unsafe fn dealloc(&self, ptr: *mut u8, _layout: Layout) {
        lib_ruby_parser_free(ptr);
    }
}

#[global_allocator]
static GLOBAL: LibRubyParserAllocator = LibRubyParserAllocator;
