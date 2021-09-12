ifeq ($(DETECTED_OS), Windows)
	LIST_DEPS = dumpbin /dependents

define build_c_exe
	$(CC) $(1) $(CCFLAGS) /link /OUT:$(2)
endef
endif

ifeq ($(DETECTED_OS), Linux)
	LIST_DEPS = ldd

define build_c_exe
	$(CC) $(1) $(CCFLAGS) -lpthread -ldl -o $(2)
endef
endif

ifeq ($(DETECTED_OS), Darwin)
	LIST_DEPS = otool -L

define build_c_exe
	$(CC) $(1) $(CCFLAGS) -o $(2)
endef
endif
