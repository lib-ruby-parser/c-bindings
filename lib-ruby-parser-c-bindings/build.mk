ifeq ($(CARGO_BUILD_TARGET),)
	# default target
	RUST_TARGET_DIR = target
else
	CARGOFLAGS += --target $(CARGO_BUILD_TARGET)
	RUST_TARGET_DIR = target/$(CARGO_BUILD_TARGET)
endif

BINDINGS_DIR = lib-ruby-parser-c-bindings

ifeq ($(BUILD_ENV), debug)
	RUST_ENV = debug
	CARGOFLAGS +=
else
	RUST_ENV = release
	CARGOFLAGS += --release
endif

ifeq ($(CARGO_BUILD_TARGET), x86_64-pc-windows-msvc)
	RUST_OBJ_FILE = lib_ruby_parser_c_bindings.lib
	STATIC_LIB_EXT = lib
else
	# GCC-like compiler (GCC/Clang/MinGW)
	RUST_OBJ_FILE = liblib_ruby_parser_c_bindings.a
	STATIC_LIB_EXT = a
endif

RUST_SRCS = $(wildcard $(BINDINGS_DIR)/src/*.rs)

RUST_OBJ = $(TARGET_DIR)/lib-ruby-parser-rust-static.$(STATIC_LIB_EXT)
$(RUST_OBJ): $(RUST_SRCS)
	cd $(BINDINGS_DIR) && cargo build $(CARGOFLAGS)
	ls -l $(BINDINGS_DIR)/$(RUST_TARGET_DIR)/$(RUST_ENV)/
	cp $(BINDINGS_DIR)/$(RUST_TARGET_DIR)/$(RUST_ENV)/$(RUST_OBJ_FILE) $(RUST_OBJ)

header: $(RUST_SRCS) $(BINDINGS_DIR)/cbindgen.toml
	cd $(BINDINGS_DIR) && \
		cbindgen --config cbindgen.toml --crate lib-ruby-parser-c-bindings -d --output ../src/lib-ruby-parser.h -q
