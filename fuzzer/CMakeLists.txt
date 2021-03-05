project(fuzzer)

add_executable(fuzzer EXCLUDE_FROM_ALL parse.c)
set(USE_FUZZER "-fsanitize=fuzzer,address")
set_target_properties(fuzzer PROPERTIES COMPILE_FLAGS ${USE_FUZZER} LINK_FLAGS ${USE_FUZZER})
add_dependencies(fuzzer header)
target_link_libraries(fuzzer lib_ruby_parser_full)
