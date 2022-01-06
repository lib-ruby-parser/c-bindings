CODEGEN_DEPS = $(wildcard codegen/codegen/*.rs)
CODEGEN_DEPS += codegen/Cargo.toml
CODEGEN_DEPS += codegen/build.rs

DO_CODEGEN = cd codegen && cargo build

# Codegen deps
messages.c: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += messages.c

messages.h: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += messages.h

nodes.c: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += nodes.c

nodes.h: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += nodes.h

ruby-parser-c/src/node.rs: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += ruby-parser-c/src/node.rs

ruby-parser-c/src/message.rs: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += ruby-parser-c/src/message.rs

# token_id.{h,c} codegen
DO_CODEGEN_TOKEN_IDS = cargo run --example build_token_ids --manifest-path codegen/Cargo.toml

token_ids.h: codegen/examples/build_token_ids.rs
	$(DO_CODEGEN_TOKEN_IDS)
CLEAN += token_ids.h
update-depend: token_ids.h

# lib-ruby-parser.h codegen
lib-ruby-parser.h: codegen/examples/merge_headers.rs $(H_FILES) token_ids.h
	cargo run --example merge_headers --manifest-path codegen/Cargo.toml
CLEAN += lib-ruby-parser.h
update-depend: lib-ruby-parser.h

# manual codegen task
do-codegen:
	$(DO_CODEGEN)
