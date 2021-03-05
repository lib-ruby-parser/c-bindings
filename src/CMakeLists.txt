project(c-bindings)

file(GLOB C_SRC_FILES "*.c")
add_library(c_obj_files OBJECT ${C_SRC_FILES})
