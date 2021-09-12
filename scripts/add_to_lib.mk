ifeq ($(DETECTED_OS), Windows)
	A = lib
endif
ifeq ($(DETECTED_OS), Linux)
	A = a
endif
ifeq ($(DETECTED_OS), Darwin)
	A = a
endif

# Usage:
# $(call add_to_lib,$(LIB),$(FILES))

ifeq ($(DETECTED_OS), Windows)

define add_to_lib
	lib.exe $(1) $(2) /OUT:$(1)
endef

else

define add_to_lib
	$(AR) r $(1) $(2)
endef

endif
