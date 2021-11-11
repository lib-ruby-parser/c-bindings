$(info Compiling x86_64-pc-windows-gnu target)

O = o
A = a

STATIC_LIB_FILE = libruby_parser_c.$(A)
LIST_DEPS = ldd

CFLAGS += -Wall -Wextra -g

ifeq ($(BUILD_ENV), debug)
CFLAGS += -O0 -DTEST_ENV
else
CFLAGS += -O3
endif

define add_to_lib
$(AR) r $(1) $(2)
endef

define build_c_obj
$(CC) $(1) $(CFLAGS) -c -o $(2)
endef

define build_c_exe
$(CC) $(1) $(CFLAGS) -lws2_32 -luserenv -o $(2)
endef

BENCHMARK_RUNNER_ASSET_NAME = rust-parser-x86_64-pc-windows-gnu.exe
