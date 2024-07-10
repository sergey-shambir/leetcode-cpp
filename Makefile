# Use `make BUILD_TYPE=Release` to change build type
BUILD_TYPE = Debug

ifeq ($(BUILD_TYPE), Debug)
	CONAN_RPOFILE = debug
else ifeq ($(BUILD_TYPE), Release)
	CONAN_RPOFILE = release
else
	$(error Unknown build type $(BUILD_TYPE))
endif

all: conan cmake build test

conan:
	conan install . --build=missing --profile=$(CONAN_RPOFILE)

cmake:
	cmake CMakeLists.txt -Bbuild/$(BUILD_TYPE) -DCMAKE_TOOLCHAIN_FILE="generators/conan_toolchain.cmake" -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)

build:
	cmake --build build/$(BUILD_TYPE)

test: build 
	 ctest --output-on-failure --test-dir build/$(BUILD_TYPE)

.PHONY: conan cmake build test
