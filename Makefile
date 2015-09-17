ROOT_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
INC_DIR := $(addprefix $(ROOT_DIR), includes/)
LIB_DIR := $(addprefix $(ROOT_DIR), lib/)
TESTS_DIR := $(addprefix $(ROOT_DIR), tests/)
EXAMPLES_DIR := $(addprefix $(ROOT_DIR), examples/)
BUILD_DIR := $(addprefix $(ROOT_DIR), build/)

CC=gcc
LD=gcc
CFLAGS=-I$(INC_DIR) -g -Wall -Werror -std=c99 -pedantic-errors
LDFLAGS=


.PHONY: clean

all: libs

# Source Files

include $(addprefix $(LIB_DIR), lib.mk)

#Tests

include $(addprefix $(TESTS_DIR), tests.mk)

#Examples

include $(addprefix $(EXAMPLES_DIR), examples.mk)

#Helpers

build:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rfv $(BUILD_DIR)
