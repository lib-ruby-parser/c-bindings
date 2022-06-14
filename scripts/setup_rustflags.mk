CARGOFLAGS += --target $(TARGET)

ifeq ($(BUILD_ENV), debug)
RUST_ENV = debug
RUSTFLAGS += --cfg test
else
RUST_ENV = release
CARGOFLAGS += --release
endif
