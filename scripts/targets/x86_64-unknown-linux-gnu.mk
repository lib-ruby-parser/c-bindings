$(info Compiling x86_64-unknown-linux-gnu target)

O = o
A = a

STATIC_LIB_FILE = libruby_parser_c.$(A)
LIST_DEPS = ldd

CFLAGS += -Wall -Wextra -g

ifeq ($(BUILD_ENV), debug)
CFLAGS += -O0
else
CFLAGS += -O3
endif

define add_to_lib
$(AR) r $(1) $(2)
endef

define build_c_obj
$(CC) $(1) $(CFLAGS) -flto=thin -c -o $(2)
llvm-nm-12 $(2)
endef

define build_c_exe
$(CC) $(1) $(CFLAGS) -fuse-ld=lld-12 -flto -lpthread -ldl -lm -o $(2)
endef

