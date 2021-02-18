ifeq ($(OS), Windows_NT)
	DETECTED_OS = Windows
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
		DETECTED_OS = Linux
	else
		ifeq ($(UNAME_S), Darwin)
			DETECTED_OS = Darwin
		else
			DETECTED_OS = Unknown
		endif
	endif
endif

ifndef BUILD_ENV
	BUILD_ENV = debug
endif

ifeq ($(CARGO_BUILD_TARGET),)
	# default target
	RUST_TARGET_DIR = target
	RELEASE_FILE = lib-ruby-parser-unknown-unknown-unknown
else
	CARGOFLAGS += --target $(CARGO_BUILD_TARGET)
	RUST_TARGET_DIR = target/$(CARGO_BUILD_TARGET)
	RELEASE_FILE = lib-ruby-parser-$(CARGO_BUILD_TARGET)
endif

BINDINGS_DIR = lib-ruby-parser-c-bindings

ifeq ($(DETECTED_OS), Windows)
	CCFLAGS += /std:c++17 /nologo
	CCOBJFLAGS += /c /Fo
	CCFLAGS += /MT /Zi

	ifeq ($(BUILD_ENV), debug)
		CCFLAGS += /Od /DEBUG
	else
		CCFLAGS += /O2
	endif

	OBJ_FILE_EXT = .obj
	STATIC_LIB_EXT = .lib
	EXEC_EXT = .exe

	CC_SET_OUT_FILE = /link /OUT:
	LD_SET_OUT_FILE = /OUT:
	LIST_DEPS = dumpbin /dependents
	RUST_OBJ_FILE = lib_ruby_parser_c_bindings.lib
endif

ifeq ($(DETECTED_OS), Linux)
	CCFLAGS += -Wall -Wextra
	CCOBJFLAGS += -fPIC -c
	CCEXECFLAGS = -lpthread -ldl
	LDFLAGS = -r

	ifeq ($(BUILD_ENV), debug)
		CCFLAGS += -g -O0
	else
		CCFLAGS += -O2
	endif

	OBJ_FILE_EXT = .o
	STATIC_LIB_EXT = .a
	EXEC_EXT =

	CC_SET_OUT_FILE = -o #
	LD_SET_OUT_FILE = -o #
	LIST_DEPS = ldd
	RUST_OBJ_FILE = liblib_ruby_parser_c_bindings.a
endif

ifeq ($(DETECTED_OS), Darwin)
	CCFLAGS += -Wall -Wextra
	CCOBJFLAGS += -fPIC -c
	CCEXECFLAGS = -lpthread -ldl
	LDFLAGS = -r

	ifeq ($(BUILD_ENV), debug)
		CCFLAGS += -g -O0
	else
		CCFLAGS += -O2
	endif
	OBJ_FILE_EXT = .o
	STATIC_LIB_EXT = .a
	EXEC_EXT =

	CC_SET_OUT_FILE = -o #
	LD_SET_OUT_FILE = -o #
	LIST_DEPS = otool -L
	RUST_OBJ_FILE = liblib_ruby_parser_c_bindings.a
endif

ifeq ($(BUILD_ENV), debug)
	RUST_ENV = debug
	TARGET_DIR = target/debug
	CARGOFLAGS +=
else
	RUST_ENV = release
	TARGET_DIR = target/release
	CARGOFLAGS += --release
endif

setup:
	mkdir -p target/debug
	mkdir -p target/release

RUST_OBJ = $(TARGET_DIR)/lib-ruby-parser-rust-static$(STATIC_LIB_EXT)
$(RUST_OBJ):
	cd $(BINDINGS_DIR) && cargo build $(CARGOFLAGS)
	ls -l $(BINDINGS_DIR)/$(RUST_TARGET_DIR)/$(RUST_ENV)/
	cp $(BINDINGS_DIR)/$(RUST_TARGET_DIR)/$(RUST_ENV)/$(RUST_OBJ_FILE) $(RUST_OBJ)

rust-object: $(RUST_OBJ)
gen-headers: $(RUST_OBJ)

# headers

