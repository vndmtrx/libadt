ROOT_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
INC_DIR := $(addprefix $(ROOT_DIR), includes/)
LIB_DIR := $(addprefix $(ROOT_DIR), lib/)
ALG_DIR := $(addprefix $(ROOT_DIR), algorithms/)
TESTS_DIR := $(addprefix $(ROOT_DIR), tests/)
EXAMPLES_DIR := $(addprefix $(ROOT_DIR), examples/)
BUILD_DIR := $(addprefix $(ROOT_DIR), build/)

CC?=gcc
AR?=ar
RL?=ranlib
CFLAGS=-I$(INC_DIR) -g -Wall -Werror -Wextra -std=c11 -coverage -O0
CLIBFLAGS=$(CFLAGS) -fPIC
ARFLAGS=rcs

.PHONY: clean

all: libs

# Source Files

include $(addprefix $(LIB_DIR), lib.mk)

#Tests

include $(addprefix $(TESTS_DIR), tests.mk)

#Algorithms

include $(addprefix $(ALG_DIR), algorithms.mk)

#Examples

include $(addprefix $(EXAMPLES_DIR), examples.mk)

#Helpers

build:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rfv $(BUILD_DIR)
