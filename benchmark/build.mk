BENCHMARK_RUNNER = $(TARGET_DIR)/benchmark-runner
$(BENCHMARK_RUNNER): benchmark/lib-ruby-parser.c $(STATIC_LIB)
	$(CC) -I. benchmark/lib-ruby-parser.c $(STATIC_LIB) $(CCFLAGS) $(CCEXECFLAGS) -L /usr/local/Cellar/jemalloc/5.2.1_1/lib -ljemalloc -o $(BENCHMARK_RUNNER)

benchmark: $(BENCHMARK_RUNNER)
	$(BENCHMARK_RUNNER)

.PHONY: benchmark
