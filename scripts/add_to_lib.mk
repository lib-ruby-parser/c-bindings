ifeq ($(DETECTED_OS), Windows)
	A = lib
	STATIC_LIB_FILE = ruby_parser_c.$(A)
endif
ifeq ($(DETECTED_OS), Linux)
	A = a
	STATIC_LIB_FILE = libruby_parser_c.$(A)
endif
ifeq ($(DETECTED_OS), Darwin)
	A = a
	STATIC_LIB_FILE = libruby_parser_c.$(A)
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
