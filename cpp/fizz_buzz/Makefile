BUILD_DIRECTORY := build

all: usage

build: build_dir
	cd ${BUILD_DIRECTORY} && cmake ..

build_dir:
	mkdir -p ${BUILD_DIRECTORY}

test: compile_test
	./${BUILD_DIRECTORY}/test_fizz_buzz

compile_test:
	cd ${BUILD_DIRECTORY} && make

usage:
	@echo "usage:"
	@echo "  primary targets:"
	@echo "    build        -> let CMake generate Makefiles"
	@echo "    test         -> execute test_fizz_buzz"
	@echo "  secondary targets:"
	@echo "    build_dir    -> create build directory"
	@echo "    compile_test -> compile test_fizz_buzz executable"

.PHONY: \
	build \
	build_dir \
	compile_test \
	test \
	usage
