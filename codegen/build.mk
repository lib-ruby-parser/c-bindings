CODEGEN_DEPS = $(wildcard codegen/codegen/*.rs)
CODEGEN_DEPS += codegen/Cargo.toml
CODEGEN_DEPS += codegen/build.rs

DO_CODEGEN = cd codegen && touch build.rs && cargo build

# Codegen deps
tests/messages_test.c: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += tests/messages_test.c

messages.h: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += messages.h

tests/nodes_test.c: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += tests/nodes_test.c

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

merge-headers:
	wget -q https://github.com/iliabylich/merge_headers/releases/download/v1.0.0/merge-headers-$(TARGET) -O merge-headers
	chmod +x merge-headers
CLEAN += merge-headers

# A literal space.
space :=
space +=

# Joins elements of the list in arg 2 with the given separator.
#   1. Element separator.
#   2. The list.
join-with = $(subst $(space),$1,$(strip $2))

# lib-ruby-parser.h codegen
lib-ruby-parser.h: merge-headers $(H_FILES) token_ids.h nodes.h messages.h
	./merge-headers \
		--cc $(CC) \
		--headers "$(call join-with,;,$(H_FILES));token_ids.h" \
		--write-to lib-ruby-parser.h \
		--include-guard-prefix LIB_RUBY_PARSER_ \
		--output-guard LIB_RUBY_PARSER_H

CLEAN += lib-ruby-parser.h
update-depend: lib-ruby-parser.h

# manual codegen task
do-codegen:
	$(DO_CODEGEN)
