.DELETE_ON_ERROR:

include scripts/detect_build_env.mk
include scripts/setup_target.mk
include scripts/setup_rustflags.mk

SOURCES = alloc decoder string token_rewriter

C_FILES = $(foreach source,$(SOURCES),$(source).c)
H_FILES = alloc.h \
	bytes.h \
	decoded_input.h \
	diagnostic.h \
	loc.h \
	messages.h \
	parser_options.h \
	shared_byte_list.h \
	string.h \
	token_ids.h \
	api.h \
	comment.h \
	decoder.h \
	magic_comment.h \
	nodes.h \
	parser_result.h \
	source_line.h \
	token.h \
	token_rewriter.h
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
	touch codegen/build.rs

doxygen: messages.h nodes.h token_ids.h
	rm -rf docs
	doxygen
