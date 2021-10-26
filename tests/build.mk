tests/runner: $(STATIC_LIB)
	$(call build_c_exe,tests/test.c $(STATIC_LIB),tests/runner)
	$(LIST_DEPS) tests/runner
tests/run: tests/runner
	./tests/runner
CLEAN += tests/runner
