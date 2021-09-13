ifndef TARGET
$(error TARGET variable is required)
endif

include scripts/targets/$(TARGET).mk

$(info Build configuration:)

$(info O = $(O))
$(info A = $(A))
$(info STATIC_LIB_FILE = $(STATIC_LIB_FILE))
$(info LIST_DEPS = $(LIST_DEPS))
$(info CFLAGS = $(CFLAGS))

$(info add_to_lib = $(call add_to_lib,lib.$(A),object.$(O)))
$(info build_c_obj = $(call build_c_obj,file.c,file.$(O)))
$(info build_c_exe = $(call build_c_exe,file.$(O),out))

$(info )