LIB_RUBY_PARSER_TMP_H = target/lib-ruby-parser-tmp.h
LIB_RUBY_PARSER_H = target/lib-ruby-parser.h
$(LIB_RUBY_PARSER_H):
	cat src/node.h > $(LIB_RUBY_PARSER_TMP_H)

	cat src/loc.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/token.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/diagnostic.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/comment.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/magic_comment.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/node_list.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/custom_decoder.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/token_rewriter.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/parser_options.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/parser_result.h >> $(LIB_RUBY_PARSER_TMP_H)

	echo "#ifndef LIB_RUBY_PARSER_H" > $(LIB_RUBY_PARSER_H)
	echo "#define LIB_RUBY_PARSER_H" >> $(LIB_RUBY_PARSER_H)

	cat $(LIB_RUBY_PARSER_TMP_H) | \
		grep -v "#include \"" | \
		grep -v "#ifndef LIB_RUBY_PARSER_" | \
		grep -v "#define LIB_RUBY_PARSER_" | \
		grep -v "#endif // LIB_RUBY_PARSER_" \
		>> $(LIB_RUBY_PARSER_H)
	echo "#endif // LIB_RUBY_PARSER_H" >> $(LIB_RUBY_PARSER_H)

# Objects

OBJECTS =
$(TARGET_DIR)/comment$(OBJ_FILE_EXT): src/comment.h src/comment.c
	$(CC) src/comment.c $(CCFLAGS) $(CCOBJFLAGS)
	mv comment$(OBJ_FILE_EXT) $(TARGET_DIR)/comment$(OBJ_FILE_EXT)
OBJECTS += $(TARGET_DIR)/comment$(OBJ_FILE_EXT)

$(TARGET_DIR)/loc$(OBJ_FILE_EXT): src/loc.h src/loc.c
	$(CC) src/loc.c $(CCFLAGS) $(CCOBJFLAGS)
	mv loc$(OBJ_FILE_EXT) $(TARGET_DIR)/loc$(OBJ_FILE_EXT)
OBJECTS += $(TARGET_DIR)/loc$(OBJ_FILE_EXT)

$(TARGET_DIR)/diagnostic$(OBJ_FILE_EXT): src/diagnostic.h src/diagnostic.c
	$(CC) src/diagnostic.c $(CCFLAGS) $(CCOBJFLAGS)
	mv diagnostic$(OBJ_FILE_EXT) $(TARGET_DIR)/diagnostic$(OBJ_FILE_EXT)
OBJECTS += $(TARGET_DIR)/diagnostic$(OBJ_FILE_EXT)

$(TARGET_DIR)/custom_decoder$(OBJ_FILE_EXT): src/custom_decoder.h src/custom_decoder.c
	$(CC) src/custom_decoder.c $(CCFLAGS) $(CCOBJFLAGS)
	mv custom_decoder$(OBJ_FILE_EXT) $(TARGET_DIR)/custom_decoder$(OBJ_FILE_EXT)
OBJECTS += $(TARGET_DIR)/custom_decoder$(OBJ_FILE_EXT)

$(TARGET_DIR)/magic_comment$(OBJ_FILE_EXT): src/magic_comment.h src/magic_comment.c
	$(CC) src/magic_comment.c $(CCFLAGS) $(CCOBJFLAGS)
	mv magic_comment$(OBJ_FILE_EXT) $(TARGET_DIR)/magic_comment$(OBJ_FILE_EXT)
OBJECTS += $(TARGET_DIR)/magic_comment$(OBJ_FILE_EXT)

$(TARGET_DIR)/node_list$(OBJ_FILE_EXT): src/node_list.h src/node_list.c
	$(CC) src/node_list.c $(CCFLAGS) $(CCOBJFLAGS)
	mv node_list$(OBJ_FILE_EXT) $(TARGET_DIR)/node_list$(OBJ_FILE_EXT)
OBJECTS += $(TARGET_DIR)/node_list$(OBJ_FILE_EXT)

$(TARGET_DIR)/parser_result$(OBJ_FILE_EXT): src/parser_result.h src/parser_result.c
	$(CC) src/parser_result.c $(CCFLAGS) $(CCOBJFLAGS)
	mv parser_result$(OBJ_FILE_EXT) $(TARGET_DIR)/parser_result$(OBJ_FILE_EXT)
OBJECTS += $(TARGET_DIR)/parser_result$(OBJ_FILE_EXT)

$(TARGET_DIR)/token$(OBJ_FILE_EXT): src/token.h src/token.c
	$(CC) src/token.c $(CCFLAGS) $(CCOBJFLAGS)
	mv token$(OBJ_FILE_EXT) $(TARGET_DIR)/token$(OBJ_FILE_EXT)
