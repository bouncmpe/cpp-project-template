SOURCE_DIRECTORY = $(PWD)
BUILD_DIRECTORY = /tmp/build

all: configure build test

configure:
	cmake \
		-S $(SOURCE_DIRECTORY) \
		-B $(BUILD_DIRECTORY) \
		-DCMAKE_BUILD_TYPE=Release \
		-DENABLE_TESTS=ON
	
build:
	cmake --build $(BUILD_DIRECTORY)

test:
	ctest --test-dir $(BUILD_DIRECTORY) --output-on-failure
