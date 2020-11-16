CC = clang
RUST_OBJ = lib-ruby-parser-c-bindings/target/debug/liblib_ruby_parser_c_bindings.a
CC_DEFAULT_FLAGS = -g -lpthread -ldl
TARGET_DIR = target

main: build-main
	$(TARGET_DIR)/main

build-main: cargo-build target-dir
	$(CC) main.c $(RUST_OBJ) $(CC_DEFAULT_FLAGS) -o $(TARGET_DIR)/main

test: build-test
	./$(TARGET_DIR)/test

build-test: cargo-build target-dir
	$(CC) test.c $(RUST_OBJ) $(CC_DEFAULT_FLAGS) -o $(TARGET_DIR)/test

test-valgrind: build-test
	valgrind --leak-check=full --error-exitcode=1 ./$(TARGET_DIR)/test

test-asan: build-test
	$(CC) main.c $(RUST_OBJ) -fsanitize=address $(CC_DEFAULT_FLAGS) -o $(TARGET_DIR)/main
	./$(TARGET_DIR)/test

test-all: test test-valgrind test-asan

target-dir:
	mkdir -p $(TARGET_DIR)

cargo-build:
	cd lib-ruby-parser-c-bindings && cargo build

clean:
	rm -rf $(TARGET_DIR)
	rm includes/gen.h
	rm lib-ruby-parser-c-bindings/src/bindings.rs
	rm lib-ruby-parser-c-bindings/src/node_gen.rs

test-cov: cargo-build target-dir
	$(CC) test.c $(RUST_OBJ) $(CC_DEFAULT_FLAGS) -fprofile-instr-generate -fcoverage-mapping -o $(TARGET_DIR)/test
	LLVM_PROFILE_FILE="$(TARGET_DIR)/test.profraw" $(TARGET_DIR)/test
	llvm-profdata merge -sparse $(TARGET_DIR)/test.profraw -o $(TARGET_DIR)/test.profdata
	llvm-cov report ./$(TARGET_DIR)/test -instr-profile=$(TARGET_DIR)/test.profdata
	llvm-cov show ./$(TARGET_DIR)/test -instr-profile=$(TARGET_DIR)/test.profdata
