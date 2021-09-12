ifeq ($(DETECTED_OS), Windows)
	O = obj
endif
ifeq ($(DETECTED_OS), Linux)
	O = o
endif
ifeq ($(DETECTED_OS), Darwin)
	O = o
endif

ifeq ($(DETECTED_OS), Windows)

define build_c_obj
	$(CC) $(1) $(CCFLAGS) /c /Fo
endef

else

define build_c_obj
	$(CC) $(1) $(CCFLAGS) -c -o $(2)
endef

endif
