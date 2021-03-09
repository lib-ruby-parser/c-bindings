project(c-bindings)

file(GLOB C_SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.c")
add_library(c_obj_files STATIC ${C_SRC_FILES})
