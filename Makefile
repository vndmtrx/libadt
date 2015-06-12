CC=gcc
LD=gcc
CFLAGS=-Iincludes/ -g -Wall
LDFLAGS=

OBJS=teste1.o

.PHONY: clean

all: tests

# Source Files

include lib/lib.mk

#Tests

include tests/tests.mk

#Helpers

build:
	mkdir -p $@

clean:
	rm -rfv build/
