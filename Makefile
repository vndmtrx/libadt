CC=gcc
LD=gcc
CFLAGS=-Iincludes -g -Wall -Werror -std=c99 -pedantic-errors
LDFLAGS=

.PHONY: clean

all: mk_tests mk_examples

# Source Files

include lib/lib.mk

#Tests

include tests/tests.mk

#Examples

include examples/examples.mk

#Helpers

build:
	mkdir -p $@

clean:
	rm -rfv build/
