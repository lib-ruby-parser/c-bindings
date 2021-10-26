benchmark/c-parser: $(STATIC_LIB) benchmark/benchmark.c
	$(call build_c_exe,benchmark/benchmark.c $(STATIC_LIB),benchmark/c-parser)

define download_latest_bench_asset
curl $(CURL_ARGS) -s https://api.github.com/repos/lib-ruby-parser/bench/releases/latest \
	| jq '.assets[] | select(.name == "$(1)") | .browser_download_url' \
	| xargs wget -q -O "$(2)"
endef

benchmark/download:
	@echo "Downloading repos.zip..."
	$(call download_latest_bench_asset,repos.zip,benchmark/repos.zip)
	@echo "Unpacking repos.zip..."
	unzip -q benchmark/repos.zip -d benchmark

	@echo "Downloading Rust parser..."
	$(call download_latest_bench_asset,$(BENCHMARK_RUNNER_ASSET_NAME),benchmark/rust-parser)
	chmod +x benchmark/rust-parser

	@echo "Downloading Ruby parser..."
	$(call download_latest_bench_asset,ruby-parser.rb,benchmark/ruby-parser.rb)

BENCHMARK_ASSETS = \
	benchmark/repos \
	benchmark/c-parser \
	benchmark/filelist \
	benchmark/repos.zip \
	benchmark/ruby-parser.rb \
	benchmark/rust-parser \
	benchmark/stats

benchmark/clear:
	rm -rf $(BENCHMARK_ASSETS)

define run_benchmark
cd benchmark && FILELIST_PATH=filelist $(1)
endef

benchmark/compare: benchmark/c-parser
	$(call run_benchmark, ./rust-parser)
	$(call run_benchmark, ruby ruby-parser.rb)
	$(call run_benchmark, ./c-parser)
