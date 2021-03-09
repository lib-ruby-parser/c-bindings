project(tests)

if(UNIX)
    link_libraries(pthread dl m)
endif()

add_executable(test-runner test.c)
add_dependencies(test-runner header)
target_link_libraries(test-runner lib_ruby_parser_full)
