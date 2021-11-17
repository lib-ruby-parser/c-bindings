RUST_SRCS = $(wildcard ruby-parser-c/src/*.rs)
RUST_SRCS += ruby-parser-c/src/node.rs
RUST_SRCS += ruby-parser-c/src/message.rs

ruby-parser-c/lib_ruby_parser_c.$(A): $(RUST_SRCS)
	RUSTFLAGS="$(RUSTFLAGS)" cargo build $(CARGOFLAGS) --manifest-path ruby-parser-c/Cargo.toml
	ls -l ruby-parser-c/target/$(TARGET)
	ls -l ruby-parser-c/target/$(TARGET)/$(RUST_ENV)
	cp ruby-parser-c/target/$(TARGET)/$(RUST_ENV)/$(STATIC_LIB_FILE) ruby-parser-c/lib_ruby_parser_c.$(A)

CLEAN += ruby-parser-c/lib_ruby_parser_c.$(A)
CLEAN += ruby-parser-c/target/$(TARGET)
