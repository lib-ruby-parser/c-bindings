ifeq ($(CARGO_BUILD_TARGET), x86_64-pc-windows-msvc)
	CC_SET_OUT_FILE = /link /OUT:
else
	# GCC-like compiler (GCC/Clang/MinGW)
	CC_SET_OUT_FILE = -o #
endif

ifeq ($(DETECTED_OS), Linux)
	CCEXECFLAGS = -lpthread -ldl
endif

ifeq ($(CARGO_BUILD_TARGET), x86_64-pc-windows-gnu)
	CCEXECFLAGS += -lws2_32 -luserenv
endif

TEST_O = $(TARGET_DIR)/test.$(OBJ_FILE_EXT)
$(TEST_O): test/test.c
	$(CC) test/test.c $(CCFLAGS) $(CCOBJFLAGS)
	mv test.$(OBJ_FILE_EXT) $(TEST_O)

$(TARGET_DIR)/test-runner: $(STATIC_LIB) $(TEST_O)
	$(CC) $(TEST_O) $(STATIC_LIB) $(CCFLAGS) $(CCEXECFLAGS) $(CC_SET_OUT_FILE)$(TARGET_DIR)/test-runner

test: $(TARGET_DIR)/test-runner
	$(TARGET_DIR)/test-runner

test-valgrind: $(TARGET_DIR)/test-runner
	valgrind --leak-check=full --error-exitcode=1 $(TARGET_DIR)/test-runner

test-cov: cargo-build target-dir
	$(CC) test.c $(RUST_OBJ) $(CC_DEFAULT_FLAGS) -fprofile-instr-generate -fcoverage-mapping -o $(TARGET_DIR)/test
	LLVM_PROFILE_FILE="$(TARGET_DIR)/test.profraw" $(TARGET_DIR)/test
	llvm-profdata merge -sparse $(TARGET_DIR)/test.profraw -o $(TARGET_DIR)/test.profdata
	llvm-cov report ./$(TARGET_DIR)/test -instr-profile=$(TARGET_DIR)/test.profdata
	# llvm-cov show ./$(TARGET_DIR)/test -instr-profile=$(TARGET_DIR)/test.profdata
