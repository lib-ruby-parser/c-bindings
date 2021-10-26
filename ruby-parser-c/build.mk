RUST_SRCS = $(wildcard ruby-parser-c/src/*.rs)

ruby-parser-c/lib_ruby_parser_c.$(A): $(RUST_SRCS) sizes-out
	LIB_RUBY_PARSER_SIZES_FILEPATH=$(shell pwd)/sizes-out \
		RUSTFLAGS="$(RUSTFLAGS)" \
		cargo build $(CARGOFLAGS) --manifest-path ruby-parser-c/Cargo.toml
	ls -l ruby-parser-c/target/$(TARGET)
	ls -l ruby-parser-c/target/$(TARGET)/$(RUST_ENV)
	cp ruby-parser-c/target/$(TARGET)/$(RUST_ENV)/$(STATIC_LIB_FILE) ruby-parser-c/lib_ruby_parser_c.$(A)

CLEAN += ruby-parser-c/lib_ruby_parser_c.$(A)
CLEAN += ruby-parser-c/target/$(TARGET)