OBJECTS += $(TARGET_DIR)/token$(OBJ_FILE_EXT)

$(TARGET_DIR)/node$(OBJ_FILE_EXT): src/node.h src/node.c
	$(CC) src/node.c $(CCFLAGS) $(CCOBJFLAGS)
	mv node$(OBJ_FILE_EXT) $(TARGET_DIR)/node$(OBJ_FILE_EXT)
OBJECTS += $(TARGET_DIR)/node$(OBJ_FILE_EXT)

TEST_O = $(TARGET_DIR)/test$(OBJ_FILE_EXT)
$(TEST_O): test.c $(LIB_RUBY_PARSER_H)
	$(CC) test.c $(CCFLAGS) $(CCOBJFLAGS)
	mv test$(OBJ_FILE_EXT) $(TEST_O)

LIB_RUBY_PARSER_STATIC = $(TARGET_DIR)/lib-ruby-parser$(STATIC_LIB_EXT)

ifeq ($(DETECTED_OS), Windows)
	BUILD_STATIC = lib.exe ws2_32.lib advapi32.lib userenv.lib $(RUST_OBJ) $(OBJECTS) /OUT:$(LIB_RUBY_PARSER_STATIC)
else
	LIB_RUBY_PARSER_O = $(TARGET_DIR)/lib-ruby-parser$(OBJ_FILE_EXT)
	BUILD_STATIC = cp $(TARGET_DIR)/lib-ruby-parser-rust-static.a $(TARGET_DIR)/lib-ruby-parser.a && \
					rm -f $(LIB_RUBY_PARSER_O) && \
					$(LD) $(OBJECTS) -r -o $(LIB_RUBY_PARSER_O) && \
					ar -rv $(TARGET_DIR)/lib-ruby-parser.a $(LIB_RUBY_PARSER_O)
endif

$(LIB_RUBY_PARSER_STATIC): $(RUST_OBJ) $(OBJECTS)
	$(BUILD_STATIC)

# tests

TEST_DEPS = $(LIB_RUBY_PARSER_STATIC) $(TEST_O)
$(TARGET_DIR)/test-runner: $(TEST_DEPS)
	$(CC) $(TEST_O) $(LIB_RUBY_PARSER_STATIC) $(CCFLAGS) $(CCEXECFLAGS) $(CC_SET_OUT_FILE)$(TARGET_DIR)/test-runner

test: $(TARGET_DIR)/test-runner
	$(TARGET_DIR)/test-runner

test-valgrind: $(TARGET_DIR)/test-runner
	valgrind --leak-check=full --error-exitcode=1 $(TARGET_DIR)/test-runner

clean:
	rm -rf $(TARGET_DIR)
	mkdir -p $(TARGET_DIR)
	rm -f $(LIB_RUBY_PARSER_H)

test-cov: cargo-build target-dir
	$(CC) test.c $(RUST_OBJ) $(CC_DEFAULT_FLAGS) -fprofile-instr-generate -fcoverage-mapping -o $(TARGET_DIR)/test
	LLVM_PROFILE_FILE="$(TARGET_DIR)/test.profraw" $(TARGET_DIR)/test
	llvm-profdata merge -sparse $(TARGET_DIR)/test.profraw -o $(TARGET_DIR)/test.profdata
	llvm-cov report ./$(TARGET_DIR)/test -instr-profile=$(TARGET_DIR)/test.profdata
	# llvm-cov show ./$(TARGET_DIR)/test -instr-profile=$(TARGET_DIR)/test.profdata

# release

STATIC_RELEASE_LIB = $(TARGET_DIR)/$(RELEASE_FILE)$(STATIC_LIB_EXT)

$(STATIC_RELEASE_LIB): $(LIB_RUBY_PARSER_STATIC)
	cp $(LIB_RUBY_PARSER_STATIC) $(STATIC_RELEASE_LIB)

build-static: $(STATIC_RELEASE_LIB) $(TEST_O)
	# test
	$(CC) $(TEST_O) $(STATIC_RELEASE_LIB) $(CCFLAGS) $(CCEXECFLAGS) $(CC_SET_OUT_FILE)$(TARGET_DIR)/static-test-runner
	$(LIST_DEPS) $(TARGET_DIR)/static-test-runner
	$(TARGET_DIR)/static-test-runner
