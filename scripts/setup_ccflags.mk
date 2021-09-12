# Windows
ifeq ($(DETECTED_OS), Windows)
CCFLAGS += /nologo /bigobj /MT /Zi

ifeq ($(BUILD_ENV), debug)
CCFLAGS += /Od /DEBUG
else
CCFLAGS += /O2
endif

ifdef LTO
$(error Windows build doesn't support LTO)
endif
endif

# Linux
ifeq ($(DETECTED_OS), Linux)
CCFLAGS += -Wall -Wextra -g

ifeq ($(BUILD_ENV), debug)
CCFLAGS += -O0
else
CCFLAGS += -O3
endif

ifdef LTO
$(warning Enabling LTO flags)
CCFLAGS += --target=$(TARGET) -flto=thin
endif
endif

# Darwin
ifeq ($(DETECTED_OS), Darwin)
CCFLAGS += -Wall -Wextra -g

ifeq ($(BUILD_ENV), debug)
CCFLAGS += -O0
else
CCFLAGS += -O3
endif

ifdef LTO
$(error Darwin build doesn't support LTO)
CCFLAGS += -flto=thin
endif
endif
