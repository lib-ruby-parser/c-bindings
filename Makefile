build: cargo-build target-dir
	clang main.c lib-ruby-parser-c-bindings/target/debug/liblib_ruby_parser_c_bindings.a -o target/main
	./target/main

test: cargo-build target-dir
	clang test.c lib-ruby-parser-c-bindings/target/debug/liblib_ruby_parser_c_bindings.a -o target/test
	./target/test

target-dir:
	mkdir -p target

cargo-build:
	cd lib-ruby-parser-c-bindings && cargo build

clean:
	rm -rf target
	cd lib-ruby-parser-c-bindings && cargo clean
