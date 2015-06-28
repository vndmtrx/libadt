CC=gcc
LD=gcc
CFLAGS=-Iincludes -g -Wall -Werror -std=c99 -pedantic-errors
LDFLAGS=

.PHONY: clean

all: mk_tests

# Source Files

include lib/lib.mk

#Tests

include tests/tests.mk

#Helpers

build:
	mkdir -p $@

clean:
	rm -rfv build/
