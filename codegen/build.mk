define download_file
URL="$(1)" SAVE_AS="$(2)" ruby scripts/download_file.rb
endef

CODEGEN_EXE = codegen/codegen$(EXE)

$(CODEGEN_EXE):
	$(call download_file, https://github.com/lib-ruby-parser/nodes/releases/download/v0.52.0/codegen-$(TARGET)$(EXE), $@)
	chmod +x $(CODEGEN_EXE)
CLEAN += $(CODEGEN_EXE)

# Codegen deps
tests/messages_test.c: codegen/messages_test.c.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
CLEAN += tests/messages_test.c

messages.h: codegen/messages.h.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
CLEAN += messages.h

tests/nodes_test.c: codegen/nodes_test.c.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
CLEAN += tests/nodes_test.c

nodes.h: codegen/nodes.h.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
CLEAN += nodes.h

ruby-parser-c/src/node.rs: codegen/nodes.rs.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
CLEAN += ruby-parser-c/src/node.rs

ruby-parser-c/src/message.rs: codegen/messages.rs.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
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
