target/fuzzer: $(STATIC_LIB) $(HEADER) fuzzer/parse.c
	$(CC) fuzzer/parse.c -fsanitize=fuzzer,address $(STATIC_LIB) $(CCFLAGS) $(CCEXECFLAGS) $(CC_SET_OUT_FILE)target/fuzzer

fuzz: target/fuzzer
	./target/fuzzer -max_len=50 -timeout=10
