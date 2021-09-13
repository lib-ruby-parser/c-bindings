ifndef BUILD_ENV
	BUILD_ENV = debug
endif

ifeq ($(BUILD_ENV), debug)
# ok
else
ifeq ($(BUILD_ENV), release)
# ok
else
$(error Unknown BUILD_ENV=$(BUILD_ENV); known values: debug, release; default: debug)
endif
endif
