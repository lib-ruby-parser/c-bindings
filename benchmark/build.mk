BENCHMARK_RUNNER = $(TARGET_DIR)/benchmark-runner
$(BENCHMARK_RUNNER): benchmark/lib-ruby-parser.c $(STATIC_LIB) $(HEADER)
	$(CC) -I. benchmark/lib-ruby-parser.c $(STATIC_LIB) $(CCFLAGS) $(CCEXECFLAGS) -o $(BENCHMARK_RUNNER)

benchmark: $(BENCHMARK_RUNNER)
	$(BENCHMARK_RUNNER)

.PHONY: benchmark
