TESTS = \
	tests/api_test.c \
	tests/bytes_test.c \
	tests/comment_test.c \
	tests/decoded_input_test.c \
	tests/decoder_test.c \
	tests/diagnostic_test.c \
	tests/loc_test.c \
	tests/magic_comment_test.c \
	tests/messages_test.c \
	tests/nodes_test.c \
	tests/parser_options_test.c \
	tests/parser_result_test.c \
	tests/shared_byte_list_test.c \
	tests/source_line_test.c \
	tests/string_test.c \
	tests/token_rewriter_test.c \
	tests/token_test.c

tests/runner: $(STATIC_LIB)
	$(call build_c_exe,tests/runner.c $(STATIC_LIB),tests/runner)
	$(LIST_DEPS) tests/runner
tests/run: tests/runner
	./tests/runner
CLEAN += tests/runner
