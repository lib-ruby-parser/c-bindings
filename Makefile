include scripts/detect_build_env.mk
include scripts/setup_target.mk
include scripts/setup_rustflags.mk

SOURCES = \
	bytes \
	decoder \
	loc \
	messages \
	parser_options \
	shared_byte_list \
	string \
	token_rewriter \
	comment \
	diagnostic \
	magic_comment \
	nodes \
	parser_result \
	source_line \
	token

C_FILES = $(foreach source,$(SOURCES),$(source).c)
H_FILES = $(foreach source,$(SOURCES),$(source).h)
O_FILES = $(foreach source,$(SOURCES),$(source).$(O))
STATIC_LIB = libruby_parser_c.$(A)

# Codegen
include codegen/build.mk

# *.o
%.$(O): %.c %.h
	$(call build_c_obj,$<,$@)
objects: $(O_FILES)

# Rust
include ruby-parser-c/build.mk

$(STATIC_LIB): ruby-parser-c/lib_ruby_parser_c.$(A) $(O_FILES)
	cp ruby-parser-c/lib_ruby_parser_c.$(A) ./$(STATIC_LIB)
	$(call add_to_lib,$(STATIC_LIB),$(O_FILES))

rebuild-static-lib:
	./scripts/rebuild-static-lib.sh

# Sizes
sizes:
	$(call build_c_exe,sizes.c,sizes)
sizes-out: sizes
	./sizes > sizes-out
CLEAN += sizes sizes-out

# tests
include tests/build.mk

# benchmark
include benchmark/build.mk

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

check:
	CC=$(CC) ruby assert_defs.rb bindings.h bindings.c bindings_messages.c bindings_nodes.c
