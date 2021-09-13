include scripts/detect_build_env.mk
include scripts/setup_target.mk
CODEGEN_DIR = codegen
RUST_DIR = ruby-parser-c
CLEAN =
include scripts/setup_rustflags.mk

SOURCES = \
	alloc \
	api \
	bindings \
	bindings_messages \
	bindings_nodes \
	messages \
	nodes \
	structs

C_FILES = $(foreach source,$(SOURCES),$(source).c)
H_FILES = $(foreach source,$(SOURCES),$(source).h)
O_FILES = $(foreach source,$(SOURCES),$(source).$(O))
STATIC_LIB = libruby_parser_c.$(A)

# Codegen
include codegen/build.mk

# CXX
%.$(O): %.c %.h
	$(call build_c_obj,$<,$@)

# Rust
CLEAN += $(RUST_TARGET_DIR)
# RUSTFLAGS += -Clinker-plugin-lto -Clinker=clang-13 -Clink-arg=-fuse-ld=lld-13
# RUSTFLAGS += -Clinker-plugin-lto -Clinker=clang -Clink-arg=-fuse-ld=lld.darwinnew

$(STATIC_LIB): $(wildcard $(RUST_DIR)/src/*.rs) $(O_FILES) sizes-out
	LIB_RUBY_PARSER_SIZES_FILEPATH=$(shell pwd)/sizes-out \
		RUSTFLAGS=$(RUSTFLAGS) \
		cargo build $(CARGOFLAGS) --manifest-path $(RUST_DIR)/Cargo.toml
	ls -l $(RUST_TARGET_DIR)
	ls -l $(RUST_TARGET_DIR)/$(RUST_ENV)
	cp $(RUST_TARGET_DIR)/$(RUST_ENV)/$(STATIC_LIB_FILE) ./$(STATIC_LIB)
	$(call add_to_lib,$(STATIC_LIB),$(O_FILES))

# Sizes
sizes:
	$(call build_c_exe,sizes.c,sizes)
sizes-out: sizes
	./sizes > sizes-out
CLEAN += sizes sizes-out

# test
test-runner: $(STATIC_LIB)
	$(call build_c_exe,test.c $(STATIC_LIB),test-runner)
test: test-runner
	./test-runner
CLEAN += test-runner

# benchmark
benchmark-runner: $(STATIC_LIB)
	$(call build_c_exe,benchmark.c $(STATIC_LIB),benchmark-runner)
benchmark: benchmark-runner
	./benchmark-runner
CLEAN += benchmark-runner

# deps
update-depend: $(C_FILES) $(H_FILES)
	CC=$(CC) ./scripts/update-depend.sh

include .depend

# clean
clean:
	rm -rf $(CLEAN)
	rm -f *.$(O)
	rm -f *.$(A)
	rm -rf *.dSYM

# RUST_TARGET=x86_64-unknown-linux-gnu CFLAGS="-flto" BUILD_ENV=release make test-runner
