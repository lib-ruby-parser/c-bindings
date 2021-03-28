include scripts/setup.mk

ifeq ($(DETECTED_OS), Windows)
	LIST_DEPS = dumpbin /dependents
endif

ifeq ($(DETECTED_OS), Linux)
	LIST_DEPS = ldd
endif

ifeq ($(DETECTED_OS), Darwin)
	LIST_DEPS = otool -L
endif

# Rust
include lib-ruby-parser-c-bindings/build.mk

# Header
include header/build.mk

# C
include src/build.mk

STATIC_LIB = $(TARGET_DIR)/lib-ruby-parser.$(STATIC_LIB_EXT)

ifeq ($(CARGO_BUILD_TARGET), x86_64-pc-windows-msvc)
	BUILD_STATIC = lib.exe ws2_32.lib advapi32.lib userenv.lib $(RUST_OBJ) $(OBJECTS) /OUT:$(STATIC_LIB)
else
	LIB_RUBY_PARSER_O = $(TARGET_DIR)/lib-ruby-parser.$(OBJ_FILE_EXT)
	BUILD_STATIC = cp $(TARGET_DIR)/lib-ruby-parser-rust-static.a $(TARGET_DIR)/lib-ruby-parser.a && \
					rm -f $(LIB_RUBY_PARSER_O) && \
					$(LD) $(OBJECTS) -r -o $(LIB_RUBY_PARSER_O) && \
					ar -rv $(TARGET_DIR)/lib-ruby-parser.a $(LIB_RUBY_PARSER_O)
endif

$(STATIC_LIB): $(RUST_OBJ) $(OBJECTS)
	$(BUILD_STATIC)
build-static: $(STATIC_LIB)

# tests
include test/build.mk

clean:
	rm -rf target
	mkdir -p $(TARGET_DIR)
	rm -f $(HEADER)

# fuzzer
include fuzzer/build.mk

# benchmark
include benchmark/build.mk
