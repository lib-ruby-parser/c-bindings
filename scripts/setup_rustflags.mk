CARGOFLAGS += --target $(TARGET)
RUST_TARGET_DIR = $(RUST_DIR)/target/$(TARGET)

ifeq ($(BUILD_ENV), debug)
	RUST_ENV = debug
	CARGOFLAGS +=
else
	RUST_ENV = release
	CARGOFLAGS += --release
endif
