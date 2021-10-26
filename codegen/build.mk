TAG_TO_SYNC = v3.0.11
BASE_FN_SYNC_URL = https://raw.githubusercontent.com/lib-ruby-parser/lib-ruby-parser/$(TAG_TO_SYNC)

codegen/sync-fns:
	wget -q $(BASE_FN_SYNC_URL)/codegen/fns/shared.rs -O codegen/codegen/fns_shared.rs
	wget -q $(BASE_FN_SYNC_URL)/codegen/fns/c.rs -O codegen/codegen/fns_c.rs

CODEGEN_DEPS = $(wildcard codegen/codegen/*.rs)
CODEGEN_DEPS += codegen/Cargo.toml
CODEGEN_DEPS += codegen/build.rs

DO_CODEGEN = cd codegen && cargo build

CLEAN += codegen/target

# Codegen deps
bindings.h: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += bindings.h

bindings_messages.c: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += bindings_messages.c

bindings_nodes.c: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += bindings_nodes.c

blobs_gen.h: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += blobs_gen.h

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

sizes_gen.h: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += sizes_gen.h

# manual codegen task
do-codegen:
	$(DO_CODEGEN)
