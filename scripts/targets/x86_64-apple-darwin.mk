$(info Compiling x86_64-apple-darwin target)

O = o
A = a
EXE =

STATIC_LIB_FILE = libruby_parser_c.$(A)
LIST_DEPS = otool -L

CFLAGS += -Wall -Wextra -Wpedantic -Weverything -Wdocumentation -g
# but disable -Wpadded, we inherit Rust layouts
CFLAGS += -Wno-padded
# ignore documentation, it has examples of syntax errors on purpose
CFLAGS += -Wno-documentation-unknown-command

ifeq ($(BUILD_ENV), debug)
CFLAGS += -O0 -DTEST_ENV
else
CFLAGS += -O3
endif

define add_to_lib
$(AR) r $(1) $(2)
endef

define build_c_obj
$(CC) $(1) $(CFLAGS) -c -o $(2)
endef

define build_c_exe
$(CC) $(1) $(CFLAGS) -o $(2)
endef

BENCHMARK_RUNNER_ASSET_NAME = rust-parser-x86_64-apple-darwin
