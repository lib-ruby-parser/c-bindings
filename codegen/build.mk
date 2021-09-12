CODEGEN_DEPS = $(wildcard codegen/codegen/*.rs)
CODEGEN_DEPS += codegen/Cargo.toml
CODEGEN_DEPS += codegen/build.rs

DO_CODEGEN = cd $(CODEGEN_DIR) && cargo build

CLEAN += codegen/target

# Codegen deps
bindings.h: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
bindings_messages.c: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
bindings_nodes.c: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
blobs_gen.h: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
messages.c: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
messages.h: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
nodes.c: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
nodes.h: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
sizes_gen.h: $(CODEGEN_DEPS)
	$(DO_CODEGEN)

CODEGEN_C = \
	bindings_messages.c \
	bindings_nodes.c \
	messages.c \
	nodes.c

CODEGEN_H = \
	bindings.h \
	blobs_gen.h \
	messages.h \
	nodes.h \
	sizes_gen.h

CLEAN += $(CODEGEN_C)
CLEAN += $(CODEGEN_H)
