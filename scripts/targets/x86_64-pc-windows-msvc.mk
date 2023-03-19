$(info Compiling x86_64-pc-windows-msvc target)

O = obj
A = lib
EXE = .exe

STATIC_LIB_FILE = ruby_parser_c.$(A)
LIST_DEPS = dumpbin /dependents
CARGO_BUILD = cargo build

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
$(CC) /c $(CFLAGS) /Fo $(1)
endef

define build_c_exe
$(CC) $(CFLAGS) ws2_32.lib advapi32.lib userenv.lib bcrypt.lib $(1) /link /OUT:$(2)
endef

BENCHMARK_RUNNER_ASSET_NAME = rust-parser-x86_64-pc-windows-msvc.exe
CODEGEN_ASSET_NAME = codegen-x86_64-pc-windows-msvc.exe
