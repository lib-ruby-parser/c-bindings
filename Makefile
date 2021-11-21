include scripts/detect_build_env.mk
include scripts/setup_target.mk
include scripts/setup_rustflags.mk

SOURCES = \
	alloc \
	api \
	bytes \
	comment \
	decoder \
	diagnostic \
	loc \
	magic_comment \
	messages \
	nodes \
	parser_options \
	parser_result \
	shared_byte_list \
	source_line \
	string \
	token \
	token_rewriter

ifeq ($(BUILD_ENV), debug)
SOURCES += test_helper
endif

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
