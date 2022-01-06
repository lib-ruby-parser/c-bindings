$(info Compiling x86_64-pc-windows-msvc target)

O = obj
A = lib

STATIC_LIB_FILE = ruby_parser_c.$(A)
LIST_DEPS = dumpbin /dependents

# /nologo
CFLAGS += /bigobj /MT /Zi

ifeq ($(BUILD_ENV), debug)
CFLAGS += /Od /DEBUG /DTEST_ENV
else
CFLAGS += /O2
endif

define add_to_lib
lib.exe $(1) $(2) /OUT:$(1)
endef

define build_c_obj
$(CC) $(1) $(CFLAGS) /c /Fo
endef

define build_c_exe
$(CC) ws2_32.lib advapi32.lib userenv.lib bcrypt.lib $(1) $(CFLAGS) /link /OUT:$(2)
endef

BENCHMARK_RUNNER_ASSET_NAME = rust-parser-x86_64-pc-windows-msvc.exe
