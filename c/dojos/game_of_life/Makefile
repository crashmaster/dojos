DOJO_NAME := game_of_life
DOJOS_DIR := /dojos
DOJO_DIR := ${DOJOS_DIR}/${DOJO_NAME}
BUILD_DIR := ${DOJO_DIR}/build
BIN_DIR := ${BUILD_DIR}/source
TEST_EXECUTABLE := ${BIN_DIR}/test_${DOJO_NAME}
CLANG := /usr/bin/clang
CLANGPP := /usr/bin/clang++
CMAKE := /usr/bin/cmake
DOCKER := /usr/bin/docker
DOCKER_TAG := c_lang
DOCKER_CONFIG_PATH := ../../
DOCKER_USER := --user "$(shell id -u):$(shell id -g)"
DOCKER_VOLUME := --volume=$(shell readlink -f $(shell pwd)/../..${DOJOS_DIR}):${DOJOS_DIR}
DOCKER_OPTS := --tty --interactive
DOCKER_BUILD := ${DOCKER} build --tag=${DOCKER_TAG} ${DOCKER_CONFIG_PATH}
DOCKER_RUN := docker run ${DOCKER_USER} ${DOCKER_VOLUME} ${DOCKER_OPTS} ${DOCKER_TAG}

CALL_RM_BUILD_DIR := sh -c "rm -rf ${BUILD_DIR}"
CALL_CMAKE := sh -c "mkdir -p ${BUILD_DIR} && cd ${BUILD_DIR} && CC=${CLANG} CXX=${CLANGPP} ${CMAKE} .."
CALL_MAKE := sh -c "cd ${BUILD_DIR} && ${MAKE} --silent"
CALL_TEST := sh -c "${TEST_EXECUTABLE}"

.PHONY: all clean compile docker_build make test

all: compile

clean: docker_build
	@${DOCKER_RUN} ${CALL_RM_BUILD_DIR}

compile: docker_build
	@${DOCKER_RUN} ${CALL_MAKE}

docker_build:
	@${DOCKER_BUILD}

make: docker_build
	@${DOCKER_RUN} ${CALL_CMAKE}

test: docker_build compile
	@${DOCKER_RUN} ${CALL_TEST}
