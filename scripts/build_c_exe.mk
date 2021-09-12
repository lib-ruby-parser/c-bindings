ifeq ($(DETECTED_OS), Windows)
	LIST_DEPS = dumpbin /dependents

define build_c_exe
	$(CC) ws2_32.lib advapi32.lib userenv.lib $(1) $(CCFLAGS) /link /OUT:$(2)
endef
endif

ifeq ($(DETECTED_OS), Linux)
	LIST_DEPS = ldd

define build_c_exe
	$(CC) $(1) $(CCFLAGS) -lpthread -ldl -lm -o $(2)
endef
endif

ifeq ($(DETECTED_OS), Darwin)
	LIST_DEPS = otool -L

define build_c_exe
	$(CC) $(1) $(CCFLAGS) -o $(2)
endef
endif
