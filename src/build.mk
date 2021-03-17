ifeq ($(CARGO_BUILD_TARGET), x86_64-pc-windows-msvc)
	CCFLAGS += /std:c++17 /nologo
	CCOBJFLAGS += /c /Fo
	CCFLAGS += /MT /Zi

	ifeq ($(BUILD_ENV), debug)
		CCFLAGS += /Od /DEBUG
	else
		CCFLAGS += /O2
	endif

	OBJ_FILE_EXT = obj
else
	# GCC-like compiler (GCC/Clang/MinGW)
	CCFLAGS += -Wall -Wextra
	CCOBJFLAGS += -fPIC -c

	ifeq ($(BUILD_ENV), debug)
		CCFLAGS += -g -O0
	else
		CCFLAGS += -O2
	endif

	OBJ_FILE_EXT = o
endif

ALL_SRCS = $(wildcard src/*.c)
ALL_HEADERS = $(wildcard src/*.h)
OBJECTS = $(foreach src,$(ALL_SRCS), $(patsubst src/%.c,$(TARGET_DIR)/%.$(OBJ_FILE_EXT),$(src)))

include .depend
.depend: $(ALL_SRCS) $(ALL_HEADERS)
	rm -f "$@"
	touch "$@"
	$(foreach src,$(ALL_SRCS), $(CC) -MT $(patsubst src/%.c,$(TARGET_DIR)/%.$(OBJ_FILE_EXT),$(src)) -MM $(src) >> $@; echo "" >> $@;)
depend: .depend

$(TARGET_DIR)/%.$(OBJ_FILE_EXT): filename = $(patsubst $(TARGET_DIR)/%.$(OBJ_FILE_EXT),%,$@)
$(TARGET_DIR)/%.$(OBJ_FILE_EXT): source = src/$(filename).c
$(TARGET_DIR)/%.$(OBJ_FILE_EXT): header = src/$(filename).h
$(TARGET_DIR)/%.$(OBJ_FILE_EXT):
	$(CC) $(source) $(CCFLAGS) $(CCOBJFLAGS)
	mv $(filename).$(OBJ_FILE_EXT) $(TARGET_DIR)/$(filename).$(OBJ_FILE_EXT)

