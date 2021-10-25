benchmark/c-runner: $(STATIC_LIB) benchmark/benchmark.c
	$(call build_c_exe,benchmark/benchmark.c $(STATIC_LIB),benchmark/c-runner)
CLEAN += benchmark/c-runner

run-benchmark: benchmark/c-runner
	./benchmark/c-runner

define download_latest_bench_asset
curl -s https://api.github.com/repos/lib-ruby-parser/bench/releases/latest \
	| jq '.assets[] \
	| select(.name == "$(1)") \
	| .browser_download_url' \
	| xargs wget -q -O "$(2)"
endef

download-benchmark-assets:
	@echo "Downloading repos.zip..."
	$(call download_latest_bench_asset,repos.zip,benchmark/repos.zip)
	@echo "Unpacking repos.zip..."
	unzip -q benchmark/repos.zip -d benchmark

	@echo "Downloading Rust parser..."
	$(call download_latest_bench_asset,$(BENCHMARK_RUNNER_ASSET_NAME),benchmark/rust-parser)
	chmod +x benchmark/rust-parser

	@echo "Downloading Ruby parser..."
	$(call download_latest_bench_asset,ruby-parser.rb,benchmark/ruby-parser.rb)

define run_benchmark
cd benchmark && FILELIST_PATH=filelist $(1)
endef

benchmark/compare: benchmark/c-runner
	$(call run_benchmark, ./rust-parser)
	$(call run_benchmark, ruby ruby-parser.rb)
	$(call run_benchmark, ./c-runner)
